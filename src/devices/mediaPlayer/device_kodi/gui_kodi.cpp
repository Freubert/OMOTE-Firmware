#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "gui_kodi.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Up", &KEYBOARD_UP},
  {"Down", &KEYBOARD_DOWN},
  {"Left", &KEYBOARD_LEFT},
  {"Right", &KEYBOARD_RIGHT},
  {"Select", &KEYBOARD_SELECT},
  {"Play/Pause", &KEYBOARD_PLAYPAUSE},
  {"Menu", &KEYBOARD_MENU},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_kodi(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  for (const ButtonDef& def : buttons) {
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

// While this tab is shown, the arrow keys on the remote control this device
static std::map<char, repeatModes> key_repeatModes_kodi;
static std::map<char, uint16_t> key_commands_short_kodi;
static std::map<char, uint16_t> key_commands_long_kodi;

static void gui_setKeys_kodi(void) {
  key_repeatModes_kodi = {{KEY_UP, SHORT_REPEATED}, {KEY_DOWN, SHORT_REPEATED}, {KEY_LEFT, SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT}};
  key_commands_short_kodi = {{KEY_UP, KEYBOARD_UP}, {KEY_DOWN, KEYBOARD_DOWN}, {KEY_LEFT, KEYBOARD_LEFT}, {KEY_RIGHT, KEYBOARD_RIGHT}, {KEY_OK, KEYBOARD_SELECT}};
}

void register_gui_kodi(void) {
  register_gui(std::string(tabName_kodi), & create_tab_content_kodi, & notify_tab_before_delete_kodi,
    & gui_setKeys_kodi, & key_repeatModes_kodi, & key_commands_short_kodi, & key_commands_long_kodi);
}
