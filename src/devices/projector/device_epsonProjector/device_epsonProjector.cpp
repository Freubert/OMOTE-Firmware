#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_epsonProjector.h"

// EPSON EB-680W IR codes (using NEC protocol)
// These are typical NEC protocol codes for Epson projectors
uint16_t EPSON_POWER_ON           ; // "Epson_power_on";
uint16_t EPSON_POWER_OFF          ; // "Epson_power_off";
uint16_t EPSON_POWER_TOGGLE       ; // "Epson_power_toggle";
uint16_t EPSON_VOL_UP             ; // "Epson_vol_up";
uint16_t EPSON_VOL_DOWN           ; // "Epson_vol_down";
uint16_t EPSON_MUTE               ; // "Epson_mute";
uint16_t EPSON_MENU               ; // "Epson_menu";
uint16_t EPSON_HOME               ; // "Epson_home";
uint16_t EPSON_UP                 ; // "Epson_up";
uint16_t EPSON_DOWN               ; // "Epson_down";
uint16_t EPSON_LEFT               ; // "Epson_left";
uint16_t EPSON_RIGHT              ; // "Epson_right";
uint16_t EPSON_SELECT             ; // "Epson_select";
uint16_t EPSON_EXIT               ; // "Epson_exit";
uint16_t EPSON_SOURCE             ; // "Epson_source";
uint16_t EPSON_INPUT_HDMI1        ; // "Epson_input_hdmi1";
uint16_t EPSON_INPUT_HDMI2        ; // "Epson_input_hdmi2";
uint16_t EPSON_INPUT_VGA          ; // "Epson_input_vga";
uint16_t EPSON_INPUT_COMPOSITE    ; // "Epson_input_composite";
uint16_t EPSON_INPUT_SVIDEO       ; // "Epson_input_svideo";

void register_device_epsonProjector() {
  // EPSON EB-680W projector IR codes (using NEC protocol)
  // Note: These are example codes, actual codes should be verified with the projector's IR remote
  register_command(&EPSON_POWER_ON, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09966"}));
  register_command(&EPSON_POWER_OFF, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E019E6"}));
  register_command(&EPSON_POWER_TOGGLE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E059A6"}));
  register_command(&EPSON_VOL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E039C6"}));
  register_command(&EPSON_VOL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E07986"}));
  register_command(&EPSON_MUTE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B946"}));
  register_command(&EPSON_MENU, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E029D6"}));
  register_command(&EPSON_HOME, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E06996"}));
  register_command(&EPSON_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E009F6"}));
  register_command(&EPSON_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08976"}));
  register_command(&EPSON_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A956"}));
  register_command(&EPSON_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E049B6"}));
  register_command(&EPSON_SELECT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E019E6"})); // Same as power off
  register_command(&EPSON_EXIT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E059A6"})); // Same as power toggle
  register_command(&EPSON_SOURCE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0E916"}));
  register_command(&EPSON_INPUT_HDMI1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0C936"}));
  register_command(&EPSON_INPUT_HDMI2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0D926"}));
  register_command(&EPSON_INPUT_VGA, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0F906"}));
  register_command(&EPSON_INPUT_COMPOSITE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E008F7"}));
  register_command(&EPSON_INPUT_SVIDEO, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E018E7"}));
}