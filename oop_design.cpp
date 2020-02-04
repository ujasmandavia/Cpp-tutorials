//Inheritance

#include <iostream>

using namespace std;

class MyBase{
public:
  void show(){
    cout << "Base class show function called" << endl;
  }
  virtual void print(){
    cout << "Base class print function called" << endl;
  }
};

class MyDerived : public MyBase{
  void show(){
    cout << "Derived class show function called" << endl;
  }
  void print(){
    cout << "Derived class print function called" << endl;
  }

};
int main(){
  MyBase *baseptr;
  MyDerived derivedObj;

  baseptr = &derivedObj;

  //run time polymorphism
  baseptr->print();   //derived class print function was called
  baseptr->show();    //base class shpw function was called

  return 0;
}
