#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "scenes/gui_deviceMenu.h"
#include "scenes/scene__default.h"
#include "scenes/scene_directDeviceControl.h"

// Full-width buttons only (touch x-axis is broken).
// Back to the scene selection, the scene itself stays active
static void leave_scene_cb(lv_timer_t* timer) {
  executeCommand(SCENE_SELECTION);
}

static void jump_to_gui_cb(lv_timer_t* timer) {
  guis_doTabCreationForSpecificGUI(SCENE_GUI_LIST, (int)(intptr_t)timer->user_data);
}

// The tabs are changed in a short timer, not inside the click callback of a button that lives on the tab being deleted
static void button_clicked_event_cb(lv_event_t* e) {
  intptr_t target = (intptr_t)lv_event_get_user_data(e);
  lv_timer_t* timer = (target < 0) ? lv_timer_create(leave_scene_cb, 5, NULL)
                                   : lv_timer_create(jump_to_gui_cb, 5, (void*)target);
  lv_timer_set_repeat_count(timer, 1);
}

static lv_obj_t* add_button(lv_obj_t* tab, const char* text, intptr_t target) {
  lv_obj_t* button = lv_btn_create(tab);
  lv_obj_set_size(button, LV_PCT(100), 40);
  lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
  lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void*)target);
  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, text);
  lv_obj_center(label);
  return button;
}

void create_tab_content_deviceMenu(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  lv_obj_t* back = add_button(tab, LV_SYMBOL_LEFT " Zurück", -1);
  lv_obj_set_style_bg_color(back, lv_palette_darken(LV_PALETTE_RED, 2), LV_PART_MAIN);

  // one button per device tab of the scene, the menu itself is index 0
  gui_list guiList = get_gui_list_withFallback(SCENE_GUI_LIST);
  for (int i = 1; i < (int)guiList->size(); i++) {
    add_button(tab, guiList->at(i).c_str(), i);
  }
}

void notify_tab_before_delete_deviceMenu(void) {
}

void register_gui_deviceMenu(void) {
  register_gui(std::string(tabName_deviceMenu), & create_tab_content_deviceMenu, & notify_tab_before_delete_deviceMenu,
    NULL, NULL, NULL, NULL);
}
