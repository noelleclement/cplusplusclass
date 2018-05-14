//variabelen en constanten definieren en declareren (basistypen en andere types)
//flow control statements > done (forloops in mearm)
//arithmetic operatoren > done
//relational operatoren > done
//logical operatoren  > done
//bitwise operatoren > done
//functies met willekeurige parameters en return type
//extern
//static
//dynamic
//automatic
//void > done
//meervoudige overerving > done
//polymorphism met abstract base classes en virtual function overriding > done


#include <iostream>
using namespace std;

class Plant{

	public:
		bool likesShade;
		virtual void water()=0;
};

class Food{
	protected:
		int calories;
		bool isDelicious;

	public:
		void foodCanTalk(){
			cout << "I'm food and I can talk and that makes sense" << endl;
		}

};



class Succulent: public Plant{

	public:

		//bool likesShade;

		Succulent(){
			this->likesShade = false;
		}

		void water(){
			cout << "I'm a succulent and I need very little water" << endl;
		}
};

class Fern: public Plant{

	public:

		//bool likesShade;

		Fern(){
			this->likesShade = true;
		}

		void water(){
			cout << "I'm a fern and I loveeee water" << endl;
		}

};


class Pineapple: public Food{

	protected:
		//int calories;
		bool isDelicious;

	public: 
		int calories; 			//in public to demonstrate only possible to directly call from 'outside' function when not protected

		Pineapple(){
			this->calories = 180;
			this->isDelicious = true;
		}

		void foodCanTalk(){
			cout << "Pineapples are super cool and delicious. Some people think I shouldn't be on pizze" << endl;
		}

		int getCal(){
			return this->calories;
		}
};

class Spinach: public Plant, public Food{

	public: 
		//bool likesShade;
		int calories;
		bool isDelicious;

		Spinach(){
			this->likesShade = false;
			this->calories = 30;
			this->isDelicious = false;
		}

		void water(){
			cout << "pff okay, I'll add this method... Guess spinach needs a lot of water?" << endl;
		}

		void foodCanTalk(){
			cout << "Aweee come on, spinach can be very delicious!" << endl;
		}
};

class Pizza: public Food{

	protected:
		int calories;
		bool isDelicious;

	public:
		Pizza() {
			this->calories = 1200;
			this->isDelicious = false;
		}
	
		int getCal(){
			return this->calories;
		}

		//no foodCantalk, which is okay because not virtual, so will print the Food->foodCanTalk


};



int main(){
	Succulent succulent;			//initializing and declaring of objects
	Fern fern;
	Pineapple pineapple;
	Spinach spinach;
	Pizza pizza;

	Food* food1 = &spinach;			//pointer
	Plant &plant1 = spinach;		//reference

	food1->foodCanTalk();			//one way to call functions (when using pointer)
	plant1.water();					//other way to call functions (when using reference, or a 'regular' object)

	int pinCal = pineapple.calories;

	cout << "\nIf I eat pineapple on pizza, that is " << pinCal + pizza.getCal() << " calories " << endl ;		//both a variable and getter can be used in cout summations 	

	cout << "\nDo succulents like shade?" << endl;
	if(succulent.likesShade){
		cout << "yep!" << endl;
	}
	else{
		cout << "nope!" << endl;
	}

	cout << "\nDo ferns like shade?" << endl;
	if(fern.likesShade){
		cout << "yep!" << endl;
	}
	else{
		cout << "nope!" << endl;
	}

	cout << "\nDo succulents and ferns both like shade?" << endl;
	if(succulent.likesShade && fern.likesShade){
		cout << "yep!" << endl;
	}
	else{
		cout << "nope!" << endl;
	}

	cout << "\nDo either succulents or ferns like shade?" << endl;
	if(succulent.likesShade || fern.likesShade){
		cout << "yep!" << endl;
	}
	else{
		cout << "nope!" << endl;
	}

	cout << "\nDoes spinach have more calories than pineapple?" << endl;
	if(spinach.calories > pineapple.getCal()){
		cout << "yep!" << endl;
	}
	else{
		cout << "nope!" << endl;
	}

	cout << "\nWhat is 72 & 184? That would be: " << (72&184) << endl;
	cout << "Huh that's weird" << endl;
	cout << "Ooooh it's in bits!" << endl << "01001000 &" << endl << "10111000 =" << endl << "00001000" << endl;


	return 0;
}


//extern = variable can come from other file 

//static = variable is only 'known' in own file (globals, but only in the file), 
	//useful if you have several files in which there are variables that are declared in each, 
	//but need to only be referenced by their own file, not externally

//dynamic (memory allocation) =  
	//creating variables or objects that are saved in the heap (workingmemory?), not in stack (regular storage?) 
	//pointer in stack(<type>* <name>), memory location (new <type>) in heap 
		//fe 'int *p = new int;   *p = 5;' > creates the pointer and a memory location
	//if want the same pointer to point to different memory in heap: <name> = new <type>(<value>) 
		//fe 'p = new int(10);' 		> attention, can create garbage
	//to not create garbage: 'delete p;' before assigning to new memory location (like above)
		//doesn't remove pointer from stack, just the memory in heap
	//nullpointer: NULL or nullptr (c++11)

//automatic = 
	//the program will automatically decide what datatype should be used
	//can be useful for:
		//less rewriting when changing methodtypes (when called later in code, datatype of assigned variable for returnvariable, won't have to be changed as well)
			//fe auto name = getName(); (if getName() is changed from a std::string to a char* fe)
			//may give some problems if using 'name' (from above) later in code, because not all possible functionalities of it may be clear > so maybe more errorprone actually
		//when using/referencing a variable for part of code (fe iratation), easier to use auto, so not so long, fe forloops
	//& > reference etc still needs to be used

//const = variable that can't change value, if used in global variable for object necessary to define and declare in constructor, because otherwise it will change value 'later' 

//using = used when you want to alias a part of code (because it's long fe)








