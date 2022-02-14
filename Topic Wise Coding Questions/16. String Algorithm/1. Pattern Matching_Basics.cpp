#include<bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p){
	int n=s.length();
	int m=p.length();

	for(int i=0;i<=(n-m);i++){
		bool isFound=true;
		for(int j=0;j<m;j++){
			if(s[i+j]!=p[j]){
				isFound=false;
				break;
			}
		}
		if(isFound==true){
			return true;
		}
	}
	return false;
}

int main(){
	string s,p;
	ci>>s>>p;

	cout<<isMatching(s,p)<<endl;
}

//T.c :- O(n*m)