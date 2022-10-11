https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



#include<bits/stdc++.h>
string shortestSupersequence(string s, string t)
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
    
    //length of shortest comon supersequence will be :- n + m - len(lcs(s,t));

    string ans = "";
    int i=n, j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){      
            ans += s[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += s[i-1];
            i--;
        }
        else{
            ans += t[j-1];
            j--;
        }
    }

    while(i>0){        //print remaining part of string s
        ans +=s[i-1];
        i--;
    }

    while(j>0){       //print remaining part of string t
        ans +=t[j-1];
        j--;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}




//Another Solution :-
string shortestCommonSupersequence(string& A, string& B) {
    int i = 0, j = 0;
    string res = "";
    for (char c : lcs(A, B)) {
        while (A[i] != c){
            res += A[i++];
        }
        while (B[j] != c){
            res += B[j++];
        }
        res += c, i++, j++;
    }
    return res + A.substr(i) + B.substr(j);
}

string lcs(string& A, string& B) {
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (A[i] == B[j]){
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            }
            else{
                dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
            }
        }
    }
    return dp[n][m];
}
