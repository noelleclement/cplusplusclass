#include <iostream>

using namespace std;

int main(){

	int const size = 10;

	int intArray[size];
	int *array = intArray;

	for(int i=0; i<10*size; i+=10){
		*(array++) = i; 		
	}

	for(int i=0; i<size; i++){
		cout << intArray[i] << endl;
	}

	cout << *(intArray+2) << endl;



	int *array2 = new int[size];

	for(int i=0; i<10*size; i+=size){
		*(array2++) = i;				//make a copy, this increments the pointer location, so not really an array anymore
	}

	delete [] (array2-size);			//dont do this

	int *pI;
	*pI = 3;
	cout << *pI << endl;

	return 0;
}


//my g++ isnt really safe
