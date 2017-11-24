#ifndef PHYSICS
#define PHYSICS
//
#include <SDL.h>
#include "typedefs.h"
//
#define PHYSICS_GRAVITY 0.0005
//
typedef struct{
  float x, y;
} Vector2;
Uint64 curr_tick, prev_tick;
double delta_time;
//
void physics_update();
void physics_init();
//
Vector2 vector2_add(Vector2 v1, Vector2 v2);
Vector2 vector2_mul(Vector2 v, Sint32 constant);
//
#endif
