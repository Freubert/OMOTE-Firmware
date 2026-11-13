#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_WIIUFERNSEHER;
// FORCE sends the start sequence again even if scene is already active
extern uint16_t SCENE_WIIUFERNSEHER_FORCE;

extern std::string scene_name_wiiUFernseher;
void register_scene_wiiUFernseher(void);
