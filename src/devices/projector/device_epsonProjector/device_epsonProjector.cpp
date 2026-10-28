#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_epsonProjector.h"

uint16_t EPSON_POWER_ON;
uint16_t EPSON_POWER_OFF;
uint16_t EPSON_POWER_TOGGLE;
uint16_t EPSON_VOL_UP;
uint16_t EPSON_VOL_DOWN;
uint16_t EPSON_MUTE;
uint16_t EPSON_MENU;
uint16_t EPSON_UP;
uint16_t EPSON_DOWN;
uint16_t EPSON_LEFT;
uint16_t EPSON_RIGHT;
uint16_t EPSON_SELECT;
uint16_t EPSON_EXIT;
uint16_t EPSON_SOURCE;
uint16_t EPSON_INPUT_HDMI1;
uint16_t EPSON_INPUT_HDMI2;
uint16_t EPSON_INPUT_VGA;
uint16_t EPSON_INPUT_COMPOSITE;
uint16_t EPSON_INPUT_SVIDEO;

void register_device_epsonProjector() {
  // Source: irdb Epson/Projector (NEC2, device 131, subdevice 85). EPSON_MUTE is the A/V mute (blank) key.
  register_command(&EPSON_POWER_ON, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA09F6"}));
  register_command(&EPSON_POWER_OFF, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA8976"}));
  register_command(&EPSON_POWER_TOGGLE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA09F6"}));
  register_command(&EPSON_VOL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA19E6"}));
  register_command(&EPSON_VOL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA9966"}));
  register_command(&EPSON_MUTE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAC936"}));
  register_command(&EPSON_MENU, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA59A6"}));
  register_command(&EPSON_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA0DF2"}));
  register_command(&EPSON_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA4DB2"}));
  register_command(&EPSON_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AACD32"}));
  register_command(&EPSON_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA8D72"}));
  register_command(&EPSON_SELECT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAA15E"}));
  register_command(&EPSON_EXIT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA21DE"}));
  register_command(&EPSON_SOURCE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA31CE"}));
  register_command(&EPSON_INPUT_HDMI1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AACE31"}));
  register_command(&EPSON_INPUT_HDMI2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAEE11"}));
  register_command(&EPSON_INPUT_VGA, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAB946"}));
  register_command(&EPSON_INPUT_COMPOSITE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA0EF1"}));
  register_command(&EPSON_INPUT_SVIDEO, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA39C6"}));
}
