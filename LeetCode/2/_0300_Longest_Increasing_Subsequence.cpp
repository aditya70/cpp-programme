#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
              // cout<<" "<<nums[i]<<" "<<nums[j]<<"\n";
				if(nums[i]>nums[j])dp[i]=max(dp[i],1+dp[j]);
			}
          // cout<<dp[i]<<endl;
			ans=max(ans,dp[i]);
		}
		return ans;
    }
};
int main(){
	return 0;
}

/*
 * Time Limited exceeded if cout statements are there.
 * /
