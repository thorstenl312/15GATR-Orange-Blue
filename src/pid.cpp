#include "pid.h"
#include <iostream>
void forwardPID(float pos, int maxPower, int tim, float decel, int lowSpeed, bool closeEarly, int closer) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  encode.resetRotation();
	while (t<tim) {
		error = (pos-encode.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 650 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp, D = derivative * kd, I = totalerror * ki;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=70 && error>100) speed=fabs(FrontL.velocity(rpm))+70; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 100 || error < 30)) speed = 0;
    if(error < pos/decel && FrontL.velocity(rpm)>lowSpeed) speed=FrontL.velocity(rpm)-80;
    if(error < pos/decel && (fabs(FrontL.velocity(rpm)) < lowSpeed || speed < lowSpeed)) speed = lowSpeed;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    if(closeEarly && error < closer){
      pneum.open();
    }
    if(error>150) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(hold);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Encoder: %ld\n", encode.value());

}
void forwardPIDFAST(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  encode.resetRotation();
	while (t<tim) {
		error = (pos-encode.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 600 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 0.6, D = derivative * kd, I = totalerror * ki * 0;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=70 && error>100) speed=fabs(FrontL.velocity(rpm))+70; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 100 || error < 30)) speed = 0;
    if(error < pos/2.5 && FrontL.velocity(rpm)>80) speed=FrontL.velocity(rpm)-80;
    if(error < pos/2.5 && (fabs(FrontL.velocity(rpm)) < 80 || speed < 80)) speed = 80;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    if(error > 150) t = 0;
    t = t+15;
		wait(15, msec);
    if(error < 300)pneum.open();
  }
	//Stops motor to ensure accuracy
  stopDrive(hold);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Encoder: %ld\n", encode.value());

}
void forwardPID2(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  encode.resetRotation();
	while (t<tim) {
		error = (pos-encode.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 600 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 0.5, D = derivative * kd, I = totalerror * ki *0.8;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=70 && error>100) speed=fabs(FrontL.velocity(rpm))+70; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 100)) speed = 0;
    if(error < pos/2.4 && FrontL.velocity(rpm)>80) speed=FrontL.velocity(rpm)-80;
    if(error < pos/2.4 && (fabs(FrontL.velocity(rpm)) < 80 || speed < 80)) speed = 80;
    //std::cout << "Speed: " << speed << std::endl;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    if(error>150) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(hold);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Encoder: %ld\n", encode.value());

}
void backwardPID2(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  encode.setRotation(0, degrees);
	while (t<tim) {
		error = (pos+encode.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 600 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 0.2, D = derivative * kd*1, I = totalerror * ki * 0;
    speed=P+I+D;
    if(speed>=maxPower)speed=maxPower;
    if((speed-fabs(FrontL.velocity(rpm)))>=50 && error>500) speed=fabs(FrontL.velocity(rpm))+50; //Acceleration 
    if(error < pos/2 && fabs(FrontL.velocity(rpm)) > 40) speed=fabs(FrontL.velocity(rpm))-80;
    if(error < pos/2 && (fabs(FrontL.velocity(rpm)) < 30 || speed < 30)) speed = 30;
    if(speed < 0 && ((fabs(error-pos) < 100))) speed = 0;
		rightDrive.spin(reverse, speed, rpm); //Give Power to Motors
    leftDrive.spin(reverse, speed, rpm);
		lasterror = error;
    if(error>150) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(hold);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Encoder: %ld\n", encode.value());

}
void backwardPID(float pos, int maxPower, int tim, float decel, int lowSpeed) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  encode.resetRotation();
  rollerSystem.stop(hold);
	while (t<tim) {
		error = (pos+encode.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 600 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 0.8, D = derivative * kd, I = totalerror * ki;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm))) >= 50 && error > 100) speed=fabs(FrontL.velocity(rpm)) + 50; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(error< pos/decel && fabs(FrontL.velocity(rpm))>50) speed=fabs(FrontL.velocity(rpm))-80; //Deceleration
    if(speed < 0 && (fabs(error-pos) < 100)) speed = 0;
    if(error < pos/decel && (fabs(FrontL.velocity(rpm)) < lowSpeed || speed < lowSpeed)) speed = lowSpeed;
		rightDrive.spin(reverse, speed, rpm); //Give Power to Motors
    leftDrive.spin(reverse, speed, rpm);
		lasterror = error;
    if(error>150) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Encoder: %ld\n", encode.value());
}
void turnLeft(float pos, int maxPower, int tim) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (t<tim) {
		error = inert.rotation() - pos;//Q-pos;
		if (error < 0)totalerror = 0;
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
    Power=P+I+D;
    if(Power>= maxPower)Power= maxPower;
    if(Power<0 && (fabs(error-pos) < 5 || fabs(error-pos) < 1)) Power = 0;
    if((Power-fabs(FrontL.velocity(rpm))) >= 60 && error > pos*0.5 && fabs(pos)>45) Power=fabs(FrontL.velocity(rpm)) + 60; //Acceleration 
    rightDrive.spin(forward, Power, rpm); //Give Power to Motors
    leftDrive.spin(reverse, Power, rpm);
		lasterror = error;
    if(error>1.5) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(brake);
   while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Angle: %.2f\n", inert.rotation());
}
void turnRight(float pos, int maxPower, int tim) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (t<tim) {
		error = pos - inert.rotation();
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
    Power=P+I+D;
    if(maxPower < 10) maxPower = 10;
    if(Power>maxPower)Power=maxPower;
    if(Power<0 && (fabs(error-pos) < 5 || error < 1)) Power = 0;
    if((Power-fabs(FrontL.velocity(rpm))) >= 50 && error > pos*0.5) Power=fabs(FrontL.velocity(rpm)) + 50; //Acceleration 
		rightDrive.spin(reverse, Power, rpm); //Give Power to Motors
    leftDrive.spin(forward, Power, rpm);
		lasterror = error;
    if(error>2) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(brake);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Angle: %.2f\n", inert.rotation());
}