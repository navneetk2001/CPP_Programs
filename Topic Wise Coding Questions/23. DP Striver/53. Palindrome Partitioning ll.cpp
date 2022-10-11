https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Recursion
#include<bits/stdc++.h>
bool check(string str)
{
    int n = str.length();
    for(int i=0;i<n/2;i++){ 
        if(str[i]!=str[n-i-1]){
            return false; 
        }
    }
   return true;
}

int sol(string str, int n, int i)
{
    if(i==n){
        return 0;
    }

    int ans=INT_MAX;
    for(int j=i;j<n;j++){
        if(check(str.substr(i,j-i+1))){
           int temp = 1 + sol(str,n,j+1);
           ans = min(ans,temp);
        }
    }
    return ans;
}

int palindromePartitioning(string str){
    int n = str.length();
    return sol(str,n,0) - 1;
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
bool check(string str)
{
    int n = str.length();
    for(int i=0;i<n/2;i++){ 
        if(str[i]!=str[n-i-1]){
            return false; 
        }
    }
   return true;
}

int sol(string str,int n,int i,vector<int> &dp)
{
    if(i==n){
        return 0;
    }
   
    if(dp[i]!=-1){ 
        return dp[i];
    }
    int ans=INT_MAX;
    for(int j=i;j<n;j++){
        if(check(str.substr(i,j-i+1))){
           int temp = 1 + sol(str,n,j+1,dp);
           ans = min(ans,temp);
        }
    }
    return dp[i] = ans;
}

int palindromePartitioning(string str){
    int n = str.length();
    vector<int> dp(n,-1);
    return sol(str,n,0,dp) - 1;
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
bool isPalin(int i, int j, string& s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int solve(int i, int n, string& s, vector<int>& dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    int cost = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalin(i, j, s)){
            int cut = 1 + solve(j+1, n, s, dp);
            cost = min(cut, cost);
        }
    }
    return dp[i] = cost;
}

int palindromePartitioning(string s) {
    int n = s.length();
    vector<int> dp(n, -1);

    int ans = solve(0, n, s, dp)-1;
    return ans;
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
bool isPalin(int i, int j, string& s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int palindromePartitioning(string s) {
    int n = s.length();
    vector<int> dp(n+1, 0);
    
    dp[n] = 0;

    for(int i=n-1;i>=0;i--){
        int cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i, j, s)){
                int cut = 1 + dp[j+1];
                cost = min(cut, cost);
            }
        }
        dp[i] = cost;
    }
    return dp[0]-1;
}





//Fourth Solution :- Tabulation
#include<bits/stdc++.h>
bool isPalindrome(string &s, int i,int j){
    while(i<j){
        if(s[i] != s[j]){ 
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                dp[i][j] = 0;
            }
            else{
                int ans = 1e9;
                for(int k=i;k<j;k++){
                    ans = min(ans, 1 + dp[i][k] + dp[k+1][j]);
                } 
                dp[i][j] = ans;    
            }
        }
    }
    return dp[0][n-1];
}


