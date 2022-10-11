https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1




//Solution Approach :- 
int dp[1001][1001];
int solve(vector<int>& A,int i,int j){
   	if(i == j){
       	return A[i];
   	}
   	if(i > j){
       	return 0;
   	}
   	if(dp[i][j] != -1){
       	return dp[i][j];
   	}
   
   	int left = A[i] + min(solve(A, i+2, j), solve(A, i+1, j-1));
   	int right = A[j] + min(solve(A, i, j-2),solve(A, i+1, j-1));
   
   	return dp[i][j] = max(left, right);
}

int maxCoins(vector<int> &A, int n){
    memset(dp, -1, sizeof(dp));
    return solve(A,0,n-1);
}




//Second Solution :- 
class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> &A, int i, int j){
        if (i == j){
            return A[i];
        }
        if (i + 1 == j){
            return max(A[i], A[j]);
        }

        if (dp[i][j] == 0){
            int start = A[i] + min(helper(A, i + 2, j), helper(A, i + 1, j - 1));
            int end = A[j] + min(helper(A, i + 1, j - 1), helper(A, i, j - 2));
            dp[i][j] = max(start, end);
        }
        return dp[i][j];
    }

    int maxCoins(vector<int>&A,int n) {
	    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	    return helper(A, 0, n - 1);
    }
};




//Third Soluton :- 
int maxCoins(vector<int>&A,int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j]=A[i];
            }
            else if(g==1){
                dp[i][j]=max(A[i],A[j]);
            }
            else{
                int val1=A[i]+min(dp[i+2][j],dp[i+1][j-1]);
                int val2=A[j]+min(dp[i+1][j-1],dp[i][j-2]);
                dp[i][j]=max(val1,val2);
            }
        }
    }
    return dp[0][n-1];
}