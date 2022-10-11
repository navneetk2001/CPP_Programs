// here is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.
// A neighborhood is a maximal group of continuous houses that are painted with the same color.
// For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
// Given an array houses, an m x n matrix cost and an integer target where:

// houses[i]: is the color of the house i, and 0 if the house is not painted yet.
// cost[i][j]: is the cost of paint the house i with the color j + 1.
// Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

// Example 1:
// Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
// Output: 9
// Explanation: Paint houses of this way [1,2,2,1,1]. This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}]. Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

// Example 2:
// Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
// Output: 11
// Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]. This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. Cost of paint the first and last house (10 + 1) = 11.

// Example 3:
// Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
// Output: -1
// Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.




//Solution Approach :- Memoization 
// The concept of the problem is very simple. All you need to do is to colour houses in such a way that total number of neighbourhood should be exactly equal to the given target in the problem.
// This can be done very easily by maintaing the current track of previous house colour and number of target neighbourhoods left by moving from left to right, index by index.
// Everytime on visiting any house, you check whether it is already coloured or not.If it is already coloured you decrese target if colour does not matches to the prevoius one. If it is not coloured then you start colouring it with every colour one by one and recursively call function for next index and add cost[index][colour-1] and decrement target if it not matches with the previous one.
// So,dp states are dp[index][prev][target];

#define ll long long
ll dp[105][25][105];
ll solve(vector<int>& houses, ll index, vector<vector<int>>& cost, ll prev, ll m, ll n, ll target){
    if(target<0){              // If target index is -ve then answer is not build as it has more neighbours.
        return INT_MAX;
    }
    if(index == m){            // If we have visited all houses
        if(target == 0){       // If neighbours are same as required, then no more cost is required.
            return 0;
        }
        return INT_MAX;        // If neighbours are not same, then this build is not valid.
    }

    if(dp[index][prev][target] != -1){
        return dp[index][prev][target];
    }
    if(houses[index] != 0){       // If house is already coloured.
        return dp[index][prev][target] = solve(houses,index+1,cost,houses[index],m,n,target-(prev!=houses[index]));
    }
    ll ans = INT_MAX;                 // If we are colouring house, then find minimum cost.
    for(int i=1;i<=n;i++){
        ans = min(ans,cost[index][i-1]+solve(houses,index+1,cost,i,m,n,target-(prev!=i)));
    }
    return dp[index][prev][target] = ans;
}

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));	     // memset dp with -1.

        ll ans = solve(houses,0,cost,n+1,m,n,target);		// Calculate answer using recursive dp.
        if(ans == INT_MAX){                        // If answer comes out to be INT_MAX then actually such combination is not possible.
            return -1;
        }
        return ans;
    }
};




//Second Solution :- Tabulation
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        const int INF = 1e9;
        vector<vector<int>> dp(target + 1, vector<int>(n, INF));
        if (houses[0] == 0){
            dp[1] = cost[0];
        } 
        else{
            dp[1][houses[0]-1] = 0;
        }
        
        for (int i = 1; i < m; i++){
            for (int groups = target; groups > 0; groups--){
                for (int color1 = 0; color1 < n; color1++){
                    int min_cost = dp[groups][color1];
                    dp[groups][color1] = INF;
                    if (houses[i] != 0 && houses[i] != color1 + 1){
                    	continue;
                    }

                    int c = (houses[i] == 0) ? cost[i][color1] : 0;
                    min_cost += c;
                    for (int color2 = 0; color2 < n; color2++){
                        if (color1 == color2) continue;
                        min_cost = min(min_cost, dp[groups - 1][color2] + c);
                    }
                    dp[groups][color1] = min_cost;
                }
            }
        }
        
        int ans = INF;
        for (int color = 0; color < n; color++){
            ans = min(ans, dp[target][color]);
        }
        return (ans < INF ? ans : -1);
    }
};



//Third Solution :-
class Solution {
public:
    int dp[101][21][101];
    int help(int i,int l,int t,vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target){
        if(t>target){
            return INT_MAX/2;
        }
        
        if(i == m){
            return (t==target)?0:INT_MAX/2;
        }
        
        if(dp[i][l][t] != -1){
            return dp[i][l][t];
        }
        else{
            int ans = INT_MAX/2;
            
            if(houses[i] == 0){
                for(int j=0;j<n;j++){
                    ans = min(ans, cost[i][j]+help(i+1,j+1,(l==j+1)?t:t+1,houses,cost,m,n,target));
                }
            }
            else{
                ans = min(ans, help(i+1,houses[i],(houses[i] == l)?t:t+1,houses,cost,m,n,target));
            }
            return dp[i][l][t] = ans;
        }
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        memset(dp,-1,sizeof dp);
        int ans = help(0,0,0,houses,cost,m,n,target);
        return ans==INT_MAX/2?-1:ans;
    }
};