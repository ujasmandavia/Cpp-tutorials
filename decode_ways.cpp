//Decode ways
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numDecoding(string s){
  int n = s.size();

  if(n ==0 || s[0] == '0')
    return 0;

  vector<int> count(n+1,1);
  count[0] = 0;

  for(int i=1; i<n; i++){
    if(s[i-1] == '1' || s[i-1] =='2' && s[i] <='6')
      count[i+1] = count[i] + 1;
    else
      count[i+1] = count[i];
  }

  return count[n];
}

int main(){
  string s = "226";

  int result = numDecoding(s);

  cout << result << endl;
}
