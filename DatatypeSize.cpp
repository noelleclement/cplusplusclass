#include <iostream>
using namespace std;

int main(){

	signed short a;
	unsigned short b;
	signed long c;
	unsigned long d;
	float e;
	int f;

	cout << "The datasize of the following datatypes: " << endl
		 << "Signed short: " << sizeof(a) << " bytes" << endl
		 << "Unsigned short: " << sizeof(b) << " bytes" << endl
		 << "Signed long: " << sizeof(c) << " bytes" << endl
		 << "Unsigned long: " << sizeof(d) << " bytes" << endl
		 << "Float: " << sizeof(e) << " bytes" << endl
		 << "Int: " << sizeof(f) << " bytes" << endl;
}