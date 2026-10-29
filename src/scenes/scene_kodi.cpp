#include <map>
#include "scenes/scene_kodi.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "devices/mediaPlayer/device_kodi/device_kodi.h"
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
    {KEY_STOP,  SHORTorLONG      },    {KEY_REWI,  SHORT            },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORT            },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORTorLONG      },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                                                                          {KEY_CHDOW, SHORT            },
                                       {KEY_GREEN, SHORT            },    {KEY_YELLO, SHORT            },
  };

  // Back is on Stop (long press: stop playback), Info (long press: player controls), Conf is the context menu, Src is Home
  key_commands_short_kodi = {
    {KEY_STOP,  KODI_BACK        },    {KEY_REWI,  KODI_REWIND      },    {KEY_PLAY,  KEYBOARD_PLAYPAUSE},   {KEY_FORW,  KODI_FASTFORWARD},
    {KEY_CONF,  KODI_CONTEXT     },                                                                          {KEY_INFO,  KODI_INFO        },
                                                         {KEY_UP,    KEYBOARD_UP      },
                      {KEY_LEFT,  KEYBOARD_LEFT   },     {KEY_OK,    KEYBOARD_SELECT  },    {KEY_RIGHT, KEYBOARD_RIGHT   },
                                                         {KEY_DOWN,  KEYBOARD_DOWN    },
                                                                                                             {KEY_SRC,   KEYBOARD_HOME    },
    {KEY_VOLUP, KEYBOARD_VOLUME_INCREMENT},              {KEY_MUTE,  KEYBOARD_MUTE    },                     {KEY_CHUP,  KEYBOARD_SCAN_NEXT_TRACK},
    {KEY_VOLDO, KEYBOARD_VOLUME_DECREMENT},                                                                  {KEY_CHDOW, KEYBOARD_SCAN_PREVIOUS_TRACK},
                                       {KEY_GREEN, KODI_SUBTITLES   },    {KEY_YELLO, KODI_SUBTITLE_NEXT},
  };

  key_commands_long_kodi = {
    {KEY_STOP,  KODI_STOP        },                                                                          {KEY_INFO,  KODI_OSD         },
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
