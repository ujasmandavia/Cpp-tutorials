//Friend in c++
//Friends function and friends classes
#include <iostream>
using namespace std;

//Friends function
class Distance{
private:
  int meters;

public:
  Distance(int x): meters{x} {}

  void displayData(){
    cout << meters << endl;
  }

  friend void addValue(Distance &d);
};

void addValue(Distance &d){
  d.meters = d.meters + 10;
}

//Friend class
class Myclass1{
  friend class Myclass2;  //this basically suggests that Myclass2 is a friend of Myclass1
private:
  int x;
public:
  Myclass1(int x_): x(x_) {}
};

class Myclass2{
public:
  void showData(Myclass1 obj){
    cout << "x val in myclass 1 is: " << obj.x << "\n";
  }
};

int main(){
  Distance d1(0);
  d1.displayData();

  addValue(d1); //It is gonna pass this by reference
  d1.displayData();

  Myclass1 obj1(5);
  Myclass2 obj2;
  obj2.showData(obj1);




  return 0;
}
