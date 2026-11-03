#include <map>
#include "scenes/scene_filmFernseher.h"
#include "scenes/scene_devicePower.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// devices
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
#include "devices/mediaPlayer/device_kodi/device_kodi.h"
// guis
#include "devices/mediaPlayer/device_kodi/gui_kodi.h"
#include "devices/TV/device_philipsTV/gui_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/gui_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/gui_athenVS482.h"

uint16_t SCENE_FILMFERNSEHER;
uint16_t SCENE_FILMFERNSEHER_FORCE;
std::string scene_name_filmFernseher = "Film Fernseher";

std::map<char, repeatModes> key_repeatModes_filmFernseher;
std::map<char, uint16_t> key_commands_short_filmFernseher;
std::map<char, uint16_t> key_commands_long_filmFernseher;

// Only the audio keys are defined here (Teufel); everything else falls back to the active tab / defaults.
void scene_setKeys_filmFernseher() {
  key_repeatModes_filmFernseher = {
    {KEY_VOLUP, SHORT_REPEATED}, {KEY_VOLDO, SHORT_REPEATED}, {KEY_MUTE, SHORT},
  };
  key_commands_short_filmFernseher = {
    {KEY_VOLUP, TEUFEL_VOL_PLUS}, {KEY_VOLDO, TEUFEL_VOL_MINUS}, {KEY_MUTE, TEUFEL_MUTE},
  };
  key_commands_long_filmFernseher = {};
}

// Devices that were already on in the previous scene are not switched on again.
void scene_start_sequence_filmFernseher(void) {
  uint8_t on = scene_devicesToPowerOn(scene_name_filmFernseher);
  if (on & DEVICE_TV) {
    executeCommand(PHILIPS_POWER_ON);
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
  if (on & DEVICE_TV) {
    // the TV ignores IR commands until it has booted
    delay(12000);
  }
  executeCommand(PHILIPS_INPUT_HDMI_1);
}

// Devices that the next scene needs as well stay on.
void scene_end_sequence_filmFernseher(void) {
  uint8_t off = scene_devicesToPowerOff(scene_name_filmFernseher);
  if (off & DEVICE_KODI) {
    // stop playback, open the shutdown menu and confirm its first entry
    executeCommand(KODI_STOP);
    delay(500);
    executeCommand(KODI_SHUTDOWN_MENU);
    delay(1000);
    executeCommand(KEYBOARD_SELECT);
    delay(500);
  }
  if (off & DEVICE_TV) {
    executeCommand(PHILIPS_POWER_OFF);
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

t_gui_list scene_filmFernseher_gui_list = {tabName_kodi, tabName_philipsTV, tabName_teufelSConcept, tabName_athenVS482};

void register_scene_filmFernseher(void) {
  scene_setRequiredDevices(scene_name_filmFernseher, DEVICE_TV | DEVICE_TEUFEL | DEVICE_ATHEN | DEVICE_KODI);
  register_command(&SCENE_FILMFERNSEHER,       makeCommandData(SCENE, {scene_name_filmFernseher}));
  register_command(&SCENE_FILMFERNSEHER_FORCE, makeCommandData(SCENE, {scene_name_filmFernseher, "FORCE"}));

  register_scene(
    scene_name_filmFernseher,
    & scene_setKeys_filmFernseher,
    & scene_start_sequence_filmFernseher,
    & scene_end_sequence_filmFernseher,
    & key_repeatModes_filmFernseher,
    & key_commands_short_filmFernseher,
    & key_commands_long_filmFernseher,
    & scene_filmFernseher_gui_list,
    SCENE_FILMFERNSEHER);
}
