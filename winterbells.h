#ifndef WINTERBELLS
#define WINTERBELLS
//
#include "modules/typedefs.h"
#include "modules/logger.h"
#include "modules/graphics.h"
#include "modules/input.h"
#include "modules/physics.h"
#include "modules/random.h"
#include "game-objects/stage.h"
#include "game-objects/player.h"
#include "game-objects/bell.h"
//
#define GAMEMODE_QUIT 0
#define GAMEMODE_START 1
#define GAMEMODE_GAME 2
#define GAMEMODE_RESTART 3
#define GAMEMODE_PAUSE 4
#define GAMEMODE_HIGHSCORES 5
//
Uint8 game_mode;
//
void game_update();
void game_draw();
void game_load();
void game_unload();
//
#endif
