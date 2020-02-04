//Reverse a linked list

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

using namespace std;

struct node{
  node *next;

  int val;

  node(int v){
    val = v;
    next = nullptr;
  }
};

class Reverse_LL{
private:
  node *head; //pointer pointing towards the head

public:
  //Constructor
  Reverse_LL(){
    head = nullptr;
  }

  node *reverse_ite(node *head);

  void reverse_rec(node *n);

  node *insert(node *head,int v);

  void print();
};

node *Reverse_LL::reverse_ite(node *head){
  node *curr,*prev,*next;
  curr = head;
  prev = nullptr;
  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    curr = next;
  }
  head = prev;
  return head;
}

void Reverse_LL::reverse_rec(node *n){
  if(n->next == nullptr){
    head = p;
    return;
  }
  reverse_rec(n->next);
  node *m = n->next;
  m->next = n;
  n->next = nullptr;

  //orelse
  //n->next->next = m;
}

node *Reverse_LL::insert(int v){
  node *new_node = new node(v);

  //for an empty list
  if(head == nullptr)
    new_node = head;
  else
    node *temp = head;

  while(temp != nullptr){
    temp = temp->next;
  }
  temp->next = new_node;

  cout << "Node is inserted here with the value " << v << endl;
}

void Reverse_LL::print(){
  node *temp = head;

  while(temp != nullptr){
    cout << temp->val << "\t";
    temp = temp->next;
  }
  cout << endl;
}

int main(){
  Reverse_LL rll;

  ll.insert(2);
  ll.insert(5);
  ll.insert(6);
  ll.insert(4);
  ll.insert(7);

  ll.print();

  ll.head = ll.reverse_ite(head);

  ll.print();

  ll.head = ll.reverse_rec(head);

  ll.print();

  //I need to write another function here to create a list by inserting elements into it.
  return 0;
}
