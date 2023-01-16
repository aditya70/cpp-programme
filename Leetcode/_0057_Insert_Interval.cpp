#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        return {min(v1[0], v2[0]), max(v1[1], v2[1])};
    }
    bool overlap(vector<int>& v1, vector<int>& v2) {
        return min(v1[1], v2[1]) - max(v1[0], v2[0]) >= 0;
    }
    void add(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool f = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                f = 1;
                break;
            }
        }
        if (!f) {
            intervals.push_back(newInterval);
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        add(intervals, newInterval);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> c = {intervals[i][0], intervals[i][1]};
            while (i < intervals.size() && overlap(c, intervals[i])) {
                c = merge(c, intervals[i]);
                i++;
            }
            i--;
            ans.push_back(c);
        }
        return ans;
    }
};
