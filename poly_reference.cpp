//polymorphism and virtual function by coffee before arch

#include <iostream>
#include <vector>

using namespace std;

//Our base class with a virtual fucntion
class Mammal{
public:
  virtual void speak() const{
    std::cout << "I'm a mammal!\n";
  }
};

//Our first inherited class
class Dog : public Mammal{
public:
  void speak() const override{
    std::cout << "I'm a mammal, but also a dog!\n";
  }
};

//Our second inherited class
class Cat : public Mammal{
public:
  void speak() const override{
    std::cout << "I'm a mammal, but also a cat!\n";
  }
};

//We can treat objects of different types in a uniform way!
void callFunc(Mammal &m){
  m.speak();
}

int main(){
  //Let's create three objects!
  Mammal m;
  Dog d;
  Cat c;

  //We pass all three created objects to a function which implicitly upcasts those objects
  //Each will still call the correct method (dynamic dispatch)
  callFunc(m);
  callFunc(d);
  callFunc(c);

  return 0;
}
