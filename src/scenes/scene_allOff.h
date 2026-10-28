#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_ALLOFF;
extern uint16_t SCENE_ALLOFF_FORCE;
extern std::string scene_name_allOff;

void register_scene_allOff(void);
void scene_start_sequence_allOff(void);
void scene_end_sequence_allOff(void);