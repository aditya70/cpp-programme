#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int c=1, m=points[0][1], n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]>m) {c++;m=points[i][1];}
            else {m=min(m,points[i][1]);}
        }
        return c;
    }
};