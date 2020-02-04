#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int sum(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4, int target){
  int count = 0;
  int sum = 0;
  unordered_map<int,int> mymap;  //It keeps the count of the sum as a key and its frequency as its value

  // count frequency of each sum obtained from the
  // pairs of nums1[] and nums2[] and store them in 'mymap'
  for(int i=0; i<nums1.size(); i++){
    for(int j=0; j<nums2.size();j++){
      mymap[nums1[i] + nums2[j]]++;
    }
  }

  // generate pair from arr3[] and arr4[]
  for(int k=0; k<nums3.size(); k++){
    for(int l=0; l<nums4.size();l++){
      // calculate the sum of elements in
            // the pair so generated
      int pair_sum = nums3[k] + nums4[l];

      if(mymap.find(target-pair_sum) != mymap.end())
        count += mymap[target-pair_sum];
        //sum = mymap[target-pair_sum];
    }
  }

  return count;
}

int main(){
  vector<int> nums1 = {};
  vector<int> nums2 = {};
  vector<int> nums3 = {};
  vector<int> nums4 = {};
  int target = 30;

  int end_count = sum(nums1,nums2,nums3,nums4,target);
  cout << end_count << endl;

  return 0;
}
