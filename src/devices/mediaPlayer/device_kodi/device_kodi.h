#pragma once

// Kodi commands sent as plain key presses over the BLE keyboard (Kodi default keyboard map).
extern uint16_t KODI_BACK;
extern uint16_t KODI_ESCAPE;
extern uint16_t KODI_FULLSCREEN;
extern uint16_t KODI_PAGE_UP;
extern uint16_t KODI_PAGE_DOWN;
extern uint16_t KODI_CONTEXT;
extern uint16_t KODI_INFO;
extern uint16_t KODI_OSD;
extern uint16_t KODI_STOP;
extern uint16_t KODI_REWIND;
extern uint16_t KODI_FASTFORWARD;
extern uint16_t KODI_SKIP_FORWARD;
extern uint16_t KODI_SKIP_BACK;
extern uint16_t KODI_SUBTITLES;
extern uint16_t KODI_SUBTITLE_NEXT;
extern uint16_t KODI_AUDIO_DELAY;
extern uint16_t KODI_DISPLAY_INFO;
extern uint16_t KODI_PROCESS_INFO;
extern uint16_t KODI_SHUTDOWN_MENU;
extern uint16_t KODI_QUEUE;
extern uint16_t KODI_WATCHED;
extern uint16_t KODI_SWITCH_PLAYER;
extern uint16_t KODI_WINDOWED;
extern uint16_t KODI_TV_GUIDE;
extern uint16_t KODI_TV_CHANNELS;
extern uint16_t KODI_TV_RECORDINGS;
extern uint16_t KODI_TV_RADIO;
extern uint16_t KODI_NUM[10]; // digits 0-9

void register_device_kodi();
