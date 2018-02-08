#include "MeArm.h"
#include <cantino.h>
#include <Servo.h>

using namespace cantino;

Servo left, right, claw, middle;
int turnFirstGlobal = -10;    //if negative, don't continue etc
int turnSecondGlobal = -10;


int main(){
  prepare();
  delay(100);
  
  if(turnFirstGlobal <= 180 && turnFirstGlobal >= 0
     && turnSecondGlobal <= 180 && turnSecondGlobal >= 0){
    prog();
  }
  
  return 0;
}


int servoAttach(){
  left.attach(11);
  claw.attach(10);
  middle.attach(9);
  right.attach(6);
}

int prepare(){
  Serial.begin(9600);
  servoAttach();
  base();
  askInput();
}

int askInput(){
  int inputTurnFirst;
  int inputTurnSecond;
  
  cout << "What turn first? Pick something between 0 (right) and 180 (left)" << endl;
  cin >> inputTurnFirst;
  cout << "The MeArm is first going to turn: " << inputTurnFirst << endl;
  turnFirstGlobal = inputTurnFirst;

  cout << "What turn second? Pick something between 0 (right) and 180 (left)" << endl;
  cin >> inputTurnSecond;
  cout << "The MeArm is first going to turn: " << inputTurnSecond << endl;
  turnSecondGlobal = inputTurnSecond;

  return 0;
}

int prog(){

  base();
  delay(1000);
  middleTurn(turnFirstGlobal);
  delay(1000);
  clawOpen();
  delay(1000);
  forward();
  delay(1000);
  clawClose();
  delay(1000);
  backwardStance();
  delay(1000);
  
  middleTurn(turnSecondGlobal);
  delay(1000);
  forward();
  delay(1000);
  clawOpen();
  delay(1000);
  backwardStance();
  delay(1000);

  prog();
}


int base(){
  backwardStance();
  middleMiddle();
  return 0;
}


int turn(int turnValue){
  backwardStance();
  middleTurn(turnValue);
  return 0;
}

int middleTurn(int turnValue){
  middle.write(turnValue);
  return 0;
}


int backwardStance(){
  leftArm(10);
  rightArm(0);
  return 0;
}

int forward(){
  leftArm(40);
  rightArm(40);
  return 0;
}


////////////////

int leftArm(int value){
  left.write(value);
  return 0;
}

int rightArm(int value){
  right.write(value);
  return 0;
}

int clawOpen(){
  claw.write(0);
  return 0;
}

int clawClose(){
  claw.write(55);
  return 0;
}

int middleMiddle(){
  middle.write(83);
  return 0;
}

int middleLeft(){
  middle.write(135);
  return 0;
}

int middleRight(){
  middle.write(45);
  return 0;
}


