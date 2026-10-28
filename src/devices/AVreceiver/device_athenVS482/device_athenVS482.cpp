#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_athenVS482.h"

uint16_t ATHEN_POWER_OFF;
uint16_t ATHEN_POWER_ON;
uint16_t ATHEN_POWER_TOGGLE;
uint16_t ATHEN_INPUT_HDMI_1;
uint16_t ATHEN_INPUT_HDMI_2;
uint16_t ATHEN_INPUT_HDMI_3;
uint16_t ATHEN_INPUT_HDMI_4;
uint16_t ATHEN_INPUT_HDMI_5;
uint16_t ATHEN_INPUT_HDMI_6;
uint16_t ATHEN_INPUT_HDMI_7;
uint16_t ATHEN_INPUT_HDMI_8;
uint16_t ATHEN_INPUT_COMPOSITE_1;
uint16_t ATHEN_INPUT_COMPOSITE_2;
uint16_t ATHEN_INPUT_SVIDEO_1;
uint16_t ATHEN_INPUT_SVIDEO_2;
uint16_t ATHEN_INPUT_VGA_1;
uint16_t ATHEN_INPUT_VGA_2;
uint16_t ATHEN_MENU;
uint16_t ATHEN_UP;
uint16_t ATHEN_DOWN;
uint16_t ATHEN_LEFT;
uint16_t ATHEN_RIGHT;
uint16_t ATHEN_SELECT;
uint16_t ATHEN_EXIT;

void register_device_athenVS482() {
  // Source: irdb Aten/Unknown_VS-431 (NEC, device 0). That is a different Aten model, so the codes are assumed to match the VS482 for
  // inputs 1-4 and up/down (previous/next port). Everything else has no known code yet.
  register_command(&ATHEN_INPUT_HDMI_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FF20DF"}));
  register_command(&ATHEN_INPUT_HDMI_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FFA05F"}));
  register_command(&ATHEN_INPUT_HDMI_3, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FF609F"}));
  register_command(&ATHEN_INPUT_HDMI_4, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FF7887"}));
  register_command(&ATHEN_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FF38C7"}));
  register_command(&ATHEN_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x00FFB847"}));
  // No IR codes available yet. They only get a unique ID, so executing them does nothing.
  get_uniqueCommandID(&ATHEN_POWER_OFF);
  get_uniqueCommandID(&ATHEN_POWER_ON);
  get_uniqueCommandID(&ATHEN_POWER_TOGGLE);
  get_uniqueCommandID(&ATHEN_INPUT_HDMI_5);
  get_uniqueCommandID(&ATHEN_INPUT_HDMI_6);
  get_uniqueCommandID(&ATHEN_INPUT_HDMI_7);
  get_uniqueCommandID(&ATHEN_INPUT_HDMI_8);
  get_uniqueCommandID(&ATHEN_INPUT_COMPOSITE_1);
  get_uniqueCommandID(&ATHEN_INPUT_COMPOSITE_2);
  get_uniqueCommandID(&ATHEN_INPUT_SVIDEO_1);
  get_uniqueCommandID(&ATHEN_INPUT_SVIDEO_2);
  get_uniqueCommandID(&ATHEN_INPUT_VGA_1);
  get_uniqueCommandID(&ATHEN_INPUT_VGA_2);
  get_uniqueCommandID(&ATHEN_MENU);
  get_uniqueCommandID(&ATHEN_LEFT);
  get_uniqueCommandID(&ATHEN_RIGHT);
  get_uniqueCommandID(&ATHEN_SELECT);
  get_uniqueCommandID(&ATHEN_EXIT);
}
