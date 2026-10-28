#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_philipsTV.h"

uint16_t PHILIPS_NUM_0;
uint16_t PHILIPS_NUM_1;
uint16_t PHILIPS_NUM_2;
uint16_t PHILIPS_NUM_3;
uint16_t PHILIPS_NUM_4;
uint16_t PHILIPS_NUM_5;
uint16_t PHILIPS_NUM_6;
uint16_t PHILIPS_NUM_7;
uint16_t PHILIPS_NUM_8;
uint16_t PHILIPS_NUM_9;
uint16_t PHILIPS_POWER_TOGGLE;
uint16_t PHILIPS_MUTE;
uint16_t PHILIPS_VOL_UP;
uint16_t PHILIPS_VOL_DOWN;
uint16_t PHILIPS_UP;
uint16_t PHILIPS_DOWN;
uint16_t PHILIPS_CHANNEL_UP;
uint16_t PHILIPS_CHANNEL_DOWN;
uint16_t PHILIPS_RIGHT;
uint16_t PHILIPS_LEFT;
uint16_t PHILIPS_MENU;
uint16_t PHILIPS_EXIT;
uint16_t PHILIPS_INPUT_EXTERNAL;
uint16_t PHILIPS_POWER_ON;
uint16_t PHILIPS_POWER_OFF;
uint16_t PHILIPS_GUIDE;
uint16_t PHILIPS_SELECT;
uint16_t PHILIPS_REWIND;
uint16_t PHILIPS_PAUSE;
uint16_t PHILIPS_FASTFORWARD;
uint16_t PHILIPS_PLAY;
uint16_t PHILIPS_INPUT_HDMI_1;
uint16_t PHILIPS_INPUT_HDMI_2;
uint16_t PHILIPS_INPUT_HDMI_3;
uint16_t PHILIPS_INPUT_TV;

void register_device_philipsTV() {
  // Source: irdb Philips/TV (RC5, device 0). The power key is a toggle. The toggle bit of the RC5 frame is always 0.
  register_command(&PHILIPS_NUM_0, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x0"}));
  register_command(&PHILIPS_NUM_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x1"}));
  register_command(&PHILIPS_NUM_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x2"}));
  register_command(&PHILIPS_NUM_3, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x3"}));
  register_command(&PHILIPS_NUM_4, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x4"}));
  register_command(&PHILIPS_NUM_5, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x5"}));
  register_command(&PHILIPS_NUM_6, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x6"}));
  register_command(&PHILIPS_NUM_7, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x7"}));
  register_command(&PHILIPS_NUM_8, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x8"}));
  register_command(&PHILIPS_NUM_9, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x9"}));
  register_command(&PHILIPS_POWER_TOGGLE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xC"}));
  register_command(&PHILIPS_MUTE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xD"}));
  register_command(&PHILIPS_VOL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x10"}));
  register_command(&PHILIPS_VOL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x11"}));
  register_command(&PHILIPS_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x1C"}));
  register_command(&PHILIPS_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x1D"}));
  register_command(&PHILIPS_CHANNEL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x20"}));
  register_command(&PHILIPS_CHANNEL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x21"}));
  register_command(&PHILIPS_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x2B"}));
  register_command(&PHILIPS_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x2C"}));
  register_command(&PHILIPS_MENU, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x2E"}));
  register_command(&PHILIPS_EXIT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xF"}));
  register_command(&PHILIPS_INPUT_EXTERNAL, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x38"}));
  // Source: LIRC Philips LCD_TV_DISCRETE (discrete power/HDMI, converted from LIRC to IRremoteESP8266 RC5X layout) and Flipper-IRDB Philips_14GX8510 (guide).
  register_command(&PHILIPS_POWER_ON, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x3F"}));
  register_command(&PHILIPS_POWER_OFF, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xC"}));
  register_command(&PHILIPS_GUIDE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x3E"}));
  register_command(&PHILIPS_INPUT_HDMI_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xF9"}));
  register_command(&PHILIPS_INPUT_HDMI_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x10FB"}));
  // No IR codes available yet. They only get a unique ID, so executing them does nothing.
  get_uniqueCommandID(&PHILIPS_SELECT);
  get_uniqueCommandID(&PHILIPS_REWIND);
  get_uniqueCommandID(&PHILIPS_PAUSE);
  get_uniqueCommandID(&PHILIPS_FASTFORWARD);
  get_uniqueCommandID(&PHILIPS_PLAY);
  get_uniqueCommandID(&PHILIPS_INPUT_HDMI_3);
  get_uniqueCommandID(&PHILIPS_INPUT_TV);
}
