#include <kipr/botball.h>
#include "wj.h"
#define ARMPORT 0
#define ARMDOWN 200 
#define ARMUP 1780
// when calling create spin
// 3000 ms at 100 velocity is a half turn

// make sure to add the tournament light stuff
int main(){
printf("hello");
// connect to the roomba
create_connect();
moveServo(ARMPORT, ARMDOWN, 1000);
// asuming starts next to balls
moveServo(ARMPORT, ARMUP, 2000);
msleep(3000);
// drive towards the transporter


create_stop();


// then do stuff
return 1;
}
