https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include <bits/stdc++.h> 
int f(int i, int j){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    
    int up=f(i-1,j);
    int left=f(i,j-1);
    return up+left;
}

int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}



//Second Solution :- Memoization 
#include <bits/stdc++.h> 
int f(int i, int j,vector<vector<int>> &dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m,vector<int>(n,-1));
	return f(m-1,n-1,dp);
}


//Third Solution :- Tabulation 
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m,vector<int>(n,-1));
	for(int i=0; i<m ;i++){
      	for(int j=0; j<n; j++){
          	if(i==0 && j==0){    //base condition
              	dp[i][j]=1;
              	continue;
            }
          	int up=0;
          	int left = 0;
          
          	if(i>0){
            	up = dp[i-1][j];
          	}
          	if(j>0){
            	left = dp[i][j-1];
          	}
            
          	dp[i][j] = up+left;
      	}
    }
    return dp[m-1][n-1];
}


//Fourth Solution :- Space Optimized Solution 
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
}