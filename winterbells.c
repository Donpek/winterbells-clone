#include "winterbells.h"
//
int main(int argc, char *argv[]){
  SDL_Init(0);
  logger_init();
  graphics_init();
  game_load_textures();
  game_mode = GAMEMODE_START;
  while(game_mode != GAMEMODE_QUIT){
    game_update();
    game_draw();
    SDL_Delay(5000);
    log_debug("Hello, world!");
    game_mode = GAMEMODE_QUIT;
  }
  game_unload_textures();
  graphics_quit();
  logger_quit();
  SDL_Quit();
  return 0;
}
//
void game_draw(){
  stage_draw();
  SDL_RenderPresent(ren);
}
//
void game_load_textures(){
  stage_load();
}
void game_unload_textures(){
  stage_unload();
}
//
void game_update(){}
