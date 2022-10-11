// Given two strings S and T, find length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return -1. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. A string of length n has 2^n different possible subsequences.

// Example 1:
// Input:
// S = "babab"
// T = "babba"
// Output: 3
// Explanation: There are no subsequences of S with length less than 3 which is not a subsequence of T. "aab" is an example of a subsequence of length 3 which isn't a subsequence of T.

// Example 2:
// Input:
// S = "babhi"
// T = "babij"
// Output: 1
// Explanation: "h" is a subsequence of S that is not a subsequence of T.




//Solution Approach :- TOP DOWN APPROOACh :- Memoization
int findShortest(vector<vector<int>> &dp, string &S, string &T, int n, int m, int i, int j){
    if(i >= n){            //This is because if we reach end of the string it means -> we were not able to find a subsequence which was not common
        return 501;
    }
    
    if(j >= m){     //Now if i is not reached at end yet but j is reached we can definitely say that if now I take ith character in our subsequence, it will definitely create an uncommon subsequence
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //Suppose any of the above condition is not true, we will try to find current ith character in T string starting from j,
    int k = j;
    for(; k < m; k++){
        //if we find the character, it gives us two options -> either take that character in the uncommon subsequence and increase j to k + 1 and check to next character or don't add to subsequence and check for next character
        if(S[i] == T[k]){
            break;
        }
    }
    //or in case we did not find the ith character of S in T, then it's sure that we will get the uncommon subsequence by adding that character to our current ans
    if(k == m){
        return 1;
    }
    return dp[i][j] = min(findShortest(dp, S, T, n, m, i + 1, j), 1 + findShortest(dp, S, T, n, m, i + 1, k + 1));
}


int shortestUnSub(string S, string T) {
    int n = S.size();
    int m = T.size();
    vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
    int ans = findShortest(dp, S, T, n, m, 0, 0);
    return ans >= 501 ? -1 : ans;
}





//Second Solution :- Approach : 
// For substring of S starting from index 0 find the minimum length of uncommon sequence between substring and every substring of T 
// DP state 
// if matching character is not found then answer is 1
// if matching character is found then answer will be…
// dp[i][j] will denote length of minimum uncommon sequence of S of first i chars and T of first j chars
// dp[i][j] → S upto length i and T upto length j 

// Let's suppose string is 
// S → upiu
// T → pipu
// S[0] ≠ T[0]
// so dp[1][1] = 1 … considering 1 based indexing
// S[0] ≠ T[1]
// S[0] ≠ T[0]
// dp[1][2] = 1
// S[0] ≠ T[2]
// S[0] ≠ T[1]
// S[0] ≠ T[0]
// dp[1][3] = 1

// S[0] == T[4]
// u
// pipu
// There is no uncommon subsequence possible…
// now what ??? 
// We have two choices for state dp[i][j]
// We have to exclude the ith character and check upto given index j i.e. dp[i][j] can be equal to dp[i-1][j]…
// But suppose the first matching character was found at kth index so we are sure that length of uncommon sequence from k to j and string s of length i must be 1 right…
// i.e. dp[i][j] can be equal to dp[i-1][k-1]+1
// Our answer is minimum of 2

int shortestUnSub(string S, string T) {
    int n = S.size(), m = T.size();
    vector <vector<int>> dp(n+1, vector<int>(m+1, 1000));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k = j;
            while(k && S[i-1] != T[k-1]){
                k -= 1;
            }
            if(k == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = min(dp[i-1][j], 1+dp[i-1][k-1]);
            }
        }
    }
    return dp[n][m] == 1000 ? -1 : dp[n][m];
}




//Third Solution :- Space Optimization
int shortestUnSub(string S, string T) {
    if(S==T)
        return -1;
    int n = S.length();
    int m = T.length();
    
    vector<int> next(m+1,1e9),curr(m+1,1e9);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            int k = j;
            for(;k>=0;k--)
                if(S[i]==T[k])
                    break;
            if(k<0)
                next[j+1] = 1;
            else
                next[j+1] = min(curr[j+1],1+curr[k]);
        }
        curr = next;
    }
    if(next[m]>=1e9)
        return -1;
    return next[m];
}




//Fourth Solution :-
int shortestUnSub(string S, string T) {
    // code here
    int n=S.size();
    int m=T.size();
    int maxi=1000;
    int dp[n+1][m+1];
    for(int i=1;i<=n; i++)
    {
        dp[i][0]=1;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=maxi;
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<m;j++)
        {
            int k=j;
            for(k; k>=0;k--)
            {
                if(S[i]==T[k])
                break;
            }
            if(k<0)
            {
                dp[i+1][j+1]=1;
            }
            else
            {
                dp[i+1][j+1]=min(dp[i][j+1], dp[i][k]+1);
            }
        }
    }
    if(dp[n][m]>=maxi){
    	return -1;
    }
    return dp[n][m];
}



//Fifth Solution :- Recursion + Memoization
class Solution{
public:
    int dp[501][501];
    int solve(string& s, string& t, int i, int j)
    {
        if(i >= s.size())
        return 1000;
        
        if(j >= t.size())
        return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int k = j;
        for(; k < t.size(); k++)
        {
            if(t[k] == s[i])
            {
                break;
            }
        }
        
        if(k == t.size()) return 1; // this character is not present in t
        
        int ans1 = solve(s, t, i + 1, j);
        int ans2 = 1 + solve(s, t, i + 1, k + 1);
        
        return dp[i][j] = min(ans1, ans2);
        
        
    }
    int shortestUnSub(string s, string t) {
        // code here
        int sz = s.size();
        int ts = t.size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(s, t, 0, 0);
        
        if(ans >= 1000)
        return -1;
        
        return ans;
        
    }
};