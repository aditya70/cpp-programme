
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> player;
        int n=scores.size();
         int ans=0;
        for(int i=0;i<n;i++)player.push_back({ages[i],scores[i]});
        sort(player.begin(),player.end());
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=player[i].second;
            ans=max(ans,dp[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(player[i].second>=player[j].second)dp[i]=max(dp[i],dp[j]+player[i].second);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
