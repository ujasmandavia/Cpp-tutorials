#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct comparator{
  bool operator()(const pair<int, int> & a, const pair<int, int>& b){
    return a.first+a.second < b.first+b.second;
  }
}; //comparator

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
  priority_queue< pair<int, int>, vector<pair<int, int> >,comparator > qu;
  vector<vector<int>> res;

  for(int i =0; i<nums1.size() && i<k; i++){
    for(int j =0; j<nums2.size() && j<k; j++){
      if(qu.size() < k)
        qu.push(make_pair(nums1[i], nums2[j]));
      else if(qu.top().first+qu.top().second > nums1[i]+nums2[j]){
        qu.pop();
        qu.push(make_pair(nums1[i],nums2[j]));
      }
    }
  }

  while(!qu.empty()){
    auto p = qu.top();
    res.push_back({p.first, p.second});
    qu.pop();
  }
  reverse(res.begin(),res.end());
  return res;
}

int main(){
  vector<int> nums1 = {1,7,11};
  vector<int> nums2 = {2,4,6};
  int k = 3;
  vector<vector<int>> res = kSmallestPairs(nums1,nums2,k);

  for(int i = 0; i<res.size() ; i++){
    cout << "pair: " << res[i][0] << "," << res[i][1] << endl;
  }

  return 0;
}
