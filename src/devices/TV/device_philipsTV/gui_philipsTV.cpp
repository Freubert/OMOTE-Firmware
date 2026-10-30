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
  {"TV", &PHILIPS_INPUT_TV},
  {"HDMI 1", &PHILIPS_INPUT_HDMI_1},
  {"HDMI 2", &PHILIPS_INPUT_HDMI_2},
  {"HDMI 3", &PHILIPS_INPUT_HDMI_3},
  {"HDMI Side", &PHILIPS_INPUT_SIDE},
  {"EXT", &PHILIPS_INPUT_EXT},
  {"Info", &PHILIPS_INFO},
  {"Subtitle", &PHILIPS_SUBTITLE},
  {"Green", &PHILIPS_GREEN},
  {"Yellow", &PHILIPS_YELLOW},
  {"Blue", &PHILIPS_BLUE},
  {"Options", &PHILIPS_OPTIONS},
  {"Exit", &PHILIPS_EXIT},
  {"Power On", &PHILIPS_POWER_ON},
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
  key_commands_short_philipsTV = {
    {KEY_STOP, PHILIPS_STOP}, {KEY_REWI, PHILIPS_REWIND}, {KEY_PLAY, PHILIPS_PAUSE}, {KEY_FORW, PHILIPS_FASTFORWARD},
    {KEY_CONF, PHILIPS_GUIDE}, {KEY_BACK, PHILIPS_BACK}, {KEY_REC, PHILIPS_HOME}, {KEY_INFO, PHILIPS_TEXT},
    {KEY_UP, PHILIPS_UP}, {KEY_DOWN, PHILIPS_DOWN}, {KEY_LEFT, PHILIPS_LEFT}, {KEY_RIGHT, PHILIPS_RIGHT}, {KEY_OK, PHILIPS_SELECT},
    {KEY_SRC, PHILIPS_SOURCES}, {KEY_CHUP, PHILIPS_CHANNEL_UP}, {KEY_CHDOW, PHILIPS_CHANNEL_DOWN},
    {KEY_VOLUP, PHILIPS_VOL_UP}, {KEY_VOLDO, PHILIPS_VOL_DOWN}, {KEY_MUTE, PHILIPS_MUTE},
  };
  key_commands_long_philipsTV = {{KEY_STOP, PHILIPS_POWER_TOGGLE}, {KEY_PLAY, PHILIPS_PLAY}, {KEY_INFO, PHILIPS_INFO}, {KEY_CONF, PHILIPS_POWER_TOGGLE}};
  for (const auto& entry : key_commands_short_philipsTV) {
    bool repeated = (entry.first == KEY_UP) || (entry.first == KEY_DOWN) || (entry.first == KEY_LEFT) || (entry.first == KEY_RIGHT) || (entry.first == KEY_VOLUP) || (entry.first == KEY_VOLDO);
    key_repeatModes_philipsTV[entry.first] = repeated ? SHORT_REPEATED : SHORT;
  }
  key_repeatModes_philipsTV[KEY_INFO] = SHORTorLONG;
  key_repeatModes_philipsTV[KEY_BACK] = SHORTorLONG;
  key_repeatModes_philipsTV[KEY_CONF] = SHORTorLONG;
  key_repeatModes_philipsTV[KEY_PLAY] = SHORTorLONG;
  key_repeatModes_philipsTV[KEY_STOP] = SHORTorLONG;

}

void register_gui_philipsTV(void) {
  register_gui(std::string(tabName_philipsTV), & create_tab_content_philipsTV, & notify_tab_before_delete_philipsTV,
    & gui_setKeys_philipsTV, & key_repeatModes_philipsTV, & key_commands_short_philipsTV, & key_commands_long_philipsTV);
}
