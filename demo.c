#include <stdio.h>
#include <kipr/botball.h>
#include "wj.h"

int main(){
printf("stuff");
//turnOneWheel(0,100,180);
//turn();

/*wait_for_light(0);
motor(0, 300);
msleep(1000);
ao();*/

moveServo(0, 200, 1000);
moveServo(0, 1000, 1000);
return 1;
}
