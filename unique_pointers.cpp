//Smart Pointers

#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

// The Cherno

class Entity{
public:
  Entity(){
    cout << "Created Entity!" << endl;
  }

  ~Entity(){
    cout << "Destroyed Entity!" << endl;
  }

  void Print(){}
};

//Shared pointers works on reference counting

//Now the coffeebeforearch thing *youtube




int main() {
  /*
  {
    std::shared_ptr<Entity> e0;
    {
      //std::unique_ptr<Entity> entity(new Entity());
      //entity->Print();

      //Shared Pointers
      std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
      std::weak_ptr<Entity> weakEntity = sharedEntity;
      e0 = sharedEntity;
    }
  }
  */
  //Create a shared pointer
  //Shared Pointers are valid while at least one shared pointer points to the data. The last pointer frees it
  shared_ptr<int> shared_int_1(new int(5));
  shared_ptr<int> shared_int_2 = shared_int_1;

  //Print out the use count
  cout << "Use count of shared_int: " << shared_int_1.use_count() << endl;

  //Create a weak pointer
  //Weak pointer points to memory, but are not an owner
  //Good when we don't want an owner, or handling cyclic references

  weak_ptr<int> weak_int = shared_int_1;

  //print out use count
  cout << "Use count of shared_int: " << weak_int.use_count() << endl;

  //Conert the weak pointer to the shared pointer and print again
  auto shared_int_3 = weak_int.lock();
  cout << "Use count of shared_int: " << shared_int_3.use_count() << endl;

  //Destroy the memory for the 2 of the shared pointers and check uniqueness
  shared_int_1.reset();
  shared_int_2.reset();
  cout << "Use count of shared_int: " << shared_int_3.use_count() << endl;
  cout << "shared_int_3 is unique?: " << shared_int_3.unique() << endl;

  shared_int_3.reset();
  cout << "shared int valid?: " << shared_int_3.get() << endl;

  //Create a unique pointer
  //Unique pointers, but are the only owners of the memory it points to
  //Good for exclusive ownership
  unique_ptr<int> unique_int(new int(10));

  cin.get();
  return 0;
}
