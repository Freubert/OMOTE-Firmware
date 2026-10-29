#pragma once

// Codes from the user's Harmony config (NEC, address 0x20), functions identified by the user by trial.
extern uint16_t TEUFEL_POWER;
extern uint16_t TEUFEL_VOL_PLUS;
extern uint16_t TEUFEL_VOL_MINUS;
extern uint16_t TEUFEL_INPUT_VCR;
extern uint16_t TEUFEL_INPUT_OPT;
extern uint16_t TEUFEL_INPUT_AUX;
extern uint16_t TEUFEL_INPUT_COAX;
extern uint16_t TEUFEL_CENTER_PLUS;
extern uint16_t TEUFEL_CENTER_MINUS;
extern uint16_t TEUFEL_BALANCE_LEFT;
extern uint16_t TEUFEL_BALANCE_RIGHT;
extern uint16_t TEUFEL_BALANCE_CENTER;
extern uint16_t TEUFEL_BASS_PLUS;
extern uint16_t TEUFEL_TREBLE_PLUS;
extern uint16_t TEUFEL_SUB_PLUS;
extern uint16_t TEUFEL_SUB_MINUS;

void register_device_teufelSConcept();

// Remaining unidentified codes from the Harmony config, to find out by trial.
#define TEUFEL_TRY_COUNT 7
extern uint16_t TEUFEL_TRY[TEUFEL_TRY_COUNT];
extern const char* const TEUFEL_TRY_LABELS[TEUFEL_TRY_COUNT];
