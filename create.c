#include <kipr/botball.h>
#include "wj.h"
#define ARMPORT 0
#define ARMUP 1500
#define ARMDOWN 200


int main(){
  // connect to the roomba
  create_connect();
  // do the other stuff
  moveServo(ARMPORT, ARMDOWN);
  
  moveServo(ARMPORT, ARMUP);
  
  create_drive(300, 0);
  msleep(2000);
  create_stop();
  
  return 1;
  {
