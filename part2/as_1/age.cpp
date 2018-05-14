#include <iostream>

#include "age.h"

using namespace std;

void Age::askAge(){
	cout << "What is your age?" << endl;
	cin >> age;								//no Age:: needed since it's already in a function of Age::

	if(age>=18 && age<=99){
		cout << "Don't forget to do your taxes before May 1th!" << endl;
	}
	else if(age<18 && age>=0){
		cout << "You're too young to worry about taxes, yay!" << endl;
	}
	else if(age<0){
		cout << "You're not even born yet, what are you doing on a computer" << endl;
	}
	else{
		cout << "Wow you're super old, congratulations! Can you teach me your secret?" << endl;
	}
}

//&& not necessary if 'compared' well enough that <18 and <99 only needed (it will choose the right one automatically)
//can be more clear to only use <, not <=
//see if you can avoid 'not's