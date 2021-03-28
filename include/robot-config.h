using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontL;
extern motor BackL;
extern motor FrontR;
extern motor MiddelL;
extern motor MiddleR;
extern motor BackR;

extern motor intakeL;
extern motor intakeR;

extern motor stage1;
extern motor stage2;
extern motor stage3;
extern motor decide;

extern controller Controller1;
extern inertial inert;
extern pneumatics pneum;
extern motor_group leftDrive;
extern motor_group intake;
extern motor_group rightDrive;
extern motor_group rollerSystem;
extern encoder encode;
extern optical Optical;
extern led beamLed;
extern led beamLed2;
extern limit beamBot;
extern limit beamBack;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );