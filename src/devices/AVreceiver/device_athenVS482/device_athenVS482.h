#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t ATHEN_POWER_ON;
extern uint16_t ATHEN_POWER_OFF;
extern uint16_t ATHEN_INPUT_HDMI_1;
extern uint16_t ATHEN_INPUT_HDMI_2;
extern uint16_t ATHEN_INPUT_HDMI_3;
extern uint16_t ATHEN_INPUT_HDMI_4;
extern uint16_t ATHEN_SETUP;
extern uint16_t ATHEN_MENU;
extern uint16_t ATHEN_INFO;
extern uint16_t ATHEN_ARC;
extern uint16_t ATHEN_HDMI_MUTE;
extern uint16_t ATHEN_UP;
extern uint16_t ATHEN_DOWN;
extern uint16_t ATHEN_LEFT;
extern uint16_t ATHEN_RIGHT;

void register_device_athenVS482();