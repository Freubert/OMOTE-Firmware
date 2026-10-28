#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_teufelSConcept.h"

uint16_t TEUFEL_POWER_OFF;
uint16_t TEUFEL_POWER_ON;
uint16_t TEUFEL_VOL_MINUS;
uint16_t TEUFEL_VOL_PLUS;
uint16_t TEUFEL_MUTE_TOGGLE;
uint16_t TEUFEL_INPUT_HDMI_1;
uint16_t TEUFEL_INPUT_HDMI_2;
uint16_t TEUFEL_INPUT_AUX;
uint16_t TEUFEL_INPUT_TV;
uint16_t TEUFEL_SOURCE;
uint16_t TEUFEL_CHANNEL_UP;
uint16_t TEUFEL_CHANNEL_DOWN;
uint16_t TEUFEL_MENU;
uint16_t TEUFEL_GUIDE;
uint16_t TEUFEL_UP;
uint16_t TEUFEL_DOWN;
uint16_t TEUFEL_LEFT;
uint16_t TEUFEL_RIGHT;
uint16_t TEUFEL_SELECT;
uint16_t TEUFEL_EXIT;
uint16_t TEUFEL_REWIND;
uint16_t TEUFEL_PAUSE;
uint16_t TEUFEL_FASTFORWARD;
uint16_t TEUFEL_PLAY;
uint16_t TEUFEL_TRY[TEUFEL_TRY_COUNT];

static const char* const tryCodes[TEUFEL_TRY_COUNT] = {"0x04FB609F", "0x04FB50AF", "0x04FBF20D", "0x04FB708F", "0x04FB728D", "0x04FB12ED", "0x04FBF00F", "0x04FBB04F", "0x04FB32CD", "0x04FB52AD", "0x04FBD22D"};

void register_device_teufelSConcept() {
  for (int i = 0; i < TEUFEL_TRY_COUNT; i++) {
    register_command(&TEUFEL_TRY[i], makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), tryCodes[i]}));
  }
  // Source: the user's Harmony 650 config (NEC, address 0x20), read via the device mode key map. Power, inputs, menu and exit are not bound to a key there and are still unknown.
  // No IR codes available yet. They only get a unique ID, so executing them does nothing.
  get_uniqueCommandID(&TEUFEL_POWER_OFF);
  get_uniqueCommandID(&TEUFEL_POWER_ON);
  register_command(&TEUFEL_VOL_MINUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB18E7"}));
  register_command(&TEUFEL_VOL_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBAA55"}));
  register_command(&TEUFEL_MUTE_TOGGLE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBD02F"}));
  get_uniqueCommandID(&TEUFEL_INPUT_HDMI_1);
  get_uniqueCommandID(&TEUFEL_INPUT_HDMI_2);
  get_uniqueCommandID(&TEUFEL_INPUT_AUX);
  get_uniqueCommandID(&TEUFEL_INPUT_TV);
  get_uniqueCommandID(&TEUFEL_SOURCE);
  register_command(&TEUFEL_CHANNEL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB48B7"}));
  register_command(&TEUFEL_CHANNEL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB6897"}));
  get_uniqueCommandID(&TEUFEL_MENU);
  get_uniqueCommandID(&TEUFEL_GUIDE);
  register_command(&TEUFEL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB08F7"}));
  register_command(&TEUFEL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB8877"}));
  register_command(&TEUFEL_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBA857"}));
  register_command(&TEUFEL_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB9A65"}));
  register_command(&TEUFEL_SELECT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB28D7"}));
  get_uniqueCommandID(&TEUFEL_EXIT);
  register_command(&TEUFEL_REWIND, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBA05F"}));
  register_command(&TEUFEL_PAUSE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB8A75"}));
  register_command(&TEUFEL_FASTFORWARD, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBEA15"}));
  register_command(&TEUFEL_PLAY, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBCA35"}));
}
