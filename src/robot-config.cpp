#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontL = motor(PORT11, ratio6_1, true);
motor BackL = motor(PORT12, ratio6_1, true);
motor MiddleL = motor(PORT13, ratio6_1, false);
motor FrontR = motor(PORT17, ratio6_1, false);
motor BackR = motor(PORT15, ratio6_1, false);
motor MiddleR = motor(PORT16, ratio6_1, true);

motor intakeL = motor(PORT1, ratio6_1);
motor intakeR = motor(PORT9, ratio6_1, true);
motor stage2 = motor(PORT10, ratio18_1);
motor stage1 = motor(PORT7, ratio6_1);
motor stage3 = motor(PORT8, ratio6_1, true);
motor decide = motor(PORT20, ratio6_1);


motor_group leftDrive(FrontL, BackL,MiddleL);
motor_group intake(intakeL, intakeR);
motor_group rightDrive(FrontR, BackR,MiddleR);
motor_group rollerSystem(stage2,stage3,decide,stage1);
controller Controller1 = controller(primary);

encoder encode = encoder(Brain.ThreeWirePort.C);
limit beamBot = limit(Brain.ThreeWirePort.G);
led beamLed2 = led(Brain.ThreeWirePort.A);

inertial inert = inertial(PORT14);
optical Optical = optical(PORT18);
limit beamBack = limit(Brain.ThreeWirePort.F);
led beamLed = led(Brain.ThreeWirePort.B);
pneumatics pneum= pneumatics(Brain.ThreeWirePort.H);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}