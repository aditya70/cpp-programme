#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ump;
        int n=nums.size(),ans,c=0;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            if (ump[nums[i]]>c){
                c=ump[nums[i]]; ans=nums[i];
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v;
    v.push_back(2);
    Solution ob;
    cout<<ob.majorityElement(v);
    return 0;
}