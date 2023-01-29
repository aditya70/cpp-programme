#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices[0], mp=0;
        for(int i=1;i<prices.size();i++){
            if(b>prices[i]) b=prices[i];
            else if(prices[i]-b>mp) mp=prices[i]-b;
        }
        return mp;
    }
};