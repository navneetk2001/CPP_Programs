https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Using Recursion
int f(int ind, int prev_ind, int arr[], int n){
    if(ind == n){       //base case
        return 0;
    }
    
    int notpick = 0 + f(ind+1, prev_ind, arr, n);
    int pick = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        pick = 1 + f(ind+1, ind, arr, n);
    }
    return max(pick,notpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(0,-1,arr,n);   //ind :- 0, //prev_ind :- -1
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp){
    if(ind == n){       //base case
        return 0;
    }
    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }
    
    int notpick = 0 + f(ind+1, prev_ind, arr, n, dp);
    int pick = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        pick = 1 + f(ind+1, ind, arr, n, dp);
    }
    return dp[ind][prev_ind+1] = max(pick,notpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);   //ind :- 0, //prev_ind :- -1
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int notpick = 0 + dp[ind+1][prev_ind+1];
            int pick = 0;
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                pick = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_ind+1] = max(pick,notpick);
        }
    }
    return dp[0][0];
}



//Fourth Solution :- Space-Optimized Solution
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n+1,0), cur(n+1,0);

    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int notpick = 0 + next[prev_ind+1];
            int pick = 0;
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                pick = 1 + next[ind+1];
            }
            cur[prev_ind+1] = max(pick,notpick);
        }
        next = cur;
    }
    return next[0];
}



//Fifth Solution :- 1-D DP OPtimized Tabulation Solution
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    
    int maxi = 1;   //store maximum ans
    for(int i=0; i < n; i++){
        for(int prev=0; prev<i; prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}



//Sixth Solution :- For Printing Purpose
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1), hash(n);
    int lastIndex = 0;

    int maxi = 1;   //store maximum ans
    for(int i=0; i < n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> LIS;
    LIS.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        LIS.push_back(arr[lastIndex]);
    }
    reverse(LIS.begin(),LIS.end());

    for(auto it : LIS){
        cout<<it<<" ";
    }
    cout<<endl;
    return maxi;
}




//Seventh Solution :- Binary Search Intuition
//Here, we are only concerned with size of LIS, not with actual element of LIS
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);       //insert first element in vector
    int len = 1;                  //store size of LIS

    for(int i=1;i<n;i++){
        if(arr[i] > temp.back()){    //if curr_element is greater than previous element then push it in vector
            temp.push_back(arr[i]);
            len++;                    //increment length each time you push
        }
        else{                         //else if not greater then find an element which is greater than current element and replace that element with curr_ele
            int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();;
            temp[ind] = arr[i];
        }
    }
    return len;
}



