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
  {"Vol +", &TEUFEL_VOL_PLUS},
  {"Vol -", &TEUFEL_VOL_MINUS},
  {"Mute", &TEUFEL_MUTE_TOGGLE},
  {"Up", &TEUFEL_UP},
  {"Down", &TEUFEL_DOWN},
  {"Left", &TEUFEL_LEFT},
  {"Right", &TEUFEL_RIGHT},
  {"Select", &TEUFEL_SELECT},
  {"Rewind", &TEUFEL_REWIND},
  {"Play", &TEUFEL_PLAY},
  {"Pause", &TEUFEL_PAUSE},
  {"Forward", &TEUFEL_FASTFORWARD},
};

static const char* const tryLabels[TEUFEL_TRY_COUNT] = {"Try 1", "Try 2", "Try 3", "Try 4", "Try 5", "Try 6", "Try 7", "Try 8", "Try 9", "Try 10", "Try 11"};

static void button_clicked_event_cb(lv_event_t* e) {
  uint16_t* command = (uint16_t*)(e->user_data);
  executeCommand(*command);
}

void create_tab_content_teufelSConcept(lv_obj_t* tab) {
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

  // Unlabeled Harmony codes: press each and note what the Teufel does.
  for (int i = 0; i < TEUFEL_TRY_COUNT; i++) {
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_set_size(button, LV_PCT(100), 40);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
    lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void*)&TEUFEL_TRY[i]);
    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, tryLabels[i]);
    lv_obj_center(label);
  }
}

void notify_tab_before_delete_teufelSConcept(void) {
}

void register_gui_teufelSConcept() {
  register_gui(std::string(tabName_teufelSConcept), & create_tab_content_teufelSConcept, & notify_tab_before_delete_teufelSConcept);
}
