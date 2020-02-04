//Operator overloading

#include <iostream>
#include <vector>

using namespace std;

class Test{
private:
  int x;
public:
  Test(int x = 0): x{x} {}

  friend istream& operator >> (istream& input, Test& obj);
  friend ostream& operator << (ostream& output, Test& obj);
};

istream& operator >> (istream& input, Test& obj){
  input >> obj.x;
  return input;
}

ostream& operator << (ostream& output, Test& obj){
  output << obj.x << endl;
  return output;
}


class Complex : public class Test{
private:
  int real, imaginary;
public:
  Complex(int a = 0, int b=0): real(a),imaginary(b) {}

  Complex operator + (Complex const& obj){
    Complex res;
    res.real = real + obj.real;
    res.imaginary = imaginary + obj.imaginary;
    return res;
  }

  void print(){
    cout << real << "+ i" << imaginary << endl;
  }

};

//conversion operator
class Fraction{
private:
  int num, den;
public:
  Fraction(int a, int b): num(a), den(b) {}

  operator float() const{
    return float(num)/float(den);
  }
};


//Conversion contructor for implicit conversion

class Point{
private:
  int x, y;
public:
  Point(int a=0,int b=0): x(a), y(b) {}

  void print(){
    cout << x << "," << y << endl;
  }
};

//Copy constructor vs assigning operator
class Test1{
public:
  Test1() {}
  Test1(const Test1 &t){
    cout << "Copy constructor called " << endl;
  }

  Test1& operator = (const Test1 &t){
    cout<<"Assignment operator called "<<endl;
    return *this;
  }
};

//When to use an assignment operator (we mostly use it when we are having pointers in the class) Test2 and Tes3
class Test2{
private:
  int *ptr;
public:
  Test2(int i=0) {ptr = new int(i);}
  void setValue(int i){
    *ptr = i;
  }
  void print(){
    cout << *ptr << endl;
    cout << "The address is: " << &ptr << endl;
  }
};

class Test3
{
    int *ptr;
public:
    Test3 (int i = 0)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
    Test3 & operator = (const Test3 &t);
};

Test3 & Test3::operator = (const Test3 &t)
{
   // Check for self assignment
   if(this != &t)
     *ptr = *(t.ptr);

   return *this;
}

//When to use [] operator (mostly when to check out of bound status )
class Array{
private:
  int *ptr;
  int size;
public:
  Array(int *, int);
  int &operator[] (int);

  void print() const;
};

int &Array::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return ptr[index];
}

// constructor for array class
Array::Array(int *p = NULL, int s = 0)
{
    size = s;
    ptr = NULL;
    if (s != 0)
    {
        ptr = new int[s];
        for (int i = 0; i < s; i++)
            ptr[i] = p[i];
    }
}

void Array::print() const
{
    for(int i = 0; i < size; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}

int main(){
  Test t;
  cin >> t;
  cout << t;

  Complex c1(10,5), c2(2,4);
  Complex c3 = c1+c2;
  c3.print();

  Fraction f(2, 5);
  float val = f;
  cout << val;

  Point p(20,30);
  p.print();
  p = 40;
  p.print();

  Test1 t1, t2;
  t2 = t1;
  Test1 t3(t1);
  getchar();

  Test2 a1(5);
  Test2 a2;
  a2 = a1;
  a1.setValue(10);
  a2.print();

  Test3 b1(5);
  Test3 b2;
  b2 = b1;
  b1.setValue(10);
  b2.print();

  int a[] = {1, 2, 4, 5};
  Array arr1(a, 4);
  arr1[2] = 6;
  arr1.print();
  arr1[8] = 6;

  return 0;
}
