// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.


//Profit = Selling Price[i] - costPrice[j]; and we have to maximize this profit
// So, for Solution :- We will have to buy at min cost price and Sell at highest price


//Solution 1 :- Greedy Approach :-
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxim = 0, minim = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minim) 
            	minim = prices[i];
            else if (prices[i] > minim) 
            	maxim = max(prices[i] - minim, maxim);
        }
        return maxim;
    }
};


//Solution 2:- 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};


//Solution 3:- 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};

//Solution 3 :- DP Approach :- [At most one transaction]
                | i |
                 / \
   Already bought   Not bought
      / \              /  \
   Sell  Not Sell    Buy Not Buy
     |     |          |     |
   A[i]   i+1       -A[i]   


int dp[1000005][2];
//Here i is index, k is no of transaction(not more than 1), bool buy=1 (need to buy), buy=0(already bought)
int find(vector<int>& prices, int i, int k, bool buy){
	if(i>=prices.size() || k<=0){
		return 0;
	}
	if(dp[i][buy]!=-1){
		return dp[i][buy];
	}
	if(buy==1){    //buy or not buy
		return dp[i][buy] = max(-prices[i]+find(prices,i+1,k,0), find(prices,i+1,k,1));
	}
	else{          //sell or not sell
		return dp[i][buy] = max(prices[i]+find(prices,i+1,0,1), find(prices,i+1,k,0));
	}
}



int maxProfit(vector<int>& prices){
	int n=prices.size();
	memset(dp,-1,sizeof(dp));

	return find(prices,0,1,1);
}