#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_FERNSEHEN;
// FORCE sends the start sequence again even if scene is already active
extern uint16_t SCENE_FERNSEHEN_FORCE;

extern std::string scene_name_fernsehen;
void register_scene_fernsehen(void);
