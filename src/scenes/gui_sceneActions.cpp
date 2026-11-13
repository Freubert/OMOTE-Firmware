#include <map>
#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "scenes/gui_sceneActions.h"
#include "scenes/scene_sequence.h"

// Full-width buttons only (touch x-axis is broken). A button runs a sequence of commands.
static void action_kodi(void) {
  executeCommand(ATHEN_INPUT_HDMI_1);
}

static void action_wiiU(void) {
  executeCommand(ATHEN_INPUT_HDMI_2);
}

// Opens the TV's yellow-button menu and picks the screen-off entry
static void action_screenOff(void) {
  if (sequence_isRunning()) {
    return;
  }
  sequence_add(PHILIPS_GREEN, 5000);
  sequence_add(PHILIPS_DOWN, 500);
  sequence_add(PHILIPS_SELECT);
}

struct ActionDef {
  const char* label;
  void (*action)(void);
};

static const ActionDef actions[] = {
  {"Kodi", &action_kodi},
  {"Wii U", &action_wiiU},
  {"Bildschirm aus", &action_screenOff},
};

static void button_clicked_event_cb(lv_event_t* e) {
  ((void (*)(void))(e->user_data))();
}

void create_tab_content_sceneActions(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  for (const ActionDef& def : actions) {
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_set_size(button, LV_PCT(100), 40);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
    lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void*)def.action);

    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, def.label);
    lv_obj_center(label);
  }
}

void notify_tab_before_delete_sceneActions(void) {
}

void register_gui_sceneActions(void) {
  register_gui(std::string(tabName_sceneActions), & create_tab_content_sceneActions, & notify_tab_before_delete_sceneActions,
    NULL, NULL, NULL, NULL);
}
