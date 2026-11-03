#include <map>
#include "scenes/scene_fernsehen.h"
#include "scenes/scene_devicePower.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// devices
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
// guis
#include "devices/TV/device_philipsTV/gui_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/gui_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/gui_athenVS482.h"

uint16_t SCENE_FERNSEHEN;
uint16_t SCENE_FERNSEHEN_FORCE;
std::string scene_name_fernsehen = "Fernsehen";

std::map<char, repeatModes> key_repeatModes_fernsehen;
std::map<char, uint16_t> key_commands_short_fernsehen;
std::map<char, uint16_t> key_commands_long_fernsehen;

// All keys control the TV, only the audio keys (volume, mute) control the Teufel amplifier.
// Colour keys: short press is not defined here, so the default tab navigation applies; long press sends the TV colour command.
void scene_setKeys_fernsehen() {
  key_repeatModes_fernsehen = {
    {KEY_STOP,  SHORTorLONG   }, {KEY_REWI,  SHORT         }, {KEY_PLAY,  SHORTorLONG   }, {KEY_FORW,  SHORT         },
    {KEY_BACK,  SHORTorLONG   }, {KEY_REC,   SHORT         }, {KEY_CONF,  SHORT         }, {KEY_INFO,  SHORTorLONG   },
    {KEY_UP,    SHORT_REPEATED}, {KEY_DOWN,  SHORT_REPEATED}, {KEY_LEFT,  SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED},
    {KEY_OK,    SHORT         }, {KEY_SRC,   SHORT         },
    {KEY_VOLUP, SHORT_REPEATED}, {KEY_VOLDO, SHORT_REPEATED}, {KEY_MUTE,  SHORT         },
    {KEY_CHUP,  SHORT         }, {KEY_CHDOW, SHORT         },
    {KEY_RED,   SHORTorLONG   }, {KEY_GREEN, SHORTorLONG   }, {KEY_YELLO, SHORTorLONG   }, {KEY_BLUE,  SHORTorLONG   },
  };

  key_commands_short_fernsehen = {
    {KEY_STOP,  PHILIPS_STOP    }, {KEY_REWI,  PHILIPS_REWIND}, {KEY_PLAY,  PHILIPS_PAUSE }, {KEY_FORW,  PHILIPS_FASTFORWARD},
    {KEY_BACK,  PHILIPS_BACK    }, {KEY_REC,   PHILIPS_HOME  }, {KEY_CONF,  PHILIPS_GUIDE }, {KEY_INFO,  PHILIPS_TEXT},
    {KEY_UP,    PHILIPS_UP      }, {KEY_DOWN,  PHILIPS_DOWN  }, {KEY_LEFT,  PHILIPS_LEFT  }, {KEY_RIGHT, PHILIPS_RIGHT},
    {KEY_OK,    PHILIPS_SELECT  }, {KEY_SRC,   PHILIPS_SOURCES},
    {KEY_VOLUP, TEUFEL_VOL_PLUS }, {KEY_VOLDO, TEUFEL_VOL_MINUS}, {KEY_MUTE,  TEUFEL_MUTE  },
    {KEY_CHUP,  PHILIPS_CHANNEL_UP}, {KEY_CHDOW, PHILIPS_CHANNEL_DOWN},
  };

  key_commands_long_fernsehen = {
    {KEY_RED,   PHILIPS_RED }, {KEY_GREEN, PHILIPS_GREEN}, {KEY_YELLO, PHILIPS_YELLOW}, {KEY_BLUE, PHILIPS_BLUE},
    {KEY_STOP,  PHILIPS_POWER_TOGGLE},
    {KEY_INFO,  PHILIPS_INFO}, {KEY_PLAY, PHILIPS_PLAY},
  };
}

// Devices that were already on in the previous scene are not switched on again.
void scene_start_sequence_fernsehen(void) {
  uint8_t on = scene_devicesToPowerOn(scene_name_fernsehen);
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
  executeCommand(ATHEN_ARC);
  delay(500);
  executeCommand(TEUFEL_INPUT_OPT);
  if (on & DEVICE_TV) {
    // the TV ignores IR commands until it has booted
    delay(12000);
  }
  executeCommand(PHILIPS_INPUT_TV);
}

// Devices that the next scene needs as well stay on.
void scene_end_sequence_fernsehen(void) {
  uint8_t off = scene_devicesToPowerOff(scene_name_fernsehen);
  executeCommand(ATHEN_ARC);
  delay(500);
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

t_gui_list scene_fernsehen_gui_list = {tabName_philipsTV, tabName_teufelSConcept, tabName_athenVS482};

void register_scene_fernsehen(void) {
  scene_setRequiredDevices(scene_name_fernsehen, DEVICE_TV | DEVICE_TEUFEL | DEVICE_ATHEN);
  register_command(&SCENE_FERNSEHEN,       makeCommandData(SCENE, {scene_name_fernsehen}));
  register_command(&SCENE_FERNSEHEN_FORCE, makeCommandData(SCENE, {scene_name_fernsehen, "FORCE"}));

  register_scene(
    scene_name_fernsehen,
    & scene_setKeys_fernsehen,
    & scene_start_sequence_fernsehen,
    & scene_end_sequence_fernsehen,
    & key_repeatModes_fernsehen,
    & key_commands_short_fernsehen,
    & key_commands_long_fernsehen,
    & scene_fernsehen_gui_list,
    SCENE_FERNSEHEN);
}
