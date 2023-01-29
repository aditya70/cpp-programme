#include <bits/stdc++.h>
// #include <boost/functional/hash.hpp>
using namespace std;
// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2) return n;
        //  unordered_map<pair<int,int>, int, boost::hash<pair<int,int>> > mp;
        unordered_map<pair<int,int>,int, hash_pair > mp;
        int maxp=0,opoint,vpoint,cmax;
        for(int i=0;i<n;i++){
            cmax=opoint=vpoint=0;
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1]) opoint++;
                else if(points[i][0]==points[j][0]) vpoint++;
                else{
                    int ydif=points[j][1]-points[i][1];
                    int xdif=points[j][0]-points[i][0];
                    int g=__gcd(xdif,ydif);
                    if (mp.find(make_pair(ydif/g,xdif/g)) == mp.end()){
                        mp[make_pair(ydif/g,xdif/g)] = 1;
                    } else {
                        mp[make_pair(ydif/g,xdif/g)] += 1;
                    }
                   // mp[make_pair(ydif/g,xdif/g)]++;
                   cmax=max(cmax,mp[make_pair(ydif/g,xdif/g)]);
                // cmax=max(cmax,1);
                }
                cmax=max(cmax,vpoint);
            }
            maxp=max(maxp,cmax+opoint+1);
            mp.clear();
        }
        return maxp; 
    }
};