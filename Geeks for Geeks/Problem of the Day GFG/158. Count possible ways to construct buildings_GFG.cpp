// Given N, the number of plots on either sides of the road. Find the total ways to construct buildings in the plots such that there is a space between any 2 buildings. All plots on one side of the road are continuous.
// Lets suppose * represents a plot, then for N=3, the plots can be represented as * * * | | * * *                               
// Where | | represents the road.                                                                                                                                                                  
// Note: As the answer can be very large, print it mod 1000000007

// Example 1:
// Input: N = 3
// Output: 25
// Explanation: 3 plots, which means possible ways for one side are BSS, BSB, SSS, SBS, SSB where B represents a building and S represents an empty space Total possible 
// ways are 25, because a way to place on one side can correspond to any of 5 ways on other side.

// Example 2:
// Input: N = 10
// Output: 20736
// Explanation: There are 20736 ways for N = 10.



//First Solution :- Memoization
class Solution{
public:
	#define ll long long int
	const int mod = 1e9+7;
	ll f(int i, vector<ll> &dp){
	    if(i==0) return 1;
	    if(i==1) return 2;
	    
	    if(dp[i]!=-1) return dp[i];
	    
	    ll one = f(i-2,dp)%mod;
	    ll two = f(i-1, dp)%mod;
	    
	    return dp[i] = (one + two) % mod;
	}
	
	int TotalWays(int N)
	{
	    vector<ll> dp(N+1, -1);
	    ll count = f(N,dp);
	    count = (count * count) % mod;
	    return int(count);
	}
};


//Second Solution :- Tabulation
#define ll long long int

int TotalWays(int N){
    ll mod = 1e9 + 7;
    vector<ll> dp(N+1,-1);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= N; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % mod;
    }
    dp[N] = (dp[N] * dp[N]) % mod;
    return (dp[N]);
}



//Third Solution :- Space Optimized Solution
#define ll long long int
int TotalWays(int N){
    ll mod = 1e9 + 7;
    ll prev2 = 1, prev = 2;
    
    for(int i = 2; i <= N; i++){
        ll curr = (prev2 + prev) % mod;
        prev2 = prev;
        prev = curr;
    }
    prev = (prev * prev) % mod;
    return (prev);
}


