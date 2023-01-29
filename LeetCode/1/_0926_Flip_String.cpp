#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, n = 0;
        for (char c : s) {
            if (c == '0')ans=min(n, ans + 1);
            else n++;
        }
        return ans;
    }
};