#include "random.h"
//
void random_init(){
  srand(time(0));
}
int random_range(int from, int to){
  return rand() % (to-from+1) + from;
}
