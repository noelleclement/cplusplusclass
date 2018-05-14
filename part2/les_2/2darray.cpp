#include <iostream>

using namespace std;

int main(){

	int size = 3;
	int intArray[size][size];
	int value = 0;

	for(int iRow = 0; iRow<size; iRow++){
		for(int iCol = 0; iCol<size; iCol++){
			intArray[iRow][iCol] = value++;
		}
	}

	for(int iRow = 0; iRow<size; iRow++){
		for(int iCol = 0; iCol<size; iCol++){
			cout << intArray[iRow][iCol] << ' ';
		}
		cout << endl;
	}
}

//dont start appnames with number (like I did here)