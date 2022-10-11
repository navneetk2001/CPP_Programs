https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include<bits/stdc++.h>
int f(int ind, int buy, vector<int> &prices){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind >= prices.size()){  
        return 0;
    }
    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,prices)), 0 + f(ind+1,1,prices));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind] + f(ind+2,1,prices)), 0 + f(ind+1,0,prices));
        //profit = max( sell on that day, not sell on that day)
    }
    return profit;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    return f(0, 1, prices);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind >= prices.size()){  
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,prices,dp)), 0 + f(ind+1,1,prices,dp));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind] + f(ind+2,1,prices,dp)), 0 + f(ind+1,0,prices,dp));
        //profit = max( sell on that day, not sell on that day)
    }
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0, 1, prices, dp);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){
                profit = max((-prices[ind] + dp[ind+1][0]), 0 + dp[ind+1][1]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{
                profit = max((prices[ind] + dp[ind+2][1]), 0 + dp[ind+1][0]);
                //profit = max( sell on that day, not sell on that day)
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}



//Fourth Solution :- 
#include<bits/stdc++.h>
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    for(int ind = n-1; ind>=0; ind--){
        dp[ind][1] = max((-prices[ind] + dp[ind+1][0]), 0 + dp[ind+1][1]);        //profit = max( buy on that day, not buy on that day)

        dp[ind][0] = max((prices[ind] + dp[ind+2][1]), 0 + dp[ind+1][0]);         //profit = max( sell on that day, not sell on that day)
    }
    return dp[0][1];
}




//Fifth Solution :-  Space OPtimization
#include<bits/stdc++.h>
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2,0), front1(2,0), cur(2,0);

    for(int ind = n-1; ind>=0; ind--){
        cur[1] = max((-prices[ind] + front1[0]), 0 + front1[1]);        //profit = max( buy on that day, not buy on that day)
        cur[0] = max((prices[ind] + front2[1]), 0 + front1[0]);         //profit = max( sell on that day, not sell on that day)
        
        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}
