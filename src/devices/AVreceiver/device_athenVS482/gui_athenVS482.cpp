#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_athenVS482.h"
#include "gui_athenVS482.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power", &ATHEN_POWER_TOGGLE},
  {"HDMI 1", &ATHEN_INPUT_HDMI_1},
  {"HDMI 2", &ATHEN_INPUT_HDMI_2},
  {"HDMI 3", &ATHEN_INPUT_HDMI_3},
  {"HDMI 4", &ATHEN_INPUT_HDMI_4},
  {"Up", &ATHEN_UP},
  {"Select", &ATHEN_SELECT},
  {"Exit", &ATHEN_EXIT},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_athenVS482(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);

  for (const ButtonDef& def : buttons) {
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_set_size(button, 100, 40);
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

void register_gui_athenVS482(void) {
  register_gui(std::string(tabName_athenVS482), & create_tab_content_athenVS482, & notify_tab_before_delete_athenVS482);
}
