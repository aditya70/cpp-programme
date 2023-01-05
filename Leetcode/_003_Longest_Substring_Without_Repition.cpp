#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n == 0) return n;
        unordered_map<char, int> m;
        int st=0,max_l=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(m.find(c) != m.end()) st=max(st,m[c]+1);
            m[c]=i;
            if(max_l<(i-st+1)) max_l=i-st+1;
        }
        return max_l;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abba");
    return 0;
}