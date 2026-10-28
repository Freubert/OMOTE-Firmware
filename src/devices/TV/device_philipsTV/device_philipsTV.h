#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t PHILIPS_NUM_1;
extern uint16_t PHILIPS_NUM_2;
extern uint16_t PHILIPS_NUM_3;
extern uint16_t PHILIPS_NUM_4;
extern uint16_t PHILIPS_NUM_5;
extern uint16_t PHILIPS_NUM_6;
extern uint16_t PHILIPS_NUM_7;
extern uint16_t PHILIPS_NUM_8;
extern uint16_t PHILIPS_NUM_9;
extern uint16_t PHILIPS_NUM_0;
extern uint16_t PHILIPS_CHANNEL_UP;
extern uint16_t PHILIPS_CHANNEL_DOWN;
extern uint16_t PHILIPS_MENU;
extern uint16_t PHILIPS_GUIDE;
extern uint16_t PHILIPS_UP;
extern uint16_t PHILIPS_DOWN;
extern uint16_t PHILIPS_LEFT;
extern uint16_t PHILIPS_RIGHT;
extern uint16_t PHILIPS_SELECT;
extern uint16_t PHILIPS_EXIT;
extern uint16_t PHILIPS_REWIND;
extern uint16_t PHILIPS_PAUSE;
extern uint16_t PHILIPS_FASTFORWARD;
extern uint16_t PHILIPS_PLAY;
extern uint16_t PHILIPS_POWER_OFF;
extern uint16_t PHILIPS_POWER_ON;
extern uint16_t PHILIPS_INPUT_HDMI_1;
extern uint16_t PHILIPS_INPUT_HDMI_2;
extern uint16_t PHILIPS_INPUT_HDMI_3;
extern uint16_t PHILIPS_INPUT_TV;

void register_device_philipsTV();