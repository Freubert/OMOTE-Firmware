#include <map>
#include "scenes/scene_sequence.h"
#include "scenes/scene_allOff.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "devices/TV/device_philipsTV/device_philipsTV.h"
#include "devices/AVreceiver/device_teufelSConcept/device_teufelSConcept.h"
#include "devices/AVreceiver/device_athenVS482/device_athenVS482.h"
#include "devices/projector/device_epsonProjector/device_epsonProjector.h"

uint16_t SCENE_ALLOFF;
uint16_t SCENE_ALLOFF_FORCE;
std::string scene_name_allOff = "allOff";

// The scene registry dereferences these without null checks, so they must exist, even if empty.
std::map<char, repeatModes> key_repeatModes_allOff;
std::map<char, uint16_t> key_commands_short_allOff;
std::map<char, uint16_t> key_commands_long_allOff;

void scene_setKeys_allOff() {
  key_repeatModes_allOff = {};
  key_commands_short_allOff = {};
  key_commands_long_allOff = {};
}

void register_scene_allOff(void) {
  register_command(&SCENE_ALLOFF, makeCommandData(SCENE, {scene_name_allOff}));
  register_command(&SCENE_ALLOFF_FORCE, makeCommandData(SCENE, {scene_name_allOff, "FORCE"}));

  // Register allOff scene - this simply turns off all devices
  register_scene(
    scene_name_allOff,
    &scene_setKeys_allOff,
    &scene_start_sequence_allOff,
    &scene_end_sequence_allOff,
    &key_repeatModes_allOff,
    &key_commands_short_allOff,
    &key_commands_long_allOff,
    NULL, // No GUI list
    SCENE_ALLOFF
  );
}

void scene_start_sequence_allOff(void) {
  // Turn off all devices. The Teufel only has a toggle command, so it is switched off by the end sequence of the Fernsehen scene.
  sequence_add(PHILIPS_POWER_OFF, 500);
  sequence_add(EPSON_POWER_OFF, 500);
  // the Athen does not react while the TV / projector is shutting down, so it goes last after a pause
  sequence_wait(5000);
  sequence_add(ATHEN_POWER_OFF, 500);
}

void scene_end_sequence_allOff(void) {
  // No special end sequence needed
}
