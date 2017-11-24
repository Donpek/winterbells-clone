#ifndef PLAYER
#define PLAYER
//
#include "../modules/typedefs.h"
#include "../modules/graphics.h"
#include "../modules/input.h"
#include "../modules/logger.h"
#include "../modules/physics.h"
#include "stage.h"
//
#define PLAYER_DEFAULT_MASS 1
#define PLAYER_MOUSE_ACCELERATION_SCALAR 0.000005
#define PLAYER_FRICTION 0.05
//
SDL_Texture *tex_rabbit;
struct{
  Vector2 pos;
  int w, h;
  Vector2 acceleration, velocity;
  float gravity, mass;
} player;
//
void player_draw();
void player_load();
void player_unload();
void player_update();
//
bool player_is_within_stage();
void player_physics();
//
#endif
