// Given two integers M and N, generate all primes between M and N.

// Example 1:
// Input:
// M=1,N=10
// Output:
// 2 3 5 7
// Explanation:
// The prime numbers between 1 and 10
// are 2,3,5 and 7.

// Example 2:
// Input:
// M=2, N=5
// Output:
// 2,3,5
// Explanation:
// The prime numbers between 2 and 5 are 
// 2,3 and 5.


//First Solution :- Check each number 
int isPrime(int N){
	if(N==2) return 1;
	if(N<2 || N%2 == 0) return 0;
	for(int i=3;i*i<=N;i+=2){
		if(N%i==0) return 0;
	}
	return 1;
}

vector<int>primeRange(int M, int N){
	vector<int>ans;
	for(int i=M;i<=N;i++){
		if(isPrime(i)) ans.push_back(i);
	}
	return ans;
}


//Second Solution :- Using Seive Method 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int p[100];
	for(int i=0;i<100;i++){
		p[i]=1;
	}
	p[1]=0;
	for(int i=2;i<100;i++){
		if(p[i]){
			for(int j=i*2;j<100;j+=i){
				p[j]=0;
			}
		}
	}

	for(int i=1;i<100;i++){
		if(p[i]){
			cout<<i<<" ";
		}
	}

	return 0;
}

//Time Complexity: O(Nlog(log(N)))
//Space Complexity:O(N)
class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<bool> primes(N+1, true);
        primes[0] = false;
        primes[1] = false;
        
        for(int i = 2;i*i<N+1;i++){
            
                if(primes[i]){
                    for(int j =i*i;j<N+1;j+=i){
                        primes[j] = false;
                }
            }
        }
        
        vector<int> ans;
        for (int i = M;i<=N;i++){
            if(primes[i]) ans.push_back(i);
        }
        return ans;
        
    }
};


//Second Solution :- Using Segmented-Seive Method 
// fillPrime function fills primes from 2 to sqrt of high in chprime(vector) array
void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= sqrt(high); j = j + i) {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}
// in segmented sieve we check for prime from range [low, high]
void segmentedSieve(int low, int high)
{
    bool prime[high - low + 1];
  //here prime[0] indicates whether low is prime or not similarly prime[1] indicates whether low+1 is prime or not
    memset(prime, true, sizeof(prime));
 
    vector<int> chprime;
    fillPrimes(chprime, high);
    //chprimes has primes in range [2,sqrt(n)]
     // we take primes from 2 to sqrt[n] because the multiples of all primes below high are marked by these
   // primes in range 2 to sqrt[n] for eg: for number 7 its multiples i.e 14 is marked by 2, 21 is marked by 3,
   // 28 is marked by 4, 35 is marked by 5, 42 is marked 6, so 49 will be first marked by 7 so all number before 49
  // are marked by primes in range [2,sqrt(49)]
    for (int i : chprime) {
        int lower = (low / i);
        //here lower means the first multiple of prime which is in range [low,high]
        //for eg: 3's first multiple in range [28,40] is 30         
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }
   
    for (int i = low; i <= high; i++) {
        if (prime[i - low] == true) {
            cout << (i) << " ";
        }
    }
}


//Fourth Solution :- 
vector<int> primeRange(int M, int N) {
    vector<int> vect;
        
    if(M <= 1) M = 2;
    for(int i = M; i <= N; i++){
        int flag = 0;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) vect.push_back(i);
    }
    return vect;
 }