#ifndef GRAPHICS
#define GRAPHICS
//
#include "logger.h"
#include <SDL.h>
//
#define WINDOW_TITLE "Winter Bells"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_X 0
#define WINDOW_Y 0
//
SDL_Window *win;
SDL_Renderer *ren;
//
void graphics_quit();
void graphics_init();
void graphics_render_texture_whole(SDL_Texture *tex, int x, int y);
SDL_Texture *graphics_load_texture(char *filepath);
//
#endif
