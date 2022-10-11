// You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.
// Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).
// Example :
// Input : 
// 	S = [1, 2, 3] 
// 	N = 4
// Return : 4
// Explanation : The 4 possible ways are
// {1, 1, 1, 1}
// {1, 1, 2}
// {2, 2}
// {1, 3}	
// Note that the answer can overflow. So, give us the answer % 1000007




//Solution Approach :- Tabulation
int Solution::coinchange2(vector<int> &A, int B) {
	int ways[B+1];
	memset(ways, 0, sizeof(ways));

	ways[0] = 1;
	for(int i = 0; i < A.size(); i++){
		for(int j = A[i]; j <= B; j++){
			ways[j] = ways[j] + ways[j-A[i]];
			ways[j] = ways[j]%1000007;
		}
	}
	return ways[B];
}



//Second Solution :- 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1));
        
        int i,j;
        for(i=1;i<=amount;++i)
            dp[0][i] = 0;
        
        for(i=0;i<=n;++i)
            dp[i][0] = 1;
       
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=amount;++j)
            {
                if(j>=coins[i-1])
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};



//Method 1: RECURSION
class Solution {
public:
    int recursion(int w, vector<int>& wt, int n)
    {
        if (n == 0 || w == 0){
            return w == 0 ? 1 : 0;
        }
        
        if (wt[n - 1] > w){
            return recursion(w, wt, n - 1);
        }
        else{
            return recursion(w, wt, n - 1) + recursion(w - wt[n - 1], wt, n);
        }
    }
    
    int change(int amount, vector<int>& coins){
        return recursion(amount, coins, coins.size());    
    }
};



//Method 2: DP MEMOIZATION
class Solution {
public:
    int dp[5000 + 1][300 + 1];
    int memoization(int w, vector<int>& wt, int n){
        if (n == 0 || w == 0){
            return w == 0 ? 1 : 0;
        }
        
        if (dp[w][n] != -1){
            return dp[w][n];
        }
        
        if (wt[n - 1] > w){
            return dp[w][n] = memoization(w, wt, n - 1);
        }
        else{
            return dp[w][n] = memoization(w, wt, n - 1) + memoization(w - wt[n - 1], wt, n);
        }
    }
    
    int change(int amount, vector<int>& coins){
        memset(dp, -1, sizeof(dp));
        return memoization(amount, coins, coins.size());    
    }
};