//Weak Pointer to avoid cycling dependencies in shared pointers
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

usingn namespace std;

struct Mother{
  ~Mother(){
    cout << "Mother gone!\n";
  }

  void setSon(const std::shared_ptr<Son> s){
    mySon = s;
  }

  void setDaughter(const std::shared_ptr<Daughter> d){
    myDaughter = d;
  }

  //std::weak_ptr<Son> mySon;
  //std::weak_ptr<Daughter> myDaughter;

  std::shared_ptr<Son> mySon;
  std::shared_ptr<Daughter> myDaughter;
};

struct Son{
  Son(std::shared_ptr<Mother> m) : myMother(m) {}
  ~Son(){
    cout << "Son is gone\n";
  }
  std::shared_ptr<const Mother> myMother;
};

struct Daughter{
  Daughter(std::shared_ptr<Mother> m) : myMother(m) {}
  ~Daughter() { cout << "Daughter gone\n"; }

  std::shared_ptr<const Mother> myMother;
};

int main(){
  std::cout << endl;
  {
    std::shared_ptr<Mother> mother = std::shared_ptr<Mother>(new Mother);
    std::shared_ptr<Son> son = std::shared_ptr<Son>(new Son(mother));
    std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>(new Daughter(mother));
    mother->setSon(son);
    mother->setDaughter(daughter);
  }
  std::cout << endl;
  return 0;
}
