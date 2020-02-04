#include <iostream>
#include <algorithm>

using namespace std;


class NumberList{

private:

  struct ListNode{
    double value;                //The value in the node
    struct ListNode *next;       //Pointer pointing towards the next node
  };

  ListNode *head;                //Pointer pointing to the head

public:

  NumberList(){
    head = nullptr;
  }        //Constructor

  ~Numberlist();     //Decosntructor

  void appendNode(double);
  void insertNode(double);
  void deletNode(double);
  void reverseList(double);
  void displayList(double);

};

void NumberList::appendNode(double num){

  ListNode *newNode;   //To point to a new node
  ListNode *nodePtr;   //To move through the node

  //Allocate the new node and store the number in it
  newNode = new ListNode;
  newNode->value = num;
  newNode->next = nullptr;

  //if there are no nodes in the list make newNode the first node

  if(!head){
    head = newNode;
  }
  else{
    nodePtr = head;    //Initalize the nodePtr to the head of the list;

    //Find the last node in the list
    while(nodePtr->next)
      nodePtr = nodePtr->next;

    //Insert newNode as the last node
    nodePtr->next = newNode;
  }
}

void NumberList::displayList(){

  ListNode *nodePtr;

  nodePtr = head;

  while(nodePtr){
    cout << nodePtr->value << endl;
    nodePtr = nodePtr->next;
  }
}

void NumberList::insertNode(double num){
  ListNode *newNode;
  ListNode *nodePtr;
  ListNode *previousNode = nullptr;

  newNode = new ListNode;
  newNode->value = num;

  if(!head){
    head = newNode;
    newNode->next = nullptr;
  }

  else{
    nodePtr = head;
    previousNode = nullptr;

    while(nodePtr!=nullptr && nodePtr->value < num){
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if(previousNode==nullptr){
      head = newNode;
      newNode->next = nodePtr;
    }

    else{
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }

}

void NumberList::deletNode(double num){
  ListNode *nodePtr;
  ListNode *previousNode;

  if(!head)
    return;

  if(head->value == num){
    nodePtr = head->next;
    delet head;
    head = nodePtr;
  }

  else{
    nodePtr = head;

    while (nodePtr != nullptr && nodePtr->value != num){
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (nodePtr){
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

int main(){

  NumberList list;

  list.appendNode(2.5);
  list.appendNode(7.9);
  list.appendNode(12.6);

  list.insertNode(10.2);

  list.deletNode(2.5);

  list.displayList();
  return 0;

}

NumberList::~NumberList(){

  ListNode *nodeptr;
  ListNode *nextNode;

  nodePtr = head;

  while(nodePtr != nullptr){
    nextNode = nodePtr->next;

    delet nodePtr;

    nodePtr = nextNode;
  }
}
