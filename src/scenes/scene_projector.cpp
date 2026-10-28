#include <map>
#include "scenes/scene_projector.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// devices
#include "devices/projector/device_epsonProjector/device_epsonProjector.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_PROJECTOR;
uint16_t SCENE_PROJECTOR_FORCE;

std::map<char, repeatModes> key_repeatModes_projector;
std::map<char, uint16_t> key_commands_short_projector;
std::map<char, uint16_t> key_commands_long_projector;

std::string scene_name_projector = "Projector";
t_gui_list scene_projector_gui_list = {tabName_numpad};

// Epson projector on the navigation/volume keys, Athen HDMI switch inputs on the media keys.
void scene_setKeys_projector() {
  key_repeatModes_projector = {
    {KEY_STOP,  SHORT            },    {KEY_REWI,  SHORT            },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORT            },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                                                                          {KEY_CHDOW, SHORT            },
  };

  key_commands_short_projector = {
    {KEY_STOP,  ATHEN_INPUT_HDMI_1},   {KEY_REWI,  ATHEN_INPUT_HDMI_2},   {KEY_PLAY,  ATHEN_INPUT_HDMI_3},   {KEY_FORW,  ATHEN_INPUT_HDMI_4},
    {KEY_CONF,  EPSON_EXIT       },                                                                          {KEY_INFO,  EPSON_MENU       },
                                                         {KEY_UP,    EPSON_UP         },
                      {KEY_LEFT,  EPSON_LEFT      },     {KEY_OK,    EPSON_SELECT     },    {KEY_RIGHT, EPSON_RIGHT      },
                                                         {KEY_DOWN,  EPSON_DOWN       },
                                                                                                             {KEY_SRC,   EPSON_SOURCE     },
    {KEY_VOLUP, EPSON_VOL_UP     },                      {KEY_MUTE,  EPSON_MUTE       },                     {KEY_CHUP,  EPSON_INPUT_HDMI1},
    {KEY_VOLDO, EPSON_VOL_DOWN   },                                                                          {KEY_CHDOW, EPSON_INPUT_HDMI2},
  };

  key_commands_long_projector = {
  };
}

void scene_start_sequence_projector(void) {
  executeCommand(EPSON_POWER_ON);
}

void scene_end_sequence_projector(void) {
}

void register_scene_projector(void) {
  register_command(&SCENE_PROJECTOR, makeCommandData(SCENE, {scene_name_projector}));
  register_command(&SCENE_PROJECTOR_FORCE, makeCommandData(SCENE, {scene_name_projector, "FORCE"}));

  register_scene(
    scene_name_projector,
    &scene_setKeys_projector,
    &scene_start_sequence_projector,
    &scene_end_sequence_projector,
    &key_repeatModes_projector,
    &key_commands_short_projector,
    &key_commands_long_projector,
    &scene_projector_gui_list,
    SCENE_PROJECTOR);
}
