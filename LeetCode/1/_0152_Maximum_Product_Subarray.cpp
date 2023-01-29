#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int mx(int a, int b, int c){
        return max(max(a,b),max(b,c));
    }
    int mn(int a,int b, int c){
        return min(min(a,b),min(b,c));
    }
    int maxProduct(vector<int>& nums) {
        int max_here=nums[0],min_here=nums[0],max_far=nums[0];
        for(int i=1;i<nums.size();i++){
            int t=mx(nums[i],nums[i]*max_here,nums[i]*min_here);
            min_here=mn(nums[i],nums[i]*max_here,nums[i]*min_here);
            max_here=t;
            max_far=max(max_far,max_here);
        }
        return max_far;
    }
};