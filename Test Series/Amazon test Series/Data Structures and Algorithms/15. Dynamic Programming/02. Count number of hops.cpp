https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1




//First Solution :- Using Recursion
class Solution{
public:
    //Function to count the number of ways in which frog can reach the top.
    long long solve(int ind)
    {
        if(ind < 0){
            return 0;
        }

        if(ind == 0){
            return 1;
        }

        int ans  = (solve(ind - 1) + solve(ind - 2) + solve(ind - 3)) % 1000000007;
        return ans;
    }

    long long countWays(int n)
    {
        return solve(n);
    }
};




//Second Solution :- Memoization 
class Solution{
public:
    //Function to count the number of ways in which frog can reach the top.
    long long solve(int ind, vector<int> &dp)
    {
        if(ind < 0){
            return 0;
        }

        if(ind == 0){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int ans  = (solve(ind - 1, dp) + solve(ind - 2, dp) + solve(ind - 3, dp)) % 1000000007;
        return dp[ind] = ans;
    }

    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(n, dp);
    }
};



//Third Solution :- Tabulation 
class Solution{
public:
    //Function to count the number of ways in which frog can reach the top.
    const long int m = 1e9+7;
    long long countWays(int n){
        long long mod = 1e9+7;
        long long dp[n+1];
       
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
       
        for(int i=4; i<=n; i++){
            dp[i] = ((dp[i-1] + dp[i-2]) % mod + dp[i-3]) % mod;
        }
       
        return dp[n];
    }
};
 


//Fourth Solution :- Constant Space Optimization
class Solution{
public:
    //Function to count the number of ways in which frog can reach the top.
    const long int m = 1e9+7;
    long long countWays(int n){
        if(n == 1 || n == 2){    //edge case
            return n;
        }
        if(n == 3){     //edge case
            return 4;
        }
    
        long long first = 1;
        long long second = 2;
        long long third = 4;
    
        long long sum;
        for(int i=4; i<=n; i++){
            sum = first % m + second % m + third % m;
            
            first = second % m;
            second = third % m;
            third = sum % m;
        }
        return sum % m;
    }
};
