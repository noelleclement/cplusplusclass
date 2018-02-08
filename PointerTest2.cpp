#include <iostream>
using namespace std;

int main(){

	int number = 1;
	int *pNumber = &number;

	cout << endl << "Content pNumber: " << pNumber << endl; 
	cout << "Address number: " << &number << endl;
	cout << "Value pointed pNumber: " << *pNumber << endl;
	cout << "Value number: " << number << endl; 

	*pNumber = 2;

	cout << endl << "Content pNumber: " << pNumber << endl; 
	cout << "Address number: " << &number << endl;
	cout << "Value pointed pNumber: " << *pNumber << endl;
	cout << "Value number: " << number << endl; 
	cout << "Address pNumber: " << &pNumber << endl;

}