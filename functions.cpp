//Functions in c++
//Inline, overloading and function multiple return value
//Pass by value
#include <iostream>

using namespace std;


void passByValue(int x, int y){
  int z =x;
  x= y;
  y=z;
}

//Pass by reference
void passByRef(int &x, int &y){
  int z=x;
  x= y;
  y=z;
}

//Pass by pointer
void passByPtr(int* x, int* y){
  int z = *x;
  *x = *y;
  *y = z;
}

int main(){
  int a=5, b=6;
  cout << "Before swapping: " << endl << "a: " << a << endl <<"b: " << b << endl << endl;

  //passByValue(a,b);
  //passByRef(a,b);
  passByPtr(&a,&b);

  cout << "After swapping: " << endl << "a: " << a << endl <<"b: " << b << endl << endl;
}
