#include <map>
#include "scenes/scene_sequence.h"
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
#include "scenes/gui_sceneActions.h"

uint16_t SCENE_FILMFERNSEHER;
uint16_t SCENE_FILMFERNSEHER_FORCE;
std::string scene_name_filmFernseher = "Film Fernseher";

std::map<char, repeatModes> key_repeatModes_filmFernseher;
std::map<char, uint16_t> key_commands_short_filmFernseher;
std::map<char, uint16_t> key_commands_long_filmFernseher;

// All keys control Kodi, only the audio keys (volume, mute) control the Teufel amplifier.
// Colour keys: short press is not defined here, so the default tab navigation applies; long press controls Kodi.
void scene_setKeys_filmFernseher() {
  key_repeatModes_filmFernseher = {
    {KEY_STOP,  SHORTorLONG   }, {KEY_REWI,  SHORTorLONG   }, {KEY_PLAY,  SHORT         }, {KEY_FORW,  SHORTorLONG   },
    {KEY_CONF,  SHORT         }, {KEY_INFO,  SHORT         }, {KEY_BACK,  SHORTorLONG   }, {KEY_SRC,   SHORT         }, {KEY_REC, SHORT},
    {KEY_UP,    SHORT_REPEATED}, {KEY_DOWN,  SHORT_REPEATED}, {KEY_LEFT,  SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT},
    {KEY_VOLUP, SHORT_REPEATED}, {KEY_VOLDO, SHORT_REPEATED}, {KEY_MUTE,  SHORT         },
    {KEY_CHUP,  SHORTorLONG   }, {KEY_CHDOW, SHORTorLONG   },
    {KEY_RED,   SHORTorLONG   }, {KEY_GREEN, SHORTorLONG   }, {KEY_YELLO, SHORTorLONG   }, {KEY_BLUE,  SHORTorLONG   },
  };
  key_commands_short_filmFernseher = {
    {KEY_STOP, KODI_STOP}, {KEY_REWI, KODI_REWIND}, {KEY_PLAY, KEYBOARD_PLAYPAUSE}, {KEY_FORW, KODI_FASTFORWARD},
    {KEY_CONF, KODI_CONTEXT}, {KEY_INFO, KODI_INFO}, {KEY_BACK, KODI_ESCAPE}, {KEY_SRC, KODI_OSD},
    {KEY_UP, KEYBOARD_UP}, {KEY_LEFT, KEYBOARD_LEFT}, {KEY_RIGHT, KEYBOARD_RIGHT}, {KEY_DOWN, KEYBOARD_DOWN}, {KEY_OK, KEYBOARD_SELECT},
    {KEY_REC, KEYBOARD_HOME},
    {KEY_CHUP, KEYBOARD_SCAN_NEXT_TRACK}, {KEY_CHDOW, KEYBOARD_SCAN_PREVIOUS_TRACK},
    {KEY_VOLUP, TEUFEL_VOL_PLUS}, {KEY_VOLDO, TEUFEL_VOL_MINUS}, {KEY_MUTE, TEUFEL_MUTE},
  };
  key_commands_long_filmFernseher = {
    {KEY_STOP, KODI_SHUTDOWN_MENU}, {KEY_REWI, KODI_SKIP_BACK}, {KEY_FORW, KODI_SKIP_FORWARD},
    {KEY_BACK, KODI_BACK},
    {KEY_CHUP, KODI_PAGE_UP}, {KEY_CHDOW, KODI_PAGE_DOWN},
    {KEY_RED, KODI_SUBTITLES}, {KEY_GREEN, KODI_SUBTITLE_NEXT}, {KEY_YELLO, KODI_AUDIO_DELAY}, {KEY_BLUE, KODI_FULLSCREEN},
  };
}

// Devices that were already on in the previous scene are not switched on again.
void scene_start_sequence_filmFernseher(void) {
  uint8_t on = scene_devicesToPowerOn(scene_name_filmFernseher);
  if (on & DEVICE_TV) {
    sequence_add(PHILIPS_POWER_ON, 500);
  }
  if (on & DEVICE_TEUFEL) {
    // the Teufel only has a toggle command
    sequence_add(TEUFEL_POWER, 500);
  }
  if (on & DEVICE_ATHEN) {
    sequence_add(ATHEN_POWER_ON, 500);
  }
  sequence_add(ATHEN_INPUT_HDMI_1, 500);
  sequence_add(TEUFEL_INPUT_OPT);
  if (on & DEVICE_TV) {
    // the TV ignores IR commands until it has booted
    sequence_wait(20000);
  }
  sequence_add(PHILIPS_INPUT_HDMI_1);
}

// Devices that the next scene needs as well stay on.
void scene_end_sequence_filmFernseher(void) {
  uint8_t off = scene_devicesToPowerOff(scene_name_filmFernseher);
  if (off & DEVICE_TV) {
    sequence_add(PHILIPS_POWER_OFF, 500);
  }
  if (off & DEVICE_TEUFEL) {
    // toggle, so this switches the Teufel off only if it is currently on
    sequence_add(TEUFEL_POWER, 500);
  }
  if (off & DEVICE_ATHEN) {
    // the Athen does not react while the TV / projector is shutting down (HDMI handshake), so it goes last after a pause
    sequence_wait(5000);
    sequence_add(ATHEN_POWER_OFF, 500);
  }
  // late, because the BLE connection can take long and must not delay the IR commands (also of the next scene)
  if (off & DEVICE_KODI) {
    // stop playback, open the shutdown menu and confirm its first entry
    sequence_addBle(KODI_STOP, 500);
    sequence_addBle(KODI_SHUTDOWN_MENU, 1000);
    sequence_addBle(KEYBOARD_SELECT, 500);
  }
}

t_gui_list scene_filmFernseher_gui_list = {tabName_sceneActions, tabName_kodi, tabName_philipsTV, tabName_teufelSConcept, tabName_athenVS482};

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
