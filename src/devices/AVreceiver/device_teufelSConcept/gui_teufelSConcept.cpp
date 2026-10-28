#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_teufelSConcept.h"
#include "gui_teufelSConcept.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power On", &TEUFEL_POWER_ON},
  {"Power Off", &TEUFEL_POWER_OFF},
  {"Vol +", &TEUFEL_VOL_PLUS},
  {"Vol -", &TEUFEL_VOL_MINUS},
  {"Mute", &TEUFEL_MUTE_TOGGLE},
  {"Source", &TEUFEL_SOURCE},
  {"TV", &TEUFEL_INPUT_TV},
  {"HDMI 1", &TEUFEL_INPUT_HDMI_1},
  {"HDMI 2", &TEUFEL_INPUT_HDMI_2},
  {"AUX", &TEUFEL_INPUT_AUX},
  {"Menu", &TEUFEL_MENU},
  {"Up", &TEUFEL_UP},
  {"Down", &TEUFEL_DOWN},
  {"Left", &TEUFEL_LEFT},
  {"Right", &TEUFEL_RIGHT},
  {"Select", &TEUFEL_SELECT},
  {"Exit", &TEUFEL_EXIT},
  {"Rewind", &TEUFEL_REWIND},
  {"Play", &TEUFEL_PLAY},
  {"Pause", &TEUFEL_PAUSE},
  {"Forward", &TEUFEL_FASTFORWARD},
};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_teufelSConcept(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_ROW_WRAP);
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

void notify_tab_before_delete_teufelSConcept(void) {
}

void register_gui_teufelSConcept() {
  register_gui(std::string(tabName_teufelSConcept), & create_tab_content_teufelSConcept, & notify_tab_before_delete_teufelSConcept);
}
