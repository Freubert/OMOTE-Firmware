#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_philipsTV.h"
#include "gui_philipsTV.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power", &PHILIPS_POWER_TOGGLE},
  {"Power On", &PHILIPS_POWER_ON},
  {"Input", &PHILIPS_INPUT_EXTERNAL},
  {"HDMI 1", &PHILIPS_INPUT_HDMI_1},
  {"HDMI 2", &PHILIPS_INPUT_HDMI_2},
  {"Guide", &PHILIPS_GUIDE},
  {"Vol +", &PHILIPS_VOL_UP},
  {"Vol -", &PHILIPS_VOL_DOWN},
  {"Mute", &PHILIPS_MUTE},
  {"Menu", &PHILIPS_MENU},
  {"Up", &PHILIPS_UP},
  {"Down", &PHILIPS_DOWN},
  {"Left", &PHILIPS_LEFT},
  {"Right", &PHILIPS_RIGHT},
  {"Exit", &PHILIPS_EXIT},
  {"Channel +", &PHILIPS_CHANNEL_UP},
  {"Channel -", &PHILIPS_CHANNEL_DOWN},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_philipsTV(lv_obj_t* tab) {
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

void notify_tab_before_delete_philipsTV(void) {
}

// While this tab is shown, the arrow keys on the remote control this device
static std::map<char, repeatModes> key_repeatModes_philipsTV;
static std::map<char, uint16_t> key_commands_short_philipsTV;
static std::map<char, uint16_t> key_commands_long_philipsTV;

static void gui_setKeys_philipsTV(void) {
  key_repeatModes_philipsTV = {{KEY_UP, SHORT_REPEATED}, {KEY_DOWN, SHORT_REPEATED}, {KEY_LEFT, SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT}};
  key_commands_short_philipsTV = {{KEY_UP, PHILIPS_UP}, {KEY_DOWN, PHILIPS_DOWN}, {KEY_LEFT, PHILIPS_LEFT}, {KEY_RIGHT, PHILIPS_RIGHT}, {KEY_OK, PHILIPS_SELECT}};
}

void register_gui_philipsTV(void) {
  register_gui(std::string(tabName_philipsTV), & create_tab_content_philipsTV, & notify_tab_before_delete_philipsTV,
    & gui_setKeys_philipsTV, & key_repeatModes_philipsTV, & key_commands_short_philipsTV, & key_commands_long_philipsTV);
}
