#include <map>
#include "scenes/scene_kodi.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_KODI;
uint16_t SCENE_KODI_FORCE;

std::map<char, repeatModes> key_repeatModes_kodi;
std::map<char, uint16_t> key_commands_short_kodi;
std::map<char, uint16_t> key_commands_long_kodi;

std::string scene_name_kodi = "Kodi";
t_gui_list scene_kodi_gui_list = {tabName_numpad};

void scene_setKeys_kodi() {
  key_repeatModes_kodi = {
    {KEY_STOP,  SHORT            },    {KEY_REWI,  SHORTorLONG      },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORTorLONG      },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                                                                          {KEY_CHDOW, SHORT            },
  };

  key_commands_short_kodi = {
    {KEY_STOP,  KEYBOARD_BACK    },    {KEY_REWI,  KEYBOARD_REWIND  },    {KEY_PLAY,  KEYBOARD_PLAYPAUSE},   {KEY_FORW,  KEYBOARD_FASTFORWARD},
    {KEY_CONF,  KEYBOARD_HOME    },                                                                          {KEY_INFO,  KEYBOARD_MENU    },
                                                         {KEY_UP,    KEYBOARD_UP      },
                      {KEY_LEFT,  KEYBOARD_LEFT   },     {KEY_OK,    KEYBOARD_SELECT  },    {KEY_RIGHT, KEYBOARD_RIGHT   },
                                                         {KEY_DOWN,  KEYBOARD_DOWN    },
                                                                                                             {KEY_SRC,   KEYBOARD_HOME    },
    {KEY_VOLUP, KEYBOARD_VOLUME_INCREMENT},              {KEY_MUTE,  KEYBOARD_MUTE    },                     {KEY_CHUP,  KEYBOARD_SCAN_NEXT_TRACK},
    {KEY_VOLDO, KEYBOARD_VOLUME_DECREMENT},                                                                  {KEY_CHDOW, KEYBOARD_SCAN_PREVIOUS_TRACK},
  };

  key_commands_long_kodi = {
    {KEY_REWI,  KEYBOARD_REWIND_LONG     },                                                                  {KEY_FORW,  KEYBOARD_FASTFORWARD_LONG},
  };
}

void scene_start_sequence_kodi(void) {
}

void scene_end_sequence_kodi(void) {
}

void register_scene_kodi(void) {
  register_command(&SCENE_KODI, makeCommandData(SCENE, {scene_name_kodi}));
  register_command(&SCENE_KODI_FORCE, makeCommandData(SCENE, {scene_name_kodi, "FORCE"}));

  register_scene(
    scene_name_kodi,
    &scene_setKeys_kodi,
    &scene_start_sequence_kodi,
    &scene_end_sequence_kodi,
    &key_repeatModes_kodi,
    &key_commands_short_kodi,
    &key_commands_long_kodi,
    &scene_kodi_gui_list,
    SCENE_KODI);
}
