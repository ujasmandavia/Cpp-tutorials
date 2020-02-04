//Min heap
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

class minHeap{
private:
  //current size of the heap
  int size;
  //Max size of heap
  int capacity;
  //Store elements as a vector
  vector<int> heap;
  //Return the parent index
  int parent(int i){return (i-1)/2;}
  //Return the left child
  int left(int i){return 2*i+1;}
  //Return the right child
  int right(int i){return 2*i-1;}

public:
  //Constructor
  minHeap(int capacity);
  //Insert the key into min heap
  void insert(int k);
  //Extract the minimum element
  int extractMin();
  //Recursively heapify a sub tree
  void heapify(int i);
  //Print the heap
  void printHeap();

};

//Constructor that sets the heap size and capacity
minHeap::minHeap(int capacity){
  size = 0;
  this->capacity = capacity;
  heap.resize(capacity);
}

//Insert the key into the min heap
void minHeap::insert(int k){
  //Make sure there is still space in heap
  if(size == capacity){
    cout << "Min heap is full" << endl;
    return;
  }

  //Increase the amount of elements in the heap
  size++;

  //Insert the new key at the end
  int i = size - 1;
  heap[i] = k;

  //Fix the min heap property
  //Moves the element up until i>=parent or root
  while(i!=0 && heap[parent(i)] > heap[i]){
    swap(heap[i],heap[parent(i)]);
    i = parent(i);
  }
}

//Recursive function to maintain the structure
void minHeap::heapify(int i){
  //Set initial condition
  int l = left(i);
  int r = right(i);
  int smallest = i;

  //Find the smallest element of the three
  if((l<size) && (heap[l] < heap[smallest])){
    smallest = l;
  }
  if((r<size) && (heap[r] < heap[smallest])){
    smallest = r;
  }

  //If the smallest of l or r, continue heapify
  if(smallest != i){
    swap(heap[i],heap[smallest]);
    heapify(smallest);
  }
}

//Remove the smallest element and fix the order
int minHeap::extractMin(){
  //Check if heap is empty
  if(size == 0){
    cout << "EMPTY HEAP" << endl;
    return -1;
  }
  else if(size == 1){
    size--;
    return heap[0];
  }
  else{
    int root = heap[0];

    //Maintain the heap order and then shape
    heap[0] = heap[size-1];
    size--;
    heapify(0);

    //Return minimum element
    return root;
  }
}

//Print the heap in a pretty format
void minHeap::printHeap(){
  int power = 0;
  int value = 1;
  for(int i =0; i<size; i++){
    if(i==value){
      cout << endl;
      power += 1;
      value += (1 << power);
    }
    cout << heap[i] << " ";
  }
  cout << endl;
}

int main(){
  //Number of elements for our min heap
  int N = 15;

  //Declare a heap with size of 10 elements
  minHeap heap(N);

  //Insert N random numbers
  for(int i =0; i<N; i++){
    cout << "Inserting element " << i+1 << endl;
    heap.insert(rand() % 100);
    heap.printHeap();
    cout << endl;
  }
  return 0;
}
