#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_FILMLEINWAND;
// FORCE sends the start sequence again even if scene is already active
extern uint16_t SCENE_FILMLEINWAND_FORCE;

extern std::string scene_name_filmLeinwand;
void register_scene_filmLeinwand(void);
