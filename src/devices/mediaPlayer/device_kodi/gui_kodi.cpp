#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/keys.h"
#include "device_kodi.h"
#include "gui_kodi.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Display info", &KODI_DISPLAY_INFO},
  {"Process info", &KODI_PROCESS_INFO},
  //{"Queue", &KODI_QUEUE},
  {"Watched / unwatched", &KODI_WATCHED},
  //{"Switch player", &KODI_SWITCH_PLAYER},
  //{"Windowed / fullscreen", &KODI_WINDOWED},
  {"Live TV: guide", &KODI_TV_GUIDE},
  {"Live TV: channels", &KODI_TV_CHANNELS},
  //{"Live TV: recordings", &KODI_TV_RECORDINGS},
  //{"Live TV: radio", &KODI_TV_RADIO},
  //{"Escape / exit fullscreen", &KODI_ESCAPE},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_kodi(lv_obj_t* tab) {
  const ButtonDef* defs = buttons;
  size_t count = sizeof(buttons) / sizeof(buttons[0]);
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  for (size_t i = 0; i < count; i++) {
    const ButtonDef& def = defs[i];
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_set_size(button, LV_PCT(100), 40);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
    lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void*)def.command);

    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, def.label);
    lv_obj_center(label);
  }
}

void notify_tab_before_delete_kodi(void) {
}

// While a Kodi tab is shown, the hardware keys control Kodi, except volume/mute (left to the scene, e.g. the amplifier)
static std::map<char, repeatModes> key_repeatModes_kodi;
static std::map<char, uint16_t> key_commands_short_kodi;
static std::map<char, uint16_t> key_commands_long_kodi;

static void gui_setKeys_kodi(void) {
  key_repeatModes_kodi = {
    {KEY_STOP, SHORTorLONG}, {KEY_REWI, SHORTorLONG}, {KEY_PLAY, SHORT}, {KEY_FORW, SHORTorLONG},
    {KEY_CONF, SHORT}, {KEY_INFO, SHORT}, {KEY_BACK, SHORTorLONG}, {KEY_SRC, SHORT},
    {KEY_UP, SHORT_REPEATED}, {KEY_DOWN, SHORT_REPEATED}, {KEY_LEFT, SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT},
    {KEY_CHUP, SHORTorLONG}, {KEY_CHDOW, SHORTorLONG},
    {KEY_RED, SHORTorLONG}, {KEY_GREEN, SHORTorLONG}, {KEY_YELLO, SHORTorLONG}, {KEY_BLUE, SHORTorLONG},
  };
  // Info (long press: player controls), Conf is the context menu
  key_commands_short_kodi = {
    {KEY_STOP, KODI_STOP}, {KEY_REWI, KODI_REWIND}, {KEY_PLAY, KEYBOARD_PLAYPAUSE}, {KEY_FORW, KODI_FASTFORWARD},
    {KEY_CONF, KODI_CONTEXT}, {KEY_INFO, KODI_INFO}, {KEY_BACK, KODI_ESCAPE}, {KEY_SRC, KODI_OSD},
    {KEY_UP, KEYBOARD_UP}, {KEY_LEFT, KEYBOARD_LEFT}, {KEY_RIGHT, KEYBOARD_RIGHT}, {KEY_DOWN, KEYBOARD_DOWN}, {KEY_OK, KEYBOARD_SELECT},
    {KEY_REC, KEYBOARD_HOME},
    {KEY_CHUP, KEYBOARD_SCAN_NEXT_TRACK}, {KEY_CHDOW, KEYBOARD_SCAN_PREVIOUS_TRACK},
  };
  key_commands_long_kodi = {
    {KEY_STOP, KODI_SHUTDOWN_MENU}, {KEY_REWI, KODI_SKIP_BACK}, {KEY_FORW, KODI_SKIP_FORWARD},
    {KEY_BACK, KODI_BACK},
    {KEY_CHUP, KODI_PAGE_UP}, {KEY_CHDOW, KODI_PAGE_DOWN},
    {KEY_RED, KODI_SUBTITLES}, {KEY_GREEN, KODI_SUBTITLE_NEXT}, {KEY_YELLO, KODI_AUDIO_DELAY}, {KEY_BLUE, KODI_FULLSCREEN},
  };
}

void register_gui_kodi(void) {
  register_gui(std::string(tabName_kodi), & create_tab_content_kodi, & notify_tab_before_delete_kodi,
    & gui_setKeys_kodi, & key_repeatModes_kodi, & key_commands_short_kodi, & key_commands_long_kodi);
}
