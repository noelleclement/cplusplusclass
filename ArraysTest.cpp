#include <iostream>
using namespace std;

//array of integers declared
//ask user for how many elements in array (max 100)
//array is filled with random numbers between 1 and 100
//highest number is found and printed on screen


int main(){

	int inputArray[100];
	int amountElements;
	int biggestElement;

	cout << "How many elements do you want in the array (1-100)?" << endl;
	cin >> amountElements;

	if(amountElements<=100 && amountElements>0){

		//fill array with # of amountElements with random numbers
		srand(time(NULL));
		for (int i=0; i < amountElements; i++){
			inputArray[i] = rand() % 100+1;
		}

		//print array
		cout << "This is the array: " << endl;
		for (int i=0; i < amountElements; i++){
			cout << inputArray[i] << ", ";
		}

		//find highest number
		for (int i=0; i < amountElements; i++){
			if(inputArray[i] > biggestElement){
				biggestElement = inputArray[i];
			}
		}

		//print highest number
		cout << endl << "Biggest number in array is:" << biggestElement << endl;
	}
	else{
		cout << "Error: incorrect amount" << endl;
	}

	return 0;

}