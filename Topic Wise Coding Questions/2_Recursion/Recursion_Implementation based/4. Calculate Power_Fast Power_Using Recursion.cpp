#include<bits/stdc++.h>
using namespace std;

//Compute a^n
//T.C :- O(n)
int power(int a, int n){
	if(n==0){
		return 1;
	}
	return a*power(a,n-1);
}

//Fast Exponentiation :- T.C :- O(logn)

//a^n = (a^n/2)^2 if n is even
//a^n = a*(a^n/2)^2 if n is odd
int fast_power(int a, int n){
	if(n==0){
		return 1;
	}
	//rec case
	int smallAns=fast_power(a,n/2);
	smallAns*=smallAns;

	if(n&1){ //odd case
		return smallAns*a;
	}
	return smallAns;
}


int main(){
	int a,n;
	cin>>a>>n;

	cout<<power(a,n)<<endl;
	cout<<fast_power(a,n)<<endl;
}