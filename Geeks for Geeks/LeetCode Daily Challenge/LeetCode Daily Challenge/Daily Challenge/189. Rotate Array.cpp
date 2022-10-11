// Given an array, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]




//Solution Approach :- Approach 1 - O(1) space
class Solution {
public:
    void rotate(vector<int>&nums,int k) {
        int n=nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end());       //reverse whole array
        reverse(nums.begin(), nums.begin()+k);   //Now reverse first k elements
        reverse(nums.begin()+k, nums.end());     //Then reverse last n-k elements
    }
};



//Solution Approach :- Approach 2 - O(n) space
class Solution {
public:
    void rotate(vector<int>&nums, int k) {
        int n=nums.size();
        if ((n == 0) || (k <= 0)){
            return;
        }
        
        vector<int> numsCopy(n);       // Make a copy of nums
        for (int i = 0; i < n; i++){
            numsCopy[i] = nums[i];
        }
        
        // Rotate the elements.
        for (int i = 0; i < n; i++){
            nums[(i + k)%n] = numsCopy[i];
        }
    }
};



