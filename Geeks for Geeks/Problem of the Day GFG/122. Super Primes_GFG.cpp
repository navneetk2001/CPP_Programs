// A prime number is Super Prime if it is a sum of two primes. Find all the Super Primes upto N

// Example 1:
// Input:
// N = 5
// Output: 1
// Explanation: 5 = 2 + 3, 5 is the only super prime

// Example 2:
// Input: N = 10 
// Output: 2
// Explanation: 5 and 7 are super primes




//Solution Approach :-
class Solution{
public:	
	int superPrimes(int n){
	    int p[n+1];
	    memset(p,1,sizeof(p));

	    p[0]=p[1]=0;
	    for(int i=2;i<=n;i++){
	        if(p[i])
	        for(int j=i*2;j<=n;j+=i){
	            p[j]=0;
	        }
	    }
	    
	    int count = 0;
	    for(int i=4;i<=n;i++){
	        if(p[i] && p[i-2]){
	            count++;
	        }
	    }
	   
	   return count;
	}
};




//Second Solution :-
bool isprime(int n){
    for(int i = 2; i*i <=n ;i++){
        if(n%i == 0 || (n-2)%i == 0){
            return false;
        }
    }   
    return true;
}

int superPrimes(int n){
    int cnt = 0;
    for(int i=5;i<=n;i++){
        if(isprime(i)){
            cnt++;
        }
    }
    return cnt;
}




//Third Solution :-
class Solution{
public:	
	bool isPrime(int n){
	    if(n==0 ||n==1) return  false;
	    bool flag= true;
	    for(int i=2;i*i<=n;i++){
	        if(n%i==0){
	            return false;
	        }
	    }
	   return true;
	}

	int superPrimes(int n)
	{
	    int count=0;
	    for(int i=2;i<=n;i++){
	        if(isPrime(i-2) && isPrime(i)){
	            count++;
	        }
	    }
	    return count;
	}
};
