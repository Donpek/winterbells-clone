#ifndef STAGE
#define STAGE
//
#include "../modules/graphics.h"
//

//
SDL_Texture *bg;
SDL_Texture *ground;
//
void stage_draw();
void stage_load();
void stage_unload();
//
#endif
