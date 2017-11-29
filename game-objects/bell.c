#include "bell.h"
//
void bells_draw(){
  int i;
  for(i=0;i<BELL_MAX_BELLS_AT_ONCE;i++){
    graphics_render_texture_whole(tex_bell, bells[i].x, bells[i].y);
  }
}
void bells_load(){
  tex_bell = graphics_load_texture("assets/bell.bmp");
  int i, w, h;
  if(SDL_QueryTexture(tex_bell, 0, 0, &w, &h) != 0){
    log_error_SDL("SDL_QueryTexture tex_bell");
  }
  for(i=0;i<BELL_MAX_BELLS_AT_ONCE;i++){
    bells[i].w = w;
    bells[i].h = h;
    bells[i].x = random_range(0, WINDOW_WIDTH - w);
    bells[i].y = BELL_DESPAWN_Y_LEVEL - (i + 1) * h;
  }
  bell_current_highest_index = BELL_MAX_BELLS_AT_ONCE -1;
}
void bells_unload(){
  SDL_DestroyTexture(tex_bell);
}
void bells_update(){
  int i;
  for(i=0;i<BELL_MAX_BELLS_AT_ONCE;i++){
    // non-player-driven despawning
    if(bells[i].y > BELL_DESPAWN_Y_LEVEL - bells[i].h
/*|| bells[i].y > camera.y + WINDOW_HEIGHT*/){
      bells[i].x = random_range(0, WINDOW_WIDTH - bells[i].w);
      bells[i].y = bells[bell_current_highest_index].y - bells[i].h;
      bell_current_highest_index = i;
    }
    // player-driven despawning
    else if(bells[i].x + bells[i].w/2 > player.pos.x &&
bells[i].x + bells[i].w/2 < player.pos.x + player.w &&
bells[i].y + bells[i].h/2 > player.pos.y &&
bells[i].y + bells[i].h/2 < player.pos.y + player.h){
      // TODO: add score and sfx, gfx
      bells[i].x = random_range(0, WINDOW_WIDTH - bells[i].w);
      bells[i].y = bells[bell_current_highest_index].y - bells[i].h;
      bell_current_highest_index = i;
      player.velocity.y = BELL_JUMP_BOOST_TO_PLAYER;
    }
    // gravity
    bells[i].y += BELL_GRAVITY;
  }

}
