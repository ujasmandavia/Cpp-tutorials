#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main(){
  //int n;
  //cin >> n;
  vector<int> A;
  A = {2,2,3,4,5};
  int n = A.size();

  long long S;

  for(int i=0; i<n; i++){
    //cin >> A[i];
    S+= A[i];
  }

  if(S & 1){
    cout << "NO!\n";
    return 0;
  }

  unordered_map<long long,int> first;
  unordered_map<long long,int> second;

  first[A[0]] = 1;

  for(int i = 1; i<n; i++){
    second[A[i]]++;
  }

  for(auto i:second){
    cout << i.first << "---" << i.second << endl;
  }

  long long sdash = 0;
  for(int i =0; i<n ;i++){
    sdash += A[i]; //first i numbers;
    if(sdash == S/2){
      cout << "YES 1\n";
      return 0;
    }

    else if(sdash <S/2){
      long long x = S/2-sdash; //delete that element x from the right hand side of the partition or second half and insert into first half
      if(second[x]>0){
        cout << "YES 2\n";
        return 0;
      }
    }

    else{
      long long y = sdash-S/2;
      if(first[y]>0){
        cout << "YES 3\n";
        return 0;
      }
    }
    first[A[i+1]]++;
    second[A[i+1]]--;
  }

  cout << "NO!\n";

  return 0;

}
