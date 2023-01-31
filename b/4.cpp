#include <iostream>
#include <unordered_set>
using namespace std;

bool f(string word1, string word2){
	unordered_set<string> s;
	int n=word1.size();
	string t="";
	for(int i=0;i<n;i++){
		t=t+word1.substr(i,n)+word1.substr(0,i);
		s.insert(t);
		t="";
	}
	//for(string st:s)cout<<st<<endl;
	if(s.find(word2)!=s.end())return true;
	return false;
}

int main(){
	cout<<f("sample","plesam")<<endl;
	return 0;
}
