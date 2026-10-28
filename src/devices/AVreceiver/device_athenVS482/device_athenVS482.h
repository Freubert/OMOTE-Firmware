#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t ATHEN_POWER_OFF;
extern uint16_t ATHEN_POWER_ON;
extern uint16_t ATHEN_POWER_TOGGLE;
extern uint16_t ATHEN_INPUT_HDMI_1;
extern uint16_t ATHEN_INPUT_HDMI_2;
extern uint16_t ATHEN_INPUT_HDMI_3;
extern uint16_t ATHEN_INPUT_HDMI_4;
extern uint16_t ATHEN_INPUT_HDMI_5;
extern uint16_t ATHEN_INPUT_HDMI_6;
extern uint16_t ATHEN_INPUT_HDMI_7;
extern uint16_t ATHEN_INPUT_HDMI_8;
extern uint16_t ATHEN_INPUT_COMPOSITE_1;
extern uint16_t ATHEN_INPUT_COMPOSITE_2;
extern uint16_t ATHEN_INPUT_SVIDEO_1;
extern uint16_t ATHEN_INPUT_SVIDEO_2;
extern uint16_t ATHEN_INPUT_VGA_1;
extern uint16_t ATHEN_INPUT_VGA_2;
extern uint16_t ATHEN_MENU;
extern uint16_t ATHEN_UP;
extern uint16_t ATHEN_DOWN;
extern uint16_t ATHEN_LEFT;
extern uint16_t ATHEN_RIGHT;
extern uint16_t ATHEN_SELECT;
extern uint16_t ATHEN_EXIT;

void register_device_athenVS482();