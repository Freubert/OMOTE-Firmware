#include <map>
#include "scenes/scene_filmLeinwand.h"
#include "scenes/scene_devicePower.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// devices
#include "devices/projector/device_epsonProjector/device_epsonProjector.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
#include "devices/mediaPlayer/device_kodi/device_kodi.h"
// guis
#include "devices/mediaPlayer/device_kodi/gui_kodi.h"
#include "devices/projector/device_epsonProjector/gui_epsonProjector.h"
#include "devices/AVreceiver/device_teufelSConcept/gui_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/gui_athenVS482.h"

uint16_t SCENE_FILMLEINWAND;
uint16_t SCENE_FILMLEINWAND_FORCE;
std::string scene_name_filmLeinwand = "Film Leinwand";

std::map<char, repeatModes> key_repeatModes_filmLeinwand;
std::map<char, uint16_t> key_commands_short_filmLeinwand;
std::map<char, uint16_t> key_commands_long_filmLeinwand;

// Only the audio keys are defined here (Teufel); everything else falls back to the active tab / defaults.
void scene_setKeys_filmLeinwand() {
  key_repeatModes_filmLeinwand = {
    {KEY_VOLUP, SHORT_REPEATED}, {KEY_VOLDO, SHORT_REPEATED}, {KEY_MUTE, SHORT},
  };
  key_commands_short_filmLeinwand = {
    {KEY_VOLUP, TEUFEL_VOL_PLUS}, {KEY_VOLDO, TEUFEL_VOL_MINUS}, {KEY_MUTE, TEUFEL_MUTE},
  };
  key_commands_long_filmLeinwand = {};
}

// Devices that were already on in the previous scene are not switched on again.
void scene_start_sequence_filmLeinwand(void) {
  uint8_t on = scene_devicesToPowerOn(scene_name_filmLeinwand);
  if (on & DEVICE_EPSON) {
    executeCommand(EPSON_POWER_ON);
    delay(500);
  }
  if (on & DEVICE_TEUFEL) {
    // the Teufel only has a toggle command
    executeCommand(TEUFEL_POWER);
    delay(500);
  }
  if (on & DEVICE_ATHEN) {
    executeCommand(ATHEN_POWER_ON);
    delay(500);
  }
  executeCommand(ATHEN_INPUT_HDMI_1);
  delay(500);
  executeCommand(TEUFEL_INPUT_OPT);
  if (on & DEVICE_EPSON) {
    // the projector ignores input commands until it has warmed up
    delay(10000);
  }
  executeCommand(EPSON_INPUT_HDMI1);
}

// Devices that the next scene needs as well stay on.
void scene_end_sequence_filmLeinwand(void) {
  uint8_t off = scene_devicesToPowerOff(scene_name_filmLeinwand);
  if (off & DEVICE_KODI) {
    // stop playback, open the shutdown menu and confirm its first entry
    executeCommand(KODI_STOP);
    delay(500);
    executeCommand(KODI_SHUTDOWN_MENU);
    delay(1000);
    executeCommand(KEYBOARD_SELECT);
    delay(500);
  }
  if (off & DEVICE_EPSON) {
    executeCommand(EPSON_POWER_OFF);
    delay(500);
  }
  if (off & DEVICE_ATHEN) {
    executeCommand(ATHEN_POWER_OFF);
    delay(500);
  }
  if (off & DEVICE_TEUFEL) {
    // toggle, so this switches the Teufel off only if it is currently on
    executeCommand(TEUFEL_POWER);
    delay(500);
  }
}

t_gui_list scene_filmLeinwand_gui_list = {tabName_kodi, tabName_epsonProjector, tabName_teufelSConcept, tabName_athenVS482};

void register_scene_filmLeinwand(void) {
  scene_setRequiredDevices(scene_name_filmLeinwand, DEVICE_EPSON | DEVICE_TEUFEL | DEVICE_ATHEN | DEVICE_KODI);
  register_command(&SCENE_FILMLEINWAND,       makeCommandData(SCENE, {scene_name_filmLeinwand}));
  register_command(&SCENE_FILMLEINWAND_FORCE, makeCommandData(SCENE, {scene_name_filmLeinwand, "FORCE"}));

  register_scene(
    scene_name_filmLeinwand,
    & scene_setKeys_filmLeinwand,
    & scene_start_sequence_filmLeinwand,
    & scene_end_sequence_filmLeinwand,
    & key_repeatModes_filmLeinwand,
    & key_commands_short_filmLeinwand,
    & key_commands_long_filmLeinwand,
    & scene_filmLeinwand_gui_list,
    SCENE_FILMLEINWAND);
}
