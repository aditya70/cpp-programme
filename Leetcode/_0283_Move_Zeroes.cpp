#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0,n=nums.size(),t;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                t=nums[j];
                nums[j]=nums[i];
                nums[i]=t;
                j++;
            }
        }
    }
};