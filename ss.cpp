//Longest Palindromic Substring
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int PalindromicSS(string s){
  if(s.size() == 1)
    return 1;

  vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));

  for(int i=0 ;i<s.size() ; i++){
    dp[i][i] = 1;
  }

  for(int l=2; l<=s.size(); l++){
    for(int i=0;i<s.size()-l+1;i++){
      int j = i+l-1;
      if(l == 2 && s[i] == s[j]){
        dp[i][j] = 2;
      }
      dp[i][j] = s[i]==s[j] ? dp[i+1][j-1] + 2:max(dp[i+1][j],dp[i][j-1]);
      /*
      else if(s[i] == s[j]){
        dp[i][j] = dp[i + 1][j-1] + 2;
      }else{
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
      */
    }
  }
  return dp[0][s.size()-1];

}

int main(){
  string s = "bbbab";
  getline(cin,s);

  int result = PalindromicSS(s);

  cout << result << endl;
}
