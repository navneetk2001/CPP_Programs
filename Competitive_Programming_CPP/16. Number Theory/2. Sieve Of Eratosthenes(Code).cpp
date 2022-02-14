//Approach :-
//we know that 2 is a prime hence we know that any multiple of 2 will not be a prime
//Hence we wouldn't have to checkPrime for 4, 6, 8 etc.

//How we can do that?
//we will make a boolean aray which will maintain 'true' or 'false' and that will tell whether that number is a prime or not 

//Number :- 0 1 2 3 4 5 6 7 8 9 10 
//boolean:- F F T T F T F T F F F

//we will have to maintain that array from 2 to sqrt(N) and make all multiples as Not Prime


Steps:-
//1. Make any array boolean of size N and initialize with true
//2. Make arr[0] and arr[1] = false;
//3. loop i -> 2 to sqrt(N) -> mark all multiples of i starting from i*i as false;
//4. You have array of prime numbers with the true values in array

//Time Complexity :- O(N*log(logN))

#include<bits/stdc++.h>
using namespace std;

//Prime Number
void makeSeive(int n){
	bool isPrime[n+1];
	for(int i=0;i<=n;i++){
		isPrime[i]=true;
	}
	isPrime[0]=false;
	isPrime[1]=false;

	for(int i=2;i*i<=n;i++){
		if(isPrime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				isPrime[j]=false;
			}
		}
	}

	for(int i=0;i<=n;i++){
		cout<<i<<" : "<<isPrime[i]<<endl;
	}
}


int main(){
	int n;
	cin>>n;

	makeSeive(n);
    return 0;
}