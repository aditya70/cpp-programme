
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long s=0l;
        priority_queue<int> pq;
        int i=0;
        for(int i:nums) pq.push(i);
        while (!pq.empty() && i<k){
            int t=pq.top();
            if(t==0) break;
            s+=t;
            pq.pop();
            if(t%3==0)
            pq.push(ceil(t/3));
            else  pq.push(1+ceil(t/3));
            i++;
        }
        return s;
    }
};