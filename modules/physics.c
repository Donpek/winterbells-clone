#include "physics.h"
//
void physics_init(){
  curr_tick = SDL_GetPerformanceCounter();
}
void physics_update(){
  prev_tick = curr_tick;
  curr_tick = SDL_GetPerformanceCounter();
  delta_time = (curr_tick - prev_tick) * 1000 /
    (double)SDL_GetPerformanceFrequency();
}
//
Vector2 vector2_add(Vector2 v1, Vector2 v2){
  v1.x += v2.x;
  v1.y += v2.y;
  return v1;
}
Vector2 vector2_mul(Vector2 v, Sint32 constant){
  v.x *= constant;
  v.y *= constant;
  return v;
}
