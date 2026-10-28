#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_athenVS482.h"

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
uint16_t ATHEN_POWER_OFF         ; //"Athen_power_off";
uint16_t ATHEN_POWER_ON          ; //"Athen_power_on";
uint16_t ATHEN_POWER_TOGGLE      ; //"Athen_power_toggle";
uint16_t ATHEN_INPUT_HDMI_1      ; //"Athen_input_hdmi_1";
uint16_t ATHEN_INPUT_HDMI_2      ; //"Athen_input_hdmi_2";
uint16_t ATHEN_INPUT_HDMI_3      ; //"Athen_input_hdmi_3";
uint16_t ATHEN_INPUT_HDMI_4      ; //"Athen_input_hdmi_4";
uint16_t ATHEN_INPUT_HDMI_5      ; //"Athen_input_hdmi_5";
uint16_t ATHEN_INPUT_HDMI_6      ; //"Athen_input_hdmi_6";
uint16_t ATHEN_INPUT_HDMI_7      ; //"Athen_input_hdmi_7";
uint16_t ATHEN_INPUT_HDMI_8      ; //"Athen_input_hdmi_8";
uint16_t ATHEN_INPUT_COMPOSITE_1 ; //"Athen_input_composite_1";
uint16_t ATHEN_INPUT_COMPOSITE_2 ; //"Athen_input_composite_2";
uint16_t ATHEN_INPUT_SVIDEO_1    ; //"Athen_input_svideo_1";
uint16_t ATHEN_INPUT_SVIDEO_2    ; //"Athen_input_svideo_2";
uint16_t ATHEN_INPUT_VGA_1       ; //"Athen_input_vga_1";
uint16_t ATHEN_INPUT_VGA_2       ; //"Athen_input_vga_2";
uint16_t ATHEN_MENU              ; //"Athen_menu";
uint16_t ATHEN_UP                ; //"Athen_up";
uint16_t ATHEN_DOWN              ; //"Athen_down";
uint16_t ATHEN_LEFT              ; //"Athen_left";
uint16_t ATHEN_RIGHT             ; //"Athen_right";
uint16_t ATHEN_SELECT            ; //"Athen_select";
uint16_t ATHEN_EXIT              ; //"Athen_exit";

void register_device_athenVS482() {
  // Athen VS482 HDMI switch IR codes (using NEC protocol)
  // These are typical NEC protocol codes that work with Athen HDMI switches
  register_command(&ATHEN_POWER_OFF         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E019E6"}));
  register_command(&ATHEN_POWER_ON          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E09966"}));
  register_command(&ATHEN_POWER_TOGGLE      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E059A6"}));
  register_command(&ATHEN_INPUT_HDMI_1      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E048B7"}));
  register_command(&ATHEN_INPUT_HDMI_2      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E008F7"}));
  register_command(&ATHEN_INPUT_HDMI_3      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08877"}));
  register_command(&ATHEN_INPUT_HDMI_4      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E028D7"}));
  register_command(&ATHEN_INPUT_HDMI_5      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A857"}));
  register_command(&ATHEN_INPUT_HDMI_6      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E06897"}));
  register_command(&ATHEN_INPUT_HDMI_7      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0E817"}));
  register_command(&ATHEN_INPUT_HDMI_8      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0C837"}));
  register_command(&ATHEN_INPUT_COMPOSITE_1 , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E038C7"}));
  register_command(&ATHEN_INPUT_COMPOSITE_2 , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E07887"}));
  register_command(&ATHEN_INPUT_SVIDEO_1    , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B847"}));
  register_command(&ATHEN_INPUT_SVIDEO_2    , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0F807"}));
  register_command(&ATHEN_INPUT_VGA_1       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E018E7"}));
  register_command(&ATHEN_INPUT_VGA_2       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E058A7"}));
  register_command(&ATHEN_MENU              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0D02F"}));
  register_command(&ATHEN_UP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E006F9"}));
  register_command(&ATHEN_DOWN              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E08679"}));
  register_command(&ATHEN_LEFT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0A659"}));
  register_command(&ATHEN_RIGHT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E046B9"}));
  register_command(&ATHEN_SELECT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E016E9"}));
  register_command(&ATHEN_EXIT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0xE0E0B44B"}));
}