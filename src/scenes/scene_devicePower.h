#pragma once

#include <string>
#include <stdint.h>

// Devices a scene needs powered on. Scenes declare them with scene_setRequiredDevices() and use
// scene_devicesToPowerOn() / scene_devicesToPowerOff() in their start / end sequences, so devices
// needed by both the old and the new scene are neither switched off nor toggled again.
enum : uint8_t {
  DEVICE_TV     = 1 << 0,
  DEVICE_TEUFEL = 1 << 1,
  DEVICE_ATHEN  = 1 << 2,
  DEVICE_EPSON  = 1 << 3,
  DEVICE_KODI   = 1 << 4,
};

void scene_setRequiredDevices(const std::string& sceneName, uint8_t devices);
// called by handleScene() right before the end sequence of the old scene
void scene_devicePower_setTransition(const std::string& oldScene, const std::string& newScene);
// devices of the new scene that were not already on in the old scene (use in start sequence)
uint8_t scene_devicesToPowerOn(const std::string& ownScene);
// devices of the old scene that the new scene does not need (use in end sequence)
uint8_t scene_devicesToPowerOff(const std::string& ownScene);
