//Function and Class templates
#include <iostream>

using namespace std;
/*
int add(int x, int y){
  return (x+y);
}

float add(float x, float y){
  return (x+y);
}

double add(double x, double y){
  return (x+y);
}
*/

template <typename T,typename U>
U add(T x, U y){
  return (x+y);
}

template <typename T>
class Weight{
private:
  T kg;
public:
  void setData(T x){
    kg = x;
  }
  T getData(){
    return kg;
  }
};

int main(){
  int a = add<int>(3,4);
  float b = add<float>(2.3f,4.5f);
  double c = add<double>(4.556,5.782);
  float d = add<int,float>(3,4.6f);

  cout << "int val is: " << a << "\n";
  cout << "float val is: " << b << "\n";
  cout << "double val is: " << c << "\n";
  cout << "int/float val is: " << d << "\n";

  Weight <int>body;
  body.setData(70);
  cout << "The body weight is: " << body.getData() << endl;

  Weight <double>body1;
  body1.setData(70.556);
  cout << "The body weight is: " << body1.getData() << endl;



  return 0;
}
