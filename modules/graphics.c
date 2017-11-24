#include "graphics.h"
//
SDL_Texture *graphics_load_texture(char *filepath){
  SDL_Texture *texture = NULL;
  SDL_Surface *loaded_image = SDL_LoadBMP(filepath);
  if(loaded_image == NULL){
    log_error_SDL("SDL_LoadBMP");
  }else{
    texture = SDL_CreateTextureFromSurface(ren, loaded_image);
    SDL_FreeSurface(loaded_image);
    if(texture == NULL){
      log_error_SDL("SDL_CreateTextureFromSurface");
    }
  }
  return texture;
}
//
void graphics_quit(){
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
}
//
void graphics_render_texture_whole(SDL_Texture *tex, int x, int y){
  SDL_Rect dst = {x, y, 0, 0};
  SDL_QueryTexture(tex,NULL,NULL,&dst.w,&dst.h);
  SDL_RenderCopy(ren,tex,NULL,&dst);
}
//
void graphics_init(){
  if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0){
    log_error_SDL("SDL_INIT_VIDEO");
  }
  win = SDL_CreateWindow(
    WINDOW_TITLE, WINDOW_X, WINDOW_Y,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  if(win == NULL){
    log_error_SDL("SDL_CreateWindow");
  }
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
  if(ren == NULL){
    log_error_SDL("SDL_CreateRenderer");
  }
}
// void draw_rect(SDL_Renderer *r, int x, int y, int w, int h){
//   SDL_Rect rect = {x,y,w,h};
//   SDL_RenderFillRect(r,&rect);
// }
