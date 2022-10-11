https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int i, int j, string &s, string &t){
    if(j<0){     //if s2 exhausts and i part of s1 remains, then return i+1
        return i+1;
    }
    if(i<0){    //if s1 exhausts and j part of s2 remains, then return j+1
        return j+1;
    }

    if(s[i] == t[j]){
        return 0 + f(i-1,j-1,s,t);
    }
    else{     //insertion :- 1 + f(i,j-1),  //deletion :- 1 + f(i-1,j),  //rep1ace :-1 + f(i-1,j-1)
        return 1 + min(f(i-1,j,s,t), min(f(i,j-1,s,t), f(i-1,j-1,s,t)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m=str2.size();
    return f(n-1, m-1, str1, str2);
}




//First Solution :- Using Recursion
int f(int i, int j, string &s, string &t){
    if(j==0){     //if s2 exhausts and i part of s1 remains, then return i+1
        return i;
    }
    if(i==0){    //if s1 exhausts and j part of s2 remains, then return j+1
        return j;
    }

    if(s[i-1] == t[j-1]){
        return 0 + f(i-1,j-1,s,t);
    }
    else{     //insertion :- 1 + f(i,j-1),  //deletion :- 1 + f(i-1,j),  //rep1ace :-1 + f(i-1,j-1)
        return 1 + min(f(i-1,j,s,t), min(f(i,j-1,s,t), f(i-1,j-1,s,t)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m=str2.size();
    return f(n, m, str1, str2);
}



//Second Solution :- Memoization 
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j<0){     //if s2 exhausts and i part of s1 remains, then return i+1
        return i+1;
    }
    if(i<0){    //if s1 exhausts and j part of s2 remains, then return j+1
        return j+1;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i] == t[j]){
        return dp[i][j] = 0 + f(i-1,j-1,s,t,dp);
    }
    else{     //insertion :- 1 + f(i,j-1),  //deletion :- 1 + f(i-1,j),  //rep1ace :-1 + f(i-1,j-1)
        return dp[i][j] = 1 + min(f(i-1,j,s,t,dp), min(f(i,j-1,s,t,dp), f(i-1,j-1,s,t,dp)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m=str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1, m-1, str1, str2, dp);
}



//Second Solution :- Memoization 
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j==0){     //if s2 exhausts and i part of s1 remains, then return i+1
        return i;
    }
    if(i==0){    //if s1 exhausts and j part of s2 remains, then return j+1
        return j;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i-1] == t[j-1]){
        return dp[i][j] = 0 + f(i-1,j-1,s,t,dp);
    }
    else{     //insertion :- 1 + f(i,j-1),  //deletion :- 1 + f(i-1,j),  //rep1ace :-1 + f(i-1,j-1)
        return dp[i][j] = 1 + min(f(i-1,j,s,t,dp), min(f(i,j-1,s,t,dp), f(i-1,j-1,s,t,dp)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n, m, str1, str2, dp);
}



//Third Solution :- Tabulation 
int editDistance(string s, string t)
{
    int n = s.size(), m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){  //Base case
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){  //Base case
        dp[0][j] = j;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{   //insertion :- dp[i][j-1],  //deletion :- dp[i-1][j],  //replace :- dp[i-1][j-1]
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}



//Fourth Solution :- Space Optimized Solution
int editDistance(string s, string t)
{
    int n = s.size(), m=t.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    
    for(int j=0;j<=m;j++){  //Base case
        prev[j] = j;
    }

    for(int i=1;i<=n;i++){
        cur[0] = i;
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 0 + prev[j-1];
            }
            else{   //insertion :- dp[i][j-1],  //deletion :- dp[i-1][j],  //replace :- dp[i-1][j-1]
                cur[j] = 1 + min(prev[j], min(cur[j-1], prev[j-1]));
            }
        }
        prev = cur;
    }
    return prev[m];
}

