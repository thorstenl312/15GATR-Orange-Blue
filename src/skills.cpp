#include "auton.h"
void skills(){
  //First Goal
  rollerSystem.stop(coast);
  turnRight(13,  50, 50);
  pneum.close();
  intake.spin(fwd, 70, pct);
  rollerSystem.spin(fwd, 50,pct);
  stage3.spin(reverse, 80, pct);
  task pick1(closePneumAndIntake);
  stage3.spin(reverse, 80, pct);
  forwardPID(6000);
  stage2.stop(hold);
  stage3.spin(reverse, 80, pct);
  pneum.open();

  turnLeft(-43);

  intake.spin(fwd, 60, pct);

  driveUntilStop();
  bool blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,100,pct);
    intake.spin(fwd,60,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(hold);
  stage1.spin(fwd,30,pct);
  intake.spin(fwd,100,pct);
  while(beamBot.value() == 1);
  stage3.spin(fwd, 80, pct);
  intake.rotateFor(200, degrees, 100, percent, false);
  stage1.rotateFor(250, degrees, 100, percent);
  pneum.close();
  intake.stop(hold);
  wait(200, msec);
  //Second Goal
  backwardPID2(1300, 100, 50);
  pneum.close();
  rollerSystem.stop(hold);
  turnLeft(-210.5);
  task shoot1(shootOutBB2);
  task pick2(closePneumAndIntake);
  forwardPID(11000, 400, 50, 4.3, 60, true,950);
  turnRight(-90);
  driveUntilStop(300, 50);
  pneum.open();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }

  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  intake.spin(reverse, 60, pct);
  wait(300,msec);
  pneum.close();
  intake.stop(coast);
  backwardPID2(1300, 100, 50);
  turnLeft(-180);
  task shoot2(shootOutBB);

  //Third Goal
  task pick3(closePneumAndIntake);
  forwardPID(8500, 450, 50, 2.7, 60, true, 1200);
  turnRight(-135);
  rollerSystem.spin(fwd, 80, pct);
  stage3.spin(reverse, 70, pct);
  intake.spin(fwd, 60, percent);
  driveUntilStop();

  pneum.open();

  blue = false;

  while(blue == false){
    rollerSystem.spin(fwd,100,pct);
    intake.spin(fwd,60,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }

  
  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  stage1.spin(fwd,80,pct);
  intake.spin(fwd,100,pct);
  while(beamBot.value() == 1);

  pneum.close();
  stage3.spin(fwd, 80, pct);
  intake.spin(fwd,20,pct);
  stage2.stop(hold);
  decide.stop(hold);
  stage1.spin(fwd,50,pct);
  wait(500,msec);
  backwardPID2(2000, 200, 50);
  turnLeft(-300);
  task shoot3(shootOutBB2);

  //Fourth Goal
  task pick4(closePneumAndIntake);
  forwardPID(10300, 450, 50, 4.3, 60, true, 450);
  turnRight(-179);
  pneum.close();
  task pick5(closePneumAndIntake);
  driveUntilStop();
  while(decide.velocity(rpm) > 10 && stage1.velocity(rpm) > 10);
  pneum.open();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  intake.spin(reverse, 60, pct);
  wait(300,msec);
  pneum.close();
  intake.stop(coast);
  backwardPID2(3500);

  //Fifth Goal
  turnLeft(-270);
  task shoot4(shootOutBB);
  task pick6(closePneumAndIntake);
  forwardPID(6800);
  turnRight(-180);
  forwardPID2(2300);
  turnLeft(-233);
  driveUntilStop();
  pneum.open();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,100,pct);
    intake.spin(fwd,60,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  stage1.spin(fwd,80,pct);
  intake.spin(fwd,100,pct);
  while(beamBot.value() == 1);
  pneum.close();
  intake.stop(hold);
  stage2.stop(hold);
  decide.stop(hold);
  stage1.spin(fwd,50,pct);
  wait(500,msec);
  backwardPID2(2000);

  //Sixth Goal
  turnLeft(-380);
  task shoot5(shootOut2);
  task pick7(closePneumAndIntake);
  forwardPID(9650);
  turnRight(-270);
  driveUntilStop();
  pneum.open();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  intake.spin(reverse, 60, pct);
  wait(300,msec);
  pneum.close();
  intake.stop(coast);
  backwardPID2(1500);

  //Seventh Goal
  turnLeft(-360);
  task shoot6(shootOutBB);
  task pick8(closePneumAndIntake);
  forwardPID(7800);
  turnRight(-315);
  driveUntilStop();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  while(beamBot.value() == 1);
  stage3.rotateFor(150, deg, 80, percent);
  intake.stop(hold);
  pneum.close();
  backwardPID2(2000);

  //Eigth Goal
  turnLeft(-450);
  task shoot7(shootOut);
  task pick9(closePneumAndIntake);
  forwardPID(7950);
  turnRight(-360);
  driveUntilStop();
  pneum.open();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  intake.spin(reverse, 60, pct);
  wait(300,msec);
  pneum.close();
  intake.stop(coast);
  backwardPID2(2000);
  
  //Middle Goal
  turnRight(-180);
  task shoot8(shootOutBB);
  task pick10(closePneumAndIntake);
  /*driveUntilStop();
  pneum.close();
  intake.spin(fwd, 100, pct);
  rollerSystem.rotateFor(360, deg, 100, percent);
  rollerSystem.spin(fwd, 100,pct);
  intake.spin(fwd, 100, pct);
  stage3.spin(reverse, 70, pct);
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  while(beamBot.value() == 1);
  wait(1000, msec);
  pneum.close();*/
  driveUntilStop();

  pneum.open();

  blue = false;

  while(blue == false){
    rollerSystem.spin(fwd,100,pct);
    intake.spin(fwd,60,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }

  
  rollerSystem.stop(coast);
  stage3.spin(fwd, 80, pct);
  stage1.spin(fwd,80,pct);
  intake.spin(fwd,100,pct);
  while(beamBot.value() == 1);

  pneum.close();
  stage3.spin(fwd, 80, pct);
  intake.spin(fwd,20,pct);
  stage2.stop(hold);
  decide.stop(hold);
  stage1.spin(fwd,50,pct);
  wait(500,msec);
  backwardPID2(1000);
}