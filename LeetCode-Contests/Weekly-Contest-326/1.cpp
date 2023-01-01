#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countDigits(int num) {
        int c=0;
      //  set<int> s;
        int n=num;
        while(num>0){
            int r=num%10;
            if(r!=0 && n%r ==0) c++;
            num=num/10;
        }
        // for(auto i:s){
        //     if(n%i == 0)c++;
        // }
        return c;
    }
};

int main(){
    Solution ob;
    cout<<ob.countDigits(1248);
    return 0;
}