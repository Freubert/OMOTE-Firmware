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
  //{"HDMI 1", &EPSON_INPUT_HDMI1},
  //{"HDMI 2", &EPSON_INPUT_HDMI2},
  //{"Computer", &EPSON_INPUT_COMPUTER},
  //{"USB", &EPSON_INPUT_USB},
  //{"LAN", &EPSON_INPUT_LAN},
  {"Auto", &EPSON_AUTO},
  {"Aspect", &EPSON_ASPECT},
  {"Color mode", &EPSON_COLOR_MODE},
  {"User", &EPSON_USER},
  {"Split", &EPSON_SPLIT},
  {"1", &EPSON_NUM_1},
  {"2", &EPSON_NUM_2},
  {"3", &EPSON_NUM_3},
  {"4", &EPSON_NUM_4},
  {"5", &EPSON_NUM_5},
  {"6", &EPSON_NUM_6},
  {"7", &EPSON_NUM_7},
  {"8", &EPSON_NUM_8},
  {"9", &EPSON_NUM_9},
  {"0", &EPSON_NUM_0},
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

// While this tab is shown, the hardware keys control the projector
static std::map<char, repeatModes> key_repeatModes_epsonProjector;
static std::map<char, uint16_t> key_commands_short_epsonProjector;
static std::map<char, uint16_t> key_commands_long_epsonProjector;

static void gui_setKeys_epsonProjector(void) {
  key_commands_short_epsonProjector = {
    {KEY_UP, EPSON_UP}, {KEY_DOWN, EPSON_DOWN}, {KEY_LEFT, EPSON_LEFT}, {KEY_RIGHT, EPSON_RIGHT}, {KEY_OK, EPSON_SELECT},
    {KEY_VOLUP, EPSON_VOL_UP}, {KEY_VOLDO, EPSON_VOL_DOWN}, {KEY_MUTE, EPSON_MUTE},
    {KEY_BACK, EPSON_EXIT}, {KEY_CONF, EPSON_MENU}, {KEY_INFO, EPSON_HOME}, {KEY_SRC, EPSON_SOURCE},
    {KEY_CHUP, EPSON_PAGE_UP}, {KEY_CHDOW, EPSON_PAGE_DOWN},
    {KEY_FORW, EPSON_ZOOM_IN}, {KEY_REWI, EPSON_ZOOM_OUT}, {KEY_PLAY, EPSON_FREEZE},
  };
  for (const auto& entry : key_commands_short_epsonProjector) {
    bool repeated = (entry.first == KEY_UP) || (entry.first == KEY_DOWN) || (entry.first == KEY_LEFT) || (entry.first == KEY_RIGHT) || (entry.first == KEY_VOLUP) || (entry.first == KEY_VOLDO);
    key_repeatModes_epsonProjector[entry.first] = repeated ? SHORT_REPEATED : SHORT;
  }
  key_commands_long_epsonProjector = {{KEY_STOP, EPSON_POWER_TOGGLE}};
  key_repeatModes_epsonProjector[KEY_STOP] = SHORTorLONG;
}

void register_gui_epsonProjector(void) {
  register_gui(std::string(tabName_epsonProjector), & create_tab_content_epsonProjector, & notify_tab_before_delete_epsonProjector,
    & gui_setKeys_epsonProjector, & key_repeatModes_epsonProjector, & key_commands_short_epsonProjector, & key_commands_long_epsonProjector);
}
