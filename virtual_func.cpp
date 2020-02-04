#include <iostream>

using namespace std;

class Animal{
public:
  void eat(){
    cout << "I'm eating generic food" << endl;
  }
};

class Cat : public Animal{
public:
  void eat(){
    cout << "I'm eating a cat food" << endl;
  }

};

class Dog : public Animal{
public:
  void eat(){
    cout << "I'm eating dog food" << endl;
  }
};

void function1(Animal* xyz){
  xyz->eat();
}

int main(){
  Animal* ptr;

  Cat catObj;
  Dog dogObj;

  ptr = &catObj;
  ptr = &dogObj;

  function1(ptr);

  return 0;
}
