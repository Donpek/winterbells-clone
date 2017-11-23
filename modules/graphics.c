#include "graphics.h"
//
// SDL_Texture *load_texture(char *file, SDL_Renderer *renderer, FILE *fp){
//   SDL_Texture *texture = NULL;
//   SDL_Surface *loaded_image = SDL_LoadBMP(file);
//   if(loaded_image == NULL){
//     logSDLError(fp,"SDL_LoadBMP");
//   }else{
//     texture = SDL_CreateTextureFromSurface(renderer,loaded_image);
//     SDL_FreeSurface(loaded_image);
//     if(texture == NULL){
//       logSDLError(fp,"SDL_CreateTextureFromSurface");
//     }
//   }
//   return texture;
// }
void graphics_quit(){
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
}
// void render_whole_texture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
//   SDL_Rect dst;
//   dst.x = x; dst.y = y;
//   SDL_QueryTexture(tex,NULL,NULL,&dst.w,&dst.h);
//   SDL_RenderCopy(ren,tex,NULL,&dst);
// }
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
