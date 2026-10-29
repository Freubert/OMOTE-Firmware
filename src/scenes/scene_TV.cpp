#include <map>
#include "scenes/scene_TV.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_TV         ; //"Scene_tv"
uint16_t SCENE_TV_FORCE   ; //"Scene_tv_force"

std::map<char, repeatModes> key_repeatModes_TV;
std::map<char, uint16_t> key_commands_short_TV;
std::map<char, uint16_t> key_commands_long_TV;

void scene_setKeys_TV() {
  key_repeatModes_TV = {
    {KEY_STOP,  SHORT            },    {KEY_REWI,  SHORT            },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORT            },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                      {KEY_CHDOW, SHORT            },

  };

  key_commands_short_TV = {
    {KEY_STOP,  PHILIPS_EXIT     },    {KEY_REWI,  PHILIPS_INPUT_HDMI_1},  {KEY_PLAY,  PHILIPS_INPUT_HDMI_2},  {KEY_FORW,  PHILIPS_INPUT_EXTERNAL},
    {KEY_CONF,  PHILIPS_GUIDE    },                                                                          {KEY_INFO,  PHILIPS_MENU     },
                                                         {KEY_UP,    PHILIPS_UP       },
                      {KEY_LEFT,  PHILIPS_LEFT    },     {KEY_OK,    PHILIPS_SELECT   },    {KEY_RIGHT, PHILIPS_RIGHT    },
                                                         {KEY_DOWN,  PHILIPS_DOWN     },
                                                                                                             {KEY_SRC,   PHILIPS_POWER_TOGGLE },
    {KEY_VOLUP, PHILIPS_VOL_UP   },                      {KEY_MUTE,  PHILIPS_MUTE     },                     {KEY_CHUP,  PHILIPS_CHANNEL_UP},
    {KEY_VOLDO, PHILIPS_VOL_DOWN },                      {KEY_CHDOW, PHILIPS_CHANNEL_DOWN},

  };
  key_commands_long_TV = {
  };

}

void scene_start_sequence_TV(void) {
  executeCommand(PHILIPS_POWER_TOGGLE);

}

void scene_end_sequence_TV(void) {

}

std::string scene_name_TV = "TV";
t_gui_list scene_TV_gui_list = {tabName_numpad};

void register_scene_TV(void) {
  register_command(&SCENE_TV,       makeCommandData(SCENE, {scene_name_TV}));
  register_command(&SCENE_TV_FORCE, makeCommandData(SCENE, {scene_name_TV, "FORCE"}));

  register_scene(
    scene_name_TV,
    & scene_setKeys_TV,
    & scene_start_sequence_TV,
    & scene_end_sequence_TV,
    & key_repeatModes_TV,
    & key_commands_short_TV,
    & key_commands_long_TV,
    & scene_TV_gui_list,
    SCENE_TV);
}
