#ifndef AGAME_MACRO_DEFINITIONS_H
#define AGAME_MACRO_DEFINITIONS_H

#define TARGET_FPS 60
#define WINDOW_TITLE "AD232 - Aleksandar Stojadinovic #3641"
// screen size
#define WIDTH (1024)
#define HEIGHT (768)

// apparent block size on the screen
#define BSIZE (32)

// blocks count in the viewport
#define SCR_W (WIDTH / BSIZE)
#define SCR_H (HEIGHT / BSIZE)
#define WRLD_W (3)
#define WRLD_H (2)

#define LVL_W (WRLD_W * SCR_W)
#define LVL_H (WRLD_H * SCR_H)

#define False 0
#define True 1

#define FONT_RES "res/UbuntuMono-R.ttf"
#define SPRITES_RES "res/sprites.png"
#define MENUBG_RES "res/menuBG.jpg"
#define MUSIC_RES "res/music.wav"
#define SHOOT_RES "res/fireball.wav"
#define STEP_RES "res/step.wav"



#endif