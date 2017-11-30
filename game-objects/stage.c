#include "stage.h"
//
void stage_draw(){
  graphics_render_texture_whole(tex_bg, 0, 0);
  graphics_render_texture_whole(tex_ground, 0, -camera.y);
}
//
void stage_load(){
  tex_bg = graphics_load_texture("assets/bg.bmp");
  tex_ground = graphics_load_texture("assets/ground.bmp");
  ground.y = GROUND_DEFAULT_Y;
}
//
void stage_unload(){
  SDL_DestroyTexture(tex_bg);
  SDL_DestroyTexture(tex_ground);
}
