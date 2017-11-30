#include "camera.h"
//
void camera_init(){
  camera.y = 0;
}
void camera_update(){
  camera.y = player.pos.y - ground.y;
}
