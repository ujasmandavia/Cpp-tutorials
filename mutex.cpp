//Mutex in c++
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int myAmount = 0;
mutex m;

void addMoney(){
  m.lock();
  ++myAmount;    //This critical region
  m.unlock();
}

int main(){
  thread t1(addMoney);
  thread t2(addMoney);

  t1.join();
  t2.join();

  cout << myAmount << "\n";
  return 0;
}
