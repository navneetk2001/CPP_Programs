// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Example 1:
// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked with bold characters in dcbabcd

// Example 2:
// Input: str = "aa"
// Output: 0
// Explanation:"aa" is already a palindrome.





//Solution Approach :- Memoization
int travel(string &str, vector<vector<int>> &dp, int i, int j){
    if(i >= j ){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(str[i] == str[j]){
        return dp[i][j] = travel(str, dp, i + 1, j - 1);
    }
    else{
        return dp[i][j] = 1 + min(travel(str, dp, i + 1, j), travel(str, dp, i, j - 1));
    }
}

int countMin(string str){
    int n = str.length();
    int i = 0;
    int j = n - 1;
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return travel(str, dp, i, j);
}



//Second Solution :- LCS with SPACE OPTIMISATION
class Solution{
  public:
    int lcs(string s1, string s2, int m, int n) {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0) {
                    curr[j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    
    int countMin(string str){
        int n = str.length();
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        int lps = lcs(str, rev, n, n);
        return n - lps;
    }
};



//Third Solution :-
class Solution{
  public:
    int dp[1001][1001];

    int solve(string a, string b,int i,int j){
    	if(i<0 || j<0){
    		return 0;
    	}
    
    	if(dp[i][j]!=-1){
    		return dp[i][j];
    	}
    
    	if(a[i]==b[j]){
    	   return dp[i][j] = 1 + solve(a,b,i-1,j-1);
    	}
    
    	return  dp[i][j] = max(solve(a,b,i-1,j), solve(a,b,i,j-1));
    }
    
    int countMin(string str){
    	memset(dp,-1,sizeof dp);
    	string rev = str;
    	reverse(rev.begin(),rev.end());
    	return str.length() - solve(str,rev,str.length()-1,rev.length()-1);
    }
};
