#ifndef BELL
#define BELL
//
#include "../modules/typedefs.h"
#include "../modules/graphics.h"
#include "../modules/random.h"
#include "player.h"
//
#define BELL_GRAVITY 1
#define BELL_MAX_BELLS_AT_ONCE 20
#define BELL_DESPAWN_Y_LEVEL WINDOW_HEIGHT * 1/2
#define BELL_JUMP_BOOST_TO_PLAYER -1
//
SDL_Texture *tex_bell;
struct Bell{
  Sint32 x, y;
  Uint16 w, h;
} bells[BELL_MAX_BELLS_AT_ONCE];
Uint8 bell_current_highest_index;
//
void bells_draw();
void bells_load();
void bells_unload();
void bells_update();
//
#endif
