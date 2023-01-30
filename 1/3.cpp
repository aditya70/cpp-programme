#include <bits/stdc++.h>
using namespace std;

string ast(string s,int width){
	for(int i=0;i<width;i++)s=s+"*";
	return s;
}
vector<string> solution(string text, int width){
	vector<string> res;
	string s1=ast("*",width);
	res.push_back(s1);
	int n=text.size(),c=0;
	string s="*  ";
	for(int i=0;i<n;i++){
		c++;
		s=s+text[i];
		if(c>width-2){
			res.push_back(s+"*");
			s="*";
			c=0;
		}
		if(text[i]=='.'||text[i]=='!'||text[i]=='?'){
			if(c<width)s=ast(s,width-1);
			res.push_back(s+"*");
			s="*  ";
		}
		
	}
	res.push_back(s1);
	return res;
}

int main(){
	vector<string> ans =solution("Hi! This is the article you have to format properly. Could you do that for me,please?",16);
	for(string s:ans)cout<<s<<"\n";
	return 0;
}
