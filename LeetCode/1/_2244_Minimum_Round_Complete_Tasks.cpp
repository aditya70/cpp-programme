#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int t:tasks) mp[t]++;
        int c=0;
        for(auto i:mp) {
            if(i.second<2) return -1;
            c+= (i.second+2)/3;
        }
        return c;
    }
};
int main(){
    return 0;
}