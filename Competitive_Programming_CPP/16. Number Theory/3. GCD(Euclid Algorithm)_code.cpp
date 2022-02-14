//Approach :-
//GCD :- Greatest Common Divisor

Steps:-
//for i=1 to min(a,b)
//     if(i divides both a and b)
//             gcd = i;

//Euclid's Algorithm :-
//if(a>b)
//   gcd(a,b) = gcd(b, a%b);

//gcd(n,0) = n


//Time Complexity :- O(log2(max(a,b)))   if a>b

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	//Special case
	if(a<b){
		return gcd(b,a);
	}

	if(b==0){       //base case :- gcd(n,0) = n
		return a;
	}

	return gcd(b, a%b);     //Answer step applying Euclid's Algorithm
}

int main(){
	int a,b;
	cin>>a>>b;
    
    cout<<"GCD is "<<gcd(a,b)<<endl;
    return 0;
}