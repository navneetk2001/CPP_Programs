https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
#include<bits/stdc++.h>
long f(int ind, int buy, long *values, int n){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind == n){  
        return 0;
    }
    long profit = 0;
    if(buy){
        profit = max((-values[ind] + f(ind+1,0,values,n)), 0 + f(ind+1,1,values,n));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((values[ind] + f(ind+1,1,values,n)), 0 + f(ind+1,0,values,n));
        //profit = max( sell on that day, not sell on that day)
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return f(0, 1, values, n);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
long f(int ind, int buy, long *values, int n, vector<vector<long>> &dp){  //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
    if(ind == n){  
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }

    long profit = 0;
    if(buy){
        profit = max((-values[ind] + f(ind+1,0,values,n,dp)), 0 + f(ind+1,1,values,n,dp));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((values[ind] + f(ind+1,1,values,n,dp)), 0 + f(ind+1,0,values,n,dp));
        //profit = max( sell on that day, not sell on that day)
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0, 1, values, n, dp);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
}



//Third Solution :- Tabulation 
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0] = dp[n][1] = 0;      //base cases

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                profit = max((-values[ind] + dp[ind+1][0]), 0 + dp[ind+1][1]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{
                profit = max((values[ind] + dp[ind+1][1]), 0 + dp[ind+1][0]);
                //profit = max( sell on that day, not sell on that day)
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}



//Fourth Solution :- Space Optimized Solution
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<long> ahead(2,0), cur(2,0);
    ahead[0] = ahead[1] = 0;      //base cases

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                profit = max((-values[ind] + ahead[0]), 0 + ahead[1]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{
                profit = max((values[ind] + ahead[1]), 0 + ahead[0]);
                //profit = max( sell on that day, not sell on that day)
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}



//Fifth Solution :- Using constant space :- using only 4 variables
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;      //base cases

    for(int ind = n-1; ind>=0; ind--){
        curNotBuy = max((-values[ind] + aheadBuy), 0 + aheadNotBuy);    //profit = max( buy on that day, not buy on that day)
        curBuy = max((values[ind] + aheadNotBuy), 0 + aheadBuy);        //profit = max( sell on that day, not sell on that day)
        
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadNotBuy;
}



