https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/




//First Solution :- Using Recursion
class Solution{
public:
    int f(int i, int j, string &s, string &t){
        if(j==0){     //if s2 ends i.e. we are finished with matching 
            return 1;
        }
        if(i==0){    //if s1 exhausted then return 0
            return 0;
        }
    
        if(s[i-1] == t[j-1]){
            return f(i-1,j-1,s,t) + f(i-1,j,s,t);
        }
        else{
            return f(i-1,j,s,t);
        }
    }
    
    int subsequenceCount(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return f(n, m, s, t);
    }
};




//Second Solution :- Memoization 
class Solution{
public:
    const int mod = 1e9+7;
	int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
	    if(j==0){     //if s2 ends i.e. we are finished with matching 
	        return 1;
	    }
	    if(i==0){     //if s1 exhausted then return 0
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }

	    if(s[i-1] == t[j-1]){
	        return dp[i][j] = (f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp)) % mod;
	    }
	    else{
	        return dp[i][j] = f(i-1,j,s,t,dp) % mod;
	    }
	}
    
    int subsequenceCount(string s, string t)
    {
        int n = s.size();
        int m = t.size();
    	
    	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    	return f(n, m, s, t, dp);
    }
};




//Third Solution :- Tabulation 
class Solution{
public:
    const int mod = 1e9+7;

    int subsequenceCount(string s, string t)
    {
        int n = s.size();
        int m = t.size();
    	
    	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){  //Base case
            dp[i][0] = 1;
        }
        for(int j=1;j<=m;j++){  //Base case
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
 


//Fourth Solution :- Space Optimized Solution
class Solution{
public:
    const int mod = 1e9+7;

    int subsequenceCount(string s, string t)
    {
    	int n = s.size();
        int m = t.size();
        vector<int> prev(m+1,0), cur(m+1,0);
    
	    prev[0] = cur[0] = 1;   //Base case
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s[i-1] == t[j-1]){
	                cur[j] = (prev[j-1] + prev[j]) % mod;
	            }
	            else{
	                cur[j] = prev[j];
	            }
	        }
	        prev = cur;
	    }
	    return prev[m];
    }
};





//Fifth Solution :- Single Array Optimization
class Solution{
public:
    const int mod = 1e9+7;

    int subsequenceCount(string s, string t)
    {
    	int n = s.size();
        int m = t.size();
        vector<int> prev(m+1,0);
    
	    prev[0] = 1;   //Base case
	    
	    for(int i=1;i<=n;i++){
	        for(int j=m;j>=1;j--){
	            if(s[i-1] == t[j-1]){
	                prev[j] = (prev[j-1] + prev[j]) % mod;
	            }
	            // else{
	            //     prev[j] = prev[j];
	            // }
	        }
	    }
	    return prev[m];
    }
};



//Sixth Solution :- Leetcode submission
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();        
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
        for(int i=0;i<=n;i++){  //Base case
            dp[i][0] = 1;
        }
        for(int j=1;j<=m;j++){  //Base case
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};