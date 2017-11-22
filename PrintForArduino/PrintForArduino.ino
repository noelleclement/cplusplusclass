#include <cantino.h>
using namespace cantino;  //standard namespace

int main(){

  //System.out.print isn't needed with this Cantino library
  cout << "Hoi ik ben: " << endl << "Noëlle " << endl << "Clement " << endl << "0935050 " << endl << "Rotterdam " << endl;

  //Trying out a CString
  char *s = "Dit is een CString";
  cout << s << endl;
}

/*
 * no stl support in Cantino, because it doesnt work great on arduino (takes up a lot of memory, which we dont have a lot of on an Arduino Uno)
 * CString better
 */
