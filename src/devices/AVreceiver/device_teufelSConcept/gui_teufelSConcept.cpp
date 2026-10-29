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
  {"Vol +", &TEUFEL_VOL_PLUS},
  {"Vol -", &TEUFEL_VOL_MINUS},
  {"Input VCR", &TEUFEL_INPUT_VCR},
  {"Input OPT", &TEUFEL_INPUT_OPT},
  {"Input AUX", &TEUFEL_INPUT_AUX},
  {"Input COAX", &TEUFEL_INPUT_COAX},
  {"Center +", &TEUFEL_CENTER_PLUS},
  {"Center -", &TEUFEL_CENTER_MINUS},
  {"Balance left", &TEUFEL_BALANCE_LEFT},
  {"Balance right", &TEUFEL_BALANCE_RIGHT},
  {"Balance center", &TEUFEL_BALANCE_CENTER},
  {"Bass +", &TEUFEL_BASS_PLUS},
  {"Treble +", &TEUFEL_TREBLE_PLUS},
  {"Subwoofer +", &TEUFEL_SUB_PLUS},
  {"Subwoofer -", &TEUFEL_SUB_MINUS},
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

  // Unlabeled Harmony codes: press each and note what the Teufel does.
  for (int i = 0; i < TEUFEL_TRY_COUNT; i++) {
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_set_size(button, LV_PCT(100), 40);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
    lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void*)&TEUFEL_TRY[i]);
    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, TEUFEL_TRY_LABELS[i]);
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
    {KEY_SRC, TEUFEL_POWER},
    {KEY_VOLUP, TEUFEL_VOL_PLUS}, {KEY_VOLDO, TEUFEL_VOL_MINUS},
    {KEY_UP, TEUFEL_CENTER_PLUS}, {KEY_DOWN, TEUFEL_CENTER_MINUS},
    {KEY_LEFT, TEUFEL_BALANCE_LEFT}, {KEY_RIGHT, TEUFEL_BALANCE_RIGHT}, {KEY_OK, TEUFEL_BALANCE_CENTER},
    {KEY_REWI, TEUFEL_BASS_PLUS}, {KEY_FORW, TEUFEL_TREBLE_PLUS},
    {KEY_PLAY, TEUFEL_SUB_PLUS}, {KEY_STOP, TEUFEL_SUB_MINUS},
    {KEY_INFO, TEUFEL_INPUT_AUX}, {KEY_CONF, TEUFEL_INPUT_VCR},
    {KEY_GREEN, TEUFEL_INPUT_OPT}, {KEY_YELLO, TEUFEL_INPUT_COAX},
  };
  for (const auto& entry : key_commands_short_teufelSConcept) {
    bool repeated = (entry.first == KEY_VOLUP) || (entry.first == KEY_VOLDO) || (entry.first == KEY_UP) || (entry.first == KEY_DOWN) || (entry.first == KEY_LEFT) || (entry.first == KEY_RIGHT);
    key_repeatModes_teufelSConcept[entry.first] = repeated ? SHORT_REPEATED : SHORT;
  }
}

void register_gui_teufelSConcept(void) {
  register_gui(std::string(tabName_teufelSConcept), & create_tab_content_teufelSConcept, & notify_tab_before_delete_teufelSConcept,
    & gui_setKeys_teufelSConcept, & key_repeatModes_teufelSConcept, & key_commands_short_teufelSConcept, & key_commands_long_teufelSConcept);
}
