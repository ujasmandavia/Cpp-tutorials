//Unique lock in mutex
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex m1;
int buffer = 0;

/*
//Example 1:

void task(const char* threadNumber, int loopFor){
  std::unique_lock<mutex> lock(m1);  //Automatically calls lock on m1
  for(int i=0; i<loopFor; i++){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
}

int main(){
  thread t1(task,"T0 ",10);
  thread t2(task,"T1 ",10);
  t1.join();
  t2.join();
  return 0;
}
*/


//Example 2:

void task(const char* threadNumber, int loopFor){
  std::unique_lock<mutex> lock(m1,std::defer_lock); //Does not call lock on mutex m1, because used defer_lock
  lock.lock(); //We need to call this explicitly
  for(int i=0; i<loopFor; i++){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
}

int main(){
  thread t1(task,"T0 ",10);
  thread t2(task,"T1 ",10);
  t1.join();
  t2.join();
  return 0;
}
