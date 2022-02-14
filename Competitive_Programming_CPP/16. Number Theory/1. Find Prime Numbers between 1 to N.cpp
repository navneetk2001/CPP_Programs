//Brute Force Approach :- O(n^2) :-> Not Acceptable
//check for each number repeatedly that it is prime or not

Logic:-
// for i=1 to N:
// 	if(checkPrime(i)){
// 		cnt++;
// 	}
// print count;

Logic for CheckPrime:-
// CheckPrime(n){
// 	count=0;
// 	for(j=1 to N){    or (j=1 to sqrt(N))
// 		if(n%j==0)
// 			count++;

// 		if(count==2){
// 			return true;
// 		}
// 		return false;
// 	}
// }


//Optimized Approach :- O(N*sqrt(N))
#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
	int countFactors=0;
	for(int j=0;j*j<=n;i++){
		if((n%j)==0){
			if(j*j==n){
				countFactors+=1;
			}
			else{
				countFactors+=2;
			}
		}
	}
	if(countFactors==2){
		return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
    
    int count=0;
	for(int i=0;i<n;i++){
		if(checkPrime(i)){
			count++;
		}
	}
	cout<<count<<endl;
}



//We can still reduce our time complexity by increasing space complexity
