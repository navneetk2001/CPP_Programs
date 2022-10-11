https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Recursion
#include<bits/stdc++.h>
#define ll long long
int mod = 1000000007;

int solve(int i, int j, int isTrue, string& exp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }
    
    ll ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll lT = solve(i, ind-1, 1, exp);
        ll lF = solve(i, ind-1, 0, exp);
        ll rT = solve(ind+1, j, 1, exp);
        ll rF = solve(ind+1, j, 0, exp);
        
        if(exp[ind]=='&'){
            if(isTrue){
                ways = (ways + (lT*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (rF*lF)%mod)%mod;
            }
        }
        else if(exp[ind]=='|'){
            if(isTrue){
                ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lF*rF)%mod)%mod;
            }
        }
        else{     //in case of (exp[ind] == '^')
            if(isTrue){
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
    }
    return ways;
}

int evaluateExp(string & exp) {
    int n = exp.length();
    return solve(0, n-1, 1, exp);
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
#define ll long long
int mod = 1000000007;

int solve(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }
    
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    
    ll ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll lT = solve(i, ind-1, 1, exp, dp);
        ll lF = solve(i, ind-1, 0, exp, dp);
        ll rT = solve(ind+1, j, 1, exp, dp);
        ll rF = solve(ind+1, j, 0, exp, dp);
        
        if(exp[ind]=='&'){
            if(isTrue){
                ways = (ways + (lT*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (rF*lF)%mod)%mod;
            }
        }
        else if(exp[ind]=='|'){
            if(isTrue){
                ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lF*rF)%mod)%mod;
            }
        }
        else{     //in case of (exp[ind] == '^')
            if(isTrue){
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return solve(0, n-1, 1, exp, dp);
}



//Third Solution :- Tabulation 
//Here's the tabulation code which got me correct!
#include<bits/stdc++.h>
#define ll long long 
int mod = 1000000007;

int evaluateExp(string & exp) {
    int n= exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));
    
    for(int i=0; i<n; i++){
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            for(int isTrue=0; isTrue <=1; isTrue++){
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2){
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];

                    if(exp[ind] == '&'){
                        if(isTrue) ways = (ways + (lT * rT)%mod)%mod;
                        else ways = (ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod)%mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lF*rF)%mod)%mod;
                    }
                    else{
                        if(isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    
    return dp[0][n-1][1];
}




//Fourth Solution :-  Memoization 
//I tried to solve the problem on my own and returned pair for counts of both true and false instead of calling 4 times recursion. 
//Below is my code:

unsigned int mod=1e9+7;
pair<long long,long long> helper(string &s,int i,int j,vector<vector<pair<long long,long long>>> &dp){
    if(i==j){
        if(s[i]=='T'){
            return {1,0};
        }
        else{
            return {0,1};
        }
    }
    if(dp[i][j]!=make_pair((long long)-1,(long long)-1)){
        return dp[i][j];
    }
    
    long long ans1=0,ans2=0;
    for(int k=i+1;k<j;k+=2){
        auto l=helper(s,i,k-1,dp);
        auto r=helper(s,k+1,j,dp);
        if(s[k]=='|'){
            int tans1 = ((l.first*r.first)%mod + (l.first*r.second)%mod + (l.second*r.first)%mod)%mod;
            int tans2=(l.second*r.second)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
        else if(s[k]=='&'){
            int tans1 = (l.first*r.first)%mod;
            int tans2=((l.first*r.second)%mod + (l.second*r.first)%mod + (l.second*r.second)%mod)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
        else{
            int tans1 = ((l.first*r.second)%mod + (l.second*r.first)%mod)%mod;
            int tans2= ((l.first*r.first)%mod + (l.second*r.second)%mod)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
    }
    return dp[i][j] = {ans1,ans2};
}

int evaluateExp(string & s) {
    int n=s.size();
    vector<vector<pair<long long,long long>>> dp(n,vector<pair<long long,long long>>(n,{-1,-1}));
    return helper(s,0,n-1,dp).first;
}



//Fifth Solution :- //Here's the Tabulation Code which is running absolutely fine in Coding Ninjas:
#define ll long long int
ll mod=1000000007;

int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else {
                ll ways=0;
                for(ll ind=i+1;ind<=j-1;ind+=2){
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    
                    if(exp[ind]=='&'){
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|'){
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else{
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}


