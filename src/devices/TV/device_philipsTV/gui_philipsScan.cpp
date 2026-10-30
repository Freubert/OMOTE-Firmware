#include <lvgl.h>
#include <string>
#include <list>
#include <vector>
#include <stdio.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "gui_philipsScan.h"

// Sweeps the RC6 command byte (address 0) so the unknown Philips buttons (e.g. Adjust) can be found by watching the TV.
// Commands that are already known are skipped.
static const uint8_t knownCommands[] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x20, 0x21, 0x28, 0x2B, 0x2C, 0x30, 0x31,
  0x38, 0x3C, 0x40, 0x4B, 0x54, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x6D, 0x6E, 0x6F, 0x70, 0x9F, 0xBF, 0xCC,
};

static std::vector<uint8_t> sweepList;
static int sweepIndex = -1;
static lv_obj_t* statusLabel = NULL;

static void buildSweepList() {
  if (!sweepList.empty()) return;
  for (int cmd = 0; cmd < 256; cmd++) {
    bool known = false;
    for (uint8_t k : knownCommands) {
      if (k == cmd) { known = true; break; }
    }
    if (!known) sweepList.push_back((uint8_t)cmd);
  }
}

static void updateStatus() {
  if (statusLabel == NULL) return;
  char text[64];
  if (sweepIndex < 0) {
    snprintf(text, sizeof(text), "Nothing sent yet\n%d commands to try", (int)sweepList.size());
  } else {
    snprintf(text, sizeof(text), "Sent cmd %d (0x%02X)\n%d of %d", sweepList[sweepIndex], sweepList[sweepIndex], sweepIndex + 1, (int)sweepList.size());
  }
  lv_label_set_text(statusLabel, text);
}

static void sendCurrent() {
  if (sweepIndex < 0) return;
  uint8_t cmd = sweepList[sweepIndex];
  char payload[24];
  snprintf(payload, sizeof(payload), "0x1%04X:20:0", (unsigned int)cmd);
  sendIRcode(IR_PROTOCOL_RC6, std::list<std::string>{payload}, "");
}

static void scan_event_cb(lv_event_t* e) {
  int action = (int)(intptr_t)lv_event_get_user_data(e);
  int count = (int)sweepList.size();
  if (action == 0) {
    sweepIndex = (sweepIndex + 1) % count;
  } else if (action == 1) {
    sweepIndex = (sweepIndex <= 0) ? count - 1 : sweepIndex - 1;
  } else if (action == 2) {
    sweepIndex = (sweepIndex + 10) % count;
  }
  sendCurrent();
  updateStatus();
}

static void createButton(lv_obj_t* tab, const char* text, int action) {
  lv_obj_t* button = lv_btn_create(tab);
  lv_obj_set_size(button, LV_PCT(100), 56);
  lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
  lv_obj_add_event_cb(button, scan_event_cb, LV_EVENT_CLICKED, (void*)(intptr_t)action);
  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, text);
  lv_obj_center(label);
}

void create_tab_content_philipsScan(lv_obj_t* tab) {
  buildSweepList();
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);
  lv_obj_set_style_pad_all(tab, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(tab, 2, LV_PART_MAIN);

  statusLabel = lv_label_create(tab);
  lv_obj_set_width(statusLabel, LV_PCT(100));
  updateStatus();

  createButton(tab, "Next (send)", 0);
  createButton(tab, "Resend", 3);
  createButton(tab, "Previous (send)", 1);
  createButton(tab, "Skip 10 (send)", 2);
}

void notify_tab_before_delete_philipsScan(void) {
  statusLabel = NULL;
}

void register_gui_philipsScan(void) {
  register_gui(std::string(tabName_philipsScan), & create_tab_content_philipsScan, & notify_tab_before_delete_philipsScan);
}
