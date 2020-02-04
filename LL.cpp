struct Node{
  int data;
  Node *link;
};
Node *head = nullptr;   //global

int main(){
  Node *prt = new Node();
  ptr->data = 2;
  ptr->link = nullptr;
  head = ptr;
  return 0;
}

//Inserting a node at the beginning or end of a list
void insertBeg(int d){
  Node *ptr = new Node();
  ptr->data = d;
  ptr->link = head;       //pointer will point where head is pointing
  head = ptr;    //head will point to the new ptr created as head
}

void insertEnd(int d){
  Node *ptr = new Node();
  ptr->data = d;
  ptr->link = nullptr;
  if(head == nullptr){
    head = ptr;
  }
  else{
    Node *temp = head;      //temp will point to the head
    while(temp->link != nullptr){
      temp = temp->link;
    }
    temp->link = ptr;       //temp's next will point towards new node
  }
}

//Delete a node at the beginning or end of a list
void deleteFront(){
  if(head == nullptr)
    cout << "List is empty" << endl;
  Node *ptr = head;     //ptr will point to the head
  head = head->link;
  free(ptr);
}

void deleteEnd(){
  Node *ptr, *prev;
  if(head == nullptr)
    cout << "List is empty" << endl;
  else(head->link == nullptr){
    ptr = head;
    head = nullptr;
    free(ptr);
  }
  ptr = head;
  while(ptr->next != nullptr){
    prev = ptr;
    ptr = ptr->link;
  }
  prev->link = nullptr;
  free(ptr);
}

//Reverse a linkedlist
void reverseList(){
  Node *p,*c,*n;
  p = nullptr;  //previous node
  c = head;     //current node
  while(c != nullptr){
    n = c->link;    //next node
    c->link = p;
    p = c;
    c = n;
  }
  head = p;
}
