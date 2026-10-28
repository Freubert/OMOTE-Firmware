#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t TEUFEL_POWER_OFF;
extern uint16_t TEUFEL_POWER_ON;
extern uint16_t TEUFEL_VOL_MINUS;
extern uint16_t TEUFEL_VOL_PLUS;
extern uint16_t TEUFEL_MUTE_TOGGLE;
extern uint16_t TEUFEL_INPUT_HDMI_1;
extern uint16_t TEUFEL_INPUT_HDMI_2;
extern uint16_t TEUFEL_INPUT_AUX;
extern uint16_t TEUFEL_INPUT_TV;
extern uint16_t TEUFEL_SOURCE;
extern uint16_t TEUFEL_CHANNEL_UP;
extern uint16_t TEUFEL_CHANNEL_DOWN;
extern uint16_t TEUFEL_MENU;
extern uint16_t TEUFEL_GUIDE;
extern uint16_t TEUFEL_UP;
extern uint16_t TEUFEL_DOWN;
extern uint16_t TEUFEL_LEFT;
extern uint16_t TEUFEL_RIGHT;
extern uint16_t TEUFEL_SELECT;
extern uint16_t TEUFEL_EXIT;
extern uint16_t TEUFEL_REWIND;
extern uint16_t TEUFEL_PAUSE;
extern uint16_t TEUFEL_FASTFORWARD;
extern uint16_t TEUFEL_PLAY;

void register_device_teufelSConcept();

// Unlabeled codes from the Harmony config, to find out by trial what they do (power, inputs, menu, exit).
#define TEUFEL_TRY_COUNT 11
extern uint16_t TEUFEL_TRY[TEUFEL_TRY_COUNT];
