#include <map>
#include "scenes/scene_devicePower.h"

static std::map<std::string, uint8_t> requiredDevices;
static std::string transitionOld;
static std::string transitionNew;

static uint8_t required(const std::string& sceneName) {
  auto it = requiredDevices.find(sceneName);
  return (it == requiredDevices.end()) ? 0 : it->second;
}

void scene_setRequiredDevices(const std::string& sceneName, uint8_t devices) {
  requiredDevices[sceneName] = devices;
}

void scene_devicePower_setTransition(const std::string& oldScene, const std::string& newScene) {
  transitionOld = oldScene;
  transitionNew = newScene;
}

uint8_t scene_devicesToPowerOn(const std::string& ownScene) {
  return required(ownScene) & ~required(transitionOld);
}

uint8_t scene_devicesToPowerOff(const std::string& ownScene) {
  return required(ownScene) & ~required(transitionNew);
}
