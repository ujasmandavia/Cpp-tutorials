//Binary search tree implementation

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct node{
  //Pointers to the left and right node
  node *left;
  node *right;

  //value
  int val;

  //Conastructor
  node(int v){
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree{
  node *root  //Root node of the tree

  //simple constructor sets the root to the nullptr
  BinarySearchTree(){
    root = nullptr;
  }

  //Simple method for inserting the nood
  node *insert_node(node *n,int v);

  //Simple method for searching the node inside a tree
  node *search(int v);

  //Function to find minimum in a tree
  node *find_min(node *n){
    while(n->left != nullptr)
      n = n->left;
    return n;
  }

  node *delet_node(node *n,int v);
};

//Recursively traverse the tree untill the node is nullptr
//(insertion point)

node *BinarySearchTree::insert_node(node *n,int v){
  //case that we are inserting the node here
  if(n==nullptr){
    cout << "X" << endl;
    return new node(d);
  }
  //case that the node is traverseing the left child's path
  else if(v < n->val){
    cout << "L";
    n->left = insert_node(n->left,v);
  }
  //case that node is traverseing the right child's path
  else if(v > n->val){
    cout << "R";
    n->right = insert_node(n->right,v);
  }
  //case we have duplicate entries(illegal)
  else{
    assert(false);
  }

  //if node was not null pointer,return it unchanges
  return n;
}

node *BinarySearchTree::search(int v){
  //temporary node for traveersing the node
  node *temp = root;

  //keep traversing the node until we find the node(or not)
  while(temp!= nullptr){
    //return the node we are looking for
    if(v == temp->val){
      cout << "X" << endl;
      return temp;
    }
    //Go down to the left
    else if(v < temp->val){
      cout << "L";
      temp = temp->left;
    }
    //Go down to the right path
    else{
      cout << "R";
      temp = temp->right;
    }
  }

  //We didn't find the node
  return nullptr;
}

node *BinarySearchTree::delet_node(node *n, int v){
  //Temperoray node for special case of noce with one child
  node *temp = root;

  if(n==nullptr)
    return n;

  else if(v < n->val){
    n->left = delet_node(n->left,v);
  }

  else if(v > n->val){
    n->right = delet_node(n->right,v);
  }
  //We found the node and now it's time to delet
  else{
    //Case 1: node with no child
    if(n->left == nullptr && n->right == nullptr){
      delete n;
      n =  nullptr;
    }

    //node with only one childran
    else if(n->left == nullptr){
      //node *temp = root;
      temp = temp->right;
      delete temp;
    }

    else if(n->right == nullptr){
      //node *temp = root;
      temp = temp->left;
      delete temp;
    }

    //Case 3: Node with two children
    else{
      temp = find_min(n->right);
      n->val = temp->val;
      n->right = delet_node(n->right,temp->val);
    }
  }
  return n;
}

int main(){
  //Create a new binary search tree
  BinarySearchTree bst;

  //Set the seed
  srand(1);

  //Insert 10 random node
  int val;
  vector<int> arr;
  for(int i=0;i<10;i++){
    //Randon number seed between 0 and 999
    val = rand() % 1000;

    //Save the number so we can search for it
    arr.push_back(val);
    cout << "Inserting node with val " << val << endl;

    //Insert the node
    bst.root = bst.insert_node(bst.root,val);
  }
  cout << endl;

  //Search for each of the inserted node
  for(int i:arr){
    cout << "Searching for the node with val " << i << endl;
    bst.search(i);
  }

  for(int i:arr){
    cout << "Deleting the node with val " << i << endl;
    bst.delet_node(i);
  }

  return 0;
}
