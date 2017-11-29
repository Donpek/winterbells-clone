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
  player.acceleration = player.velocity;
  player.mass = PLAYER_MASS;
  player.on_ground = false;
}
void player_unload(){
  SDL_DestroyTexture(tex_rabbit);
}
void player_update(){
  if(!player.on_ground){
    player.acceleration.y += PLAYER_GRAVITY;
  }
  // horizontal movement
  player.acceleration.x +=
    (mouse.x - (player.pos.x + player.w/2)) * PLAYER_MOUSE_ACCELERATION_SCALAR;

  // jumping
  if(mouse.curr_click && !mouse.prev_click && player.on_ground){
    log_debug("jmp");
    player.acceleration.y += PLAYER_JUMP_FORCE;
  }

  // first integration
  player.velocity = vector2_add(
    player.velocity,
    vector2_mul(player.acceleration, delta_time)
  );

  // friction
  player.velocity.x -= player.velocity.x *
    PLAYER_FRICTION;

  // collision detection against stage
  if(!player.on_ground && player_is_colliding_with_ground()){
    player.velocity.y = 0;
    player.on_ground = true;
  }else{player.on_ground = false;}
  if(player_is_colliding_with_right_side()){
    player.pos.x = WINDOW_WIDTH - player.w;
  }else if(player_is_colliding_with_left_side()){
    player.pos.x = 0;
  }

  // second integration
  player.pos = vector2_add(
    player.pos,
    vector2_mul(player.velocity, delta_time)
  );
  //
  player.acceleration.x = player.acceleration.y = 0;
}
//
bool player_is_colliding_with_ground(){
  return player.pos.y > ground.y;
}
bool player_is_colliding_with_right_side(){
  return player.pos.x > WINDOW_WIDTH - player.w;
}
bool player_is_colliding_with_left_side(){
  return player.pos.x < 0;
}
