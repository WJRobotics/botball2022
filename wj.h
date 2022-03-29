#include <stdio.h>
#include <kipr/botball.h>

//used for stop on black line
//measures the initial height and color
#define BLACK_TAPE 3900


int detectBlack(int tophat){
if(analog(tophat)<4000){
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
	if(stopAtBlackLine(0) == 0) {
		mav(port1, vel);
		mav(port2, -vel);
		msleep(time);
	}else{
	freeze(port1);
	freeze(port2);}
}

int goTillBlack(int port1, int port2, int vel){
while(stopAtBlackLine()!=1){
	printf("analog %d \n", analog(0));
	mav(port1, vel);
	mav(port2, -vel);

}
freeze(port1);
freeze(port2);

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

// turns the robot in place
// time in ms
// vel in ticks per second
// same conversion as move wheels

int turnPlace(int port1, int port2, int time, int vel){
	mav(port1, vel);
	mav(port2, vel);
	msleep(time);
}

int stopAtBlackLine(){
	//printf("analog 0: "+(String(analog(0)));
	if(analog(0) > (int)BLACK_TAPE){ // why broke????
// stop the stuff
		return 1;
	}
// dont stop the stuff
	return 0;
}
//
