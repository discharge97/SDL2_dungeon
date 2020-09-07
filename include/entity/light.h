#ifndef AGAME_LIGHT_H
#define AGAME_LIGHT_H


#pragma once

#include "entity/entity.h"

float light_calc(entity_t* source, int x, int y, float current_light, state_t* state);

#endif //AGAME_LIGHT_H
