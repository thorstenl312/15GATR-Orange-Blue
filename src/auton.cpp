#include "auton.h"
#include  "spline.h"
#include "functions.h"
void redLong(){ 
  //Pick up 2 balls
  pneum.close();
  intake.spin(fwd,100,pct);
  forwardPIDFAST(8000);
  while(fabs(leftDrive.velocity(pct)) > 10 || fabs(rightDrive.velocity(pct)) > 10);
  pneum.open();
  intake.spin(fwd,100,pct);
  splineRight(-65, 350, 100, 39);

  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  intake.spin(fwd,60,pct);
  stage3.spin(reverse,40,pct);
  forwardPID(2000);

  pneum.open();
  intake.spin(fwd,100,pct);
  rollerSystem.stop();
  
  //Align with wall
  backwardPID(7000, 500, 50, 3, 60);
  turnRight(90);
  driveIntoWall(300, 50);
  intake.stop(hold);

  //Go for middle home row
  forwardPID(12000, 450, 50, 4.25, 80);
  turnRight(180);
  pneum.close();
  rollerSystem.spin(fwd,50,pct);
  stage3.spin(reverse, 100,pct);
  driveUntilStop(200);
  pneum.open();
  bool blue = false;
  stage3.spin(fwd,100,pct);
  stage1.stop(hold);
  stage2.spin(fwd, 50,pct);
  decide.stop(hold);
  wait(350,msec);
  while(blue == false){
    stage1.spin(fwd, 30,pct);
    decide.stop(coast);
    intake.spin(fwd, 80,pct);
    if(Optical.hue()>200) blue = true;
  }
  rollerSystem.stop(hold);
  stage3.spin(fwd,100,pct);
  stage2.spin(fwd,80,pct);
  while(beamBot.value() == 0);
  wait(750,msec);
  pneum.close();
  stage3.stop(hold);
  intake.stop(hold);
  stage2.stop(hold);
  decide.stop(hold);
  stage1.spin(fwd,30,pct);
  backwardPID2(2000, 200, 50);
  
  //Go for corner goal
  rollerSystem.stop(coast);
  stage3.spin(reverse,70,pct);
  turnRight(270);
  rollerSystem.stop(coast);
  task shot(shootOutBB);
  forwardPID(7000, 450, 50, 2.8);
  turnLeft(234);
  pneum.close();
  forwardPID(1600);
  intake.spin(fwd,60,pct);
  pneum.open();
  driveUntilStop();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,30,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  stage1.stop(hold);
  decide.stop(hold);
  intake.rotateFor(reverse, 2, rev, 100, percent, false);
  wait(450, msec);
  intake.stop(coast);
  rollerSystem.stop(coast);
  pneum.close();
  wait(250,msec);
  backwardPID2(2000, 300);

  //Go for side middle goal
  turnRight(360);
  task shoutOutBlue2(shootOutBB);
  forwardPID(3900);
  turnLeft(321);
  pneum.close();
  //driveUntilStop();
  forwardPID(3000);
  rollerSystem.stop(coast);
  intake.stop(coast);
}
void redLongMiddle(){ 
  //Pick up 2 balls
  pneum.close();
  intake.spin(fwd,100,pct);
  forwardPIDFAST(7850,500);
  while(fabs(leftDrive.velocity(pct)) > 10 || fabs(rightDrive.velocity(pct)) > 10);
  pneum.open();
  intake.spin(fwd,100,pct);
  splineRight(-65, 350, 100, 39);
  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  intake.spin(fwd,60,pct);
  stage3.spin(reverse,40,pct);
  forwardPID(3100);
  pneum.open();
  intake.spin(fwd,100,pct);
  rollerSystem.stop();
  
  //Align with wall
  backwardPID(7000, 500, 50, 3, 60);
  turnRight(90);
  driveIntoWall(300, 50);
  intake.stop(hold);

  //Go for middle home row
  forwardPID(12000, 450, 50, 4.25, 80);
  turnRight(180);
  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  stage3.spin(reverse, 60,pct);
  driveUntilStop();
  rollerSystem.stop(coast);
  pneum.open();
  bool blue = false;
  rollerSystem.rotateFor(800, degrees, 80,percent);
  intake.spin(fwd,30,pct);
  rollerSystem.spin(fwd, 80,pct);
  stage3.spin(fwd,100,pct);
  stage1.spin(fwd, 30,pct);
  while(beamBot.value() != 1);
  while(blue == false){
    if(Optical.hue() < 35){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  int t = 0;
  while(blue == true){
    stage1.spin(fwd,20,pct);
    intake.spin(fwd, 100,pct);
    if(beamBot.value() == 1 || Optical.hue() > 200 || t > 3000){
      blue = false;
    }
    t+=15;
    wait(15,msec);
  }
  pneum.close();
  wait(250,msec);
  intake.stop(hold);
  rollerSystem.spin(fwd,100,pct);
  stage3.spin(reverse, 70,pct);
  backwardPID2(2000);

  //Go for corner goal
  rollerSystem.stop(coast);
  rollerSystem.spin(fwd,100,pct);
  stage3.spin(reverse,70,pct);
  turnRight(270);
  rollerSystem.stop(coast);
  task shot(shootOutBB);
  forwardPID(7000, 450, 50, 2.8);
  turnLeft(234);
  pneum.close();
  forwardPID(1600);
  intake.spin(fwd,60,pct);
  pneum.open();
  driveUntilStop();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,30,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
  pneum.close();
  backwardPID2(2000, 200);

  //Go for side middle goal
  turnLeft(54);
  task shoutOutBlue2(shootOutBB);
  forwardPID(7000);
  turnLeft(0);
  pneum.close();
  driveUntilStop();
  while(true){
    pneum.open();
    rollerSystem.spin(fwd,100,pct);
    stage1.spin(fwd,40,pct);
    decide.spin(fwd,40,pct);
    intake.spin(fwd, 60,pct);
    if(Optical.hue() > 200){
      rollerSystem.stop();
      intake.stop();
      wait(250,msec);
      shootOutBB();
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
}

void redShort(){
  pneum.close();
  forwardPID(3600);
  rollerSystem.stop();
  turnLeft(-133);
  pneum.close();
  forwardPID(4000);
  pneum.open();
  intake.spin(fwd,60,pct);
  driveUntilStop();
  bool blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  intake.spin(reverse,60,pct);
  rollerSystem.stop(coast);
  stage3.spin(fwd,80,pct);
  wait(1500,msec);
  intake.stop(coast);
  pneum.close();
  backwardPID2(3200);
  intake.stop(coast);
  turnLeft(-272);
  task m(shootOutBB);
  forwardPID(8000);
  turnRight(-183);
  driveUntilStop();
  pneum.open();
  intake.spin(fwd,80,pct);
  rollerSystem.spin(fwd,80,pct);
  stage3.spin(reverse,70,pct);
  wait(2000,msec);
  intake.stop();
  stage3.rotateFor(400, deg, 100,percent,false);
  stage2.rotateFor(400, deg, 100,percent,false);
  stage1.spin(reverse,40,pct);
  decide.spin(reverse,40,pct);
  wait(1000,msec);
  rollerSystem.stop(coast);
  pneum.close();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,50,pct);
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
}
void blueShort(){
  pneum.close();
  forwardPID(3600);
  rollerSystem.stop();
  turnLeft(-134.5);
  forwardPID(4300);
  pneum.open();
  intake.spin(fwd,60,pct);
  driveUntilStop();
  bool blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,40,pct);
    pneum.open();
    if(Optical.hue() < 25){
      blue = true;
    }
  }
  intake.spin(reverse,60,pct);
  rollerSystem.stop(coast);
  stage3.spin(fwd,80,pct);
  wait(1500,msec);
  intake.stop(coast);
  pneum.close();
  backwardPID2(3000);
  intake.stop(coast);
  turnLeft(-272);
  task m(shootOutBB);
  forwardPID(8000);
  turnRight(-182);
  driveUntilStop();
  pneum.open();
  intake.spin(fwd,80,pct);
  rollerSystem.spin(fwd,80,pct);
  stage3.spin(reverse,70,pct);
  wait(2000,msec);
  intake.stop();
  stage3.rotateFor(400, deg, 100,percent,false);
  stage2.rotateFor(400, deg, 100,percent,false);
  stage1.spin(reverse,40,pct);
  decide.spin(reverse,40,pct);
  wait(1000,msec);
  rollerSystem.stop(coast);
  pneum.close();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,50,pct);
    if(Optical.hue() < 25){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
}
void blueLong(){
  //Pick up 2 balls
  pneum.close();
  intake.spin(fwd,100,pct);
  forwardPIDFAST(7850,500);

  while(fabs(leftDrive.velocity(pct)) > 10 || fabs(rightDrive.velocity(pct)) > 10);
  pneum.open();
  intake.spin(fwd,100,pct);
  splineRight(-65, 350, 100, 39);

  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  intake.spin(fwd,60,pct);
  stage3.spin(reverse,40,pct);
  forwardPID(2700);

  pneum.open();
  intake.spin(fwd,100,pct);
  rollerSystem.stop();
  
  //Align with wall
  backwardPID(7000, 500, 50, 3, 60);
  turnRight(90);
  driveIntoWall(300, 50);
  intake.stop(hold);

  //Go for middle home row
  forwardPID(12000, 450, 50, 4.25, 80);
  turnRight(180);
  pneum.close();
  rollerSystem.spin(fwd,50,pct);
  stage3.spin(reverse, 100,pct);
  driveUntilStop(200);
  pneum.open();
  bool blue = false;
  stage3.spin(fwd,100,pct);
  stage1.stop(hold);
  stage2.spin(fwd, 50,pct);
  decide.stop(hold);
  wait(350,msec);
  while(blue == false){
    stage1.spin(fwd, 30,pct);
    decide.stop(coast);
    intake.spin(fwd, 80,pct);
    if(Optical.hue()<25) blue = true;
  }
  rollerSystem.stop(hold);
  stage3.spin(fwd,100,pct);
  stage2.spin(fwd,80,pct);
  while(beamBot.value() == 0);
  wait(750,msec);
  pneum.close();
  stage3.stop(hold);
  intake.stop(hold);
  stage2.stop(hold);
  decide.stop(hold);
  stage1.spin(fwd,30,pct);
  backwardPID2(2000, 200, 50);
  
  //Go for corner goal
  rollerSystem.stop(coast);
  stage3.spin(reverse,70,pct);
  turnRight(270);
  rollerSystem.stop(coast);
  task shot(shootOutBB);
  forwardPID(7000, 450, 50, 2.8);
  turnLeft(232);
  pneum.close();
  forwardPID(1600);
  intake.spin(fwd,60,pct);
  pneum.open();
  driveUntilStop();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,30,pct);
    pneum.open();
    if(Optical.hue() <25){
      blue = true;
    }
  }
  stage1.stop(hold);
  intake.rotateFor(reverse, 2, rev, 100, percent, false);
  wait(250, msec);
  intake.stop(coast);
  rollerSystem.stop(coast);
  pneum.close();
  wait(450,msec);
  backwardPID2(2000, 300);

  //Go for side middle goal
  turnRight(360);
  task shoutOutBlue2(shootOutBB);
  forwardPID(3900);
  turnLeft(323);
  pneum.close();
  driveUntilStop();
  rollerSystem.stop(coast);
  intake.stop(coast);
}
void blueLongMiddle(){
  //Pick up 2 balls
  pneum.close();
  intake.spin(fwd,100,pct);
  forwardPIDFAST(7850,500,50);
  while(fabs(leftDrive.velocity(pct)) > 10 || fabs(rightDrive.velocity(pct)) > 10);
  pneum.open();
  intake.spin(fwd,100,pct);
  splineRight(-65, 350, 100, 40);
  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  stage3.spin(reverse,40,pct);
  forwardPID(3100);
  pneum.open();
  intake.spin(fwd,100,pct);
  rollerSystem.stop();
  
  //Align with wall
  backwardPID(7000, 500, 50, 3, 60);
  turnRight(90);
  driveIntoWall(300, 50);
  intake.stop(hold);

  //Go for middle home row
  forwardPID(12000, 450, 50, 4.25, 80);
  turnRight(180);
  pneum.close();
  rollerSystem.spin(fwd,60,pct);
  stage3.spin(reverse, 60,pct);
  driveUntilStop();
  rollerSystem.stop(coast);
  pneum.open();
  bool blue = false;
  rollerSystem.rotateFor(100, degrees, 80,percent);
  intake.spin(fwd,30,pct);
  rollerSystem.spin(fwd, 80,pct);
  stage3.spin(fwd,100,pct);
  stage1.spin(fwd, 30,pct);
  while(beamBot.value() != 1);
  while(blue == false){
    if(Optical.hue() < 25){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  int t = 0;
  while(blue == true){
    stage1.spin(fwd,20,pct);
    intake.spin(fwd, 100,pct);
    if(beamBot.value() == 1 || Optical.hue() > 200 || t > 3000){
      blue = false;
    }
    t+=15;
    wait(15,msec);
  }
  pneum.close();
  wait(250,msec);
  intake.stop(hold);
  rollerSystem.spin(fwd,100,pct);
  stage3.spin(reverse, 70,pct);
  backwardPID2(2000);

  //Go for corner goal
  rollerSystem.stop(coast);
  rollerSystem.spin(fwd,100,pct);
  stage3.spin(reverse,70,pct);
  turnRight(270);
  rollerSystem.stop(coast);
  task shot(shootOutBB);
  forwardPID(7000, 450, 50, 2.8);
  turnLeft(232);
  pneum.close();
  forwardPID(1300);
  intake.spin(fwd,60,pct);
  pneum.open();
  driveUntilStop();
  blue = false;
  while(blue == false){
    rollerSystem.spin(fwd,80,pct);
    intake.spin(fwd,30,pct);
    pneum.open();
    if(Optical.hue() > 200){
      blue = true;
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
  pneum.close();
  backwardPID2(2000, 300);

  while(true){
    pneum.open();
    rollerSystem.spin(fwd,100,pct);
    stage1.spin(fwd,40,pct);
    decide.spin(fwd,40,pct);
    intake.spin(fwd, 60,pct);
    if(Optical.hue() > 200){
      rollerSystem.stop();
      intake.stop();
      wait(250,msec);
      shootOutBB();
    }
  }
  rollerSystem.stop(coast);
  intake.stop(coast);
  
}
void testSkills(){
  

}
