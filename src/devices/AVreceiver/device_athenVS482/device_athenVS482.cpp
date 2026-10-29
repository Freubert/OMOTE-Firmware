#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_athenVS482.h"

uint16_t ATHEN_POWER_ON;
uint16_t ATHEN_POWER_OFF;
uint16_t ATHEN_INPUT_HDMI_1;
uint16_t ATHEN_INPUT_HDMI_2;
uint16_t ATHEN_INPUT_HDMI_3;
uint16_t ATHEN_INPUT_HDMI_4;
uint16_t ATHEN_SETUP;
uint16_t ATHEN_MENU;
uint16_t ATHEN_INFO;
uint16_t ATHEN_ARC;
uint16_t ATHEN_HDMI_MUTE;
uint16_t ATHEN_UP;
uint16_t ATHEN_DOWN;
uint16_t ATHEN_LEFT;
uint16_t ATHEN_RIGHT;

void register_device_athenVS482() {
  // Source: ATEN VS482 IR command sheet. NEC, 38 kHz, customer code 00FD (extended address, second byte not inverted).
  register_command(&ATHEN_POWER_ON, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF48B7"}));
  register_command(&ATHEN_POWER_OFF, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF708F"}));
  register_command(&ATHEN_INPUT_HDMI_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF20DF"}));
  register_command(&ATHEN_INPUT_HDMI_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BFA05F"}));
  register_command(&ATHEN_INPUT_HDMI_3, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF609F"}));
  register_command(&ATHEN_INPUT_HDMI_4, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF7887"}));
  register_command(&ATHEN_SETUP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF9867"}));
  register_command(&ATHEN_MENU, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BFE01F"}));
  register_command(&ATHEN_INFO, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF10EF"}));
  register_command(&ATHEN_ARC, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF906F"}));
  register_command(&ATHEN_HDMI_MUTE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BFD827"}));
  register_command(&ATHEN_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF08F7"}));
  register_command(&ATHEN_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF40BF"}));
  register_command(&ATHEN_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BFB847"}));
  register_command(&ATHEN_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00BF30CF"}));
}
