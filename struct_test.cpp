#include <iostream>

using namespace std;

void a(int x){
  x++;
}

void b(int* x){
  x+=2;
}

void c(int& x){
  x+=4;
}

int main(){
  int x=0;
  a(x);
  b(&x);
  c(x);
  std::cout << x << "\n";
  return 0;
}
