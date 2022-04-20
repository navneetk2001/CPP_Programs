// Given an even number N (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only the pair whose minimum value is the smallest among all the minimum values of pairs and print the minimum element first.
// NOTE: A solution will always exist, read Goldbachs conjecture. 

// Example 1:
// Input: N = 74
// Output: 3 71
// Explaination: There are several possibilities like 37 37. But the minimum value of this pair is 3 which is smallest among all possible minimum values of all the pairs.

// Example 2:
// Input: 4
// Output: 2 2
// Explaination: This is the only possible partitioning of 4.



//Solution Approach :- using seive method
class Solution{
public:
    vector<int> primeDivision(int n){
        vector<int>p(n+1,1); //to store prime number between 1 to n
        p[0]=p[1] = 0;     //marking 0 & 1 as non prime numbers
        for(int i=2;i<n;i++){
        	if(p[i]){
        		for(int j=i*2;j<=n;j+=i){
        			p[j]=0;
        		}
        	}
        }

        int mx=INT_MAX;
        vector<int>v;    //to store ans
        for(int i=2;i<n;i++){
        	if(p[i]&&p[n-i]){   //checking for i and n-i for prime 
        		if(min(i,n-i)<mx){  
        			v={i,n-i};
        			mx=min(i,n-i);
        		}
        	}
        }
        return v;
    }
};


//Second Approach :- Brute Force
class Solution{
public:    
	bool isPrime(int n)
	{
	    // Corner cases
	    if (n <= 1)
	        return false;
	    if (n <= 3)
	        return true;
	  
	    // This is checked so that we can skip middle five numbers in below loop
	    if (n % 2 == 0 || n % 3 == 0)
	        return false;
	  
	    for (int i = 5; i * i <= n; i = i + 6)
	        if (n % i == 0 || n % (i + 2) == 0)
	            return false;
	  
	    return true;
	}

    vector<int> primeDivision(int N){
        vector<int> vc;
        int i=2;
        while(i<=N){
            if(isPrime(i)){
                if(isPrime(N-i)){
                    vc.push_back(i);
                    vc.push_back(N-i);
                    return vc;
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
        return vc;
    }
};



//BruteForce Approach :- 
class Solution{
public:
   bool isprime(int n)
   {
       for(int j=2;j<=n/2;j++)
       {
           if(n%j==0)
           {
               return 0;
           }
       }
       return 1;
   }
   vector<int> primeDivision(int N){
       int i;
       for(i=2;i<=N/2;i++)
       {
           if(isprime(i)  &&  isprime(N-i))
           {
               return {i,N-i};
           }
       }
   }
};


//Third Solution :- Modified Sieve. :- looping only n/2. :- O( Nlog(logN) )
void sieve(vector<bool>&prime,int n){
   prime[0]=prime[1]=false;

   for(int i=2;i*i<=n;i++){
       if(prime[i]){
           for(int j=i*i;j<=n;j+=i){
               prime[j]=false;
           }
       }
   }
}

vector<int> primeDivision(int n){
   vector<bool>prime(n,true);
   sieve(prime,n+1);
   
   for(int i=2;i<=n/2;i++){
       if(prime[i] && prime[n-i]) return {i,n-i};
   }
   return {};
}