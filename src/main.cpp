/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FL                   motor         1               
// BL                   motor         2               
// FR                   motor         3               
// BR                   motor         4               
// Controller1          controller                    
// inert                inertial      5               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "spline.h"
#include "pid.h"
#include "functions.h"
#include "vex.h"
#include "auton.h"
#include "skills.h"
#include "gui.h"
#include <iostream>

using namespace vex;
int autoSelect = 1;
bool side = false; //false = red, true = blue

bool badBall = false;
bool autoClose = false;
bool closeIntake = true;
competition Competition;


void pre_auton(void) {
  std::cout << "STARTING PREAUTON" << std::endl;
  vexcodeInit();

  std::cout << "  CALIBRATING SENSORS..." << std::endl;
  inert.calibrate();
  encode.resetRotation();
  while(inert.isCalibrating());
  Optical.setLightPower(50,pct);
  Optical.setLight(ledState::on);
  beamLed.on();
  beamLed2.on();
  pneum.open();
  std::cout << "  AUTONOMOUS SELECT..." << std::endl;

  // Print start up screen
  int current_page = 1;
  print_page(1, autoSelect);
  while(!Competition.isEnabled()){
    page_select(&current_page, &autoSelect);
  }

  std::cout << "ENDING PREAUTON" << std::endl;
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  std::cout << "STARTING AUTONOMOUS" << std::endl;

  task d(deploy);
  Optical.setLightPower(50,pct);
  Optical.setLight(ledState::on);
  rollerSystem.stop();
  
  if(autoSelect == 1){
    //RED LONG
    std::cout << "  STARTING RED LONG" << std::endl;
    side = false;
    redLong();
  }
  else if(autoSelect == 2){
    //RED SHORT
    std::cout << "  STARTING RED SHORT" << std::endl;
    side = false;
    redShort();
  }
  else if(autoSelect == 3){
    //SKILLS
    std::cout << "  STARTING SKILLS" << std::endl;
    side = false;
    skills();
    //shootOutBB2();
  }
  else if(autoSelect == 4){
    //BLUE LONG
    std::cout << "  STARTING BLUE LONG" << std::endl;
    side = true;
    blueLong();
  }
  else if(autoSelect == 5){
    //BLUE SHORT
    std::cout << "  STARTING BLUE SHORT" << std::endl;
    side = true;
    blueShort();
  }

  std::cout << "ENDING AUTONOMOUS" << std::endl;
  
}

void usercontrol(void) {
  Brain.Screen.clearScreen();
  beamLed.on();
  beamLed2.on();
  Optical.setLightPower(50,pct);
  Optical.setLight(ledState::on);
  Brain.Screen.clearScreen();
  encode.resetRotation();
  task bB(badBallControl);
  //task p(pne);

  while (true) {
    int controller4 = Controller1.Axis4.position(pct);
    int controller3 = Controller1.Axis3.position(pct);
    Brain.Screen.printAt(10,10,"Encoder: %d", encode.value());
    Brain.Screen.printAt(10,30, "Hue: %.2f ", Optical.hue());
    Brain.Screen.printAt(10,50, "Beam: %d", beamBack.value());
    Brain.Screen.printAt(10,70, "Ball Detected: %d", badBall);
    
    if(badBall && Controller1.ButtonL1.pressing()){
      stage2.spin(reverse,50,pct);
      stage1.spin(fwd,10,pct);
      decide.spin(fwd,100,pct);
      if(fabs(100-stage3.velocity(pct)) > 35){
        stage3.spin(fwd, stage3.velocity(pct) + 35, pct);
      }
    }
    else if(badBall && !Controller1.ButtonL1.pressing()){
      stage2.spin(reverse,50,pct);
      stage1.spin(fwd,10,pct);
      decide.spin(fwd,100,pct);
      stage3.stop(hold);
    }
    else if(Controller1.ButtonL1.pressing() && !Controller1.ButtonR1.pressing()){ 
      rollerSystem.spin(fwd, 85,pct);
      stage1.spin(fwd,70,pct);
      decide.spin(fwd,70,pct);
      intake.stop(coast);
      if(fabs(100-stage3.velocity(pct)) > 25){
        stage3.spin(fwd, stage3.velocity(pct) + 25, pct);
      }
      else{
        stage3.spin(fwd,100,pct);
      }
    }
    else if(Controller1.ButtonL1.pressing() && Controller1.ButtonR1.pressing()){
      rollerSystem.spin(fwd,85,pct);
      intake.spin(fwd,100,pct);
      stage1.spin(fwd,70,pct);
      decide.spin(fwd,70,pct);
      if(fabs(100-stage3.velocity(pct)) > 25){
        stage3.spin(fwd, stage3.velocity(pct) + 25, pct);
      }
    }
    else if(Controller1.ButtonR1.pressing() && !Controller1.ButtonL1.pressing()){ 
      intake.spin(fwd,600,rpm);
      stage2.spin(fwd,100,pct);
      stage1.spin(fwd,70,pct);
      decide.spin(fwd,70,pct);
      if(fabs(-70-stage3.velocity(pct)) > 25){
        stage3.spin(forward, stage3.velocity(pct) - 25, pct);
      }
      else{
        stage3.spin(reverse,70,pct);
      }
    }
    else if(Controller1.ButtonR2.pressing()){ 
      rollerSystem.spin(reverse,100,pct);
      intake.spin(reverse,60,pct);
    }
    else {
      rollerSystem.stop(coast);
      intake.spin(fwd, 0, pct);
    }
    if(Controller1.ButtonA.pressing()){
      autoClose = false;
      std::cout << autoClose << std::endl;
      closeIntake = !closeIntake;
      while(Controller1.ButtonA.pressing());
    }
    if(Controller1.ButtonUp.pressing() && Controller1.ButtonX.pressing()){
      side = !side;
      while(Controller1.ButtonUp.pressing() || Controller1.ButtonX.pressing());
    }
    /*if(Controller1.ButtonUp.pressing() && Controller1.ButtonX.pressing()){
      task release(shootOutBB2);
      while(Controller1.ButtonUp.pressing() || Controller1.ButtonX.pressing());
    }*/
    if(closeIntake){
      pneum.close();
    }
    else{
      pneum.open();
    }
    if(abs(controller3) < 5){
      controller3 = 0;
    }
    if(abs(controller4) < 5){
      controller4 = 0;
    }
    /*if(leftDrive.velocity(pct) > 0 && abs(controller3) < 5 && leftDrive.velocity(pct) - controller3 > 30){
      controller3 = 0.5 * leftDrive.velocity(pct);
    }
    else if(leftDrive.velocity(pct) < 0 && abs(controller3) < 5 && controller3 - leftDrive.velocity(pct) > 30){
      controller3 = 0.5 * leftDrive.velocity(pct);
    }*/
    leftDrive.spin(fwd, controller3 + controller4*0.3,pct);
    rightDrive.spin(fwd, controller3 - controller4*0.3,pct);
    wait(20,msec);
  }
}


int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  wait(3, sec);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
int skillsRelease(){
  while(true){
    
  }
}

int badBallControl(){
  while(true){
    if((beamBack.value() == 1 || Controller1.ButtonLeft.pressing())){
      badBall = false;
      wait(250,msec);
      while(beamBack.value() == 1 || Controller1.ButtonLeft.pressing());
    }
    else if(((Optical.hue() > 200 && badBall == false) && !side) || ((Optical.hue() < 30 && badBall == false) && side)){
      badBall = true;
    }
    wait(20,msec);
  }
}
int pne(){
  while(true){
    if(Controller1.ButtonR1.pressing()){
      autoClose = true;
      wait(250,msec);
      closeIntake = false;
      while(Controller1.ButtonR1.pressing());
    }
    else if(beamBot.value() == 1 && autoClose){
      closeIntake = false;
    }
    else if(autoClose && beamBot.value() == 0){
      closeIntake = true;
    }
    if(Controller1.ButtonR2.pressing()){
      autoClose = false;
    }
    if(Controller1.ButtonA.pressing()){
      autoClose = false;
      std::cout << autoClose << std::endl;
      closeIntake = !closeIntake;
      while(Controller1.ButtonA.pressing());
    }
  }
  return(0);
}