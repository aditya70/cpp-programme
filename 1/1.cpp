#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> a){
	vector<string> res;
	int n=a.size();
	for(int i=1;i<n;i++){
		char c1=a[i-1][0];
		char c2=a[i][a[i].size()-1];
		cout<<c1<<" "<<c2<<"\n";
		string s="";
		s = s+c1+c2;
		cout<<s<<"\n";
		res.push_back(s);
	}
	string s="";
	s=s+a[n-1][0]+a[0][a[0].size()-1];
	res.push_back(s);
	return res;
}

int main(){
	vector<string> r={"I","have","a","nice","surprise"};
	vector<string> ans=solution(r);
	cout<<"ans"<<ans.size()<<"\n";
	for(string s:ans)cout<<s<<" ";
	return 0;
}
