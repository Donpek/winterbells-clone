#include "winterbells.h"
//
int main(int argc, char *argv[]){
  SDL_Init(0);
  logger_init();
  graphics_init();
  physics_init();
  input_init();
  random_init();
  game_load();
  camera_init();
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
  SDL_RenderClear(ren);
  stage_draw();
  player_draw();
  bells_draw();
  SDL_RenderPresent(ren);
}
//
void game_load(){
  stage_load();
  player_load();
  bells_load();
  game_mode = GAMEMODE_START;
}
void game_unload(){
  stage_unload();
  player_unload();
  bells_unload();
}
//
void game_update(){
  if(input_update() == INPUT_QUIT_APPLICATION){
    game_mode = GAMEMODE_QUIT; return;
  }
  physics_update();
  bells_update();
  player_update();
  camera_update();
}
