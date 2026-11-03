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
uint16_t EPSON_INPUT_USB;
uint16_t EPSON_ASPECT;
uint16_t EPSON_AUTO;
uint16_t EPSON_COLOR_MODE;
uint16_t EPSON_FREEZE;
uint16_t EPSON_USER;
uint16_t EPSON_INPUT_LAN;
uint16_t EPSON_INPUT_COMPUTER;
uint16_t EPSON_SPLIT;
uint16_t EPSON_PAGE_UP;
uint16_t EPSON_PAGE_DOWN;
uint16_t EPSON_ZOOM_IN;
uint16_t EPSON_ZOOM_OUT;
uint16_t EPSON_ID;
uint16_t EPSON_HOME;
uint16_t EPSON_POINTER;
uint16_t EPSON_NUM_0;
uint16_t EPSON_NUM_1;
uint16_t EPSON_NUM_2;
uint16_t EPSON_NUM_3;
uint16_t EPSON_NUM_4;
uint16_t EPSON_NUM_5;
uint16_t EPSON_NUM_6;
uint16_t EPSON_NUM_7;
uint16_t EPSON_NUM_8;
uint16_t EPSON_NUM_9;

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
  register_command(&EPSON_INPUT_USB, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA6E91"}));
  register_command(&EPSON_ASPECT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA51AE"}));
  register_command(&EPSON_AUTO, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA7986"}));
  register_command(&EPSON_COLOR_MODE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAF10E"}));
  register_command(&EPSON_FREEZE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA49B6"}));
  register_command(&EPSON_USER, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAF906"}));
  register_command(&EPSON_INPUT_LAN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA2ED1"}));
  register_command(&EPSON_INPUT_COMPUTER, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA29D6"}));
  register_command(&EPSON_SPLIT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA41BE"}));
  register_command(&EPSON_PAGE_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA619E"}));
  register_command(&EPSON_PAGE_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAE11E"}));
  register_command(&EPSON_ZOOM_IN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA11EE"}));
  register_command(&EPSON_ZOOM_OUT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA916E"}));
  register_command(&EPSON_ID, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA8C73"}));
  register_command(&EPSON_HOME, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAA956"}));
  register_command(&EPSON_POINTER, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAD926"}));
  register_command(&EPSON_NUM_0, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA05FA"}));
  register_command(&EPSON_NUM_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA857A"}));
  register_command(&EPSON_NUM_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA45BA"}));
  register_command(&EPSON_NUM_3, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAC53A"}));
  register_command(&EPSON_NUM_4, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA25DA"}));
  register_command(&EPSON_NUM_5, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAA55A"}));
  register_command(&EPSON_NUM_6, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA659A"}));
  register_command(&EPSON_NUM_7, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AAE51A"}));
  register_command(&EPSON_NUM_8, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA15EA"}));
  register_command(&EPSON_NUM_9, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xC1AA956A"}));
}
