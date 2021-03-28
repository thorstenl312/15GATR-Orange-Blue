#pragma once
#include "vex.h"

void stopDrive(brakeType b);
int shootOut();
int shootOut2();
int spinUntilBall();
int deploy();
int badBallControl();
int pne();
int closePneumAndIntake();
int shootOutBB();
int shootOutBB2();
void driveIntoWall(int maxSpeed = 200, int accel = 50);
void shootUntilBall(int balls);
void placeBalls(int balls);
void driveUntilStop(int maxSpeed = 200, int accel = 50);