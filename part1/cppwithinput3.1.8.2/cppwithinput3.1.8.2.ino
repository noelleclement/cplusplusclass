//TODO:

  //variabelen in mearm.cpp in constructor, eventueel met const (kijken hoe doorgeven, uitbreidbaarheid)
    //
  //kijken waarom twee x op serial de zin, als input
  //ook echt iets doen met de return 0 (error handling)


#include "MeArm.h"
#include <cantino.h>

//using namespace cantino;    //no standard namespace, because multiple header files imported

int turnFirstGlobal = -10;    //if negative, don't continue 
int turnSecondGlobal = -10;

int pinLeft = 11;             //pins of mearm are determined in main application, so if pins are changed or multiple (same type of) mearms, easy change in application
int pinRight = 6;
int pinClaw = 10;
int pinMiddle = 9; 

MeArm mearm(pinLeft, pinRight, pinClaw, pinMiddle);     //create mearm object with given pins


int main(){


  askInput();                                                                         //ask user for values
  
  if(turnFirstGlobal <= 180 && turnFirstGlobal >= 0
     && turnSecondGlobal <= 180 && turnSecondGlobal >= 0){
    prog(5);                                                                          //if input between bounds, continue and run prog() for 5 loops
  }
  else{
    cantino::cout << "Please insert valid numbers, try again"<< cantino::endl;        //if input incorrect, errormessage, and you need to restart application
    //fyi: if you add askInput(); here, it will keep calling that function for some reason (doesn't wait for input)
  }
  
  return 0;
}



//asks user for input on what values the mearm needs to turn to (so only middle servo is influenced by user), through serial
int askInput(){
  
  
  int* pTurnFirstGlobal = &turnFirstGlobal;
  int* pTurnSecondGlobal = &turnSecondGlobal;
  
  cantino::cout << "What turn first? Pick something between 0 (right) and 180 (left)" << cantino::endl;
  cantino::cin >> *pTurnFirstGlobal;
  cantino::cout << "The MeArm is first going to turn: " << *pTurnFirstGlobal << cantino::endl;

  cantino::cout << "What turn second? Pick something between 0 (right) and 180 (left)" << cantino::endl;
  cantino::cin >> *pTurnSecondGlobal;
  cantino::cout << "The MeArm is first going to turn: " << *pTurnSecondGlobal << cantino::endl;


  //fyi:
    //if you change the content of askInput to something in which it will recall the function (fe if wrong input, try again), it will keep calling the function fsr 
    //if wished, also 'amount of times' can be asked for here, see the 'amount' given as an argument in prog()

  return 0;
}




//basic program with the 'steps' the mearm needs to go through for its functionality
//functions are from MeArm class
//forloop so not to overload the memory if ran for long time
int prog(int amount){

  for(int i=0; i<amount; i++){
    mearm.base();
    delay(1000);
    mearm.middleTurn(turnFirstGlobal);
    delay(1000);
    mearm.clawOpen();
    delay(1000);
    mearm.forward();
    delay(1000);
    mearm.clawClose();
    delay(1000);
    mearm.backwardStance();
    delay(1000);
    
    mearm.middleTurn(turnSecondGlobal);
    delay(1000);
    mearm.forward();
    delay(1000);
    mearm.clawOpen();
    delay(1000);
    mearm.backwardStance();
    delay(1000);
  }
}


