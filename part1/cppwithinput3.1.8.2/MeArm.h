#ifndef MEARM_H
#define MEARM_H

#include <Arduino.h>
#include <Servo.h>
#include <cantino.h>


class MeArm{

    
  public:

    Servo servoLeft, servoRight, servoClaw, servoMiddle;
    int pinServoLeft, pinServoRight, pinServoClaw, pinServoMiddle; 
     
    int valueMinMiddle;
    int valueMaxMiddle;
    int valueMiddleMiddle;

    int valueMinClaw;
    int valueMaxClaw;
    int valueOpenClaw;
    int valueClosedClaw;

    int valueMinArmLeft;
    int valueMaxArmLeft;
    
    int valueMinArmRight;
    int valueMaxArmRight;

    //constructor
    MeArm(int _pinServoLeft, int _pinServoRight, int _pinServoClaw, int _pinServoMiddle); 
  
    //destructor
    ~MeArm();

    
    virtual int servoAttach();  //should I have multiple meArms, always attach with their own functions, because pins can be different
    int prepare();

    //bool isReachable(int leftValue, int rightValue, int clawValue, int middleValue);   //no parameter is mandatory, because I want to be able to not have to check all values > cpp didn't agree with me
    bool isLeftReachable(int leftValue);
    bool isRightReachable(int rightValue);
    bool isClawReachable(int clawValue);
    bool isMiddleReachable(int middleValue);

    int leftArm(int value);
    int rightArm(int value);
    int clawOpen();
    int clawClose();
    int middleMiddle();

    int backwardStance();
    int forward();
    int base();
    int middleTurn (int input);
    int turn (int input);

    

  
};

#endif
  

  
