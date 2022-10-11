https://practice.geeksforgeeks.org/problems/nine-divisors3751/1




//Solution Approach :-
class Solution{  
private:
    void generatePrime(vector<int>&primes){
        for(int i=2;i<primes.size();i++){
            primes[i]=i;
        }
        
        for(int i=2; i*i < primes.size(); i++){
            if(primes[i]==i){
                for(int j=i*i;j<primes.size();j+=i){
                    if(primes[j]==j){
                        primes[j]=i;
                    }
                }
            }
        }
    }
    
public:
    long long int nineDivisors(long long int N){
        vector<int>primes(sqrt(N)+1,1);
        generatePrime(primes);
        int c=0;
        
        for(int i=2; i<=sqrt(N); i++){
            int a=primes[i];
            int b=primes[i/a];
            if((a!=b && primes[b]==b && b!=1 && (a*b)==i) ||(primes[i]==i && pow(i,8)<=N)){
                c++;
            }
        }
        return c;
    }
};





//Second Solution :- 
long long int nineDivisors(long long int N){
    int sN = sqrt(N);
    vector<bool> prime(sN+1,true);
    
    for(int i=2;i<=sqrt(sN)+1;i++){
        if(prime[i])
        for(int j=i*i;j<=sN;j+=i){
            prime[j]=0;
        }
    }

    vector<int> primes;
    for(int i=2;i<=sN;i++){
        if(prime[i]){
        	primes.push_back(i);
        }
    }
    
    int primesSize = primes.size();
    int ans=0;
    for(int i=0;i<primesSize;i++){
        long long notExceed  = sqrt(N)/primes[i];
        ans += (upper_bound(primes.begin(),primes.begin()+i,notExceed) - primes.begin());
    }
    
    for(int i=0;i<primesSize;i++){
        long long sq = primes[i]*primes[i];
        if(sq*sq*sq*sq <= N){
        	ans++;
        }
        else{
        	break;
        }
    }
    return ans;
}