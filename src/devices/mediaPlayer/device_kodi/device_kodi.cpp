#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_kodi.h"

uint16_t KODI_BACK;
uint16_t KODI_ESCAPE;
uint16_t KODI_FULLSCREEN;
uint16_t KODI_PAGE_UP;
uint16_t KODI_PAGE_DOWN;
uint16_t KODI_CONTEXT;
uint16_t KODI_INFO;
uint16_t KODI_OSD;
uint16_t KODI_STOP;
uint16_t KODI_REWIND;
uint16_t KODI_FASTFORWARD;
uint16_t KODI_SKIP_FORWARD;
uint16_t KODI_SKIP_BACK;
uint16_t KODI_SUBTITLES;
uint16_t KODI_SUBTITLE_NEXT;
uint16_t KODI_AUDIO_DELAY;
uint16_t KODI_DISPLAY_INFO;
uint16_t KODI_PROCESS_INFO;
uint16_t KODI_SHUTDOWN_MENU;
uint16_t KODI_QUEUE;
uint16_t KODI_WATCHED;
uint16_t KODI_SWITCH_PLAYER;
uint16_t KODI_WINDOWED;
uint16_t KODI_TV_GUIDE;
uint16_t KODI_TV_CHANNELS;
uint16_t KODI_TV_RECORDINGS;
uint16_t KODI_TV_RADIO;
uint16_t KODI_NUM[10];

// A BLE keyboard command with exactly one payload is sent as that raw key code (see keyboard_ble_executeCommand).
static void registerKey(uint16_t* command, int keyCode) {
#if (ENABLE_KEYBOARD_BLE == 1)
  register_command(command, makeCommandData(BLE_KEYBOARD, {std::to_string(keyCode)}));
#else
  get_uniqueCommandID(command);
#endif
}

void register_device_kodi() {
  registerKey(&KODI_BACK, 178); // Backspace
  registerKey(&KODI_ESCAPE, 177); // Esc
  registerKey(&KODI_FULLSCREEN, 179); // Tab
  registerKey(&KODI_PAGE_UP, 211); // next chapter / page up
  registerKey(&KODI_PAGE_DOWN, 214); // previous chapter / page down
  registerKey(&KODI_CONTEXT, 99);
  registerKey(&KODI_INFO, 105);
  registerKey(&KODI_OSD, 109); // player controls / menu
  registerKey(&KODI_STOP, 120);
  registerKey(&KODI_REWIND, 114);
  registerKey(&KODI_FASTFORWARD, 102);
  registerKey(&KODI_SKIP_FORWARD, 46);
  registerKey(&KODI_SKIP_BACK, 44);
  registerKey(&KODI_SUBTITLES, 116); // on/off
  registerKey(&KODI_SUBTITLE_NEXT, 108);
  registerKey(&KODI_AUDIO_DELAY, 65);
  registerKey(&KODI_DISPLAY_INFO, 122);
  registerKey(&KODI_PROCESS_INFO, 111);
  registerKey(&KODI_SHUTDOWN_MENU, 115);
  registerKey(&KODI_QUEUE, 113);
  registerKey(&KODI_WATCHED, 119);
  registerKey(&KODI_SWITCH_PLAYER, 121);
  registerKey(&KODI_WINDOWED, 92); // toggle windowed/fullscreen
  registerKey(&KODI_TV_GUIDE, 101);
  registerKey(&KODI_TV_CHANNELS, 104);
  registerKey(&KODI_TV_RECORDINGS, 107);
  registerKey(&KODI_TV_RADIO, 106);
  for (int i = 0; i < 10; i++) {
    registerKey(&KODI_NUM[i], '0' + i);
  }
}
