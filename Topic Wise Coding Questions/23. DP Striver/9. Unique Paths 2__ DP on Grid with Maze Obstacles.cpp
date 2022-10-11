https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>> &mat){
    if(i>=0 && j>=0 && mat[i][j]==-1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    
    int up=f(i-1,j,mat);
    int left=f(i,j-1,mat);
    return up+left;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return f(n-1,m-1,mat);
}



//Second Solution :- Memoization 
#include <bits/stdc++.h> 
const int mod = 1e9 + 7;
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i>=0 && j>=0 && mat[i][j]==-1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int up=f(i-1,j,mat,dp);
    int left=f(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}


//Third Solution :- Tabulation 
#include <bits/stdc++.h> 
const int mod = 1e9 + 7;

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    int dp[n][m];
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==-1){    //base conditions
                dp[i][j]=0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
              
            int up=0, left=0;
              
            if(i>0){
                up = dp[i-1][j];
            }
            if(j>0){
                left = dp[i][j-1];
            }
                
            dp[i][j] = (up+left)%mod;
          }
      }
      return dp[n-1][m-1];
}


//Fourth Solution :- Space Optimized Solution 
#include <bits/stdc++.h> 
const int mod = 1e9 + 7;

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<int> prev(m,0);
    
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
        	if(mat[i][j]==-1){    //base conditions
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0, left=0;
            if(i>0){
                up = prev[j];
            }
            if(j>0){
                left = temp[j-1];
            }
                
            temp[j] = (up + left)%mod;
        }
        prev = temp;
    }
    
    return prev[m-1];
}







