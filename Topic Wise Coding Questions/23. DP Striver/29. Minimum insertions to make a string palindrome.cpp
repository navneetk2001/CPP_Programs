https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Using Recursion
int f(int i, int j, string &s, string &t){
    if(i==0 || j==0){
        return 0;
    }

    if(s[i-1] == t[j-1]){
        return 1+f(i-1,j-1,s,t);
    }
    return max(f(i-1,j,s,t), f(i,j-1,s,t));
}

int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n=s.size();
    return f(n, n, s, rev);
}

int minInsertion(string &str)
{
    int n =str.size();
    int min = n - longestPalindromeSubsequence(str);
    return min;
}


//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1] == t[j-1]){
        return dp[i][j] = 1+f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(n, n, s, rev, dp);
}

int minInsertion(string &str)
{
    int n =str.size();
    int min = n - longestPalindromeSubsequence(str);
    return min;
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int j=0;j<=m;j++){  //Base case
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){  //Base case
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}

int minInsertion(string &str)
{
    int n =str.size();
    int min = n - longestPalindromeSubsequence(str);
    return min;
}


//Fourth Solution :- Space Optimized Solution 
#include<bits/stdc++.h>
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    
    for(int j=0;j<=m;j++){  //Base case
        prev[j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else{
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }
    return prev[m];
}

int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}

int minInsertion(string &str)
{
    int n =str.size();
    int min = n - longestPalindromeSubsequence(str);
    return min;
}
