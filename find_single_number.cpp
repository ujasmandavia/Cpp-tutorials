// Given an array of integers, every element appears 
// twice except for one. Find that single one.
// Input : [1 2 2 3 1]
// Output : 3

#include <iostream>
#include <vector>

using namespace std;
// #include <bits/stdc++.h>

using namespace std;
int FindSingleNumber(vector<int> nums)
{
  // Write your code here
  int n = nums.size();
  int single_num = 0;
  for(int i =0; i<n; i++){
    single_num ^= (nums[i]);
    cout << "single_num: " << single_num << endl;

  }
  return single_num;
}

int main(){
  int arr[] = {16,16,2, 2, 9, 77,29,29,77, 5, 8, 5, 7, 7, 9, 1, 1};
  vector<int> A (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  int output = FindSingleNumber(A);
  cout << "Output: " << output << endl;
}
