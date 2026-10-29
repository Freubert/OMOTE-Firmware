#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_teufelSConcept.h"

uint16_t TEUFEL_POWER;
uint16_t TEUFEL_VOL_PLUS;
uint16_t TEUFEL_VOL_MINUS;
uint16_t TEUFEL_INPUT_VCR;
uint16_t TEUFEL_INPUT_OPT;
uint16_t TEUFEL_INPUT_AUX;
uint16_t TEUFEL_INPUT_COAX;
uint16_t TEUFEL_CENTER_PLUS;
uint16_t TEUFEL_CENTER_MINUS;
uint16_t TEUFEL_BALANCE_LEFT;
uint16_t TEUFEL_BALANCE_RIGHT;
uint16_t TEUFEL_BALANCE_CENTER;
uint16_t TEUFEL_BASS_PLUS;
uint16_t TEUFEL_TREBLE_PLUS;
uint16_t TEUFEL_SUB_PLUS;
uint16_t TEUFEL_SUB_MINUS;
uint16_t TEUFEL_TRY[TEUFEL_TRY_COUNT];

const char* const TEUFEL_TRY_LABELS[TEUFEL_TRY_COUNT] = {"Try 3", "Try 4", "Try 8", "Try 9", "Try 11", "Try Ch+", "Try Ch-"};
static const char* const tryCodes[TEUFEL_TRY_COUNT] = {"0x04FBF20D", "0x04FB708F", "0x04FBB04F", "0x04FB32CD", "0x04FBD22D", "0x04FB48B7", "0x04FB6897"};

void register_device_teufelSConcept() {
  for (int i = 0; i < TEUFEL_TRY_COUNT; i++) {
    register_command(&TEUFEL_TRY[i], makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), tryCodes[i]}));
  }
  register_command(&TEUFEL_POWER, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB50AF"}));
  register_command(&TEUFEL_VOL_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBAA55"}));
  register_command(&TEUFEL_VOL_MINUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB18E7"}));
  register_command(&TEUFEL_INPUT_VCR, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB728D"}));
  register_command(&TEUFEL_INPUT_OPT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB12ED"}));
  register_command(&TEUFEL_INPUT_AUX, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBF00F"}));
  register_command(&TEUFEL_INPUT_COAX, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB52AD"}));
  register_command(&TEUFEL_CENTER_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB08F7"}));
  register_command(&TEUFEL_CENTER_MINUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB8877"}));
  register_command(&TEUFEL_BALANCE_LEFT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBA857"}));
  register_command(&TEUFEL_BALANCE_RIGHT, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB9A65"}));
  register_command(&TEUFEL_BALANCE_CENTER, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB28D7"}));
  register_command(&TEUFEL_BASS_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBA05F"}));
  register_command(&TEUFEL_TREBLE_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBEA15"}));
  register_command(&TEUFEL_SUB_PLUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FBCA35"}));
  register_command(&TEUFEL_SUB_MINUS, makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x04FB8A75"}));
}
