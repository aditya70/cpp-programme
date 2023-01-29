#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0,ps=0,n=nums.size();
        vector<int> v(k);v[0]=1;
        for(int i=0;i<n;i++){
            ps=(ps+nums[i]%k+k)%k;
            c+=v[ps];
            v[ps]++;
        }
        return c;
    }
};