#ifndef AGAME_SPRITES_H
#define AGAME_SPRITES_H

#define BSIZE_SPR 16

typedef struct spr_rect {
	int x, y;
	int w, h;
} spr_rect;

typedef enum sprites {
	SPR_NONE,
    SPR_PLAYER_LVL1,
    SPR_PLAYER_LVL2,
	SPR_FLOOR,
	SPR_WALL,
	SPR_TWALL,
	SPR_LFLOOR,
	SPR_TFLOOR,
	SPR_DFLOOR,
	SPR_COIN,
	SPR_DLADDER,
	SPR_ENEMY1,
	SPR_ENEMY2,
	SPR_PIPE,
	SPR_PIPE2,
	SPR_MBRICK,
	SPR_GRATE,
	SPR_OOZE,
	SPR_OOZEF,
	SPR_SKULL,
	SPR_TORCH,
    SPR_FLAME_LVL1,
    SPR_FLAME_LVL2,
    SPR_POTION,
    SPR_POWERUP
} sprites_e;

static void load_sprite(sprites_e spr, spr_rect* src) {
	src->w = BSIZE_SPR;
	src->h = BSIZE_SPR;
	switch (spr) {
        case SPR_PLAYER_LVL1:
            src->x = 14 * BSIZE_SPR;
            src->y = 15 * BSIZE_SPR;
            break;
        case SPR_PLAYER_LVL2:
            src->x = 15 * BSIZE_SPR;
            src->y = 15 * BSIZE_SPR;
            break;
		case SPR_DFLOOR:
			src->x = 4 * BSIZE_SPR;
			src->y = 6 * BSIZE_SPR;
			break;
		case SPR_WALL:
			src->x = 1 * BSIZE_SPR;
			src->y = 1 * BSIZE_SPR;
			break;
		case SPR_LFLOOR:
			src->x = 4 * BSIZE_SPR;
			src->y = 7 * BSIZE_SPR;
			break;
		case SPR_COIN:
			src->x = 4 * BSIZE_SPR;
			src->y = 14 * BSIZE_SPR;
			break;
		case SPR_DLADDER:
			src->x = 5 * BSIZE_SPR;
			src->y = 14 * BSIZE_SPR;
			break;
		case SPR_TORCH:
			src->x = 6 * BSIZE_SPR;
			src->y = 10 * BSIZE_SPR;
			break;
		case SPR_ENEMY1:
			src->x = 2 * BSIZE_SPR;
			src->y = 9 * BSIZE_SPR;
			break;
		case SPR_ENEMY2:
			src->x = 2 * BSIZE_SPR;
			src->y = 10 * BSIZE_SPR;
			break;
		case SPR_PIPE:
			src->x = 4 * BSIZE_SPR;
			src->y = 0 * BSIZE_SPR;
			break;
		case SPR_MBRICK:
			src->x = 4 * BSIZE_SPR;
			src->y = 2 * BSIZE_SPR;
			break;
		case SPR_TFLOOR:
			src->x = 0 * BSIZE_SPR;
			src->y = 2 * BSIZE_SPR;
			break;
		case SPR_FLOOR:
			src->x = 2 * BSIZE_SPR;
			src->y = 3 * BSIZE_SPR;
			break;
		case SPR_GRATE:
			src->x = 4 * BSIZE_SPR;
			src->y = 1 * BSIZE_SPR;
			break;
		case SPR_OOZE:
			src->x = 3 * BSIZE_SPR;
			src->y = 1 * BSIZE_SPR;
			break;
		case SPR_OOZEF:
			src->x = 3 * BSIZE_SPR;
			src->y = 2 * BSIZE_SPR;
			break;
		case SPR_TWALL:
			src->x = 0 * BSIZE_SPR;
			src->y = 0 * BSIZE_SPR;
			break;
		case SPR_PIPE2:
			src->x = 3 * BSIZE_SPR;
			src->y = 0 * BSIZE_SPR;
			break;
		case SPR_SKULL:
			src->x = 1 * BSIZE_SPR;
			src->y = 3 * BSIZE_SPR;
			break;
        case SPR_FLAME_LVL1:
            src->x = 3 * BSIZE_SPR;
            src->y = 13 * BSIZE_SPR;
            break;
        case SPR_FLAME_LVL2:
            src->x = 2 * BSIZE_SPR;
            src->y = 13 * BSIZE_SPR;
			break;
        case SPR_POTION:
            src->x = 12 * BSIZE_SPR;
            src->y = 11 * BSIZE_SPR;
            break;
        case SPR_POWERUP:
            src->x = 2 * BSIZE_SPR;
            src->y = 12 * BSIZE_SPR;
            break;
		default:
			src->x = 0 * BSIZE_SPR;
			src->y = 0 * BSIZE_SPR;
	}
}

#endif