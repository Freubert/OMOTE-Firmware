#include <map>
#include "scenes/scene_directDeviceControl.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "scenes/gui_deviceMenu.h"
#include "scenes/scene__default.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_philipsTV/device_philipsTV.h"
// guis
#include "devices/TV/device_philipsTV/gui_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/gui_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/gui_athenVS482.h"
#include "devices/projector/device_epsonProjector/gui_epsonProjector.h"
#include "devices/mediaPlayer/device_kodi/gui_kodi.h"

uint16_t SCENE_DIRECT_DEVICE_CONTROL;
uint16_t SCENE_DIRECT_DEVICE_CONTROL_FORCE;

std::map<char, repeatModes> key_repeatModes_directDeviceControl;
std::map<char, uint16_t> key_commands_short_directDeviceControl;
std::map<char, uint16_t> key_commands_long_directDeviceControl;

std::string scene_name_directDeviceControl = "Geräte";
t_gui_list scene_directDeviceControl_gui_list = {tabName_deviceMenu, tabName_philipsTV, tabName_epsonProjector, tabName_teufelSConcept, tabName_athenVS482, tabName_kodi};

// All keys are unused (default keys apply), except BACK which goes to the scene selection
void scene_setKeys_directDeviceControl() {
  key_repeatModes_directDeviceControl = {
    {KEY_BACK,  SHORT            },
  };

  key_commands_short_directDeviceControl = {
    {KEY_BACK,  SCENE_SELECTION  },
  };

  key_commands_long_directDeviceControl = {};
}

void scene_start_sequence_directDeviceControl(void) {
  // No specific start sequence needed for direct control
}

void scene_end_sequence_directDeviceControl(void) {
  // No specific end sequence needed for direct control
}

void register_scene_directDeviceControl(void) {
  register_command(&SCENE_DIRECT_DEVICE_CONTROL, makeCommandData(SCENE, {scene_name_directDeviceControl}));
  register_command(&SCENE_DIRECT_DEVICE_CONTROL_FORCE, makeCommandData(SCENE, {scene_name_directDeviceControl, "FORCE"}));

  register_scene(
    scene_name_directDeviceControl,
    &scene_setKeys_directDeviceControl,
    &scene_start_sequence_directDeviceControl,
    &scene_end_sequence_directDeviceControl,
    &key_repeatModes_directDeviceControl,
    &key_commands_short_directDeviceControl,
    &key_commands_long_directDeviceControl,
    &scene_directDeviceControl_gui_list,
    SCENE_DIRECT_DEVICE_CONTROL);
}
