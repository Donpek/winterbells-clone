#ifndef CAMERA
#define CAMERA
//
#include "../game-objects/player.h"
#include "../game-objects/stage.h"
#include "typedefs.h"
//
//
struct Camera{
  Sint32 y;
} camera;
//
void camera_init();
void camera_update();
//
#endif
