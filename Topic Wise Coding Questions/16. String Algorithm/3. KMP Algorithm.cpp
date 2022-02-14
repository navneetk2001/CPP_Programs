//Used LPS (Longest Prefix Suffix) :-Prefix Which is also a suffix

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

bool kmpSearch(string text, string pattern){
	int lenText=text.length();
	int lenPat=pattern.length();

	int i=0;
	int j=0;

	int *lps=getLPS(pattern);
	while(i<lenText && j<lenPat){
		if(text[i]==text[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=LPS[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j==lenPat){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	string str = "abcxabcdabcdabcy";
	string subString = "abcdabcy"
	
	cout<<kmpSearch(str, subString)<<endl;
    return 0;
}

//T.c :- O(n*m)