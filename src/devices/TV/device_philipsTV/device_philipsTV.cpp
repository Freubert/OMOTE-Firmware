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
uint16_t PHILIPS_INPUT_TV;
uint16_t PHILIPS_INPUT_SIDE;
uint16_t PHILIPS_INPUT_EXT;
uint16_t PHILIPS_INPUT_HDMI_1;
uint16_t PHILIPS_INPUT_HDMI_2;
uint16_t PHILIPS_INPUT_HDMI_3;
uint16_t PHILIPS_STOP;
uint16_t PHILIPS_HOME;
uint16_t PHILIPS_INFO;
uint16_t PHILIPS_SUBTITLE;
uint16_t PHILIPS_SETTINGS;
uint16_t PHILIPS_BLUE;
uint16_t PHILIPS_YELLOW;
uint16_t PHILIPS_GREEN;
uint16_t PHILIPS_TEXT;
uint16_t PHILIPS_BACK;
uint16_t PHILIPS_OPTIONS;
uint16_t PHILIPS_SOURCES;

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
  register_command(&PHILIPS_CHANNEL_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x20"}));
  register_command(&PHILIPS_CHANNEL_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x21"}));
  register_command(&PHILIPS_INPUT_EXTERNAL, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x38"}));
  // Source: LIRC Philips LCD_TV_DISCRETE (discrete power/HDMI, converted from LIRC to IRremoteESP8266 RC5X layout) and Flipper-IRDB Philips_14GX8510 (guide).
  register_command(&PHILIPS_POWER_ON, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x3F"}));
  register_command(&PHILIPS_POWER_OFF, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xC"}));
  // Modern Philips TVs: RC6, address 0 (toggle bit fixed to 1).
  register_command(&PHILIPS_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1005A:20:0"}));
  register_command(&PHILIPS_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1005B:20:0"}));
  register_command(&PHILIPS_UP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10058:20:0"}));
  register_command(&PHILIPS_DOWN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10059:20:0"}));
  register_command(&PHILIPS_SELECT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1005C:20:0"}));
  register_command(&PHILIPS_MENU, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10057:20:0"}));
  register_command(&PHILIPS_EXIT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1000A:20:0"}));
  register_command(&PHILIPS_BACK, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1000A:20:0"}));
  register_command(&PHILIPS_TEXT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1003C:20:0"}));
  register_command(&PHILIPS_GREEN, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1006E:20:0"}));
  register_command(&PHILIPS_YELLOW, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1006F:20:0"}));
  register_command(&PHILIPS_BLUE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10070:20:0"}));
  register_command(&PHILIPS_SETTINGS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x100BF:20:0"}));
  register_command(&PHILIPS_SUBTITLE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1004B:20:0"}));
  register_command(&PHILIPS_INFO, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1000F:20:0"}));
  register_command(&PHILIPS_HOME, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10054:20:0"}));
  register_command(&PHILIPS_OPTIONS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10040:20:0"}));
  register_command(&PHILIPS_GUIDE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x100CC:20:0"}));
  register_command(&PHILIPS_INPUT_TV, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1009F:20:0"}));
  register_command(&PHILIPS_SOURCES, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10038:20:0"}));
  register_command(&PHILIPS_REWIND, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1002B:20:0"}));
  register_command(&PHILIPS_PLAY, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x1002C:20:0"}));
  register_command(&PHILIPS_FASTFORWARD, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10028:20:0"}));
  register_command(&PHILIPS_STOP, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10031:20:0"}));
  register_command(&PHILIPS_PAUSE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0x10030:20:0"}));
  // Discrete inputs from LIRC LCD_TV_DISCRETE (RC5X). On this TV 0xF9 selects HDMI side and 0x10FB selects EXT; 0xC4, 0x39 and 0xF8 select HDMI 1, 2 and 3.
  register_command(&PHILIPS_INPUT_SIDE, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xF9"}));
  register_command(&PHILIPS_INPUT_EXT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x10FB"}));
  register_command(&PHILIPS_INPUT_HDMI_1, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xC4"}));
  register_command(&PHILIPS_INPUT_HDMI_2, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x39"}));
  register_command(&PHILIPS_INPUT_HDMI_3, makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0xF8"}));
}
