#include <iostream>
using namespace std;


void increment(int *pI){
	(*pI)++;

}

void increment2(int &i){
	i++;
}

int &lowestNumber (int &a, int &b, int &c){
	if(a<b){
		if(a<c){
			return a;
		}
		else{
			return c;
		}
	}
	else{
		if(b<c){
			return b;
		}
		else{
			return c;
		}
	}
}

int main (){
	
	int i = 4;
	increment(&i);
	cout << i << endl;


	increment2(i);
	cout << i << endl;

	int c1=5, c2=4, c3=8;

	lowestNumber(c1, c2, c3) = 10;

	cout << c1 << ' ' <<  c2 << ' ' << c3 << endl;  


	int p = 4;
	int &q = p;
	q++;

	cout << p << ' ' << q << endl;
}

