#include "entity/player.h"

void player_shoot(entity_t* e, alist_t* entities) {
	assert(e != (void*) 0);
	assert(e->type == E_PLAYER);
	if (e->player.next_shot > 0) {
		return;
	}
	entity_t newpew;
	newpew.x = e->x;
	newpew.y = e->y;
	newpew.hp = 10.0f;
    newpew.type = E_PEW;
    newpew.pew.dir = e->player.dir;
    newpew.pew.dmg = e->player.dmg;
    newpew.pew.lvl = e->player.lvl;
//    printf("lvl: %d\n", e->player.lvl);
    switch (newpew.pew.lvl) {
        case 2:
            newpew.sprite = SPR_FLAME_LVL2;
            break;
        default:
            newpew.sprite = SPR_FLAME_LVL1;
            break;
    }

    alist_add(entities, &newpew);
	e->player.next_shot = E_DEF_PNEXT_SHOT;
}

entity_t player_new(int x, int y) {
	entity_t newplayer;
	newplayer.x = x;
	newplayer.y = y;
	newplayer.hp = E_DEF_HP;
	newplayer.next_move = E_DEF_PNEXT_MOVE;
	newplayer.type = E_PLAYER;
	newplayer.player.dmg = E_DEF_DMG;
	newplayer.player.next_shot = E_DEF_PNEXT_SHOT;
	newplayer.player.dir = DIR_DOWN;
	newplayer.player.lvl = 1;
	newplayer.sprite = SPR_PLAYER_LVL1;
	return newplayer;
}

void player_knockback(entity_t *e, maze_t *lvl){
    enum dir last_dir = e->player.dir;

    SDL_Scancode nextMove;

    switch (last_dir) {
        case DIR_UP:
            nextMove = SDL_SCANCODE_S;
            break;
        case DIR_DOWN:
            nextMove = SDL_SCANCODE_W;
            break;
        case DIR_LEFT:
            nextMove = SDL_SCANCODE_D;
            break;
        case DIR_RIGHT:
            nextMove = SDL_SCANCODE_A;
            break;
        default:break;
    }

    player_move(e, nextMove, lvl);
    e->player.dir = last_dir;
}


void player_move(entity_t* e, SDL_Scancode code, maze_t* level) {
	assert(e->type == E_PLAYER);
	switch (code) {
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			e->player.dir = DIR_UP;
			if (level->maze[((e->y - 1) * level->w) + e->x] != level->b_wall && e->next_move == 0) {
				e->y -= 1;
				e->next_move = E_DEF_PNEXT_MOVE;
			}
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			e->player.dir = DIR_LEFT;
			if (level->maze[(e->y * level->w) + e->x - 1] != level->b_wall && e->next_move == 0) {
				e->x -= 1;
				e->next_move = E_DEF_PNEXT_MOVE;
			}
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			e->player.dir = DIR_DOWN;
			if (level->maze[((e->y + 1) * level->w) + e->x] != level->b_wall && e->next_move == 0) {
				e->y += 1;
				e->next_move = E_DEF_PNEXT_MOVE;
			}
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			e->player.dir = DIR_RIGHT;
			if (level->maze[(e->y * level->w) + e->x + 1] != level->b_wall && e->next_move == 0) {
				e->x += 1;
				e->next_move = E_DEF_PNEXT_MOVE;
			}
			break;
		default:
			break;
	}

	if(level->pickups[(e->y * level->w) + e->x] == P_POTION){
        level->pickups[(e->y * level->w) + e->x] = P_NONE;
        e->hp += P_HP_LEVEL1;
    }else if(level->pickups[(e->y * level->w) + e->x] == P_POWERUP){
        level->pickups[(e->y * level->w) + e->x] = P_NONE;
        e->player.dmg += P_DMG_LEVEL1;
        e->player.lvl++;

        switch (e->player.lvl) {
            case 1:
                e->sprite = SPR_PLAYER_LVL1;
                break;

            case 2:
                e->sprite = SPR_PLAYER_LVL2;
                break;

            default:
                break;
        }
    }

}
