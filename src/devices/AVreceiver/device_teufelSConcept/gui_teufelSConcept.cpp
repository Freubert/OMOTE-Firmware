#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "device_teufelSConcept.h"
#include "gui_teufelSConcept.h"

struct ButtonDef {
  const char* label;
  uint16_t* command;
};

static const ButtonDef buttons[] = {
  {"Power", &TEUFEL_POWER},
  {"OPT", &TEUFEL_INPUT_OPT},
  {"PC", &TEUFEL_INPUT_PC},
  {"AUX", &TEUFEL_INPUT_AUX},
  {"Radio", &TEUFEL_INPUT_TUNER},
  {"VCR", &TEUFEL_INPUT_VCR},
  {"COAX", &TEUFEL_INPUT_COAX},
  {"Listen mode", &TEUFEL_LISTEN_MODE},
  {"Night mode", &TEUFEL_NIGHT_MODE},
  {"C Delay +", &TEUFEL_C_DELAY_PLUS},
  {"C Delay -", &TEUFEL_C_DELAY_MINUS},
  {"S Delay +", &TEUFEL_S_DELAY_PLUS},
  {"S Delay -", &TEUFEL_S_DELAY_MINUS},
  {"Channel +", &TEUFEL_CHANNEL_PLUS},
  {"Channel -", &TEUFEL_CHANNEL_MINUS},
  {"Scan +", &TEUFEL_SCAN_PLUS},
  {"Scan -", &TEUFEL_SCAN_MINUS},
  {"1", &TEUFEL_NUM_1},
  {"2", &TEUFEL_NUM_2},
  {"3", &TEUFEL_NUM_3},
  {"4", &TEUFEL_NUM_4},
  {"5", &TEUFEL_NUM_5},
  {"6", &TEUFEL_NUM_6},
  {"7", &TEUFEL_NUM_7},
  {"8", &TEUFEL_NUM_8},
  {"9", &TEUFEL_NUM_9},
  {"0 / 10+", &TEUFEL_NUM_0},
  {"Test", &TEUFEL_TEST},
  {"Reset", &TEUFEL_RESET},
};

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
}

void notify_tab_before_delete_teufelSConcept(void) {
}

// While this tab is shown, the hardware keys control the Teufel
static std::map<char, repeatModes> key_repeatModes_teufelSConcept;
static std::map<char, uint16_t> key_commands_short_teufelSConcept;
static std::map<char, uint16_t> key_commands_long_teufelSConcept;

static void gui_setKeys_teufelSConcept(void) {
  key_commands_short_teufelSConcept = {
    {KEY_MUTE, TEUFEL_MUTE},
    {KEY_VOLUP, TEUFEL_VOL_PLUS}, {KEY_VOLDO, TEUFEL_VOL_MINUS},
    {KEY_UP, TEUFEL_CENTER_PLUS}, {KEY_DOWN, TEUFEL_CENTER_MINUS},
    {KEY_LEFT, TEUFEL_BALANCE_LEFT}, {KEY_RIGHT, TEUFEL_BALANCE_RIGHT}, {KEY_OK, TEUFEL_BALANCE_CENTER},
    {KEY_REWI, TEUFEL_BASS_PLUS}, {KEY_STOP, TEUFEL_BASS_MINUS},
    {KEY_PLAY, TEUFEL_TREBLE_MINUS}, {KEY_FORW, TEUFEL_TREBLE_PLUS},
    {KEY_CHUP, TEUFEL_SUB_PLUS}, {KEY_CHDOW, TEUFEL_SUB_MINUS},
  };
  for (const auto& entry : key_commands_short_teufelSConcept) {
    bool repeated = (entry.first == KEY_VOLUP) || (entry.first == KEY_VOLDO) || (entry.first == KEY_UP) || (entry.first == KEY_DOWN) || (entry.first == KEY_LEFT) || (entry.first == KEY_RIGHT);
    key_repeatModes_teufelSConcept[entry.first] = repeated ? SHORT_REPEATED : SHORT;
  }
  key_commands_long_teufelSConcept = {{KEY_STOP, TEUFEL_POWER},
    {KEY_RED, TEUFEL_REAR_LEFT_MINUS}, {KEY_GREEN, TEUFEL_REAR_LEFT_PLUS},
    {KEY_YELLO, TEUFEL_REAR_RIGHT_MINUS}, {KEY_BLUE, TEUFEL_REAR_RIGHT_PLUS}};
  for (char key : {KEY_STOP, KEY_RED, KEY_GREEN, KEY_YELLO, KEY_BLUE}) key_repeatModes_teufelSConcept[key] = SHORTorLONG;
}

void register_gui_teufelSConcept(void) {
  register_gui(std::string(tabName_teufelSConcept), & create_tab_content_teufelSConcept, & notify_tab_before_delete_teufelSConcept,
    & gui_setKeys_teufelSConcept, & key_repeatModes_teufelSConcept, & key_commands_short_teufelSConcept, & key_commands_long_teufelSConcept);
}
