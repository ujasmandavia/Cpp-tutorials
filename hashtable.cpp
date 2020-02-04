#include <iostream>
#include <list>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class HashTable{
private:
  int buckets;    //Number of buckets to store elements
  list<int> *table;    //Pointer to said bucket

public:
  //Constructer
  HashTable(int b){
    buckets = b;
    table = new list<int>[buckets];
  }

  void insert(int d);     //Insert into the hasttable

  void print();    //Print the hash table
};

void HashTable::insert(int d){
  int bucket = d%buckets;  //Simple hashfunction is modulo of buckets

  table[bucket].push_back(d); //Insert into the hastable bucket
}

void HashTable::print(){
  for(int i=0; i<buckets;i++){
    cout << "| Bucket " << i << " | ";
    for(auto j:table[i]){
      cout << "-> | " << j << " | ";
    }
    cout << endl;
  }
}

int main(){
  HashTable ht(8);  //create a hashtable with 8 bucktes

  srand(2);  //set the random number seed

  //Insert 20 random integer
  for(int i=0;i<20;i++){
    ht.insert(rand()%100);
  }

  ht.print();  //Print the sate of the hashtable.

  return 0;
}
