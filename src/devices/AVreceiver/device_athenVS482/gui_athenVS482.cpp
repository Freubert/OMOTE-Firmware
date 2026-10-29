#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_athenVS482.h"
#include "gui_athenVS482.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power On", &ATHEN_POWER_ON},
  {"Power Off", &ATHEN_POWER_OFF},
  {"Port 1", &ATHEN_INPUT_HDMI_1},
  {"Port 2", &ATHEN_INPUT_HDMI_2},
  {"Port 3", &ATHEN_INPUT_HDMI_3},
  {"Port 4", &ATHEN_INPUT_HDMI_4},
  {"Up", &ATHEN_UP},
  {"Down", &ATHEN_DOWN},
  {"Left", &ATHEN_LEFT},
  {"Right", &ATHEN_RIGHT},
  {"Setup", &ATHEN_SETUP},
  {"Menu", &ATHEN_MENU},
  {"Info", &ATHEN_INFO},
  {"ARC", &ATHEN_ARC},
  {"HDMI Mute", &ATHEN_HDMI_MUTE},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_athenVS482(lv_obj_t* tab) {
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

void notify_tab_before_delete_athenVS482(void) {
}

// While this tab is shown, the arrow keys on the remote control this device
static std::map<char, repeatModes> key_repeatModes_athenVS482;
static std::map<char, uint16_t> key_commands_short_athenVS482;
static std::map<char, uint16_t> key_commands_long_athenVS482;

static void gui_setKeys_athenVS482(void) {
  key_repeatModes_athenVS482 = {{KEY_UP, SHORT_REPEATED}, {KEY_DOWN, SHORT_REPEATED}, {KEY_LEFT, SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT}};
  key_commands_short_athenVS482 = {{KEY_UP, ATHEN_UP}, {KEY_DOWN, ATHEN_DOWN}, {KEY_LEFT, ATHEN_LEFT}, {KEY_RIGHT, ATHEN_RIGHT}, {KEY_OK, ATHEN_SETUP}};
}

void register_gui_athenVS482(void) {
  register_gui(std::string(tabName_athenVS482), & create_tab_content_athenVS482, & notify_tab_before_delete_athenVS482,
    & gui_setKeys_athenVS482, & key_repeatModes_athenVS482, & key_commands_short_athenVS482, & key_commands_long_athenVS482);
}
