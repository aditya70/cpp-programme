#include <bits/stdc++.h>

using namespace std;

struct Interval
{
    int start,end;
};

bool compareInterval(Interval i1, Interval i2) {
    return i1.start < i2.start;
}

int main(){
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr+n);
    cout<<"sorted array increasing"<<endl;
    for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";
    cout<<"decreasing order "<<endl;
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";
    Interval arr1[]
        = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sort(arr1, arr1+n1, compareInterval);
    for (int i = 0; i < n1; i++) cout<<" "<<arr1[i].start<< " "<<arr1[i].end<<endl;
    return 0;
}