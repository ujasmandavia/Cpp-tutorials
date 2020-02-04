#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int X=0,Y=0;
mutex m1,m2;

void doSomeWorkForSeconds(int seconds){ this_thread::sleep_for(chrono::seconds(seconds)); }

void incrementXY(int& XorY, mutex& m, const char* desc){
  for(int i=0;i <5; i++){
    m.lock();
    ++XorY;
    cout << desc << XorY << endl;
    m.unlock();
    doSomeWorkForSeconds(1);
  }
}

void consumeXY(){
  int useCount = 5;
  int XplusY =0;
  while(1){
    int lockResult = try_lock(m1,m2);
    if(lockResult == -1){
      if(X!=0 && Y!=0){
        --useCount;
        XplusY += X+Y;
        X=0;
        Y=0;
        cout << "X PLUS Y " << XplusY << endl;
      }
      m1.unlock();
      m2.unlock();
      if(useCount == 0) break;
    }
  }
}

int main(){
  thread t1(incrementXY, ref(X), ref(m1), "X ");
  thread t2(incrementXY, ref(Y), ref(m2), "Y ");
  thread t3(consumeXY);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
