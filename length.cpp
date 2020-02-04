#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

// "abcbacbb"
using namespace std;

int length(string s){
  int n = s.size();
  vector<int> longest{0,1};
  unordered_map<char,int> lastSeen;

  int start = 0;

  for(int i=0; i<n; i++){
    char ch = s[i];
    if(lastSeen.find(ch) != lastSeen.end())
      start = max(start,lastSeen[ch]+1);
    if(longest[1]-longest[0] < i+1-start)
      longest = {start,i+1};
    lastSeen[ch] = i;
  }
  //string result = s.substr(longest[0],longest[1]-longest[0]);

  return (longest[0],longest[1]-longest[0]);
  //return result.size();
}

int main(){
  string s = "abcabcbb";

  int res;

  res = length(s);

  cout << res << endl;

  return 0;

}
