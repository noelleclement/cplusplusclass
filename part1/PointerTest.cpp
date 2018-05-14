#include <iostream>
using namespace std;

int main(){
	int x;
	int *p;
	p = &x;

	*p = 9;

	cout << "Adres x:" << &x << endl << "Adres *p: " << p << endl;

	if(&x==p){
		cout << "Ja, kijk hij doet het, de waarde van x is: " << x << endl;
	}
}