// You are given N identical eggs and you have access to a K-floored building from 1 to K.
// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// For more description on this problem see wiki page

// Example 1:
// Input:
// N = 1, K = 2
// Output: 2
// Explanation: 
// 1. Drop the egg from floor 1. If it breaks, we know that f = 0.
// 2. Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// 3. If it does not break, then we know f = 2.
// 4. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

// Example 2:
// Input:
// N = 2, K = 10
// Output: 4




//Solution Approach :-
class Solution{
public:
    //Function to find minimum number of attempts needed in order to find the critical floor.
    int t[205][205];
    int solve(int eggs, int floors){
        if (eggs == 1 || floors == 0 || floors == 1) {
            t[eggs][floors] = floors;
            return floors;
        }
        
        if (t[eggs][floors] != -1){
            return t[eggs][floors];
        }
    
        int mn = INT_MAX;
        for(int k = 1; k <= floors; k++) {
            int temp_ans = 1 + max(solve(eggs - 1, k - 1), solve(eggs, floors - k));
            mn = min(mn, temp_ans);
        }
    
        return t[eggs][floors] = mn; 
    }


    int eggDrop(int eggs, int floors) {
        memset(t,-1,sizeof t);
        return solve(eggs, floors);
    }
};



//Second Solution :- Find x such that sum xCi >= k for 1 <= i <= n by binary search - O(n * logk)
int sumxCi(int x, int n, int k){
   int sum = 0, term = 1;
   for (int i = 1; i <= n; ++i) {
      term *= x - i + 1;
      term /= i;
      sum += term;
      if (sum > k){
         return sum;
      }
   }
   return sum;
}

//Function to find minimum number of attempts needed in order to find the critical floor.
int eggDrop(int n, int k) {
   int l = 1, r = k;
   while (l < r) {
      int mid = (l + r) / 2;
      if (sumxCi(mid, n, k) < k){
         l = mid + 1;
      }
      else{
         r = mid;
      }
  }
  return l;
}



//Third Solution :- Recursion 
int Solve(int eggs, int floors) {
   if (eggs == 1){
      return floors;
   }
   if (floors == 0 || floors == 1){
      return floors;
   }

   int mn = INT_MAX;
   for (int k = 1; k <= floors; k++) {
      int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k)); // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above 
      mn = min(mn, temp_ans);
   }

   return mn;
}




//Fourth Solution :- Tabulation 
int eggDrop(int n, int k) 
{
   int dp[k + 1][n + 1];
   for(int i = 1; i <= n; i++){
      dp[1][i] = 1;
      dp[0][i] = 0;
   }
   for(int i = 1; i <= k; i++){
      dp[i][1] = i;
   }
   for(int i = 2 ; i <= k; i++){
      for(int j = 2; j <= n; j++){
         dp[i][j] = i;
         for(int m = 1; m <= i; m++){
           dp[i][j] = min(max(dp[m - 1][j - 1], dp[i - m][j]) + 1 , dp[i][j]);
         }
      }
   }
   return dp[k][n];
}



//Fifth Solution :- DP + B.S
class Solution
{
   private:
      int dp[1001][1001];
   public:
   Solution(){
      memset(dp,-1,sizeof(dp));
   }
   int helper(int eggs, int floors){
      if(eggs==1){
         return floors;
      }
      if(floors<=1){
         return floors;
      }
      if(dp[eggs][floors]!=-1){
         return dp[eggs][floors];
      }
      int low=1;
      int high=floors;
      int res=INT_MAX;
      while(low<=high){
         int mid=(low+high)/2;
         int DID_NOT_BREAK=helper(eggs,floors-mid);
         int BROKE=helper(eggs-1,mid-1);
         if(BROKE<DID_NOT_BREAK){
            low=mid+1;  //did not break, lets go higher up
         }
         else{
             high=mid-1; //hell nah get down now
         }
         int temp=1+max(DID_NOT_BREAK,BROKE);
         res=min(res,temp);
      }
      return dp[eggs][floors]=res;
   }
    
   int eggDrop(int eggs, int floors) {
      if(eggs==1){
         return floors;
      }
      if(floors==1){
         return 1;
      }
      if(floors==0){
         return 0;
      }
      if(dp[eggs][floors]!=-1){
         return dp[eggs][floors];
      }
      return helper(eggs,floors);
    }
};



//Sixth Solution :- Memoization Optimized Code
class Solution{
public:
    //Function to find minimum number of attempts needed in order to find the critical floor.
    int dp[205][205];
    int Solve(int eggs, int floors) {
      if (dp[eggs][floors] != -1) // if value is already there in the table then return the value 
         return dp[eggs][floors];
    
      if (eggs == 1 || floors == 0 || floors == 1) { // base condition
         dp[eggs][floors] = floors;
         return floors;
      }
    
      int mn = INT_MAX;
      for (int k = 1; k <= floors; k++) {
         int top, bottom;
         if (dp[eggs - 1][k - 1] != -1) // break the temp in sub problemes 
            top = dp[eggs - 1][k - 1];
         else {
            top = Solve(eggs - 1, k - 1);
            dp[eggs - 1][k - 1] = top;
         }
    
         if (dp[eggs][floors - k] != -1)
            bottom = dp[eggs][floors - k];
         else {
            bottom = Solve(eggs, floors - k);
            dp[eggs][floors - k] = bottom;
         }
         int temp_ans = 1 + max(top, bottom);
         mn = min(mn, temp_ans);
      }
    
      return dp[eggs][floors] = mn;
    }


    int eggDrop(int eggs, int floors) {
        memset(dp,-1,sizeof(dp));
        return Solve(eggs, floors);
    }
};