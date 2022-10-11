https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
long f(int ind, int T, int *nums){
    if(ind==0){    //base case
        if(T % nums[0] == 0) return 1;
        else return 0;
    }

    long nontake = f(ind-1, T, nums);
    long take = 0;
    if(nums[ind]<=T){
        take = f(ind,  T-nums[ind], nums);
    }

    return take + nontake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(n-1,value,denominations);
}


//Second Solution :- Memoization 
#include<bits/stdc++.h>
long f(int ind, int T, int *nums, vector<vector<long>> &dp){
    if(ind==0){    //base case
        if(T % nums[0] == 0) return 1;
        else return 0;
    }
    if(dp[ind][T]!=-1){
        return dp[ind][T];
    }
    
    long nontake = f(ind-1, T, nums,dp);
    long take = 0;
    if(nums[ind]<=T){
        take = f(ind,  T-nums[ind], nums,dp);
    }

    return dp[ind][T] = take + nontake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
long countWaysToMakeChange(int *num, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    for(int T=0; T<=value; T++){
        if(T%num[0] == 0){
            dp[0][T] = 1;
        }
        else{
            dp[0][T] = 0;
        }
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long nontake = dp[ind-1][T];
            long take = 0;
            if(num[ind]<=T){
                take = dp[ind][T-num[ind]];
            }
            dp[ind][T] = take + nontake;
        }
    }
    return dp[n-1][value];
}



//Fourth Solution :- Space Optimized Solution
#include<bits/stdc++.h>
long countWaysToMakeChange(int *num, int n, int value)
{
    vector<long> prev(value+1,0), cur(value+1,0);
    for(int T=0; T<=value; T++){
        if(T%num[0] == 0){
            prev[T] = 1;
        }
        else{
            prev[T] = 0;
        }
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long nontake = prev[T];
            long take = 0;
            if(num[ind]<=T){
                take = cur[T-num[ind]];
            }
            cur[T] = take + nontake;
        }
        prev = cur;
    }
    return prev[value];
}



