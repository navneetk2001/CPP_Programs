Given a list of coins of distinct denominations and total amount of money. Find the minimum number of coins required to make up that amount. Output -1 if that money cannot be made up using given coins.
You may assume that there are infinite numbers of coins of each type.
 
Example 1:
Input: arr = [1, 2, 5], amount = 11
Output: 3
Explanation: 2*5 + 1 = 11. So taking 2 denominations of 5 and 1 denomination of  1, one can make 11.

Example 2:
Input: arr = [2, 6], amount = 7
Output: -1
Explanation: Not possible to make 7 using denominations 2 and 6.



//Approach :-
//can take any value greater than amount like:amount+1,amount+2,10001 or INT_MAX	
   // it is based on three steps,
   // 1. pick the current coin=>dp[j-nums[i]]+1, here +1 for picking this coin
   // 2. dont pick the current coin=>dp[i] value remains same
   // 3. minimum of both of them  


//Solution Approach :-
int MinCoin(vector<int>nums, int amount)
{
   vector<int> dp(amount+1,10001);
   dp[0]=0;    //now enter the value for dp[0]=0

   for(int i=0;i<nums.size();i++){
       for(int j=1;j<=amount;j++){
           if(nums[i]<=j)
            dp[j]=min(dp[j],dp[j-nums[i]]+1);
       }
   }
   if(dp[amount]>amount)
    	return -1;
   return dp[amount]; 
}



//Second Solution :-
class Solution{
public:
int min_coin(vector<int>nums, int amount, int i, vector<vector<int>>&dp){
    if(amount==0)
        return 0;
        
    if(i==0){
        if(amount>=nums[0] && amount%nums[0]==0)
            return amount/nums[0];
        else
            return 100001;
    }
    
    if(dp[i][amount]!=-1)
        return dp[i][amount];
       
    int mini = INT_MAX;
    
    // not pick
    mini = min(mini, min_coin(nums, amount, i-1, dp));
    
    // pick
    if(amount>=nums[i])
        mini = min(mini, min_coin(nums, amount-nums[i], i, dp) + 1);
       
    dp[i][amount] = mini;
    return mini;
}
int MinCoin(vector<int>nums, int amount)
{
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    int val = min_coin(nums, amount, n-1, dp);
    if(val<=10000)
        return val;
    else
        return -1;
}
};