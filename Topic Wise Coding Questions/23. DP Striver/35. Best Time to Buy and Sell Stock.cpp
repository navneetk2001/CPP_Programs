https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//Solution Approach :- 
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini = prices[0], profit = 0;
    for(int i=0;i<prices.size();i++){
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);   //remember previous
    }
    return profit;
}


