#include "winterbells.h"
//

//
#define GAMEMODE_START 0
#define GAMEMODE_GAME 1
#define GAMEMODE_RESTART 2
#define GAMEMODE_PAUSE 3
//
int main(int argc, char *argv[]){
  /* init */
  SDL_Init(0);
  logger_init();
  graphics_init();
  // input_init();
  // sound_init();
  // text_init();

  log_debug("Hello, world!");
  /* loop */
    /* update
    // draw */

  /* clean-up */
  graphics_quit();
  logger_quit();
  SDL_Quit();
  return 0;
}
