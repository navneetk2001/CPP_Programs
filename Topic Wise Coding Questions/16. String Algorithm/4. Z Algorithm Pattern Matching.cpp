//We will learn here Z-Function
//Z(k) :- Length of longest substring starting at 'k' which is also the prefix of the String

//Example :-
//String :- a a c b y a a k a a c
//z-func :- 0 1 0 0 0 2 1 0 3 1 0

//Given text and a Pattern we will generate a string of type :-
//   Pattern + $ + text   (of length m+n)
//If we want to find index of pattern in text :- it will be z-len(pat)-1;


//Code :-
#include<bits/stdc++.h>
using namespace std;

void buildZ(int* Z, string str){
	int n=str.length();
	int l=0;
	int r=0;

	for(int i=1;i<n;i++){
		if(i>r){  //i doesnot lie between l and r 
			//z does not exist for this yet
			l=i;
			r=i;
			while(r<n && str[r-l]==str[r]){
				r++;
			}
			Z[i]=r-l;
			r--;
		}
		else{
			int k=i-l;
			if(Z[k]<=r-i){
				//it will lie between l and r
				//z willexist previously
				Z[i]=Z[k];
			}
			else{
				//Some part of Z is already included
				// you have to start matching further
				l=i;
				while(r<n && str[r-l]==str[r]){
					r++;
				}
				Z[i]=r-l;
				r--;
			}
		}
	}
}


void searchString(string text, string pattern){
	string str=pattern+"$"+text; //Pattern first because we have to search pattern
	int n=str.length();

	int *Z = new int[n]();
	buildZ(Z,str);
	for(int i=0;i<n;i++){
		if(Z[i]==pattern.length()){
			cout<<i-pattern.length()-1<<endl;
		}
	}
}


int main(){
	string text = "abcdsafbcdfasbcda";
	string pattern = "bcd"
	
	searchString(text, pattern)<<endl;
    return 0;
}