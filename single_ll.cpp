include "interface.h"

using namespace std;

int main(){
  LinkedList ll;

  //Insert few nodes, alternating at head and tail
  for(int i=0; i<5;i++){
    if(i%2)
      ll.insert_head(i);
    else
      ll.insert_end(i);
  }

  ll.insert_position(5,2);

  ll.delete_position(2);

  ll.delete_head();

  ll.delete_end();
  
  return 0;
}
