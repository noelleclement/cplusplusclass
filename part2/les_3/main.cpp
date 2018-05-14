#include <iostream> 

using namespace std;

class A {
public:
	virtual void f() = 0;

};

class AB: public A{
public:
	virtual void f();

};

class AC: public A{
public:
	virtual void f();

};

void A::f (){
	cout << "dit is A" << endl;
}

void AB::f (){
	cout << "dit is AB" << endl;
}

void AC::f (){
	cout << "dit is AC" << endl;
}

int main(){

	A *a [2];
	a[0] = new AB;
	a[1] = new AC;

	for(int i=0; i<2; i++){
		a[i] -> f();
	}

	return 0;
}

