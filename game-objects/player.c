#include "player.h"
//
void player_draw(){
  graphics_render_texture_whole(tex_rabbit, player.x, player.y);
}
void player_load(){
  tex_rabbit = graphics_load_texture("assets/rabbit.bmp");
  player.x = WINDOW_WIDTH/2;
  player.y = GROUND_DEFAULT_Y;
  if(SDL_QueryTexture(tex_rabbit, NULL, NULL, &player.w, &player.h) != 0){
    log_error_SDL("SDL_QueryTexture tex_rabbit");
  }
}
void player_unload(){
  SDL_DestroyTexture(tex_rabbit);
}
void player_update(){
  player.x = mouse.x - player.w/2;
}
