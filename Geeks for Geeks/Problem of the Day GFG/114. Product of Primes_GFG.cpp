Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 109+7. If there are no primes in that range you must print 1.

Example 1:
Input: L = 1, R = 10
Output: 210
Explaination: The prime numbers are 2, 3, 5 and 7.

Example 2:
Input: L = 1, R = 20
Output: 9699690
Explaination: The primes are 2, 3, 5, 7, 11, 13, 17 and 19.



//Solution Approach :-
#define ll long long
class Solution{
	public:
	bool check(ll n){
	    if(n==1)
	   	   	return false;
	   
	    if(n==2)
	   		return true;
	    if(n%2==0)
	   		return false;
	   
	    for(int i=3;i*i<=n;i+=2){
	        if(n%i==0)
	       		return false;
	    }
	    return true;
	}

    long long primeProduct(long long L, long long R){
	    ll ans=1;
        ll mod=1e9+7;
        for(ll i=L;i<=R;i++){
        	if(check(i))
           		ans=(ll)((ans*i)%(mod));
        }
       
        return ans%mod;
    }



//Second Solution :- C++ Solution Using segmented sieve
class Solution{
    const int MOD=1000000007;
    bool prime[1000001];
    vector<int> p;
    
    void sieve(){
        prime[0]=prime[1]=1;

        for(int i=2;1LL*i*i<1000001;i++){
            if(!prime[i]){
                for(int j=i*i;j<1000001;j+=i){
                    prime[j]=1;
                }
            }
        }

        for(int i=2;i<1000001;i++){
        	if(!prime[i]){
        		p.push_back(i);
        	}
        }
    }
    
    int seg(int L,int R){
        if(L==1){
        	L++;
        }

        int max=(R-L+1),res=1;
        vector<bool> arr(max,false);
        for(auto &x:p){
            if(1LL*x*x<=R){
                long long i=(L/x)*x;
                if(i<L)i+=x;
                for(;i<=R;i+=x){
                    if(i!=x)arr[i-L]=1;
                }
            }
        }
        for(int i=L;i<=R;i++)if(!arr[i-L])res=1LL*res*i%MOD;
        return res;
    }

public:
    long long primeProduct(long long L, long long R){
        sieve();
        return seg(L,R);
    }
};



//Third Solution :-
class Solution{
    bool isprime(long long n){
        for(long long i=2;i*i<=n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    
public:
   long long primeProduct(long long L, long long R){
        long long product=1;
        for(long long i=L;i<=R;i++){
        	if(isprime(i)){
            	product = (product*i) % 1000000007;
        	}
        }
        
        return product;
   }
};
