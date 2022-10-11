https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int ind, int W, vector<int> &wt, vector<int> &val){
    if(ind==0){    //base case
        return (int)(W/wt[0])*val[0];
    }

    int nontake = 0 + f(ind-1, W, wt, val);
    int take = -1e8;
    if(wt[ind]<=W){
        take = val[ind] + f(ind,  W-wt[ind], wt, val);
    }

    return max(take,nontake);
}

int unboundedKnapsack(int n, int w, vector<int> &value, vector<int> &weight)
{
    return f(n-1,w,weight,value);
}


//Second Solution :- Memoization 
int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(ind==0){    //base case
        return (int)(W/wt[0])*val[0];
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }

    int nontake = 0 + f(ind-1, W, wt, val, dp);
    int take = -1e8;
    if(wt[ind]<=W){
        take = val[ind] + f(ind,  W-wt[ind], wt, val, dp);
    }

    return dp[ind][W] = max(take,nontake);
}

int unboundedKnapsack(int n, int w, vector<int> &value, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,weight,value,dp);
}



//Third Solution :- Tabulation 
int unboundedKnapsack(int n, int maxWeight, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int w=0; w<=maxWeight; w++){
        dp[0][w] = (int)(w/wt[0])*val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + dp[ind-1][w];
            int take = -1e8;
            if(wt[ind]<=w){
                take = val[ind] + dp[ind][w-wt[ind]];
            }
            dp[ind][w] = max(take,nontake);
        }
    }
    return dp[n-1][maxWeight];
}


//Fourth Solution :- Space Optimized Solution 
int unboundedKnapsack(int n, int maxWeight, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(maxWeight+1,0), cur(maxWeight+1,0);
    for(int w=0; w<=maxWeight; w++){
        prev[w] = (int)(w/wt[0])*val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + prev[w];
            int take = -1e8;
            if(wt[ind]<=w){
                take = val[ind] + cur[w-wt[ind]];
            }
            cur[w] = max(take,nontake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}



//Fifth Solution :- Space Optimized Solution 
int unboundedKnapsack(int n, int maxWeight, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(maxWeight+1,0);
    for(int w=0; w<=maxWeight; w++){
        prev[w] = (int)(w/wt[0])*val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + prev[w];
            int take = -1e8;
            if(wt[ind]<=w){
                take = val[ind] + prev[w-wt[ind]];
            }
            prev[w] = max(take,nontake);
        }
    }
    return prev[maxWeight];
}


//Sixth Solution :-
int unboundedKnapsack(int n, int maxWeight, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(maxWeight+1,0);
    for(int w=wt[0]; w<=maxWeight; w++){
        prev[w] = (int)(w/wt[0])*val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int nontake = 0 + prev[w];
            int take = -1e8;
            if(wt[ind]<=w){
                take = val[ind] + prev[w-wt[ind]];
            }
            prev[w] = max(take,nontake);
        }
    }
    return prev[maxWeight];
}

