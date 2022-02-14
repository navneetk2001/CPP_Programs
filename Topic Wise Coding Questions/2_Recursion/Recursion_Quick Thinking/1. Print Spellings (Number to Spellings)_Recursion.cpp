#include<bits/stdc++.h>
using namespace std;

//Problem 
//Number to Spellings
//2048 ---> two zero four eight

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpellings(int n){
	//base case
	if(n==0){
		return;
	}

	//rec case first print the spellings of (204)
	printSpellings(n/10);
	int digit=n%10;
	cout<<words[digit]<<" ";
	return;
}

void reverse_printSpellings(int n){
	//base case
	if(n==0){
		return;
	}

	//rec case first print the spellings of (204)
	cout<<words[digit]<<" ";
	reverse_printSpellings(n/10);
	int digit=n%10;
	return;
}

int main(){
	int n;
	cin>>n;
    printSpellings(n);
    cout<<endl;
	reverse_printSpellings(n);
}