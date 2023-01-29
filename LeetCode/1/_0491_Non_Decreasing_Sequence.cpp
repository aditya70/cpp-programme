#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      int n=nums.size();
      set<vector<int>> ans;
      for(int b=1;b<(1<<n);b++){
          vector<int> v;
          for(int i=0;i<n;i++){
             if (((b >> i) & 1) == 1) {
                    v.push_back(nums[i]);
                }
          }
          if(v.size()>=2){
            bool f=1;
            for(int i=0;i<v.size()-1;i++){
                f &= v[i] <= v[i + 1];
            }
            if(f==1)ans.insert(v);
          }
      }
      return vector(ans.begin(),ans.end());  
    }
};