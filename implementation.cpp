#include "interface.h"

using namespace std;

void LinkedList::insert_head(int v){
  node *new_head = new node(v);    //create a new node with the value v

  //Insert the node at the front of the list
  new_head->next = head;
  head = new_head;

  cout << "Head inserted with value: " << v << endl;
  print_list();
}

void LinkedList::insert_position(int v,int p){
  node *new_node = new node(v);  //create a new node with the value v

  //set the head as the new node if the list is empty
  if(head == nullptr){
    if(p==0)
      head = new_node;
    else
      assert(head == nullptr && p == 0);
  }
  else{
    node *temp = head;
    node *prev = nullptr;
    for(int i =0; i<p; i++){
      //check if insertion point is past potential new tail
      assert(temp != NULL);
      //update the previous and current node
      prev = temp;
      temp = temp->next;
    }
    //check if this is actually head insertion
    //otherwise perform normal insertion
    if(prev == nullptr){
      head = new_node;
      head->next = temp;
    }
    else{
      new_node->next = prev->next;
      prev->next = new_node;
    }
  }

  cout << "Position " << p << "insert with the value " << v << endl;
  print_list();
}

void LinkedList::insert_end(int v){
  node *new_tail = new node(v); //create new node with the value v

  //for an empty list
  if(head == nullptr)
    new_tail = head;
  else{
    node *temp = head;

    //traverse towards the end of the list
    while(temp->next != nullptr){
      temp = temp->next;
    }

    temp->next = new_tail;
  }

  cout << "Tail insert with the value " << v << endl;
  print_list();
}

void LinkedList::delete_head(){

  //check is list is empty
  assert(head != nullptr);

  //set head->next as the new node and delete old one
  node *temp = head;
  head = temp->next;
  delete temp;

  cout << "Head delete " << endl;
  print_list();
}

void LinkedList::delete_position(int p){
  //check if list is empty
  assert(head != nullptr);

  //traverse to the position of deletion
  node *temp = head;
  node *prev = nullptr;

  for(int i=0;i<p;i++){
    //check is deletion point is past the end of the list
    assert(temp != nullptr);
    prev = temp;
    temp = temp->next;
  }

  // Handle head deletion
  // Otherwise normal deletion
  if(prev == NULL){
      head = temp->next;
  }
  else{
      prev->next = temp->next;
  }
  delete temp;

  cout << "Position " << p << " delete" << endl;
  print_list();
}

void LinkedList::delete_end(){
  //check if the list is empty
  assert(head != nullptr);

  //traverse to the end of the list
  node *temp = head;
  node *prev = nullptr;
  while(temp->next != nullptr){
    temp = temp->next;
  }

  //Handle case with one 1 value in the list
  if(prev == nullptr)
    head = nullptr;
  else
    prev->next = temp->next;

  delete temp;

  cout << "Tail delete " << endl;
  print_list();
}

void LinkedList::print_list(){
  for(int i=0; i<72;i++){
    cout << "-";
  }

  cout << endl;

  node *temp = head;
  cout << "List\t";
  while(temp != nullptr){
    cout << temp->val << "\t";
    temp = temp->next;
  }

  cout << endl;

  for(int i=0;i<71;i++){
    cout << "-";
  }
  cout << endl;
}
