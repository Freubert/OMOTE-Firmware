#include <lvgl.h>
#include <string>
#include <list>
#include <vector>
#include <stdio.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "gui_teufelScan.h"

// Sweeps the NEC command byte (address 0x20) so the unknown Teufel buttons can be found by watching the amp.
static const uint8_t TEUFEL_NEC_ADDRESS = 0x20;

// Commands that are already known (identified, or tried without effect), the sweep skips them.
static const uint8_t knownCommands[] = {
  0x05, 0x06, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x14, 0x15, 0x16, 0x18,
  0x48, 0x4A, 0x4B, 0x4C, 0x4E, 0x4F, 0x51, 0x53, 0x55, 0x57, 0x59,
};

static std::vector<uint8_t> sweepList;
static int sweepIndex = -1;
static lv_obj_t* statusLabel = NULL;

static uint8_t reverseBits(uint8_t b) {
  uint8_t r = 0;
  for (int i = 0; i < 8; i++) {
    r = (r << 1) | ((b >> i) & 1);
  }
  return r;
}

static void buildSweepList() {
  if (!sweepList.empty()) return;
  for (int cmd = 0; cmd < 256; cmd++) {
    bool known = false;
    for (uint8_t k : knownCommands) {
      if (k == cmd) { known = true; break; }
    }
    if (!known) sweepList.push_back((uint8_t)cmd);
  }
}

static void updateStatus() {
  if (statusLabel == NULL) return;
  char text[64];
  if (sweepIndex < 0) {
    snprintf(text, sizeof(text), "Nothing sent yet\n%d commands to try", (int)sweepList.size());
  } else {
    snprintf(text, sizeof(text), "Sent cmd %d (0x%02X)\n%d of %d", sweepList[sweepIndex], sweepList[sweepIndex], sweepIndex + 1, (int)sweepList.size());
  }
  lv_label_set_text(statusLabel, text);
}

static void sendCurrent() {
  if (sweepIndex < 0) return;
  uint8_t cmd = sweepList[sweepIndex];
  uint32_t data = ((uint32_t)reverseBits(TEUFEL_NEC_ADDRESS) << 24) | ((uint32_t)reverseBits(~TEUFEL_NEC_ADDRESS) << 16)
                | ((uint32_t)reverseBits(cmd) << 8) | reverseBits(~cmd);
  char payload[16];
  snprintf(payload, sizeof(payload), "0x%08X", (unsigned int)data);
  sendIRcode(IR_PROTOCOL_NEC, std::list<std::string>{payload}, "");
}

static void scan_event_cb(lv_event_t* e) {
  int action = (int)(intptr_t)lv_event_get_user_data(e);
  int count = (int)sweepList.size();
  if (action == 0) {
    sweepIndex = (sweepIndex + 1) % count;
  } else if (action == 1) {
    sweepIndex = (sweepIndex <= 0) ? count - 1 : sweepIndex - 1;
  } else if (action == 2) {
    sweepIndex = (sweepIndex + 10) % count;
  }
  sendCurrent();
  updateStatus();
}

static void createButton(lv_obj_t* tab, const char* text, int action) {
  lv_obj_t* button = lv_btn_create(tab);
  lv_obj_set_size(button, LV_PCT(100), 56);
  lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
  lv_obj_add_event_cb(button, scan_event_cb, LV_EVENT_CLICKED, (void*)(intptr_t)action);
  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, text);
  lv_obj_center(label);
}

void create_tab_content_teufelScan(lv_obj_t* tab) {
  buildSweepList();
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  statusLabel = lv_label_create(tab);
  lv_obj_set_width(statusLabel, LV_PCT(100));
  updateStatus();

  createButton(tab, "Next (send)", 0);
  createButton(tab, "Resend", 3);
  createButton(tab, "Previous (send)", 1);
  createButton(tab, "Skip 10 (send)", 2);
}

void notify_tab_before_delete_teufelScan(void) {
  statusLabel = NULL;
}

void register_gui_teufelScan(void) {
  register_gui(std::string(tabName_teufelScan), & create_tab_content_teufelScan, & notify_tab_before_delete_teufelScan);
}
