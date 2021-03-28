#include "vex.h"
#include <iostream>

void print_page(int page, int autoSelect){
  //Brain GUI print settings
  Brain.Screen.setPenColor(white);
  if(autoSelect <= 2){
    Brain.Screen.setFillColor(red);
  }
  else if (autoSelect == 3){
    // skills
    Brain.Screen.setFillColor(purple);
  }
  else{
    Brain.Screen.setFillColor(blue);
  }

  Brain.Screen.drawRectangle(0,0, 485, 245);  //boarder showing what color you are
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(15,15, 455, 215);

  // print page 1 screen
  if(page == 0){
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.printAt(365,25, "Test Runs"); //button print

    // print the sensor info
    Brain.Screen.setCursor(3, 4);
    Brain.Screen.print("Brake Beam1: %s", false ? "true" : "false");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Brake Beam2: %s", true ? "true" : "false");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Brake Beam3: %s", true ? "true" : "false");
    Brain.Screen.printAt(150, 125, "o");
    Brain.Screen.setCursor(7, 4);
    Brain.Screen.print("Heading: %.1f", 10);
    Brain.Screen.setCursor(8, 4);
    Brain.Screen.print("Encoder: %.1f clicks", 100);

    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: RED1");}
    if(autoSelect == 2){Brain.Screen.print("Auto: RED2");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Skills");}
    if(autoSelect == 4){Brain.Screen.print("Auto: BLUE1");}
    if(autoSelect == 5){Brain.Screen.print("Auto: BLUE2");}
  }

  else if(page == 1){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(365,25, "Test Runs"); //button print

    // print auto buttons
    if(autoSelect == 1){
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 2){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 3){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 4){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 5){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }

    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(60, 80, "RED LONG"); 
    Brain.Screen.printAt(55, 170, "RED SHORT"); 
    Brain.Screen.printAt(214, 125, "SKILLS"); 
    Brain.Screen.printAt(340, 80, "BLUE LONG"); 
    Brain.Screen.printAt(335, 170, "BLUE SHORT");
  }
  else if(page == 2){
    Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(50, 50, 200, 100);
    Brain.Screen.setFillColor(transparent); Brain.Screen.printAt(80,100, "RESET SENSORS"); //button print

    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(365,25, "Test Runs"); //button print
    Brain.Screen.setFillColor(transparent);

    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: RED LONG");}
    if(autoSelect == 2){Brain.Screen.print("Auto: RED SHORT");}
    if(autoSelect == 3){Brain.Screen.print("Auto: SKILLS");}
    if(autoSelect == 4){Brain.Screen.print("Auto: BLUE LONG");}
    if(autoSelect == 5){Brain.Screen.print("Auto: BLUE SHORT");}
  }
}

void page_select(int* current_page, int* autoSelect){
  // GUI page controlls
  int xPress = Brain.Screen.xPosition();
  int yPress = Brain.Screen.yPosition();
  /*if (*current_page == 2){
    Brain.Screen.setCursor(3, 4);
    Brain.Screen.print("LDB: %.3f", 1);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("LDT: %.3f", 2);
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("RDB: %.3f", 3);
    Brain.Screen.setCursor(6, 4);
    Brain.Screen.print("RDT: %.3f", 4);
    Brain.Screen.setCursor(8, 4);
    Brain.Screen.print("FTOP: %.3f", 5);
    Brain.Screen.setCursor(9, 4);
    Brain.Screen.print("FBOT: %.3f", 6);
    Brain.Screen.setCursor(10, 4);
    Brain.Screen.print("BTOP: %.3f", 7);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("BBOT: %.3f", 8);
    Brain.Screen.setCursor(10, 31);
    Brain.Screen.print("INR: %.3f", 9);
    Brain.Screen.setCursor(11, 31);
    Brain.Screen.print("INL: %.3f", 10);
  }*/
  //check if brain is being pressed
  if (Brain.Screen.pressing()){
    // page shifting

    if((xPress >= 10 && xPress <= 130) && (yPress >= 10 && yPress <= 40)){
      // Go to page one
      *current_page = 0;
      print_page(*current_page, *autoSelect);
    }
    else if((xPress >= 180 && xPress <= 300) && (yPress >= 10 && yPress <= 40)){
      // Go to page two
      *current_page = 1;
      print_page(*current_page, *autoSelect);
    }
    else if((xPress >= 360 && xPress <= 480) && (yPress >= 10 && yPress <= 40)){
      // Go to page three
      *current_page = 2;
      print_page(*current_page, *autoSelect);
    }
    //auto selection
    if(*current_page == 1){
      if((xPress >= 35 && xPress <= 159) && (yPress >= 45 && yPress <= 110)){
        *autoSelect = 1; //red1
        print_page(*current_page, *autoSelect);
      }
      else if((xPress >= 35 && xPress <= 159) && (yPress >= 135 && yPress <= 200)){
        *autoSelect = 2; //red2
        print_page(*current_page, *autoSelect);
      }
      else if((xPress >= 179 && xPress <= 303) && (yPress >= 45 && yPress <= 200)){
        *autoSelect = 3; //skills
        print_page(*current_page, *autoSelect);
      }
      else if((xPress >= 323 && xPress <= 447) && (yPress >= 45 && yPress <= 110)){
        *autoSelect = 4; //blue1
        print_page(*current_page, *autoSelect);
      }
      else if((xPress >= 323 && xPress <= 447) && (yPress >= 135 && yPress <= 200)){
        *autoSelect = 5; //blue2
        print_page(*current_page, *autoSelect);
      }
    }
    else if(*current_page == 2){
      if((xPress >= 50 && xPress <= 250) && (yPress >= 50 && yPress <= 150)){
        inert.calibrate();
        encode.resetRotation();

        std::cout << "  RESET" << std::endl;
        Brain.Screen.setFillColor(transparent); Brain.Screen.printAt(80,200, "CALIBRATED"); //button print
      }
    }
    while(Brain.Screen.pressing()){}
  }
}