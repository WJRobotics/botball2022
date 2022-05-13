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
create_drive_straight(-100);
 msleep(700);
//create_drive_straight(100);
//msleep(1500); // gets the roomba over the first black line
    create_stop();
while(analog(0)<3500){
	    create_drive_straight(100); // until it hits the second line keep moving forward
}
    msleep(1600);
    create_stop();
    // once it finds the line, pivot so its facing the transporter
    create_spin_CW(100);
    msleep(1500); // should be a quarter revolution
    create_stop();
    
while(analog(0)<3500){
    // keep driving straight until it hits the line in front of the gate
    create_drive_straight(100);
}
    msleep(1200); // puts the center on the line
    
    create_stop();
    create_spin_CCW(100);
    msleep(1500); // another quarter turn so that it faces the gate
    create_drive_straight(100);
    msleep(1000); // move into the gate
    create_stop();
    // then lift the gate
    
    // add lift code
    // backup to get on the line
    create_drive_straight(-100);
    msleep(1200);
    create_stop();
    create_spin_CW(100);
    msleep(1500);
    create_drive_straight(200);
    msleep(2000);
    
ao();
create_stop();
create_disconnect();

// then do stuff
return 1;
}
