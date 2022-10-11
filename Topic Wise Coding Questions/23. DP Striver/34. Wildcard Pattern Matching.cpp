https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int i, int j, string &pattern, string &text){
    if(i<0 && j<0){   //base case :- if s1 and s2 both gets exhausted
    	return true;
    }
    if(i<0 && j>=0){   //base case :- if s1 gets exhausted and s2 remains
    	return false;
    }
    if(j<0 && i>=0){   //base case :- if s2 gets exhausted and s1 remains
    	for(int ii=0;ii<=i;ii++){
    		if(pattern[ii] != '*'){
    			return false;
    		}
    	}
    	return true;
    }

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return f(i-1,j-1,pattern,text);
    }
    if(pattern[i] == '*'){     
        return f(i-1,j,pattern,text) || f(i,j-1,pattern,text);
    }
    return false;
}

bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size(), m = text.size();
	return f(n-1,m-1,pattern,text);
}



//First Solution :- Using Recursion
int f(int i, int j, string &pattern, string &text){
    if(i==0 && j==0){   //base case :- if s1 and s2 both gets exhausted
        return true;
    }
    if(i==0 && j>0){   //base case :- if s1 gets exhausted and s2 remains
        return false;
    }
    if(j==0 && i>0){   //base case :- if s2 gets exhausted and s1 remains
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1] != '*'){
                return false;
            }
        }
        return true;
    }

    if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
        return f(i-1,j-1,pattern,text);
    }
    if(pattern[i-1] == '*'){     
        return f(i-1,j,pattern,text) || f(i,j-1,pattern,text);
    }
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    return f(n,m,pattern,text);
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    if(i<0 && j<0){   //base case :- if s1 and s2 both gets exhausted
        return true;
    }
    if(i<0 && j>=0){   //base case :- if s1 gets exhausted and s2 remains
        return false;
    }
    if(j<0 && i>=0){   //base case :- if s2 gets exhausted and s1 remains
        for(int ii=0;ii<=i;ii++){
            if(pattern[ii] != '*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return dp[i][j] = f(i-1,j-1,pattern,text,dp);
    }
    if(pattern[i] == '*'){     
        return dp[i][j] = f(i-1,j,pattern,text,dp) || f(i,j-1,pattern,text,dp);
    }
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,pattern,text,dp);
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    if(i==0 && j==0){   //base case :- if s1 and s2 both gets exhausted
        return true;
    }
    if(i==0 && j>0){   //base case :- if s1 gets exhausted and s2 remains
        return false;
    }
    if(j==0 && i>0){   //base case :- if s2 gets exhausted and s1 remains
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1] != '*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
        return dp[i][j] = f(i-1,j-1,pattern,text,dp);
    }
    if(pattern[i-1] == '*'){     
        return dp[i][j] = f(i-1,j,pattern,text,dp) || f(i,j-1,pattern,text,dp);
    }
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n,m,pattern,text,dp);
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    
    dp[0][0] = true;              //base case
    for(int j=1;j<=m;j++){        //base case
        dp[0][j] = false;
    }

    for(int i=1;i<=n;i++){       //base case  
        bool flag = true;
        for(int ii = 1; ii<=i; ii++){
            if(pattern[ii-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[i-1] == '*'){     
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}



//Fourth Solution :- Space Optimized Solution
#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<bool> prev(m+1,false), cur(m+1,false);
    
    prev[0] = true;              //base case
    for(int j=1;j<=m;j++){        //base case
        prev[j] = false;
    }    

    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int ii = 1; ii<=i; ii++){
            if(pattern[ii-1] != '*'){
                flag = false;
                break;
            }
        }
        cur[0] = flag;
        
        for(int j=1;j<=m;j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                cur[j] = prev[j-1];
            }
            else if(pattern[i-1] == '*'){     
                cur[j] = prev[j] || cur[j-1];
            }
            else{
                cur[j] = false;
            }
        }
        prev = cur;
    }

    return prev[m];
}





//Solution :- Memoization  (LeetCode Submission)
class Solution {
private:
    bool getMatch(int i, int j, string &s, string &p, vector<vector<int>>& dp){
        if(j<=0 && i<=0) return true;
        if(j<=0) return false;
        if(i<=0){
            while(j > 0){ 
                if(p[j-1]!='*') 
                    return false; 
                j--;
            }
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='?')){
            return dp[i][j] = getMatch(i-1, j-1, s, p, dp);
        }
        else if(p[j-1]=='*'){
            return dp[i][j] = getMatch(i-1, j, s, p, dp) || getMatch(i, j-1, s, p, dp);
        }
        else{ 
            return dp[i][j] = false;
        }
    }
    
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp (n+1, vector<int>(m+1, -1));
        return getMatch(n, m, s, p, dp);
    }
};