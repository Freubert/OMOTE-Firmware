#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_epsonProjector.h"
#include "gui_epsonProjector.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power", &EPSON_POWER_TOGGLE},
  {"HDMI 1", &EPSON_INPUT_HDMI1},
  {"HDMI 2", &EPSON_INPUT_HDMI2},
  {"Up", &EPSON_UP},
  {"Select", &EPSON_SELECT},
  {"Exit", &EPSON_EXIT},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_epsonProjector(lv_obj_t* tab) {
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

void notify_tab_before_delete_epsonProjector(void) {
}

// While this tab is shown, the arrow keys on the remote control this device
static std::map<char, repeatModes> key_repeatModes_epsonProjector;
static std::map<char, uint16_t> key_commands_short_epsonProjector;
static std::map<char, uint16_t> key_commands_long_epsonProjector;

static void gui_setKeys_epsonProjector(void) {
  key_repeatModes_epsonProjector = {{KEY_UP, SHORT_REPEATED}, {KEY_DOWN, SHORT_REPEATED}, {KEY_LEFT, SHORT_REPEATED}, {KEY_RIGHT, SHORT_REPEATED}, {KEY_OK, SHORT}, {KEY_STOP, SHORTorLONG}};
  key_commands_short_epsonProjector = {{KEY_UP, EPSON_UP}, {KEY_DOWN, EPSON_DOWN}, {KEY_LEFT, EPSON_LEFT}, {KEY_RIGHT, EPSON_RIGHT}, {KEY_OK, EPSON_SELECT}};
  key_commands_long_epsonProjector = {{KEY_STOP, EPSON_POWER_TOGGLE}};
}

void register_gui_epsonProjector(void) {
  register_gui(std::string(tabName_epsonProjector), & create_tab_content_epsonProjector, & notify_tab_before_delete_epsonProjector,
    & gui_setKeys_epsonProjector, & key_repeatModes_epsonProjector, & key_commands_short_epsonProjector, & key_commands_long_epsonProjector);
}
