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
wait_for_light(0);
create_drive_straight(100);
msleep(5000);
create_stop();
create_disconnect();

// then do stuff
return 1;
}
