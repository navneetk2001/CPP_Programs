https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Using Recursion
int f(int i, int j, vector<int> &arr){
    if(i == j){       //base case
        return 0;
    }
    
    int mini = 1e9;      //keep track of minimum
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + f(i,k,arr) + f(k+1,j,arr);
        mini = min(mini, steps);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1, N-1, arr);
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j){       //base case
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return f(1, N-1, arr, dp);
}




//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int matrixMultiplication(vector<int> &arr, int N)
{
    int dp[N][N];
    for(int i=1;i<N;i++){   //Base case
        dp[i][i] = 0;
    }

    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}
