#include <stdio.h>
#include <kipr/botball.h>
//#include <decimal.h>

//used for stop on black line
//measures the initial height and color
#define BLACK_TAPE (3900)
#define WHEEL_TO_WHEEL (16.25)
//  ^ is the distance between each wheel on jimmy in centimeters
// if the color reading from the tophat 
// if its greater than the tape value
// returns 1, else returns 0
int detectBlack(int tophat){
if(analog(tophat) > (int) (BLACK_TAPE) ){
return 1;
}
return 0;
}


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
// moves both wheels in the same direction
int moveWheels(int port1, int port2, int time, int vel){
return 1;
}
// go till analog 0 detects a color over 3900 on a tophat
int goTillBlack(int port1, int port2, int vel){
printf("analog %d /n", analog(0));
while(detectBlack(0)==0){
	printf("analog %d \n", analog(0));
	mav(port1, vel);
	mav(port2, -vel);

}
freeze(port1);
freeze(port2);
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
	return 1;
}
// 16.25 centimeters is the distance from one wheel to another
// wheel circumference is 3.5cm
// C = 2(pi)r, so full circumference of single wheel turn is about
// 102.10176 cm
// quarter circle is 25.5254 cm
// turn decimal is how much of a circle the robot should turn
//  given velocity determines the direction
// but is also impacted by the wheel port given
int turnOneWheel(int port, int velocity, int turnDegree){
mav(port, velocity);
int time = (turnDegree*WHEEL_TO_WHEEL) / velocity;
msleep(time);
freeze(port);
return 1;
}

