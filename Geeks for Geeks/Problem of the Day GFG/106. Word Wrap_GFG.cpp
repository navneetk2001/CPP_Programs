// Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 
// You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

// Example 1:
// Input: nums = {3,2,2,5}, k = 6
// Output: 10
// Explanation: Given a line can have 6 characters,
// Line number 1: From word no. 1 to 1
// Line number 2: From word no. 2 to 3
// Line number 3: From word no. 4 to 4
// So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10. As in the first line word length = 3 thus extra spaces = 6 - 3 = 3 and in the second line
// there are two word of length 2 and there already 1 space between two word thus extra spaces = 6 - 2 -2 -1 = 1. As mentioned in the problem
// description there will be no extra spaces in the last line. Placing first and second word in first line and third word on second line
// would take a cost of 02 + 42 = 16 (zero spaces on first line and 6-2 = 4 spaces on second), which isn't the minimum possible cost.

// Example 2:
// Input: nums = {3,2,2}, k = 4
// Output: 5
// Explanation: Given a line can have 4 characters,
// Line number 1: From word no. 1 to 1
// Line number 2: From word no. 2 to 2
// Line number 3: From word no. 3 to 3
// Same explaination as above total cost = (4 - 3)2 + (4 - 2)2 = 5.


//Solution Approach :- Best Solution 
class Solution {
public:
	int dp[505][2005];
	int rec(int i, int rem, vector<int>&arr, int &k){
		if(i==arr.size()){
			return 0;
		}
		if(dp[i][rem]!=-1){
			return dp[i][rem];
		}

		int ans;
		if(arr[i]>rem){
			ans=(rem+1)*(rem+1) + rec(i+1,k-arr[i]-1,arr,k);
		}
		else{
			int choice1=(rem+1)*(rem+1) + rec(i+1,k-arr[i]-1,arr,k);
			int choice2=rec(i+1,rem-arr[i]-1,arr,k);
			ans=min(choice1,choice2);
		}
		dp[i][rem]=ans;
		return dp[i][rem];
	}
	
    int solveWordWrap(vector<int>arr, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return rec(0,k,arr,k);
    } 
};


//Second Solution :-
int dp[501];

int recur(int i,int j,vector<int>&nums){
   if(i>=n){
       return 0;
   }

   if(dp[i]!=-1){
   	  return dp[i];
   }

   int su=0;
   int ans=INT_MAX;
   for(int j=i; j<n;j++){
       su+=nums[j];
       if(k-su<0)
       	  break;
       if(j<n-1)
       	  ans=min(ans,(k-su)*(k-su)+recur(j+1,j-i+1,nums));
       else 
       	  ans=0+recur(j+1,j-i+1,nums);
       
       su++;
   }
   return dp[i]=ans;
}

int solveWordWrap(vector<int>nums, int K){ 
   int n=nums.size();
   int k=K;
   memset(dp,-1,sizeof(dp));

   int ans=recur(0,0,nums);
   return ans;
}


//Third Solution :-
int square(int n){
    return n * n;
}

int helper(vector<int>&word, int n, int length, int wordIndex, int remLength, vector<vector<int>>&dp){
    //We are at the last word
    if(wordIndex == n - 1){
        //If there is required space left in the currline
        if(word[wordIndex] < remLength){
            return 0;
        }
        //Otherwise insert it in the next line and return the cost which is square of white space
        return square(remLength);
    }
    
    if(dp[wordIndex][remLength] != -1)
        return dp[wordIndex][remLength];
    
    int currWord = word[wordIndex];
    
    //If word can fit in the remaining line
    if(currWord < remLength){
        /*
        Case 1: Insert it in the same line
        (remLength == length) ==> 
        whether we are putting the first word in the line
            -> If this is the case then we dont need to add one extra space
        or we are putting next word in the same line
            -> If this is the case then we need to insert extra space between
            the two words.
        */
        int insert = helper(word, n, length, wordIndex + 1, remLength == length 
                                ? remLength - currWord : remLength - currWord - 1, dp);
                                
        //Case 2: Insert it in the next line.
        int dontInsert = square(remLength) + helper(word, n, length, wordIndex + 1, length - currWord, dp);
        
        return dp[wordIndex][remLength] = min(insert, dontInsert);
    }
    
    //We don't have any choice so insert the word in the next line.
    return dp[wordIndex][remLength] = square(remLength) + helper(word, n, length, wordIndex + 1, length - currWord, dp);
}

int solveWordWrap(vector<int>nums, int k){
    vector<vector<int>>dp(nums.size(), vector<int>(k + 1, -1));
    return helper(nums, nums.size(), k, 0, k, dp);
} 


//Fourth Solution :-
// THIS IS A BEAUTIFUL QUESTION OF DP DONT FORGET TO BOOKMARK
// TO GET THE INTUTION U KNOW THE GAP METHOD(DIAGONAL TRAVERSAL) WHICH IS A BEST TOOL IN DP QUESTIONS . SO STEPS TO GRAPS THIS QUESTION 
//  1-→https://youtu.be/lvRdFCMD_Ew WATCH AT(1.75X)
//  2-→https://youtu.be/FiQY3K4_xPo NICE EXPLANTION(WATCH FOR INTUTION)
// OTHER DOCUMENTATION -→https://www.geeksforgeeks.org/word-wrap-problem-space-optimized-solution/ best solution

class Solution{
public: 
    int solveWordWrap (int[] a, int k)
    {
        int[][]dp=new int[a.length][a.length];
        for(int gap=0;gap<dp.length;gap++){
            for(int i=0,j=gap;j<dp.length;j++,i++){
                if(gap==0){
                    dp[i][j]=k-a[i];
                }
                else{
                    dp[i][j]=dp[i][j-1]-a[j]-1;
                }
            }
        }
        for(int i=0;i<dp.length;i++)
        {
            for(int j=i;j<dp.length;j++)
            {
                if(dp[i][j] < 0)dp[i][j] = Integer.MAX_VALUE;
                else if(j== a.length-1)dp[i][j]=0;
                else dp[i][j] = (int)Math.pow(dp[i][j], 2);
            }
        }
        
        int[]ans=new int[a.length];
        for(int i=dp.length-1;i>=0;i--){
            ans[i]=dp[i][dp.length-1];
            for(int j=dp.length-1;j>i;j--){
                if(dp[i][j-1]==Integer.MAX_VALUE)continue;
                else if(ans[i]>ans[j]+dp[i][j-1]){
                    ans[i]=ans[j]+dp[i][j-1];
                }
            }
        }
        return ans[0];
    }
}