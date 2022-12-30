#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long n=0,num=x;
        while (x>0)
        {
           n=(n*10)+x%10;
           x=x/10;
        }
        if(n==num) return true;
        return false;       
    }
};

int main(){
    Solution sol;
    cout<<sol.isPalindrome(121);
    return 0;
}

