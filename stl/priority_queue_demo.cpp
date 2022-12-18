#include <bits/stdc++.h>

using namespace std;

int main(){
    // min heap
    priority_queue<int, vector<int>, greater<int> >  pq;
    pq.push(8);
    pq.push(18);
    pq.push(4);
    while (!pq.empty()){
        cout<<"\t"<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    priority_queue<int>  pq1;
    pq1.push(8);
    pq1.push(18);
    pq1.push(4);
    while (!pq1.empty()){
        cout<<"\t"<<pq1.top()<<" ";
        pq1.pop();
    }
    return 0;
}