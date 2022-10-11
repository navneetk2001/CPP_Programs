https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1




//First Solution :- Using Recursion
class Solution{
public:
    int f(int ind, int W, int wt[], int val[]){
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

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    {
        return f(n-1, maxWeight, wt, val);
    }
};



//Second Solution :- Memoization 
class Solution{
public:
    int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
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

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
        return f(n-1, maxWeight, wt, val, dp);
    }
};




//Third Solution :- Tabulation 
class Solution{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
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
};




//Fourth Solution :- Space Optimized Solution 
class Solution{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
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
};



//Fifth Solution :- Space Optimized Solution 
class Solution{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    {
        vector<int> prev(maxWeight+1,0);
        for(int i=wt[0];i<=maxWeight;i++){
            prev[i]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=maxWeight;w>=0;w--){
                int nottake=0+prev[w];
                int take=-1e8;
                if(wt[i]<=w)take=val[i]+prev[w-wt[i]];
                
                prev[w]=max(take,nottake);
            }
        }
        return prev[maxWeight];
    }
};
 