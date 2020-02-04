#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
  int n = strs.size();

  unordered_map<string,vector<string>> mymap;

  for(auto s:strs){
    string t = s;
    sort(t.begin(),t.end());
    mymap[t].push_back(s);
  }

  vector<vector<string>> anagrams;
  for(auto p:mymap){
    anagrams.push_back(p.second);
  }

  return anagrams;
}

int main(){

  vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> res;

  res = groupAnagrams(str);

  for(auto r:res){
    cout << r << endl;
  }
  return 0;
}
