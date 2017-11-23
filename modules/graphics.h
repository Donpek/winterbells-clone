#ifndef GRAPHICS
#define GRAPHICS
//
#include "logger.h"
#include <SDL.h>
//
#define WINDOW_TITLE "Winter Bells"
#define WINDOW_WIDTH 256
#define WINDOW_HEIGHT 512
#define WINDOW_X 0
#define WINDOW_Y 0
//
SDL_Window *win;
SDL_Renderer *ren;
//
void graphics_quit();
void graphics_init();
//
#endif
