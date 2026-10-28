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

void register_scene_allOff(void) {
  register_command(&SCENE_ALLOFF, makeCommandData(SCENE, {scene_name_allOff}));
  register_command(&SCENE_ALLOFF_FORCE, makeCommandData(SCENE, {scene_name_allOff, "FORCE"}));

  // Register allOff scene - this simply turns off all devices
  register_scene(
    scene_name_allOff,
    NULL, // No key setup needed
    &scene_start_sequence_allOff,
    &scene_end_sequence_allOff,
    NULL, // No key repeat modes
    NULL, // No key commands short
    NULL, // No key commands long
    NULL, // No GUI list
    SCENE_ALLOFF
  );
}

void scene_start_sequence_allOff(void) {
  // Turn off all devices
  executeCommand(PHILIPS_POWER_OFF);
  delay(500);
  executeCommand(TEUFEL_POWER_OFF);
  delay(500);
  executeCommand(ATHEN_POWER_OFF);
  delay(500);
  executeCommand(EPSON_POWER_OFF);
  delay(500);
}

void scene_end_sequence_allOff(void) {
  // No special end sequence needed
}