#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int> m;
        for(auto n:nums) m[n]++;
        for(auto a:m) {
            if(k==0){if(a.second>1)c++;}
            else if(m.find(a.first+k)!=m.end()) c++;
        }
        return c;
    }
};