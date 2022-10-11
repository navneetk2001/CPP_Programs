https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Using Recursion
#include<bits/stdc++.h>
int f(int i, int j, vector<int> &cuts){
    if(i > j){       //base case
        return 0;
    }
    
    int mini = 1e9;      //keep track of minimum
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts) + f(ind+1,j,cuts);
        mini = min(mini, cost);
    }
    return mini;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);                //add in last to get the length
    cuts.insert(cuts.begin(),0);      //add in first to get the length
    sort(cuts.begin(), cuts.end());

    return f(1, c, cuts);
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j){       //base case
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int mini = 1e9;      //keep track of minimum
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);                //add in last to get the length
    cuts.insert(cuts.begin(),0);      //add in first to get the length
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    return f(1, c, cuts, dp);
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);                //add in last to get the length
    cuts.insert(cuts.begin(),0);      //add in first to get the length
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j) continue;
            int mini = 1e9;
            for(int ind = i; ind <= j; ind++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}


