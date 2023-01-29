#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int a=0,n=height.size(),f=0,l=n-1,hf,hl;
        while(f<l){
            hf=height[f];
            hl=height[l];
            a=max(a,min(hf,hl)*(l-f));
            if(hf>hl) l--;
            else f++;
        }
        return a;
    }
};