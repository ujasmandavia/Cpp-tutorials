//Longest Increasing subsequence
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int lengthofLIS(vector<int>& nums){
  int n = nums.size();
  vector<int> res;
  for(int i=0;i<n; i++){
    auto it = lower_bound(res.begin(),res.end(),nums[i]);
    if(it == res.end()){
      res.emplace_back(nums[i]);
    }
    else
      *it = nums[i];
  }
  return res.size();
}

int main(){
  vector<int> num = {10,9,2,5,3,7,101,18};
  int result = lengthofLIS(num);

  cout << result << endl;

  return 0;
}
