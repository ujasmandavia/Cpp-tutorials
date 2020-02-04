//Condition Variable in c++ threading
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m1;
long balance = 0;

void addMoney(int money){
  std::lock_guard<mutex> lg(m1);
  balance+=money;
  cout << "Amount added and the current balance is " << balance << endl;
  cv.notify_one();
}

void withDrawMoney(int money){
  std::unique_lock<mutex> ul(m1);
  cv.wait(ul,[] { return balance != 0 ? true:false; });
  if(balance >= money){
    balance -= money;
    cout << "Amount dedeuted: " << money << endl;
  }else{
    cout << "Low in balance and this amount can't be dedeucted: " << money << endl;
  }
  cout << "Current balance is: " << balance << endl;
}

int main(){
  std::thread t1(withDrawMoney,600);
  std::thread t2(addMoney,500);

  t1.join();
  t2.join();

  return 0;
}
