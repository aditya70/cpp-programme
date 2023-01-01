#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.length(),i=0,c=0;
        if(n==0) return 0;
        int num=0,prev;
        while(i<n){
            int ch=(int) s[i]-'0';
            if (ch>k) {
                return -1;
            }   
             bool f=0;
             while (i<n && num<k) {
                ch=(int) s[i]-'0';
                 if (ch>k) {
                     return -1;
                 } 
                // prev = num;
                num = num*10 + ch;
                cout<<" "<<num<<endl;
                i++;
                f=1;
             }
            if (f) {
             c++;
            num=ch;
            i--;
            }
             cout<<ch<<" "<<num<<endl;
            i++;
        }
        if (c==0) return -1;
        return c;
    }
};

int main()
{
    Solution ob;
    cout<<ob.minimumPartition("165462",60);
    return 0;
}