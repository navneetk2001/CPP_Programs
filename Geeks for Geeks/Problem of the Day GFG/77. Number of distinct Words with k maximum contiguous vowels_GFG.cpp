// Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 

// Example 1:
// Input:
// N = 2
// K = 0
// Output: 441
// Explanation: Total of 441 unique words are possible of length 2 that will have K( =0) vowels
// together, e.g. "bc", "cd", "df", etc are valid words while "ab" (with 1 vowel) is not a valid word.

// Example 2:
// Input:
// N = 1
// K = 1
// Output: 26
// Explanation: All the english alphabets including vowels and consonants; as atmost K( =1) vowel can be taken.



//Approach :-
// Explanation :- Here for every ith index of the string that we are  trying to make, 
// we have two options if value of k is greater than 0 the its obvious that either 
// we can assign a vowel or a non-vowel alphabet to the current ith index. And if value 
// of k is 0 then we have left with 0 options to assign a vowel at ith index because of 
// the constraint that no more than k continuous vowels should be there. And the base condition 
// is that if we have completed our word then it will contribute the total count by 1. And if 
// there are 5 vowels then its obvious that remaining are 26-5 = 21 alphabets. So below is the 
// implementation of this intuituion and for better understanding dry run the given test case. 
// Normally in dp problems we simply need three things to decide i.e. (i) - the type and number 
// of parameters to pass in function, (ii) - base condition which should be decided with the smallest 
// valid input, (iii) - choice diagram in which we write different conditions according to the given 
// constraint in the problem.



//First Solution :-
long long int mod = 1e9 + 7;
long long int dp[1001][1001];
   
long long int helper(int n,int k,int remV){   //remV => remaining vowel
   if(n == 0) 
     return 1;
   
   if(dp[n][remV] != -1) return (dp[n][remV]);
   
   long long int choice1 = 0, choice2 = 0;
   if(remV > 0){
       choice1 = (5*helper(n-1,k,remV-1)) % mod;
       choice2 = (21*helper(n-1,k,k)) % mod;
   }
   else{
       choice2 = (21*helper(n-1,k,k)) % mod;
   }
   
   return dp[n][remV] = (choice1 + choice2) % mod;
}

int kvowelwords(int N, int K) {
   dp[N+1][K+1];
   memset(dp,-1,sizeof(dp));
   return (int)helper(N,K,K);
}


//Second Solution  :-
class Solution{
  public:
  
    #define ll long long int
    const int MOD = 1e9 + 7;

    int kvowelwords(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll>(k+1));
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(i == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i-1][k] * 21 % MOD;
                    if(j > 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 5 % MOD) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};


//Third Solution :-
#define ll long long int
class Solution{
public:
  ll t[1001][1001];
  ll solve(int n , int k , int cnt ){
      if(n==0)
      	  return  1;

      if(t[n][cnt]!=-1)
      	  return t[n][cnt];
      
      if(cnt<k){
          return t[n][cnt] =( 21*solve(n-1, k, 0) + 5*solve(n-1, k , cnt+1))%1000000007 ;
      }

      if(cnt== k){
          return t[n][cnt] =( 21*solve(n-1, k, 0))%1000000007 ;
      }
      
  }
    int kvowelwords(int n, int k) {
        memset(t, -1, sizeof(t)) ;
        return solve(n, k, 0 )%1000000007;
    }
};



