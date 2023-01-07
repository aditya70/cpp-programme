#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c=0,d=0,start=0;
        for(int i=0;i<gas.size();i++){
            c+=gas[i]-cost[i];
            if(c<0){
                start=i+1;
                d+=c;
                c=0;
            }

        }
        return (c+d) >= 0 ? start : -1;
    }
};