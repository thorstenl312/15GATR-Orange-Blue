#include "functions.h"
#include <iostream>

void stopDrive(brakeType b){
  leftDrive.stop(b);
  rightDrive.stop(b);
}

void driveUntilStop(int maxSpeed, int accel){
  int speed = (leftDrive.velocity(rpm)+rightDrive.velocity(rpm)) / 2;
  int startPos = encode.position(deg);
  int pastPos = 0;
  int pastSpeed = 0;
  while(encode.position(deg) - pastPos > 0 || encode.position(deg) <= startPos + 200 ){
    leftDrive.spin(forward, speed, rpm);
    rightDrive.spin(forward, speed, rpm);
    speed += 30;
    if(speed > maxSpeed)
      speed = maxSpeed;

    pastSpeed = (encode.position(deg) - pastPos);
    pastPos = encode.position(deg);
    wait(accel, msec);
  }
  intake.stop(hold);
  std::cout << "Done Accel" << std::endl;
  wait(200,msec);
  stopDrive(hold);
}

void driveIntoWall(int maxSpeed, int accel){
  int speed = (leftDrive.velocity(rpm)+rightDrive.velocity(rpm)) / 2;
  int startPos = encode.position(deg);
  int pastPos = 0;
  while(fabs(pastPos - encode.position(deg)) > 10 || fabs(encode.position(deg)) <= abs(startPos) + 50 ){
    leftDrive.spin(reverse, speed, rpm);
    rightDrive.spin(reverse, speed, rpm);
    speed += 30;
    if(speed > maxSpeed)
      speed = maxSpeed;

    pastPos = encode.position(deg);
    wait(accel, msec);
  }
  stopDrive(coast);
}
int shootOut(){
  stage1.spin(fwd, 40, pct);
  intake.spin(fwd, 70, pct);
  stage2.rotateFor(-1000, deg, 40, percent,false);
  decide.rotateFor(1000, deg, 40, percent);
  rollerSystem.stop(coast);
  intake.stop(coast);
  return(0);
}
int shootOut2(){
  rollerSystem.spin(fwd,100,pct);
  stage3.spin(reverse,100,pct);
  wait(500,msec);
  rollerSystem.stop(coast);
  decide.spin(fwd,100,pct);
  stage2.spin(reverse, 20,pct);
  stage1.stop(coast);
  wait(1200,msec);
  rollerSystem.stop(coast);
  return(0);
}
int closePneumAndIntake(){
  intake.spin(fwd, 100,pct);
  stage3.spin(reverse, 60,pct);
  while(beamBot.value() == 0);
  pneum.open();
  bool blue = false;
  while(blue == false){
    rollerSystem.spin(fwd, 80, pct);
    intake.spin(fwd, 60, pct);
    stage2.spin(fwd,40,pct);
    stage3.spin(reverse, 100, pct);
    if(Optical.hue() < 25){
      blue = true;
    }
  }
  intake.stop(coast);
  rollerSystem.stop(coast);
  pneum.close();
  return(0);
}
int shootOutBB(){
  while(beamBack.value() != 1){
    decide.spin(forward, 100,pct);
    stage2.spin(reverse, 40,pct);
    stage1.spin(fwd,20,pct);
  }
  rollerSystem.spin(fwd, 60,pct);
  stage3.spin(reverse, 60, pct);
  wait(1000,msec);
  rollerSystem.stop(coast);
  intake.stop(coast);
  return(0);
}

int shootOutBB2(){
  pneum.close();
  intake.rotateFor(3, rev, 100, percent, false);
  stage3.rotateFor(.5, rev, 100, percent, false);
  stage2.rotateFor(10, rev, 100, percent, false);
  stage1.rotateFor(10, rev, 100, percent, false);
  decide.rotateFor(20, rev, 100, percent, false);
  wait(600,msec);
  stage3.rotateFor(-10, rev, 100, percent, false);
  stage1.stop(hold);
  stage2.rotateFor(-20, rev, 30, percent, false);
  while(pneum.value() == 0);
  rollerSystem.stop(coast);
  intake.stop(coast);
  return(0);

}
int deploy(){
  pneum.close();
  rollerSystem.spin(fwd,100,pct);
  //stage1.spin(reverse,80,pct);
  stage2.stop(coast);
  stage3.stop(coast);
  decide.stop(hold);
  intake.spin(reverse,100,pct);
  wait(350,msec);
  rollerSystem.spin(fwd,100,pct);
  
  stage2.stop(hold);
  decide.stop(hold);
  wait(350,msec);
  stage1.stop(hold);
  stage3.spin(reverse, 60,pct);
  rollerSystem.stop(coast);
  intake.spin(fwd,60,pct);
  return(0);
}
