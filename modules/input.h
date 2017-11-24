#ifndef INPUT
#define INPUT
//
#include <SDL.h>
//
#define INPUT_QUIT_APPLICATION 1
//
struct{
  Sint16 x, y;
} mouse;
//
int input_update();
//
#endif
