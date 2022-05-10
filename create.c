#include <kipr/botball.h>
#include <stdio.h>
#define ARMPORT 0
#define ARMDOWN 200 
#define ARMUP 1780
// when calling create spin
// 3000 ms at 100 velocity is a half revolution

// make sure to add the tournament light stuff
int main(){
printf("hello");
// connect to the roomba
create_connect();
//wait_for_light(0); // starts when the light turns on
//shut_down_in(118); // makes sure everything turns off within the timelimit
// the lifter arm should start at position 2000
enable_servo(0);
set_servo_position(0, 50); // drops the right side of the plow and sets up to lift the thing later
msleep(1000);
create_spin_CW(100); // spins the roomba to face the door
msleep(500);
create_stop();
create_drive_straight(400); // drives towards the door
msleep(2000);
create_stop();
create_spin(100);
create_drive_straight(100);
msleep(500);
create_stop();
    
set_servo_position(0, 2010); // resets the arm servo
msleep(1000);
disable_servo(0);
ao();
create_stop();
create_disconnect();

// then do stuff
return 1;
}
