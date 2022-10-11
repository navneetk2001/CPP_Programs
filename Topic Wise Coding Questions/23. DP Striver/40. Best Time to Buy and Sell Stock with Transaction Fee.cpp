https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include<bits/stdc++.h>
int f(int ind, int buy, int fee, vector<int> &prices){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind == prices.size()){  
        return 0;
    }
    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,fee,prices)), 0 + f(ind+1,1,fee,prices));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind]-fee + f(ind+1,1,fee,prices)), 0 + f(ind+1,0,fee,prices));
        //profit = max( sell on that day, not sell on that day)
    }
    return profit;
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    return f(0, 1, fee, prices);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int ind, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind == prices.size()){  
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,fee,prices,dp)), 0 + f(ind+1,1,fee,prices,dp));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind]-fee + f(ind+1,1,fee,prices,dp)), 0 + f(ind+1,0,fee,prices,dp));
        //profit = max( sell on that day, not sell on that day)
    }
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0, 1, fee, prices, dp);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int maximumProfit(int n, int fee, vector<int> &prices) 
{
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){
                profit = max((-prices[ind] + dp[ind+1][0]), 0 + dp[ind+1][1]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{
                profit = max((prices[ind]-fee + dp[ind+1][1]), 0 + dp[ind+1][0]);
                //profit = max( sell on that day, not sell on that day)
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}



//Fourth Solution :- 
#include<bits/stdc++.h>
int maximumProfit(int n, int fee, vector<int> &prices) 
{
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for(int ind = n-1; ind>=0; ind--){
        dp[ind][1] = max((-prices[ind] + dp[ind+1][0]), 0 + dp[ind+1][1]);        //profit = max( buy on that day, not buy on that day)

        dp[ind][0] = max((prices[ind]-fee + dp[ind+1][1]), 0 + dp[ind+1][0]);         //profit = max( sell on that day, not sell on that day)
    }
    return dp[0][1];
}




//Fifth Solution :-  Space OPtimization
#include<bits/stdc++.h>
int maximumProfit(int n, int fee, vector<int> &prices) 
{
    vector<int> front1(2,0), cur(2,0);

    for(int ind = n-1; ind>=0; ind--){
        cur[1] = max((-prices[ind] + front1[0]), 0 + front1[1]);        //profit = max( buy on that day, not buy on that day)
        cur[0] = max((prices[ind]-fee + front1[1]), 0 + front1[0]);         //profit = max( sell on that day, not sell on that day)
        
        front1 = cur;
    }
    return cur[1];
}
