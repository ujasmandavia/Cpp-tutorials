//Smart Pointers

//Notes:
//0. Smart pointer is a class which wraps a raw pointer, to manage the life time of the pointer
//1. The most fundamental part of the smart pointer is to remove the chance of the memory leak
//2. It makes sure that the object is deleted if it is not reference anymore

//Types:
//1. Unique Pointers:
//   Allows only one owner of the underlying pointer

//2. Shared Pointer:
//   Allow multiple owner of the same pointer(Reference count in maintained)

//3. Weak Pointer
//   It is special type of shared pointer which doen't keep count of the reference

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <string>
#include <thread>

using namespace std;

class MyInt{
public:
  explicit MyInt(int* p = nullptr) { data = p; }
  ~MyInt() { delete data; }
  int& operator* () {return *data;}

private:
  int* data;
};

class Foo{
private:
  int x;
public:
  explicit Foo(int a): x(a) {}
  int getX(){ return x; }
~Foo() { cout << "Foo Destructor\n"; }
};

class Foo1{
private:
  int y;
public:
  Foo1(int b): y(b) {}
  int getY(){
    return y;
  }
  ~Foo1(){cout << "Foo1 dest\n";}
};

int main(){
  int* p = new int(10);
  MyInt myint(p);
  cout << *myint << endl;

  /*
  //Unique Ptr
  Foo* f = new Foo(100);
  cout << f->getX() << endl;   // Here in this part we have forgot to delete f
  //Thus we need to write delete f below here
  delete f; //This can be solved using smart pointers

  std::unique_ptr<Foo> q(new Foo(101));
  cout << q->getX() << endl;

  std::unique_ptr<Foo> p2 = make_unique<Foo>(201);
  cout << p2->getX() << endl;
  //OR
  //cout << (*p2).getX() << endl;

  //p1 = p2; //This will fail because you can copy the ownweship
  std::unique_ptr<Foo> p3 = std::move(q);

  Foo* q1 = p3.get();
  Foo* p4 = p3.release();
  */

  //Shared Ptr
  //Foo1* f = new Foo1(123);
  //cout << f->getY() << endl;
  //delete f;

  std::shared_ptr<Foo1> sp(new Foo1(234));
  cout << sp->getY() << endl;
  cout << sp.use_count() << endl;
  std::shared_ptr<Foo1> sp1 = sp;
  cout << sp.use_count() << endl;
  cout << sp1.use_count() << endl;

  auto sharedPtr = std::make_shared<int>(100);
  std::weak_ptr<int> weakPtr(sharedPtr);

  cout << "weakPtr.use_count() " << weakPtr.use_count() << endl;
  cout << "sharedPtr.use_count() " << sharedPtr.use_count() << endl;
  cout << "weakPtr.expired() " << weakPtr.expired() << endl;

  if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()){
    cout << "*sharedPtr: " << *sharedPtr << endl;
    cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << endl;
  }else{
    cout << "Don't get the resource" << endl;
  }

  weakPtr.reset();
  if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()){
    cout << "*sharedPtr: " << *sharedPtr << endl;
    cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << endl;
  }else{
    cout << "Don't get the resource" << endl;
  }



  return 0;
}
