#include <stdio.h>
#include <kipr/botball.h>

// moves at a set velocity
// vel is in ticks  per second
// goes from -1500 to 1500 ticks
// need to meausre ticks to wheel diameter
// wheel circumference is 3.5 cm
// 6.5 cm at 500 ticks per second
// 0.013 ticks per centimeter
// 1 centimeter is 80 ticks
// time is in milliseconds
// assumes that port 2 is facing the direction opposite to the motion
int moveWheels(int port1, int port2,  int time, int vel){
mav(port1, vel);
mav(port2, -vel);
msleep(time);
return 1;
}
// opens the servo 
// at a given position
// to a given tick mark
// tick supposedly between 0 and 2047, but dont go that high
// time is time given to let the claw open
// this differs for different amounts, trial and error ig
int moveServo(int port, int pos, int time){
enable_servo(port);
set_servo_position(pos);
msleep(time);
disable_servo(port);
return 1;
}

// moves a specified motor for given time
// time is measured in milliseconds
// velocity is in ticks per second
// ticks can be given from -1500 to 1500
int moveMotor(int port, int vel, int time){
mav(port, vel);
msleep(time);

}
