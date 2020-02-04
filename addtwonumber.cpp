//Add two numbers

struct Node{
  node * next;
  int val;

  Node(int v){
    val = v;
    next = nullptr;
  }
};

class Solution{
public:
  Node *addTwoNumber(Node *l1, Node *l2){
    Node *head = nullptr;
    Node *prev = nullptr;

    int carry = 0;
    while(l1 || l2){
      int sum = (l1? l1->val:0) + (l2? l2->val:0) + carry;
      cout << "Sum: " << sum << endl;
      carry = sum/10;
      int val = sum%10;
      Node *curr = new Node(val);

      if( !head)
        head = curr;
      if(prev)
        prev->next = curr;
      prev = curr;

      l1 = l1? l1->next:nullptr;
      l2 = l2? l2->next:nullptr;
    }

    if(carry>0){
      Node *l = new Node(carry);
      prev->next = l;
    }
    return head;
  }
};
