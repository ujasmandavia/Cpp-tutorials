//Hybrid Inheritance and it's diamond problem
//It combines hierarchal inheritance and multiple inheritance

#include <iostream>

using namespace std;

class Base{
protected:
  int val;
};

//First Derived class class 1
class Derived1 : virtual public Base{
public:
  Derived1() {val = 1;}

  void getValue(){
    cout << "Derived1 val is: " << val << "\n";
  }
};

//Second derived class
class Derived2 : virtual public Base{
public:
  Derived2() {val = 2;}

  void getValue(){
    cout << "Derived2 val is: " << val << "\n";
  }
};

//Derived class 3 performing multiple inheritacne
class Derived3 : public Derived1, public Derived2{
public:
  //There are 2 copies of val in derived 3
  void getValue(){
    cout << "Int value is: ";
    Derived1::getValue();
  }
};

int main(){
  Derived3 d3;
  d3.getValue();

  return 0;
}
