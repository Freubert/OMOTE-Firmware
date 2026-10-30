#include <map>
#include "scenes/scene_directDeviceControl.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
#include "devices/projector/device_epsonProjector/device_epsonProjector.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_DIRECT_DEVICE_CONTROL;
uint16_t SCENE_DIRECT_DEVICE_CONTROL_FORCE;

std::map<char, repeatModes> key_repeatModes_directDeviceControl;
std::map<char, uint16_t> key_commands_short_directDeviceControl;
std::map<char, uint16_t> key_commands_long_directDeviceControl;

std::string scene_name_directDeviceControl = "directDeviceControl";
t_gui_list scene_directDeviceControl_gui_list = {tabName_numpad};

void scene_setKeys_directDeviceControl() {
  key_repeatModes_directDeviceControl = {
    {KEY_STOP,  SHORT            },    {KEY_REWI,  SHORT            },    {KEY_PLAY,  SHORTorLONG      },    {KEY_FORW,  SHORT            },
    {KEY_BACK,  SHORTorLONG      },    {KEY_REC,   SHORT            },    {KEY_CONF,  SHORTorLONG      },                                                                          {KEY_INFO,  SHORTorLONG      },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                      {KEY_CHDOW, SHORT            },
                                                                                                             {KEY_OFF,   SHORT            },
  };

  key_commands_short_directDeviceControl = {
    {KEY_STOP,  PHILIPS_STOP     },    {KEY_REWI,  PHILIPS_REWIND   },    {KEY_PLAY,  PHILIPS_PAUSE    },    {KEY_FORW,  PHILIPS_FASTFORWARD},
    {KEY_BACK,  PHILIPS_BACK    },    {KEY_REC,   PHILIPS_HOME     },    {KEY_CONF,  PHILIPS_GUIDE    },                                                                          {KEY_INFO,  PHILIPS_TEXT     },
                                                         {KEY_UP,    PHILIPS_UP       },
                      {KEY_LEFT,  PHILIPS_LEFT    },     {KEY_OK,    PHILIPS_SELECT   },    {KEY_RIGHT, PHILIPS_RIGHT    },
                                                         {KEY_DOWN,  PHILIPS_DOWN     },
                                                                                                             {KEY_SRC,   PHILIPS_SOURCES  },
    {KEY_VOLUP, PHILIPS_VOL_UP   },                      {KEY_MUTE,  PHILIPS_MUTE     },                     {KEY_CHUP,  PHILIPS_CHANNEL_UP},
    {KEY_VOLDO, PHILIPS_VOL_DOWN },                      {KEY_CHDOW, PHILIPS_CHANNEL_DOWN},
                                                                                                             {KEY_OFF,   PHILIPS_POWER_TOGGLE},
  };

  key_commands_long_directDeviceControl = {
    {KEY_INFO,  PHILIPS_INFO     },    {KEY_PLAY,  PHILIPS_PLAY     },    {KEY_CONF,  PHILIPS_POWER_TOGGLE },
  };
}

void scene_start_sequence_directDeviceControl(void) {
  // No specific start sequence needed for direct control
}

void scene_end_sequence_directDeviceControl(void) {
  // No specific end sequence needed for direct control
}

void register_scene_directDeviceControl(void) {
  register_command(&SCENE_DIRECT_DEVICE_CONTROL, makeCommandData(SCENE, {scene_name_directDeviceControl}));
  register_command(&SCENE_DIRECT_DEVICE_CONTROL_FORCE, makeCommandData(SCENE, {scene_name_directDeviceControl, "FORCE"}));

  register_scene(
    scene_name_directDeviceControl,
    &scene_setKeys_directDeviceControl,
    &scene_start_sequence_directDeviceControl,
    &scene_end_sequence_directDeviceControl,
    &key_repeatModes_directDeviceControl,
    &key_commands_short_directDeviceControl,
    &key_commands_long_directDeviceControl,
    &scene_directDeviceControl_gui_list,
    SCENE_DIRECT_DEVICE_CONTROL);
}
