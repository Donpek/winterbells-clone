#ifndef WINTERBELLS
#define WINTERBELLS
//
#include "modules/logger.h"
#include "modules/graphics.h"
#include "game-objects/stage.h"
//
#define GAMEMODE_QUIT 0
#define GAMEMODE_START 1
#define GAMEMODE_GAME 2
#define GAMEMODE_RESTART 3
#define GAMEMODE_PAUSE 4
#define GAMEMODE_HIGHSCORES 5
//
typedef unsigned char Uint8;
typedef unsigned char bool;
enum{false,true};
//
Uint8 game_mode;
//
void game_update();
void game_draw();
void game_load_textures();
void game_unload_textures();
//
#endif
