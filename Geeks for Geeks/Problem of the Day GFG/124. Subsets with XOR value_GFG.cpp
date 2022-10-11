Given an array arr of N integers and an integer K, find the number of subsets of arr having XOR of elements as K.
 
Example 1:
Input:
N = 4
k = 6
arr: 6 9 4 2
Output: 2
Explanation: The subsets are {4,2} and {6}

Example 2:
Input:
N = 5
K = 4
arr: 1 2 3 4 5
Output: 4
Explanation:
The subsets are {1, 5}, {4}, {1, 2, 3, 4}, and {2, 3, 5}




//Solution Approach :-
class Solution{
public:
    int helper(vector<int>arr,vector<vector<int>>&dp,int K,int i){
        if(i==arr.size()){
            return K==0;
        }
        if(dp[i][K]!=-1){
            return dp[i][K];
        }
        else{
            int op1=helper(arr,dp,K,i+1);
            int op2=helper(arr,dp,K^arr[i],i+1);
            return dp[i][K]=op1+op2;
        }
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        vector<vector<int>>dp(N,vector<int>(1000,-1));
        return helper(arr,dp,K,0);
    }
};


//Second Solution :- DP
class Solution {
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        vector<vector<int>> dp(N, vector<int>(128, 0));
        dp[0][0] = dp[0][arr[0]] = 1;
        
        for(int i = 1; i < N; i++) {
            dp[i] = dp[i - 1];
            for(int j = 0; j < 128; j++) {
                int cur = j ^ arr[i];
                dp[i][cur] += dp[i - 1][j];
            }
        }
        return dp[N - 1][K];
    }
};


//Third Solution :-
int solve(vector<int> &a, int n, int k, vector<vector<int>> &dp) {
    if(n == 0){
        return k == 0;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }

    int take = solve(a, n-1, k^a[n-1],dp);
    int leave = solve(a, n-1, k,dp);

    dp[n][k] = take+leave;
    return dp[n][k];
}

int subsetXOR(vector<int> arr, int N, int K) {
    vector<vector<int>> dp(N+1, vector<int> (128,-1));
    return solve(arr, N, K, dp);
}


//Fourth Solution :-
class Solution{
public:
    int subsetXOR(vector<int> &arr, int N, int K) {
        if(N==0){
            return (K==0);
        }
        int take = subsetXOR(arr , N - 1 , K ^ arr[N - 1]);
        int leave = subsetXOR(arr , N - 1 , K);
        return take + leave;
    } 
};


