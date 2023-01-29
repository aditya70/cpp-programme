#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=nums[0],cs=0;
        for(auto& i:nums){
            cs+=i;
            s=max(s,cs);
            if(cs<0)cs=0;
        }
        return s;
    }
};