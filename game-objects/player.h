#ifndef PLAYER
#define PLAYER
//
#include "../modules/graphics.h"
#include "../modules/input.h"
#include "../modules/logger.h"
#include "stage.h"
//
SDL_Texture *tex_rabbit;
struct{
  Sint16 x, y;
  int w, h;
} player;
//
void player_draw();
void player_load();
void player_unload();
void player_update();
//
#endif
