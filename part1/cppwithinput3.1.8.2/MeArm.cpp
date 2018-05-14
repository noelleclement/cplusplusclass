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
      valueMiddleMiddle = 83;

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
      cantino::cout << "6367" << cantino::endl;
      base();
      delay(1000);
      cantino::cout << "MeArm has been prepared" << cantino::endl;
      return 0;
    }

    /*
    bool MeArm::isReachable(int leftValue, int rightValue, int clawValue, int middleValue){
      if (leftValue >= valueMinArmLeft && leftValue <= valueMaxArmLeft){
        return true;
      }
      else if (rightValue >= valueMinArmRight && rightValue <= valueMaxArmRight){
        return true;
      }
      else if (clawValue >= valueMinClaw && clawValue <= valueMaxClaw){
        return true;
      }
      else if (middleValue >= valueMinMiddle && middleValue <= valueMaxMiddle){
        return true;
      }
      else{
        return false;
      }


      //maybe do more 'research' on this:
        //left for up and down
          //45 lowest
          //135 highest
          //90 middle
          
        //right for forward and backward
          //0 for most backward
          //80 for most forward (when left 90, this is the max)
          
          //everything left possible, when right 0 
          
          //when left 135, not enough power for right to go to 0 (back)
          //when left 115, enough power for right from 0-80
          //when left 90, enough power for right from 0-80
          //when left 45, right max 40, otherwise will hit ground

    }

    */

    bool MeArm::isLeftReachable(int leftValue){
      if (leftValue >= valueMinArmLeft && leftValue <= valueMaxArmLeft){
        return true;
      }
      else{
        return false;
      }
    }

    bool MeArm::isRightReachable(int rightValue){
      if (rightValue >= valueMinArmRight && rightValue <= valueMaxArmRight){
        return true;
      }
      else{
        return false;
      }
    }

    bool MeArm::isClawReachable(int clawValue){
      if (clawValue >= valueMinClaw && clawValue <= valueMaxClaw){
        return true;
      }
      else{
        return false;
      }
    }

    bool MeArm::isMiddleReachable(int middleValue){
      if (middleValue >= valueMinMiddle && middleValue <= valueMaxMiddle){
        return true;
      }
      else{
        return false;
      }
    }
   
    int MeArm::leftArm(int value){
      if(isLeftReachable(value)){
        servoLeft.write(value);
      }
      return 0;
    }
    
    int MeArm::rightArm(int value){
      if(isRightReachable(value)){
        servoRight.write(value);
      }
      return 0;
    }
   
    int MeArm::clawOpen(){
      if(isClawReachable(valueOpenClaw)){
        servoClaw.write(valueOpenClaw);
      }
      return 0;
    }
          
    int MeArm::clawClose(){
      if(isClawReachable(valueClosedClaw)){
        servoClaw.write(valueClosedClaw);
      }
      return 0;
    }

    int MeArm::middleMiddle(){
      if(isMiddleReachable(valueMiddleMiddle)){
        servoMiddle.write(valueMiddleMiddle);
      }
      return 0;
    }

    int MeArm::middleTurn (int turnValue){
      if(isMiddleReachable(turnValue)){
        servoMiddle.write(turnValue);
      }
      return 0;
    }



    int MeArm::backwardStance(){
      cantino::cout << "444" << cantino::endl;
      leftArm(10);
      cantino::cout << "555" << cantino::endl;
      rightArm(0);
      cantino::cout << "666" << cantino::endl;
      return 0;
    }
    
    int MeArm::forward(){
      leftArm(40);
      rightArm(40);
      return 0;
    }
    
    int MeArm::base(){
      cantino::cout << "111" << cantino::endl;
      backwardStance();
      delay(1);
      cantino::cout << "222" << cantino::endl;
      middleMiddle();
      cantino::cout << "333" << cantino::endl;
      return 0;
    }
    
    int MeArm::turn (int turnValue){
      backwardStance();
      delay(1000);
      middleTurn(turnValue);
      return 0;
    }
    

  
