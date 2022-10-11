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


//Print the longest common subsequence string

int len = dp[n][m];         //stores the length of longest common subsequence
string ans = "";            //empty string to store the answer
for(int i=0;i<len;i++){
    ans += '$';
}

int index = len-1;
int i=n, j=m;
while(i>0 && j>0){
    if(s[i-1]==t[j-1]){      
        ans[index] = s[i-1];
        index--;
        i--, j--;                                                                                                                          ]
    }
    else if(dp[i-1][j] > dp[i][j-1]){
        i--;
    }
    else{
        j--;
    }
}
cout<<ans<<endl;
