#include <bits/stdc++.h>
using namespace std;
class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if(st.empty())return res;
        int s=-1,e=-1;
        for(int n:st){
            if(s<0)s=e=n;
            else if(n==e+1)e=n;
            else{
                res.push_back({s,e});
                s=e=n;
            }
        }
        res.push_back({s,e});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */