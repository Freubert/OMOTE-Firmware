#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_FILMFERNSEHER;
// FORCE sends the start sequence again even if scene is already active
extern uint16_t SCENE_FILMFERNSEHER_FORCE;

extern std::string scene_name_filmFernseher;
void register_scene_filmFernseher(void);
