// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

// Example 1:
// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Example 2:
// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 




//1. Recursion [TLE] TC: O(2^n)
class Solution {
public:
    int minCostClimbingStairs(int index, vector<int>& cost) {
        if(index == 0 || index == 1){    //Base Case
        	return 0;
        }
        int opt1 = INT_MAX, opt2 = INT_MAX;
        opt1 = cost[index-1] + minCostClimbingStairs(index-1, cost);
        if(index>1){
        	opt2 = cost[index-2] + minCostClimbingStairs(index-2, cost);
        }
        return min(opt1, opt2);
    }

    int minCostClimbingStairs(vector<int>& cost){
    	int n = cost.size();
        return minCostClimbingStairs(n, cost);
    }
};



//2. Memoization :-
class Solution {
public:
    int minCostClimbingStairs(int index, vector<int>& cost, vector<int> &dp) {
        if(index == 0 || index == 1){    //Base Case
        	return 0;
        }
        if(dp[index]!=-1){
        	return dp[index];
        }
        int opt1 = INT_MAX, opt2 = INT_MAX;
        opt1 = cost[index-1] + minCostClimbingStairs(index-1, cost, dp);
        if(index>1){
        	opt2 = cost[index-2] + minCostClimbingStairs(index-2, cost, dp);
        }
        return dp[index] = min(opt1, opt2);
    }

    int minCostClimbingStairs(vector<int>& cost){
    	int n = cost.size();
    	vector<int> dp(n+1,-1);
        return minCostClimbingStairs(n, cost, dp);
    }
};




//3. Tabulation [runtime beats 95.16 %] TC:O(n) SC:O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];

        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-2],dp[i-1]) + cost[i];
        }
    
        return min(dp[n-1],dp[n-2]);
    }
};



//3. dp [runtime beats 63.90 %] TC:O(n) SC:O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first=cost[0],second=cost[1];
        for(int i=2;i<n;i++){
            int r=min(first,second)+cost[i];
            first=second;
            second=r;
        }
        return min(first,second);
    }
};




//4. dp [runtime beats 95.16 %] TC:O(n) SC:O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++){
            cost[i]=min(cost[i-1],cost[i-2])+cost[i];
        }
        return min(cost[n-1],cost[n-2]);
    }
};