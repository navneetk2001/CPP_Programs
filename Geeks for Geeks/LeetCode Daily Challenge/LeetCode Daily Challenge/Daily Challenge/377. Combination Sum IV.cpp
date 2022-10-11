https://leetcode.com/problems/combination-sum-iv/




//Solution Approach :- ❌ Solution - I (Brute Force)
//Let's start with the most basic approach. At each index, if the element is less than target, then we can always form a combination by picking the current element. 

int combinationSum4(vector<int>& nums, int target) {
	if(target == 0) {
		return 1;
	}

	int ans = 0;
	for(auto& num : nums){   		// pick an element if it is less than target to be achieved and recurse for remaining amount.
		if(num <= target){
			ans += combinationSum4(nums, target - num);
		}
	}
	return ans;  
}

//Time Complexity : O(N^T). Please comment below if there's a tighter upper bound.
//Space Complexity : O(T).



//✔️ Solution - II (Top-Down Dynamic Programming)
//By drawing the recursion tree, we can see that for a target, we do the same calculations over and over again. This could be avoided by storing the number of combination obtained for a given target so that we don't waste time recalculating it at each recursion.
//This can be done by maintain a dp array where dp[i] will denote the number of combinations possible with target = i. Initially, all elements in dp will be initialized to -1 denoting that the number of combinations for those target aren't calculated yet.
//Once the number of combinations for subtarget = i (where 0<i<=target) is calculated, it will be stored in dp[i] and the next time any recursive call asks for the same value, dp[i] will be returned directly instead of doing recomputation.

int combinationSum4(vector<int>& nums, int target) {
	vector<int> dp(target + 1, -1);  // at start, none of the values are computed
	return helper(nums, target, dp);
}
int helper(vector<int>& nums, int target, vector<int>& dp){
	if(target == 0){   // base condition
		return 1;  
	}
	if(dp[target] != -1){
		return dp[target];  // if already computed for this value
	}

	dp[target] = 0;

	for(auto& num : nums){       // check for every element of nums. An element can only be taken if it is less than target.
		if(num <= target) {   	// If an element is chosen, recurse for remaining value.
			dp[target] += helper(nums, target - num, dp);
		}
	}
	return dp[target];
}

//Time Complexity : O(N * T), where N is the number of elements in nums and T is equal to the given target value.
//Space Complexity : O(T). We need O(T) to maintain the dp array and in the worst case, we would have to do T numbers of recursive calls of helper. So, the overall space complexity becomes O(T).



//✔️ Solution - III (Bottom-up Dynamic Programming)
//The idea in this approach is also the same. We just start filling dp from curTarget = 1 all the way up to curTarget = target. At each curTarget, an element will be chosen if its value is less that target needed.

int combinationSum4(vector<int>& nums, int target) {
	vector<uint> dp(target + 1); 
	dp[0] = 1;

	for (int curTarget = 1; curTarget <= target; curTarget++){    	// start filling the dp array from bottom, i.e curTarget = 1 till target.
        for (auto& num : nums){                                     // check for all elements from nums
            if (num <= curTarget){                                  // an element will only be taken if it is less than target to be achieved
				dp[curTarget] += dp[curTarget - num];               // the optimal answer(no. of combination) of remaining value is added to dp[curTarget]
			}
		} 
	}
    return dp[target];
}

//Time Complexity : O(N * T)
//Space Complexity : O(T). Although the space complexity remains the same, we are saving the space requried by implicit recursive stack.




//✔️ Solution IV (Slightly efficient version of Solution - III)
//The above solution will always loop for N times for each curtarget from 1 to target. We could achieve slightly better performance if we sort the array at start and break as soon as nums[i] becomes greater than curTarget in the inner loop. The same optimization can be done for Top-Down approach of Solution - II as well.

int combinationSum4(vector<int>& nums, int target) {
	sort(begin(nums), end(nums));
    vector<uint> dp(target + 1); 
    dp[0] = 1;
	for (int curTarget = 1; curTarget <= target; curTarget++){
        for (auto& num : nums){
            if (num <= curTarget){
            	dp[curTarget] += dp[curTarget - num];
            }
            else{
            	break;
            }
        }
	}
    return dp[target];
}


//Time Complexity : O(N*T). Although the time complexity remains same, the performance would be better in most cases since we wouldn't need to loop N times for every curTarget
//Space Complexity : O(T)






//Second Solution :- 
class Solution {
public:
    vector<int> dp;
    
    Solution() {
        dp.resize(1001);
        fill(dp.begin(), dp.end(), -1);
    }
    
    int combinationSum4(vector<int>& nums, int target, int currSum=0) {
        if(currSum > target) return 0;
        if(currSum == target) return 1;
        if(dp[currSum] != -1) return dp[currSum];
        int ways = 0;
        for(int i=0; i<nums.size(); i++) {
            if(currSum + nums[i] <= target){
                ways += combinationSum4(nums, target, currSum + nums[i]);
            }
        }
        return dp[currSum] = ways;
    }
};

