https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255



//First Solution :- Recursion
#include<bits/stdc++.h>
int f(int ind, int k, vector<int> &a, int n){
    if(ind == n){
        return 0;
    }
    
    int maxAns = 0, len = 0, maxi = -1e9, sum;
    for(int j = ind; j < min(n, ind+k); j++){
        len++;                    //increasing len each time
        maxi = max(maxi, a[j]);   //keep track of maximum 
        sum = (len * maxi) + f(j+1, k, a, n);    //calculate sum and call for smalller subproblems
        maxAns = max(maxAns, sum);                   //find maximum sum
    }
    return maxAns;
}

int maximumSubarray(vector<int> &a, int k)
{
    int n=a.size();
    vector<int> dp(n+1, -1);
    return f(0, k, a, n);
}




//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int ind, int k, vector<int> &a, int n, vector<int> &dp){
    if(ind == n){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }
    
    int maxAns = 0, len = 0, maxi = -1e9, sum;
    for(int j = ind; j < min(n, ind+k); j++){
        len++;                    //increasing len each time
        maxi = max(maxi, a[j]);   //keep track of maximum 
        sum = (len * maxi) + f(j+1, k, a, n, dp);    //calculate sum and call for smalller subproblems
        maxAns = max(maxAns, sum);                   //find maximum sum
    }
    return dp[ind] = maxAns;
}

int maximumSubarray(vector<int> &a, int k)
{
    int n=a.size();
    vector<int> dp(n+1, -1);
    return f(0, k, a, n, dp);
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int maximumSubarray(vector<int> &a, int k)
{
    int n=a.size();
    vector<int> dp(n+1, 0);

    for(int ind=n-1;ind>=0;ind--){
        int maxAns = 0, len = 0, maxi = -1e9, sum;
        for(int j = ind; j < min(n, ind+k); j++){
            len++;                    //increasing len each time
            maxi = max(maxi, a[j]);   //keep track of maximum 
            sum = (len * maxi) + dp[j+1];    //calculate sum and call for smalller subproblems
            maxAns = max(maxAns, sum);                   //find maximum sum
        }
        dp[ind] = maxAns;
    }

    return dp[0];
}
