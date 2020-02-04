//Timed mutex in c++
//Basically exploring try_lock_for and try_lock_util
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i){
  if(m.try_lock_for(std::chrono::seconds(1))){
    ++myAmount;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Thread " << i << "Entered\n";
    m.unlock();
  }else{
    cout << "Thread " << i << "Couldn't enter\n";
  }
}

int main(){
  thread t1(increment,1);
  thread t2(increment,2);

  t1.join();
  t2.join();

  cout << myAmount << endl;
  return 0;
}
