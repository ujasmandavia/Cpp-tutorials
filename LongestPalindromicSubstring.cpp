//Longest Palindromic Substring
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> helper(string s, int left, int right){
  while(left >=0 && right < s.size()){
    if(s[left != s[right]])
      break;
    left--;
    right++;
  }
  return {left+1,right};
}

string LongestPalindromicSubstring(string s){
  vector<int> currLongest{0,1};
  for(int i=0; i<s.size(); i++){
    vector<int> odd = helper(s,i-1,i+1);
    vector<int> even = helper(s,i-1,i);
    vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd:even;
    currLongest = currLongest[1] - currLongest[0] > longest[1] - longest[0] ? currLongest:longest;
  }
  return s.substr(currLongest[0],currLongest[1]-currLongest[0]);
}

int main(){
  string s = "babas";

  while (getline(cin, s)) {
    string ret = LongestPalindromicSubstring(s);
    string out = (ret);
    cout << out << endl;
  }
  //string res = LongestPalindromicSubstring(s);

  //getline(cin,res);

  //cout << res << endl;



  return 0;
}
