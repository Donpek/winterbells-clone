#include "stage.h"
//
void stage_draw(){
  graphics_render_texture_whole(bg, 0, 0);
  graphics_render_texture_whole(ground, 0, 0);
}
//
void stage_load(){
  bg = graphics_load_texture("assets/bg.bmp");
  ground = graphics_load_texture("assets/ground.bmp");
}
//
void stage_unload(){
  SDL_DestroyTexture(bg);
  SDL_DestroyTexture(ground);
}
