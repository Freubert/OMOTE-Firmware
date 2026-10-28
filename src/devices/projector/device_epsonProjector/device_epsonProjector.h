#pragma once

// EPSON EB-680W IR codes (using NEC protocol)
extern uint16_t EPSON_POWER_ON;
extern uint16_t EPSON_POWER_OFF;
extern uint16_t EPSON_POWER_TOGGLE;
extern uint16_t EPSON_VOL_UP;
extern uint16_t EPSON_VOL_DOWN;
extern uint16_t EPSON_MUTE;
extern uint16_t EPSON_MENU;
extern uint16_t EPSON_HOME;
extern uint16_t EPSON_UP;
extern uint16_t EPSON_DOWN;
extern uint16_t EPSON_LEFT;
extern uint16_t EPSON_RIGHT;
extern uint16_t EPSON_SELECT;
extern uint16_t EPSON_EXIT;
extern uint16_t EPSON_SOURCE;
extern uint16_t EPSON_INPUT_HDMI1;
extern uint16_t EPSON_INPUT_HDMI2;
extern uint16_t EPSON_INPUT_VGA;
extern uint16_t EPSON_INPUT_COMPOSITE;
extern uint16_t EPSON_INPUT_SVIDEO;

void register_device_epsonProjector();