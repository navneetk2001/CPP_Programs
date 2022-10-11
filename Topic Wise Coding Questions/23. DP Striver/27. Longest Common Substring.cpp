https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int solve(int i, int j, int count, string str1, string str2){
    if (i == 0 || j == 0){
        return count;
    }

    if (str1[i - 1] == str2[j - 1]){
        count = solve(i - 1, j - 1, count + 1, str1, str2);
    }

    int count1 = solve(i, j - 1, 0, str1, str2);   //for non matching set count to zero as there has been a break, now again start traversing
    int count2 = solve(i - 1, j, 0, str1, str2);   //same as above set non nmatching char -> count value as zero

    count = max({count, count1,count2});
    return count;
}

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    int ans = solve(n, m, 0, str1, str2);
    return ans;
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int lcs(string &s, string &t)
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
    
    int ans = 0; //to store the maximum value in dp table
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}




//Fourth Solution :- Space Optimized Solution 
int lcs(string &s, string &t)
{
    int n=s.size();
    int m=t.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    
    for(int j=0;j<=m;j++){  //Base case
        prev[j] = 0;
    }
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else{
                cur[j] = 0;
            }
        }
        prev = cur;
    }
    return ans;
}





// Method4()- recursive solution with memoization (Top-down approach caching on method level)
public static int LCSubStrM2A1(char[] X, char[] Y, int m, int n, int lcsCount, Integer[][][] dp) {
    if (m <= 0 || n <= 0)
        return lcsCount;

    if (dp[m][n][lcsCount] != null)
        return dp[m][n][lcsCount];

    int lcsCount1=lcsCount;
    if (X[m - 1] == Y[n - 1])
        lcsCount1 = LCSubStrM2A1(X, Y, m - 1, n - 1, lcsCount + 1, dp);

    int lcsCount2 = LCSubStrM2A1(X, Y, m, n - 1, 0, dp);
    int lcsCount3 = LCSubStrM2A1(X, Y, m - 1, n, 0, dp);

    return dp[m][n][lcsCount] = Math.max(lcsCount1, Math.max(lcsCount2, lcsCount3));
}