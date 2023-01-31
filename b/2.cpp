#include<bits/stdc++.h>
using namespace std;

vector<int> removeDup(vector<int> arr){
	vector<int> ans;
	unordered_set<int> s;
	for(int a:arr){
		if(s.count(a)<1){
			s.insert(a);
			ans.push_back(a);
		}
	}
	
	return ans;
}
int main(){
	vector<int> a={1,2,1,3,5};
	vector<int> ans=removeDup(a);
	for(int i:ans)cout<<i<<" ";
	return 0;
}
