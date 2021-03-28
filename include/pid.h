#pragma once
#include "functions.h"

#define kp 0.8
#define kd 0.12
#define ki 0.01
#define kpT 4.25
#define kdT 0.1
#define kiT 0.06

void forwardPIDFAST(float pos, int maxPower = 500, int tim = 150);
void forwardPID(float pos, int maxPower = 400, int tim = 150, float decel = 2.4, int lowSpeed = 60, bool closeEarly = false, int closer = 400);
void forwardPID2(float pos, int maxPower = 350, int tim = 150);
void backwardPID(float pos, int maxPower = 400, int tim = 150, float decel = 2.5, int lowSpeed = 50);
void backwardPID2(float pos, int maxPower = 300, int tim = 150);
void turnLeft(float pos, int maxSpeed = 200, int tim = 50);
void turnRight(float pos, int maxSpeed = 200, int tim = 50);
void turnTo(float pos, int tim, int maxSpeed);