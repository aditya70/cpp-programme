#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long int c = 0,a=0;
        int n=nums.size();
        for (int i = 0; i < n - 1; i++) {
            a=0;
            for (int j = i + 1; j < n; j++) {
                if (nums[i]==nums[j]) a++;
                if(a>=k){cout<<a<<"gh "<<c<<"rt "<<endl;c+=n-i+1; break;}    
            }
            cout<<a<<" "<<c<<" "<<endl;
        }
        return c;
    }   
};