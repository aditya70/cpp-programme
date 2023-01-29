#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int c=0,k=0,n=costs.size();
        for(int i=0;i<n;i++){
            k+=costs[i];
            if(k<=coins) c++;
            else break;
        }
        return c;
    }
};