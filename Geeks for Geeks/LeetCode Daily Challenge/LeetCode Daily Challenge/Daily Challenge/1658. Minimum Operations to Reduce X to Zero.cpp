// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// Example 1:
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

// Example 2:
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1

// Example 3:
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.




//Solution Approach :- Two Pointer Approach in which we will find a subarray with sum=sum(array)-x
// example 
// [1,1,4,2,3] , x=5
// target = sum(nums)-x, which is => 6 in this case 
// we will try to find longest subarray with given target
// max length with target is 3 [1,1,4]
// our ans is nums.size()-3 => 2

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        
        for(auto it:nums){
            sum+=it;
        }
        
        int target=sum-x;   //we are going to find a subarray with sum=sum(array)-x
        if(target<0){
            return -1;
        }

        int j=0;
        int currSum=0;
        int ans=-1;
        
        for(int i=0;i<n;i++){
            currSum+=nums[i]; 
            
            while(currSum>target){
                currSum-=nums[j];
                j++;
            }

            if(currSum==target){
                ans=max(ans,i-j+1);    //calculating window size
            }
        }
        return ans==-1?-1:n-ans;
    }
};



//Second Solution :- Using Prefix Sum
int minOperations_twoSum(vector<int>& nums, int x) {
	int target = -x;
	for (auto num : nums){
	    target += num;
	}
	int n = nums.size();
	if (target == 0){
		return n;
	}

	unordered_map<int, int> left;      // left[Sum(0..i)] = i
	left[0] = -1;

	int sum = 0, res = INT_MIN;
	for (int i = 0; i < n; ++i) {
	    sum += nums[i];
	    if (left.find(sum - target) != left.end()) {
	        res = max(res, i - left[sum-target]);
	    }
	    left[sum] = i;
	}

	return (res == INT_MIN ? -1 : n - res);
}


//Third Solution :- Recursion Solution :-
int operation(vector<int>& nums, int x, int l, int r){
	if(x<0 || l>r || nums[l]>x || nums[r]>x){
		return INT_MAX;
	}
	if(x==0){
		return 0;
	}
    return min(operation(nums,x-nums[l],l+1,r), operation(nums,x-nums[r],l,r-1))+1;
}

int minOperations(vector<int>& nums, int x) {
    int res=operation(nums,x,0,nums.length()-1);
    return res >= INT_MAX ? -1 : res;
}
