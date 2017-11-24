#include "player.h"
//
void player_draw(){
  graphics_render_texture_whole(tex_rabbit, player.pos.x, player.pos.y);
}
void player_load(){
  tex_rabbit = graphics_load_texture("assets/rabbit.bmp");
  player.pos.x = WINDOW_WIDTH/2;
  player.pos.y = 300;//GROUND_DEFAULT_Y;
  if(SDL_QueryTexture(tex_rabbit, NULL, NULL, &player.w, &player.h) != 0){
    log_error_SDL("SDL_QueryTexture tex_rabbit");
  }
  player.velocity.x = player.velocity.y = 0;
  player.acceleration = player.acceleration;
  player.mass = PLAYER_DEFAULT_MASS;
  player.gravity = PHYSICS_GRAVITY * player.mass;
}
void player_unload(){
  SDL_DestroyTexture(tex_rabbit);
}
void player_update(){
  //player.x = mouse.x - player.w/2;
  // if(mouse.x > 0 && mouse.x < WINDOW_WIDTH){
    player_physics();
  // }
}
//
bool player_is_colliding_with_ground(){
  return player.pos.y > GROUND_DEFAULT_Y;//ground.y;
}
bool player_is_colliding_with_sides(){
  return player.pos.x < 0 || player.pos.x > WINDOW_WIDTH - player.w;
}
void player_physics(){
  player.acceleration.x = player.acceleration.y = 0;
  //
  player.acceleration.y += player.gravity;
  player.acceleration.x +=
    (mouse.x - (player.pos.x + player.w/2)) * PLAYER_MOUSE_ACCELERATION_SCALAR;
  //
  player.velocity = vector2_add(
    player.velocity,
    vector2_mul(player.acceleration, delta_time)
  );
  player.velocity.x -= player.velocity.x *
    PLAYER_FRICTION;
  //
  if(player_is_colliding_with_ground()){player.velocity.y = 0;}
  if(player_is_colliding_with_sides()){player.velocity.x *= -1;}
  //
  player.pos = vector2_add(
    player.pos,
    vector2_mul(player.velocity, delta_time)
  );
}
