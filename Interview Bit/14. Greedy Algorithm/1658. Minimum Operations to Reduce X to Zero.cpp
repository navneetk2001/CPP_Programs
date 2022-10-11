https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/




//Solution Approach :-
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0); 
        if(totalsum == x){
            return nums.size();
        }
        
        int start = 0;
        int end = 0;
        int sum_to_make = totalsum - x; 
        int ans = 0;
        int sum = 0;
        
        while(end < nums.size()){  
            sum += nums[end]; 
            
            while(start < end && sum > sum_to_make) {    //shrinking our window from left
                sum -= nums[start++]; 
            }
            
            if(sum == sum_to_make){                  //if it is equal to the sum to make
                ans = max(ans, end - start + 1); 
            }
            end++;
        }
        return ans == 0 ? -1 : nums.size() - ans;
    }
};





//Second Solutions :-
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



//Third Solution :- HashMap
// Approach 1: Hash map, prefix sum, two sum
// - Idea: + create hash map satisfy mapLeft[prefix sum] = i, i is last index in prefix sum
// 		+  brute force from last index in array to first index and create suffix sum, find i satisfy mapLeft[x - suffix sum] > 0 
// 		   => that's mean prefix sum + suffix sum = x,  and min operation = min (min operation, size(prefix sum) + size(suffix sum) );
// + Time: O(n)
// + Space: O(n)
		   
class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		unordered_map<int, int> mapLeft;
		int n = nums.size();
		int ans = INT_MAX;

		for(int i = 0, prefixSum = 0; i < n; i++) {
			prefixSum += nums[i];
			mapLeft[prefixSum] = i + 1;
			if (prefixSum == x)
				ans = min(ans, i + 1);
		}

		for(int i = n - 1, suffixSum = 0; i >= 0; i--) {
			suffixSum += nums[i];
			if(suffixSum == x)
				ans = min(ans, n - i);
			if(mapLeft[x - suffixSum] > 0 && i + 1 > mapLeft[x - suffixSum]) // if i + 1 <= mapLeft => both prefix sum and suffix sum have same elements
				ans = min(ans, n - i + mapLeft[x - suffixSum]); // n - i is size suffix sum, mapLeft[x - suffixSum] is size prefix sum
		}

		return ans == INT_MAX ? -1 : ans;
	}
};