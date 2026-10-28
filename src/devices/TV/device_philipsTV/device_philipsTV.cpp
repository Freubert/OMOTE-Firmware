#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_philipsTV.h"

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
uint16_t PHILIPS_NUM_1           ; //"Philips_num_1";
uint16_t PHILIPS_NUM_2           ; //"Philips_num_2";
uint16_t PHILIPS_NUM_3           ; //"Philips_num_3";
uint16_t PHILIPS_NUM_4           ; //"Philips_num_4";
uint16_t PHILIPS_NUM_5           ; //"Philips_num_5";
uint16_t PHILIPS_NUM_6           ; //"Philips_num_6";
uint16_t PHILIPS_NUM_7           ; //"Philips_num_7";
uint16_t PHILIPS_NUM_8           ; //"Philips_num_8";
uint16_t PHILIPS_NUM_9           ; //"Philips_num_9";
uint16_t PHILIPS_NUM_0           ; //"Philips_num_0";
uint16_t PHILIPS_CHANNEL_UP      ; //"Philips_channel_up";
uint16_t PHILIPS_CHANNEL_DOWN    ; //"Philips_channel_down";
uint16_t PHILIPS_MENU            ; //"Philips_menu";
uint16_t PHILIPS_GUIDE           ; //"Philips_guide";
uint16_t PHILIPS_UP              ; //"Philips_up";
uint16_t PHILIPS_DOWN            ; //"Philips_down";
uint16_t PHILIPS_LEFT            ; //"Philips_left";
uint16_t PHILIPS_RIGHT           ; //"Philips_right";
uint16_t PHILIPS_SELECT          ; //"Philips_select";
uint16_t PHILIPS_EXIT            ; //"Philips_exit";
uint16_t PHILIPS_REWIND          ; //"Philips_rewind";
uint16_t PHILIPS_PAUSE           ; //"Philips_pause";
uint16_t PHILIPS_FASTFORWARD     ; //"Philips_fastforward";
uint16_t PHILIPS_PLAY            ; //"Philips_play";
uint16_t PHILIPS_POWER_OFF       ; //"Philips_power_off";
uint16_t PHILIPS_POWER_ON        ; //"Philips_power_on";
uint16_t PHILIPS_INPUT_HDMI_1    ; //"Philips_input_hdmi_1";
uint16_t PHILIPS_INPUT_HDMI_2    ; //"Philips_input_hdmi_2";
uint16_t PHILIPS_INPUT_HDMI_3    ; //"Philips_input_hdmi_3";
uint16_t PHILIPS_INPUT_TV        ; //"Philips_input_tv";

void register_device_philipsTV() {
  // Philips TV IR codes (using NEC protocol, common for many Philips TVs)
  // Based on typical NEC protocol codes for Philips TVs
  register_command(&PHILIPS_NUM_1             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E040BF"}));
  register_command(&PHILIPS_NUM_2             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A05F"}));
  register_command(&PHILIPS_NUM_3             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0609F"}));
  register_command(&PHILIPS_NUM_4             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E010EF"}));
  register_command(&PHILIPS_NUM_5             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0906F"}));
  register_command(&PHILIPS_NUM_6             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E050AF"}));
  register_command(&PHILIPS_NUM_7             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E030CF"}));
  register_command(&PHILIPS_NUM_8             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B04F"}));
  register_command(&PHILIPS_NUM_9             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0708F"}));
  register_command(&PHILIPS_NUM_0             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08877"}));
  register_command(&PHILIPS_CHANNEL_UP        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E048B7"}));
  register_command(&PHILIPS_CHANNEL_DOWN      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E008F7"}));
  register_command(&PHILIPS_MENU              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E058A7"}));
  register_command(&PHILIPS_GUIDE             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0F20D"}));
  register_command(&PHILIPS_UP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E006F9"}));
  register_command(&PHILIPS_DOWN              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08679"}));
  register_command(&PHILIPS_LEFT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A659"}));
  register_command(&PHILIPS_RIGHT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E046B9"}));
  register_command(&PHILIPS_SELECT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E016E9"}));
  register_command(&PHILIPS_EXIT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B44B"}));
  register_command(&PHILIPS_REWIND            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A25D"}));
  register_command(&PHILIPS_PAUSE             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E052AD"}));
  register_command(&PHILIPS_FASTFORWARD       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E012ED"}));
  register_command(&PHILIPS_PLAY              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0E21D"}));
  register_command(&PHILIPS_POWER_OFF         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E019E6"}));
  register_command(&PHILIPS_POWER_ON          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09966"}));
  register_command(&PHILIPS_INPUT_HDMI_1      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09768"}));
  register_command(&PHILIPS_INPUT_HDMI_2      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E07D82"}));
  register_command(&PHILIPS_INPUT_HDMI_3      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E043BC"}));
  register_command(&PHILIPS_INPUT_TV          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0D827"}));
}