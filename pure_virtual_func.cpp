//Pure virtual function and abstract classes
#include <iostream>

using namespace std;

class Shape{
public:
  virtual void getArea()=0;  //pure virtual function

  //This has become an abstract class and we cannot create an object of the abstract class
};

class Circle: public Shape{
public:
  void getArea(){
    cout << "Enter circle radius" << endl;
    int radius;
    cin >> radius;
    cout << "Area of circle is: " << (3.14*radius*radius) << endl;
  }
};

class Rectangle: public Shape{
public:
  void getArea(){
    cout << "Enter rectangle length and the width" << endl;
    int l,w;
    cin >> l;
    cin >> w;
    cout << "Area of rectangle is: " << (l*w) << endl;
  }
};

int main() {
  Circle c1;
  c1.getArea();

  Rectangle r1;
  r1.getArea();


  return 0;
}
