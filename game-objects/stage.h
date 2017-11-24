#ifndef STAGE
#define STAGE
//
#include "../modules/graphics.h"
//
#define GROUND_DEFAULT_Y WINDOW_HEIGHT - 150
//
SDL_Texture *tex_bg;
SDL_Texture *tex_ground;
struct{
  Sint16 y;
} ground;
//
void stage_draw();
void stage_load();
void stage_unload();
//
#endif
