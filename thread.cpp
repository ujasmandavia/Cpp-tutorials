//Threading in c++
#include <iostream>
#include <thread>
#include <mutex>

/*
thread example: A way to initiate a single thread using a callable object
std::thread thread_object(callable);

A callable can be either of three types
1. A fucntion pointer
2. A function object
3. A lambda expression


//Launching a thread using a function pointer
void foo(param){
  //Do something;
}

// The parameters to the function are put after the comma
std::thread thread_object(foo,params);

//Lunching thread using lambda expression
auto f = [](params){

  //Do something;

};

std::thread thread_object(f,params);

//We can also pass lambda function directly to the constructor
std::thread thread_object([](params) {
  //Do something;
};,params);

//Define a class of the function objects
class fn_objects_class{
  //Overload () operator
  void operator () (params){
    //Do something;
  }
};

//create a thread object
std::thread thread_object(fn_class_object(), params);

*/

using namespace std;

void foo(int Z){
  for(int i=0 ;i<Z; i++){
    cout << "Thread using function pointers as callable\n";
  }
}

//A callable object
class thread_obj{
public:
  void operator () (int X){
    for(int i=0 ;i<X; i++){
      cout << "Thread using fucntion object as callable\n";
    }
  }
};

int main(){
  cout << "Threads 1,2 and 3 operating independently\n";

  //This thread is launched by using function pointer as callable
  thread th1(foo,3);

  //This thread is launched by using function object as callable
  thread th2(thread_obj(),3);

  // Define a Lambda Expression
  auto f = [](int x) {
    for (int i = 0; i < x; i++)
        cout << "Thread using lambda"
          " expression as callable\n";
  };

  //This thread is launched using lambda expression as callable
  thread th3(f,3);

  //Wait for the threads to finish
  //Wait for thread 1 to finish
  th1.join();

  //Wait for thread 2 to finish
  th2.join();

  //Wait for thread 3 to finish
  th3.join();

  return 0;
}
