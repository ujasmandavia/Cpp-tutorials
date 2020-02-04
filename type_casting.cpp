//Type casting in c++
//Static_cast, dynamic_Cast and const_cast
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

//STATIC_CAST

//1. It performes implicit conversions between types
int main(){
  float f = 3.5;
  int a;
  a=f;
  a = std::static_cast<int>(f);
  return 0;
}

//2. It is ofter used for conversion operator or conversion constructor
class Int{
private:
  int x;
public:
  Int(int a = 0) : x{a} { cout << "Conversion Constructor is called\n"}
  operator string(){
    cout << "Conversion Operator is called\n"
    return to_string(x);
  }

};
int main(){
  Int obj(3);
  string str1 = obj;  //conversion operator
  obj = 20;  //conversion constructor

  string str2 = static_cast<string>(obj);
  obj = static_cast<Int>(30);
}

//3. It is more restrictive that C-Style cast
///reason : because char* to int* is allowed in C-Style but not with static_cast

int main(){
  char c;  //1 byte data
  int *p = (int*)&c;   //4 byte data
  *p = 5;   //Pass at compile time though fails at run time

  int *ip = static_cast<int*>(&c);  //Fail with compile time error

  return 0;
}

//4. It avoids cast from derived to private base ptr
class Base{

};

class Derived : private Base{

};

int main(){
  Derived d1;
  Base* bp1 = (Base*)&d1;               //Allowed at compile time
  Base* bp2 = static_cast<Base*>(&dp2); //Not allowed at compile time
}


//5. Use for all upcast and not for the downcast(use dynamic_Cast for down cast)

class Base1{

};
class Derived2 : public Base1{

};

class Derived2 : public Base1{

};

int main(){
  Derived1 d1;
  Derived2 d2;

  //This is upcasting
  Base1* bp3 = static_cast<Base1*>(&d1);
  Base1* bp4 = static_cast<Base1*>(&d2);

  //This is downcasting
  //It is not possible using static_Cast and for this we have to use dynamic_cast
  Derived1 *dp1 =  static_cast<Derived1*>(bp2);
  Derived2 *dp2 = static_cast<Derived *>(bp2);

  return 0;
}

//6. It is prefered when converting to void* or from void*

int main(){
  int i=10;
  void *v = static_cast<void*>(&i);
  int *ip = static_cast<int*>(v);
}


//Dynamic casting

//It is only used for polymorphic classes having virtual func
//It is mostly used for down casting
//It also have an run time over head because it checks objects at runtime

class Base{
  virtual void print(){ cout << "Base!" << endl;}
};

class Derived1 : public Base{
  void print() { cout << "Derived1" << endl;}
}

class Derived2 : public Base{
  void print() { cout << "Derived2" << endl;}
}

int main(){
  Derived1 d1;
  Base* bp = dynamic_cast<Base*>(&d1);
  Derived1* dp2 = dynamic_cast<Derived1*>(bp);
  if(dp2 == nullptr)
    cout << "NULL\N";
  else
    cout << "Not null and returning stuff\n"

  return 0;
}


//Const casting

//It is normally used to cast the const or volatile qualifiers of ptr or reference
// The type mist be of ptr, ref or ptr-to-member type

//1. When the actual refered object is not const
int main(){
  cosnt int a1 = 10;
  cosnt int* b1 = &a1;
  int* d1 = const_cast<int*>(b1);
  *d1 = 15; //Invalid and undefined behaviour

  int a2 = 20;
  const int* b2 = &a2;
  int* d2 = const_cast<int*>(b2);
  *d2 = 30;  //Valid code

  return 0;
}

//2. When we need to call some 3rd party library when it is taking object as non-const but not changing that
void third(int* x){
  int k = 10;
  cout << k+(*x);
}

int main(){
  const int x = 20;
  const int* px = &x;
  third(const_cast<int*>(px));

  return 0;
  
}
