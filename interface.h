//Singly linkedlist implementation

#include <iostream>
#include <cstddef>
#include <assert.h>

//Simple node of the list
//It contains value, and a pointer to the next node

struct node{
  int val;
  node *next;

  //Constructor
  node(int v){
    val = v;
    next = nullptr;
  }
};

class LinkedList{
private:
  node *head;  //Pointer to the head

public:
  //Constructor
  LinkedList(){
    head = nullptr;
  }

  //Add node at the head position
  void insert_head(int v);

  //Add node at the desired nth position
  void insert_position(int v, int p);

  //Add node at the end of the list
  void insert_end(int v);

  //Delete node at the head psotion
  void delete_head();

  //Delete the node at the nth position
  void delete_position(int p);

  //Delete at the end of the node
  void delete_end();

  //Print the list
  void print_list();
};
