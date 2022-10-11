https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Using Recursion
#include<bits/stdc++.h>
int f(int ind, int buy, int cap, vector<int>& prices, int n){  //cap :- maximum capacity (here infinite transactions not allowed)
    if(ind == n){         //first base case 
        return 0;
    }
    if(cap == 0){         //second base case
        return 0;
    }

    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,cap,prices,n)), 0 + f(ind+1,1,cap,prices,n));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind] + f(ind+1,1,cap-1,prices,n)), 0 + f(ind+1,0,cap,prices,n));
        //profit = max( sell on that day, not sell on that day)
    }
    return profit;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    return f(0, 1, k, prices, n);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
                                    //cap :- k, i.e. atmost only 2 transactions are allowed
}



//Second Solution :- Memoization 
#include<bits/stdc++.h>
int f(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp){  //cap :- maximum capacity (here infinite transactions not allowed)
    if(ind == n){         //first base case 
        return 0;
    }
    if(cap == 0){         //second base case
        return 0;
    }
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }

    int profit = 0;
    if(buy){
        profit = max((-prices[ind] + f(ind+1,0,cap,prices,n,dp)), 0 + f(ind+1,1,cap,prices,n,dp));
        //profit = max( buy on that day, not buy on that day)
    }
    else{
        profit = max((prices[ind] + f(ind+1,1,cap-1,prices,n,dp)), 0 + f(ind+1,0,cap,prices,n,dp));
        //profit = max( sell on that day, not sell on that day)
    }
    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (k+1,-1)));
    return f(0, 1, k, prices, n, dp);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
                                        //cap :- k, i.e. atmost 2 transactions are allowed
}



//Third Solution :- Tabulation   
//index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
//cap :- 2, i.e. atmost k transactions are allowed

#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int> (k+1,0)));
    
    //no need to write base case as they are already 0 in dp vector

    // for(int ind=0; ind<n; ind++){          //first base case
    //     for(int buy=0; buy<2; buy++){
    //         dp[ind][buy][0] = 0;
    //     }
    // }

    // for(int buy=0; buy<2; buy++){         //second base case
    //     for(int cap=0; cap<3; cap++){
    //         dp[n][buy][cap] = 0;
    //     }
    // }

    for(int ind=n-1; ind>=0; ind--){      
        for(int buy=0; buy<2; buy++){
            for(int cap=1; cap<=k; cap++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[ind] + dp[ind+1][0][cap]), 0 + dp[ind+1][1][cap]);
                    //profit = max( buy on that day, not buy on that day)
                }
                else{
                    profit = max((prices[ind] + dp[ind+1][1][cap-1]), 0 + dp[ind+1][0][cap]);
                    //profit = max( sell on that day, not sell on that day)
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}



//Fourth Solution :- Space Optimized Solution
#include<bits/stdc++.h>
int maximumProfit(vector<int>& prices, int n, int k)
{
    vector<vector<int>> after(2,vector<int> (k+1,0));
    vector<vector<int>> cur(2,vector<int> (k+1,0));
    //no need to write base case as they are already 0 in dp vector

    for(int ind=n-1; ind>=0; ind--){      
        for(int buy=0; buy<2; buy++){
            for(int cap=1; cap<=k; cap++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[ind] + after[0][cap]), 0 + after[1][cap]);
                    //profit = max( buy on that day, not buy on that day)
                }
                else{
                    profit = max((prices[ind] + after[1][cap-1]), 0 + after[0][cap]);
                    //profit = max( sell on that day, not sell on that day)
                }
                cur[buy][cap] = profit;
            }
        }
        after = cur;
    }
    return after[1][k];
}



//Sixth Solution :- Recursion :- O(N*4)
#include<bits/stdc++.h>
int f(int ind, int trans, vector<int>& prices, int n, int k){  //cap :- maximum capacity (here infinite transactions not allowed)
    if(ind == n){         //first base case 
        return 0;
    }
    if(trans == 2*k){         //second base case
        return 0;
    }

    int profit = 0;
    if(trans % 2 == 0){    //buy case
        profit = max((-prices[ind] + f(ind+1,trans+1,prices,n,k)), 0 + f(ind+1,trans,prices,n,k));
        //profit = max( buy on that day, not buy on that day)
    }
    else{         //sell case
        profit = max((prices[ind] + f(ind+1,trans+1,prices,n,k)), 0 + f(ind+1,trans,prices,n,k));
        //profit = max( sell on that day, not sell on that day)
    }
    return profit;
}

int maximumProfit(vector<int>& prices, int n, int k)
{
    return f(0, 0, prices, n, k);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
                                 //transactions :- k, i.e. atmost only 2*k transactions are allowed
}



//Seventh Solution :- Memoization
#include<bits/stdc++.h>
int f(int ind, int trans, vector<int>& prices, int n, int k, vector<vector<int>> &dp){  
    if(ind == n){         //first base case 
        return 0;
    }
    if(trans == 2*k){         //second base case
        return 0;
    }
    if(dp[ind][trans]!=-1){
        return dp[ind][trans];
    }

    int profit = 0;
    if(trans % 2 == 0){    //buy case
        profit = max((-prices[ind] + f(ind+1,trans+1,prices,n,k,dp)), 0 + f(ind+1,trans,prices,n,k,dp));
        //profit = max( buy on that day, not buy on that day)
    }
    else{         //sell case
        profit = max((prices[ind] + f(ind+1,trans+1,prices,n,k,dp)), 0 + f(ind+1,trans,prices,n,k,dp));
        //profit = max( sell on that day, not sell on that day)
    }
    return dp[ind][trans] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2*k,-1));
    return f(0, 0, prices, n, k, dp);   //index :- 0, //buy :- 1 (1 means you can buy and if 0 means you can't buy on that day)
                                 //transactions :- k, i.e. atmost only 2*k transactions are allowed
}



//Eighth Solution :- Tabulation
int maximumProfit(vector<int>& prices, int n, int k)
{
    vector<vector<int>> dp(n+1, vector<int>(2*k+1,0));

    for(int ind=n-1;ind>=0;ind--){
        for(int trans=2*k-1;trans>=0;trans--){
            int profit = 0;
            if(trans % 2 == 0){    //buy case
                profit = max((-prices[ind] + dp[ind+1][trans+1]), 0 + dp[ind+1][trans]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{         //sell case
                profit = max((prices[ind] + dp[ind+1][trans+1]), 0 + dp[ind+1][trans]);
                //profit = max( sell on that day, not sell on that day)
            }
            dp[ind][trans] = profit;
        }
    }

    return dp[0][0];
}



//Ninth Solution :- Space Optimization 
int maximumProfit(vector<int>& prices, int n, int k)
{
    vector<int> ahead(2*k+1,0);
    vector<int> cur(2*k+1,0);

    for(int ind=n-1;ind>=0;ind--){
        for(int trans=2*k-1;trans>=0;trans--){
            int profit = 0;
            if(trans % 2 == 0){    //buy case
                profit = max((-prices[ind] + ahead[trans+1]), 0 + ahead[trans]);
                //profit = max( buy on that day, not buy on that day)
            }
            else{         //sell case
                profit = max((prices[ind] + ahead[trans+1]), 0 + ahead[trans]);
                //profit = max( sell on that day, not sell on that day)
            }
            cur[trans] = profit;
        }
        ahead = cur;
    }

    return ahead[0];
}