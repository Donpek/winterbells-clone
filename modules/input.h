#ifndef INPUT
#define INPUT
//
#include <SDL.h>
#include "typedefs.h"
//
#define INPUT_QUIT_APPLICATION 1
//
struct{
  Sint16 x, y;
  Uint8 prev_click, curr_click;
} mouse;
//
void input_init();
int input_update();
//
#endif
