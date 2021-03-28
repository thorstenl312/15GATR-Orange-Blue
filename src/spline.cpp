#include "spline.h"
#include "pid.h"
void splineLeft(float firstAngle, float X, int speed, int speed2, float endingAngle){
  while(fabs(firstAngle-inert.angle())>2){
    rightDrive.spin(reverse,speed,rpm);
    leftDrive.spin(reverse,speed2,rpm);
  }
  stopDrive(coast);
  while(fabs(X+encode.position(deg))>200){
    rightDrive.spin(reverse,speed*0.65,rpm);
    leftDrive.spin(reverse,speed*0.65,rpm);
  }
  while(fabs(X+encode.position(deg))>100){
    rightDrive.spin(reverse,speed*0.35,rpm);
    leftDrive.spin(reverse,speed*0.35,rpm);
  }
  stopDrive(brake);
  double error = 30;
  while(error>3){
    error = fabs(inert.angle());
    int zoom = error*2.3;
    if(zoom<=40){
      zoom = 40;
    }
    rightDrive.stop(brake);
    leftDrive.spin(reverse,zoom,rpm);
    wait(20,msec);
  }
  stopDrive(hold);
}
void splineRight(float firstAngle, int speed, int speed2, float endingAngle){
  while(fabs(inert.rotation()-firstAngle)>2){
    rightDrive.spin(reverse,speed2,rpm);
    leftDrive.spin(reverse,speed,rpm);
  }
  stopDrive(brake);
  turnRight(endingAngle);
  //leftDrive.stop(brake);
  //rightDrive.stop(coast);
  //turnRightO(0);
	//Stops motor to ensure accuracy
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}