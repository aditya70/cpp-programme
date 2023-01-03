#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0,n=nums.size();
        for(int i:nums) s+=i;
        return ((n)*(n+1)/2)-s;
    }
};