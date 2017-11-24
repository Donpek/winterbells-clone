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
#define PLAYER_MASS 1
#define PLAYER_MOUSE_ACCELERATION_SCALAR 0.000005
#define PLAYER_FRICTION 0.05
#define PLAYER_GRAVITY PHYSICS_GRAVITY * PLAYER_MASS
#define PLAYER_JUMP_FORCE 0.025
//
SDL_Texture *tex_rabbit;
struct{
  Vector2 pos;
  int w, h;
  Vector2 acceleration, velocity;
  float mass;
  Uint8 on_ground;
} player;
//
void player_draw();
void player_load();
void player_unload();
void player_update();
//
bool player_is_colliding_with_ground();
bool player_is_colliding_with_left_side();
bool player_is_colliding_with_right_side();
//
#endif
