https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1




//Solution Approach :- Memoization
int mod=1e9+7;
long long int f(int n, vector<long long int> &dp){
    if(n <= 2){    //base case
    	return n;
    }
    if(dp[n] != -1){
    	return dp[n];
    }

    int single = f(n-1, dp);
    int pairedup = ((n-1) % mod * f(n-2, dp) % mod) % mod;
    return dp[n] = ((single) % mod + (pairedup) % mod) % mod;
}

int countFriendsPairings(int n) { 
    vector<long long int> dp(n+1,-1);
    return f(n,dp);
}




//Second Solution :- Tabulation
class Solution{
public:
    const int mod = 1e9+7;
    int countFriendsPairings(int n) 
    { 
        vector<long long int> dp(n+1);
        dp[1] = 1;
        dp[0] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = ((dp[i-1] % mod) + (i-1)*((dp[i-2]) % mod)) % mod;
        }
        return dp[n];
    }
};



//Third Solution :-
long countFriendsPairings(int n) 
{ 
   	long a = 1, b = 1, c = 1, mod = 1000000007;
   	for(int i = 2; i <= n; i++){
       	c = ((b % mod) + (((i - 1) % mod) * (a % mod)) % mod) % mod;
       	a = b;
       	b = c;
   }
   return c;
}



