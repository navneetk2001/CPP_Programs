//LPS (Longest Prefix Suffix) :-Prefix Which is also a suffix

#include<bits/stdc++.h>
using namespace std;

int* getLPS(string pattern){
	int len = pattern.length();
	int *lps=new int[len];

	lps[0]=0;
	int i=1;
	int j=0;

	while(i<len){
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;
			j--;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
    return lps;
}

int main(){
	string pattern;
	ci>>pattern;

	auto 
}

//T.c :- O(n*m)