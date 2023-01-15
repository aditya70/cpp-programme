#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dsum(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n=n/10;
        }
        return s;
    }
    int differenceOfSum(vector<int>& nums) {
        int s=0,d=0;
        for(int n:nums) {
            s+=n;
            d+=dsum(n);
        }
        return abs(s-d);
    }
};