#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canPartition(vector<int>& nums,vector<int>& res, int start_index, int k, int cur_sum, int cur_num, int target){
  if(k==1)
    return true;

  if(cur_sum == target && cur_num > 0)
    return canPartition(nums, res, 0, k-1, 0, 0, target);

  for(int i = start_index; i<nums.size(); i++){
    if(!res[i]){
      res[i] = 1;
      if(canPartition(nums,res,i+1,k,cur_sum+nums[i],cur_num++,target))
        return true;
      res[i] = 0;
    }
  }
  return false;
}


bool canPartitionKSum(vector<int>& nums, int k){
  int sum = 0;
  for(int n:nums)
    sum += n;

  if(sum %k != 0)
    return false;

  vector<int> res(nums.size(),0);

  return canPartition(nums,res,0,k,0,0,sum/k);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main(){
  vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  bool ret = canPartitionKSum(nums,k);

  string out = boolToString(ret);

  cout << out << endl;
}
