#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
};
bool compareInterval(Interval i1, Interval i2){
    if(i1.start == i2.start){
        return i1.end > i2.end;
    }
    return (i1.start < i2.start);
}
int f(int n, int time[], int cost[]){
    int res=0;
    vector<Interval> v;
    for(int i=0;i<n;i++){
        Interval o;
        o.start = cost[i];
        o.end = time[i];
        v.push_back(o);
       // v.push_back(make_pair(cost[i],time[i]));
    }
    sort(v.begin(),v.end(), compareInterval);

    for(int i=0;i<n;i++){
       // cout<<v[i].start<<" "<<v[i].end<<endl;
    }
    int s=0,e=n,t=0;
    while(s<e){
        if(t>0){
            e--;
            t--;
            // cout<<"da "<<t<<" "<<s<<" "<<e<<endl;
        } else{
            t += v[s].end;
            res += v[s].start;
            s++;
            // cout<<t<<" "<<s<<" "<<res<<endl;
        }
    }   
    return res;
}

int main(){
    int t[]={1,1,5,3,2};
    int c[]={1,2,3,4,5};
    // int t[]={1,2,2,3};
    // int c[]={1,2,2,3};
    int n=sizeof(t)/sizeof(t[0]);
    cout<<f(n,t,c); 
    return 0;
}