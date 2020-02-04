//Function templete
#include <iostream>

using namespace std;

//Function overloading example for the sum_overload finction

int sum_overload(const int a, const int b){
  return a+b;
}

double sum_overload(const double a, const double b){
  return a+b;
}

//To avoid the rewriting of the same fuction name for different datatypes we use function templete

template <typename T>
T sum( const T a, const T b){
  return a+b;
}

template <typename T, typename U>
U sum(const T a, const U b){
  return a+b;
}

int main(){
  int a_i = 10;
  int b_i = 20;
  double a_d = 12.12;
  double b_d = 13.47;

  //Print out the sum usingoverloading functions
  cout << "Overload int sum: " << sum_overload(a_i,b_i) << endl;
  cout << "Overload double sum: " << sum_overload(a_d,b_d) << endl;

  //Print out the sum using the function templete with explicit types
  cout << "Templated int sum: " << sum<int>(a_i,b_i) << endl;
  cout << "Templated double sum: " << sum<double>(a_d,b_d) << endl;

  //Print out sum using a templeted functions with implicit types
  cout << "Templated int sum with implicit types: " << sum(a_i,b_i) << endl;
  cout << "Templated double sum with implicit types: " << sum(a_d,b_d) << endl;

  //Print out sum using a templeted function with multiple types
  cout << "Templated int/double sum: " << sum(a_i,b_d) << endl;
  cout << "Templated double/int sum: " << sum(a_d,b_i) << endl;

  return 0;
}
