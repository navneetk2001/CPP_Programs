https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int ind, int W, vector<int> &wt, vector<int> &val){
    if(ind==0){    //base case
        if(wt[0] <= W) return val[0];
        return 0;
    }

    int nontake = 0 + f(ind-1, W, wt, val);
    int take = INT_MIN;
    if(wt[ind]<=W){
        take = val[ind] + f(ind-1,  W-wt[ind], wt, val);
    }

    return max(take,nontake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return f(n-1,maxWeight,weight,value);
}


//Second Solution :- Memoization 
int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(ind==0){    //base case
        if(wt[0] <= W) return val[0];
        return 0;
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }

    int nontake = 0 + f(ind-1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind]<=W){
        take = val[ind] + f(ind-1,  W-wt[ind], wt, val, dp);
    }

    return dp[ind][W] = max(take,nontake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}




//Third Solution :- Tabulation 
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int w=wt[0]; w<=maxWeight; w++){
        dp[0][w] = val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + dp[ind-1][w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind] + dp[ind-1][w-wt[ind]];
            }
            dp[ind][w] = max(take,nontake);
        }
    }

    return dp[n-1][maxWeight];
}

//Fourth Solution :- Space Optimized Solution 
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0), cur(maxWeight+1,0);
    for(int w=wt[0]; w<=maxWeight; w++){
        prev[w] = val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + prev[w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind] + prev[w-wt[ind]];
            }
            cur[w] = max(take,nontake);
        }
        prev = cur;
    }

    return prev[maxWeight];
}


//Fifth Solution :- Space Optimized Solution 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
       vector<int>prev(maxWeight+1,0);
        for(int i=weight[0];i<=maxWeight;i++){
            prev[i]=value[0];
        }
    
    for(int i=1;i<n;i++){
        for(int w=maxWeight;w>=0;w--){
             int nottake=0+prev[w];
             int take=-1e8;
             if(weight[i]<=w)take=value[i]+prev[w-weight[i]];
            
            prev[w]=max(take,nottake);
        }
    }
    return prev[maxWeight];
}
