// For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
// Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

// Example 1:
// Input: n = 3, k = 0
// Output: 1
// Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

// Example 2:
// Input: n = 3, k = 1
// Output: 2
// Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.




//Solution Approach :-
class Solution {
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        for (int N = 1; N <= n; ++N){
            for (int K = 0; K <= k; ++K){
                for (int i = 0; i <= min(K, N - 1); ++i){
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
                }
            }
        }
        return dp[n][k];
	}    
};



//Second Solution :-
class Solution {
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
	    if (k <= 0){
	        return k == 0;
	    }
	    if (dp[n][k] == 0) {
	        dp[n][k] = 1;
	        for (auto i = 0; i < n; ++i) {
	            dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
	        }
	    }
	    return dp[n][k] - 1;
	}
};





//Third Solution :-

class Solution {
public:
	const int mod = pow(10, 9) + 7;
    
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j - i >= 0){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;      //It must + mod, If you don't know why, you can check the case 1000, 1000
                }
            }
        }
        return dp[n][k];
    }
};