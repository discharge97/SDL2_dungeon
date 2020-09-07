#ifndef AGAME_PLAYER_H
#define AGAME_PLAYER_H

#pragma once

#include <maze.h>
#include "entity.h"
#include "structs/arraylist.h"

extern entity_t player_new(int x, int y);

extern void player_shoot(entity_t* e, alist_t* entities);

extern void player_move(entity_t*, SDL_Scancode, maze_t* level);

extern void player_knockback(entity_t *e, maze_t *lvl);

#endif //AGAME_PLAYER_H
