#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for(string word:words){
            int len=word.length();
            vector<bool> dp(len+1);
            dp[0]=true;
            for(int i=1;i<=len;i++){
                for(int j=(i==len ? 1 : 0); !dp[i]&&j<i;j++){
                    dp[i]=dp[j]&&dict.count(word.substr(j,i-j));
                }
            }
            if(dp[len])ans.push_back(word);
        }
        return ans;  
    }
};