#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
         int a;
        for(int i:nums) {
           if(s.find(i) == s.end()) s.insert(i);
           else {a=i; break;};
        }
        return a;
    }
};