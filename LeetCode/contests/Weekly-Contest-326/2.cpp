#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        long long n=1;
        for(auto i:nums) n*=i;
        int c=2;
        set<int> s;
        while(n>1)
        {
            if(n%c==0){
           // cout<<c<<" ";
           s.insert(c);
            n/=c;
            }
            else c++;
        }
        return s.size();
    }
};

int main(){
    Solution ob;
    // vector<int> v { 2,4,3,7,10,6 };
    // vector<int> vect{ 10, 20, 30 };
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    v.push_back(16);
    // v.push_back(10);
    // v.push_back(6);
    // v.push_back(2);
    cout<<ob.distinctPrimeFactors(v)<<endl;
    return 0;
}