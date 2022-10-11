https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int ind, int N, vector<int> &price){
    if(ind==0){    //base case
        return N*price[0];
    }

    int nontake = 0 + f(ind-1, N, price);
    int take = -1e8;
    int rodLength = ind + 1;
    if(rodLength <= N){
        take = price[ind] + f(ind,  N-rodLength, price);
    }

    return max(take,nontake);
}

int cutRod(vector<int> &price, int n)
{
    return f(n-1,n, price);
}



//Second Solution :- Memoization 
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
    if(ind==0){    //base case
        return N*price[0];
    }
    if(dp[ind][N]!=-1){
        return dp[ind][N];
    }

    int nontake = 0 + f(ind-1, N, price, dp);
    int take = -1e8;
    int rodLength = ind + 1;
    if(rodLength <= N){
        take = price[ind] + f(ind,  N-rodLength, price, dp);
    }

    return dp[ind][N] = max(take,nontake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n, price,dp);
}



//Third Solution :- Tabulation 
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int N=0; N<=n; N++){  //base case
        dp[0][N] = N*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int N=0; N<=n; N++){
            int nontake = 0 + dp[ind-1][N];
            
            int take = -1e8;
            int rodLength = ind+1;
            if(rodLength <= N){
                take = price[ind] + dp[ind][N-rodLength];
            }
            dp[ind][N] = max(take,nontake);
        }
    }
    return dp[n-1][n];
}



//Fourth Solution :- Space Optimized Solution 
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0), cur(n+1,0);
    for(int N=0; N<=n; N++){  //base case
        prev[N] = N*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int N=0; N<=n; N++){
            int nontake = 0 + prev[N];
            
            int take = -1e8;
            int rodLength = ind+1;
            if(rodLength <= N){
                take = price[ind] + cur[N-rodLength];
            }
            cur[N] = max(take,nontake);
        }
        prev = cur;
    }
    return prev[n];
}




//Fifth Solution :- Space Optimized Solution 
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0);
    for(int N=0; N<=n; N++){  //base case
        prev[N] = N*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int N=0; N<=n; N++){
            int nontake = 0 + prev[N];
            
            int take = -1e8;
            int rodLength = ind+1;
            if(rodLength <= N){
                take = price[ind] + prev[N-rodLength];
            }
            prev[N] = max(take,nontake);
        }
    }
    return prev[n];
}
