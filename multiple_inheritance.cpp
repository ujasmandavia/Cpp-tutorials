//Multiple Inheritance

#include <iostream>

using namespace std;

//base 1
class A{
public:
  void printMessage(){
    cout << "Class A print message function" << endl;
  }
};

//base 2
class B{
public:
  void printMessage(){
    cout << "Class B print message function" << endl;
  }
};

//derived class
class AB: public A, public B{

public:
  void printMessage(){
    //cout << "Class AB print message function" << endl;
    A::printMessage();
  }

};

int main(){

  AB objAB;
  objAB.printMessage();


  return 0;
}
