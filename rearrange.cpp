#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void Rearrange(string &S, int s, int e){
  while(getline(cin,S)){
    for(int i=s; i<=e;i++){
      for(int j=e; j>=0; j--){
        int temp = S[j];
        S[j] = S[j-1];
        S[j-1] = temp;
      }
    }
  }
  cout << "String: " << S << endl;
}

int main(){
  string S = "ABCHEDGHI";
  int s = 8;
  int e =8;

  Rearrange(S,s,e);
  return 0;
}
