#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int a[26],b[26],n1,n2;
        memset(a,0,sizeof a);  memset(b,0,sizeof b);
        for(char c:word1)a[c-'a']++;  for(char c:word2)b[c-'a']++;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(a[i]&&b[j]){
                    a[i]--;b[i]++;
                    b[j]--;a[j]++;
                    n1=0,n2=0;
                    for(int k=0;k<26;k++)if(a[k])n1++;
                    for(int k=0;k<26;k++)if(b[k])n2++;
                    if(n1==n2) return 1;
                    a[i]++;b[i]--;
                    b[j]++;a[j]--;
                }
            }
        }
        return 0;
    }

};

