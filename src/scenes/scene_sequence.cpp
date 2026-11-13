#include <deque>
#include <lvgl.h>
#include "scenes/scene_sequence.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/scenes/sceneHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"

struct SequenceStep {
  bool hasCommand;
  uint16_t command;
  uint32_t delayAfterMs;
  bool needsBle;
};

static std::deque<SequenceStep> sequenceQueue;
static std::deque<SequenceStep> sequenceQueueBle; // runs after all regular steps
static lv_timer_t* sequenceTimer = NULL;

// The timer polls, so that the remote's activity timestamp can be refreshed during long waits (no sleep while a sequence runs).
static const uint32_t SEQUENCE_POLL_MS = 100;
static unsigned long sequenceNextStepAt = 0;

// Non blocking BLE connection handling for steps with needsBle
static const unsigned long BLE_CONNECT_TIMEOUT_MS = 10000;
static const unsigned long BLE_SETTLE_MS = 2000; // keys sent right after connecting sometimes get lost
enum BleState { BLE_IDLE, BLE_CONNECTING, BLE_SETTLING };
static BleState bleState = BLE_IDLE;
static unsigned long bleStateUntil = 0;
static bool bleFailed = false; // connection failed, skip the remaining BLE steps

// returns true when the BLE step can be executed now; skip is set if it has to be dropped
static bool sequence_bleReady(bool& skip) {
  skip = false;
  unsigned long now = millis();
  if (bleFailed) {
    skip = true;
    return false;
  }
  switch (bleState) {
    case BLE_IDLE:
      if (keyboardBLE_isConnected()) {
        return true;
      }
      if (!keyboardBLE_startConnectionToAddress("")) {
        bleFailed = true;
        skip = true;
        return false;
      }
      bleState = BLE_CONNECTING;
      bleStateUntil = now + BLE_CONNECT_TIMEOUT_MS;
      return false;
    case BLE_CONNECTING:
      if (keyboardBLE_isConnected()) {
        bleState = BLE_SETTLING;
        bleStateUntil = now + BLE_SETTLE_MS;
      } else if ((long)(now - bleStateUntil) >= 0) {
        bleState = BLE_IDLE;
        bleFailed = true;
        skip = true;
      }
      return false;
    case BLE_SETTLING:
      if ((long)(now - bleStateUntil) >= 0) {
        bleState = BLE_IDLE;
        return true;
      }
      return false;
  }
  return false;
}

static void sequence_timer_cb(lv_timer_t* timer) {
  setLastActivityTimestamp();
  if ((long)(millis() - sequenceNextStepAt) < 0) {
    return;
  }
  std::deque<SequenceStep>& queue = sequenceQueue.empty() ? sequenceQueueBle : sequenceQueue;
  if (queue.empty()) {
    lv_timer_del(timer);
    sequenceTimer = NULL;
    bleFailed = false;
    bleState = BLE_IDLE;
    setLabelActiveScene();
    return;
  }
  const SequenceStep& front = queue.front();
  if (front.needsBle) {
    bool skip;
    if (!sequence_bleReady(skip)) {
      if (skip) {
        queue.pop_front();
      }
      return;
    }
  }
  SequenceStep step = front;
  queue.pop_front();
  if (step.hasCommand) {
    executeCommand(step.command);
  }
  sequenceNextStepAt = millis() + step.delayAfterMs;
}

static void sequence_ensureTimer() {
  if (sequenceTimer == NULL) {
    sequenceTimer = lv_timer_create(sequence_timer_cb, SEQUENCE_POLL_MS, NULL);
  }
}

void sequence_add(uint16_t command, uint32_t delayAfterMs) {
  sequenceQueue.push_back({true, command, delayAfterMs, false});
  sequence_ensureTimer();
}

void sequence_addBle(uint16_t command, uint32_t delayAfterMs) {
  sequenceQueueBle.push_back({true, command, delayAfterMs, true});
  sequence_ensureTimer();
}

void sequence_wait(uint32_t ms) {
  if (sequenceQueue.empty()) {
    sequenceQueue.push_back({false, 0, ms, false});
    sequence_ensureTimer();
  } else {
    sequenceQueue.back().delayAfterMs += ms;
  }
}

bool sequence_isRunning() {
  return sequenceTimer != NULL;
}
