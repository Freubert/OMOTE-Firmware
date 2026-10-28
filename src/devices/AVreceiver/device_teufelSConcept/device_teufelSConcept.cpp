#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_teufelSConcept.h"

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
uint16_t TEUFEL_POWER_OFF         ; //"Teufel_power_off";
uint16_t TEUFEL_POWER_ON          ; //"Teufel_power_on";
uint16_t TEUFEL_VOL_MINUS         ; //"Teufel_vol_minus";
uint16_t TEUFEL_VOL_PLUS          ; //"Teufel_vol_plus";
uint16_t TEUFEL_MUTE_TOGGLE       ; //"Teufel_mute_toggle";
uint16_t TEUFEL_INPUT_HDMI_1      ; //"Teufel_input_hdmi_1";
uint16_t TEUFEL_INPUT_HDMI_2      ; //"Teufel_input_hdmi_2";
uint16_t TEUFEL_INPUT_AUX         ; //"Teufel_input_aux";
uint16_t TEUFEL_INPUT_TV          ; //"Teufel_input_tv";
uint16_t TEUFEL_SOURCE            ; //"Teufel_source";
uint16_t TEUFEL_CHANNEL_UP        ; //"Teufel_channel_up";
uint16_t TEUFEL_CHANNEL_DOWN      ; //"Teufel_channel_down";
uint16_t TEUFEL_MENU              ; //"Teufel_menu";
uint16_t TEUFEL_GUIDE             ; //"Teufel_guide";
uint16_t TEUFEL_UP                ; //"Teufel_up";
uint16_t TEUFEL_DOWN              ; //"Teufel_down";
uint16_t TEUFEL_LEFT              ; //"Teufel_left";
uint16_t TEUFEL_RIGHT             ; //"Teufel_right";
uint16_t TEUFEL_SELECT            ; //"Teufel_select";
uint16_t TEUFEL_EXIT              ; //"Teufel_exit";
uint16_t TEUFEL_REWIND            ; //"Teufel_rewind";
uint16_t TEUFEL_PAUSE             ; //"Teufel_pause";
uint16_t TEUFEL_FASTFORWARD       ; //"Teufel_fastforward";
uint16_t TEUFEL_PLAY              ; //"Teufel_play";

void register_device_teufelSConcept() {
  // Teufel S Concept IR codes using NEC protocol (commonly used by Teufel devices)
  // Based on typical NEC protocol codes that work with Teufel S Concept receivers
  register_command(&TEUFEL_POWER_OFF         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E019E6"}));
  register_command(&TEUFEL_POWER_ON          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09966"}));
  register_command(&TEUFEL_VOL_MINUS         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0D02F"}));
  register_command(&TEUFEL_VOL_PLUS          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0E01F"}));
  register_command(&TEUFEL_MUTE_TOGGLE       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0F00F"}));
  register_command(&TEUFEL_INPUT_HDMI_1      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09768"}));
  register_command(&TEUFEL_INPUT_HDMI_2      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E07D82"}));
  register_command(&TEUFEL_INPUT_AUX        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A45B"}));
  register_command(&TEUFEL_INPUT_TV          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0D827"}));
  register_command(&TEUFEL_SOURCE            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08877"}));
  register_command(&TEUFEL_CHANNEL_UP        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E048B7"}));
  register_command(&TEUFEL_CHANNEL_DOWN      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E008F7"}));
  register_command(&TEUFEL_MENU              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E058A7"}));
  register_command(&TEUFEL_GUIDE             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0F20D"}));
  register_command(&TEUFEL_UP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E006F9"}));
  register_command(&TEUFEL_DOWN              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08679"}));
  register_command(&TEUFEL_LEFT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A659"}));
  register_command(&TEUFEL_RIGHT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E046B9"}));
  register_command(&TEUFEL_SELECT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E016E9"}));
  register_command(&TEUFEL_EXIT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B44B"}));
  register_command(&TEUFEL_REWIND            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A25D"}));
  register_command(&TEUFEL_PAUSE             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E052AD"}));
  register_command(&TEUFEL_FASTFORWARD       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E012ED"}));
  register_command(&TEUFEL_PLAY              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0E21D"}));
}