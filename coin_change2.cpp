#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;
void add(int& a, int& b){
  a += b;
  if(a>=mod)
    a-=mod;
}

int uniqueChange(int amount, std::vector<int>& coins){
  vector<int> dp(amount+1);
  dp[0] = 1;
  for(const auto& coin:coins){
    for(int i=coin; i<=amount; ++i){
      add(dp[i],dp[i-coin]);
      // res = (dp[i] + dp[i-coin])%mod;   //if you don't want to use an addd fucntion
    }
  }
  return dp[amount];
}

int main(){
  vector<int> coins = {1,5,10,25,50,100};
  int amount = 58930; //4,58390,etc ......
  int res = uniqueChange(amount,coins);
  cout << "Number of disticnt sequences of coins: " << res << endl;
}
