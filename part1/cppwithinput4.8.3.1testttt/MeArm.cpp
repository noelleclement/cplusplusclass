#include "MeArm.h"
#include <Servo.h>
#include <cantino.h>


    
    //constructor
    MeArm::MeArm(int _pinServoLeft, int _pinServoRight, int _pinServoClaw, int _pinServoMiddle){ 
      pinServoLeft = _pinServoLeft;
      pinServoRight = _pinServoRight;
      pinServoClaw = _pinServoClaw;
      pinServoMiddle = _pinServoMiddle;

      valueMinMiddle = 0;
      valueMaxMiddle = 180;
      valueMiddleMiddle = 83; //83

      valueMinClaw = 0;     //since can't go into negatives, this is the most it can open
      valueMaxClaw = 55;
      valueOpenClaw = 0;
      valueClosedClaw = 55;

      valueMinArmLeft = 0;     //lowest originally 45, but for backwardstance 10 needed
      valueMaxArmLeft = 135;    //highest
    
      valueMinArmRight = 0;     //most backward
      valueMaxArmRight = 80;    //most forward


      //cantino::cout << "pinServoLeft " << pinServoLeft << cantino::endl;
      prepare();
    };
    

    //destructor
    MeArm::~MeArm(){
      cantino::cout << "MeArm has been DESTROYEEEED, from memory at least" << cantino::endl;
    }
    
    
    int MeArm::servoAttach(){
      cantino::cout << "Servos are being attached" << cantino::endl;
      //cantino::cout << "pinServoLeft " << pinServoLeft << cantino::endl;
      servoLeft.attach(pinServoLeft);
      servoRight.attach(pinServoRight);
      servoClaw.attach(pinServoClaw);
      servoMiddle.attach(pinServoMiddle);
      cantino::cout << "Servos have been attached" << cantino::endl;
      return 0;
    }

    
    int MeArm::prepare(){
      Serial.begin(9600);
      cantino::cout << "MeArm is being prepared" << cantino::endl;
      servoAttach();
      delay(40);
      base();
      cantino::cout << "MeArm has been prepared" << cantino::endl;
      return 0;
    }
   
   
    int MeArm::leftArm(int value){
      cantino::cout << "leftarm pre written" << cantino::endl;
      servoLeft.write(value);
      cantino::cout << "leftarm written" << cantino::endl;
      return 0;
    }
    
    int MeArm::rightArm(int value){
      cantino::cout << "rightarm pre written" << cantino::endl;
      servoRight.write(value);
      cantino::cout << "rightarm written" << cantino::endl;
      return 0;
    }
   
    int MeArm::clawOpen(){
      servoClaw.write(valueOpenClaw);
      return 0;
    }
          
    int MeArm::clawClose(){
       servoClaw.write(valueClosedClaw);
      return 0;
    }

    int MeArm::middleMiddle(){
      servoMiddle.write(valueMiddleMiddle);
      cantino::cout << "middle middle written" << cantino::endl;
      return 0;
    }

    int MeArm::middleTurn (int turnValue){
      servoMiddle.write(turnValue);
      return 0;
    }

    int MeArm::backwardStance(){
      cantino::cout << "trying to put MeArm into backwardstance" << cantino::endl;
      leftArm(10);
      rightArm(0);
      cantino::cout << "MeArm is in backwardstance" << cantino::endl;
      return 0;
    }
    
    int MeArm::forward(){
      leftArm(40);
      rightArm(40);
      return 0;
    }
    
    int MeArm::base(){
      cantino::cout << "trying to put MeArm into base position" << cantino::endl;
      backwardStance();
      delay(40);
      cantino::cout << "trying to check whether middle (value) " << MeArm::valueMiddleMiddle <<" can be reached" << cantino::endl;
      middleMiddle();
      cantino::cout << "MeArm is in base position" << cantino::endl;
      return 0;
    }
    
    int MeArm::turn (int turnValue){
      backwardStance();
      delay(40);
      middleTurn(turnValue);
      return 0;
    }
    

  
