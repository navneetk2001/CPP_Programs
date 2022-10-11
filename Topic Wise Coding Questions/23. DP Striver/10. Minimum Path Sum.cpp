https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>> &grid){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return 1e9; //taking INT_MAX
    }
    
    int up=grid[i][j] + f(i-1,j,grid);
    int left=grid[i][j] + f(i,j-1,grid);
    return min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    return f(n-1,m-1,grid);
}


//Second Solution :- Memoization 
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return 1e9; //taking INT_MAX
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int up=grid[i][j] + f(i-1,j,grid,dp);
    int left=grid[i][j] + f(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}


//Third Solution :- Tabulation 
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
            }
            else{
                int up=grid[i][j], left=grid[i][j];
                if(i>0) up+= dp[i-1][j];
                else up+= 1e9;
                if(j>0) left+= dp[i][j-1];
                else left+= 1e9;
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}


//Fourth Solution :- Space Optimized Solution 
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> prev(m,0);
    
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                temp[j] = matrix[i][j];
            }
            else{
                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    return prev[m-1];    
}