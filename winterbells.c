#include "winterbells.h"
//
int main(int argc, char *argv[]){
  SDL_Init(0);
  logger_init();
  graphics_init();
  physics_init();
  game_load();
  while(game_mode != GAMEMODE_QUIT){
    game_update();
    game_draw();
    /*SDL_Delay(5000);
    log_debug("Hello, world!");
    game_mode = GAMEMODE_QUIT;*/
  }
  game_unload();
  graphics_quit();
  logger_quit();
  SDL_Quit();
  return 0;
}
//
void game_draw(){
  stage_draw();
  player_draw();
  SDL_RenderPresent(ren);
}
//
void game_load(){
  stage_load();
  player_load();
  game_mode = GAMEMODE_START;
}
void game_unload(){
  stage_unload();
  player_unload();
}
//
void game_update(){
  if(input_update() == INPUT_QUIT_APPLICATION){
    game_mode = GAMEMODE_QUIT; return;
  }
  physics_update();
  player_update();
}
