// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.

// Example 1:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Example 2:
// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

// Example 3:
// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].




//Solution Approach :- Two pointer technique.
// We can exploit the sorted property of an array.
// Let's say for indices i & j such that i<j,
// if sum of elements A[i]+A[j] == target, then we are done
// else check whether A[i]+A[j] > target, then last element has to be removed to reduce the value of sum (j--).
// similarly if A[i]+A[j] < target, we have to add little to increase the sum (i++).

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target){
            	return {i+1,j+1};
            }
            else if(sum>target){
            	j--;
            }
            else{
            	i++;
            }
        }
        return {}; // not found
    }
};

// time complexity: O(N)
// space complexity: O(1)


//Second Solution :- Using Binary Search. 
//Consider each element and find is (target-nums[i]) exist in array range [i+1,N-1]? (If yes, we are done), else increment one step, then again search the element exist in array.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        for(int i=0;i<N-1;i++){
            int lo = i+1;
            int hi = N;
            while(lo<hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]==target-nums[i]) return {i+1,mid+1};
                else if(nums[mid]>=target-nums[i]) hi=mid;
                else lo = mid+1;
            }
            if(lo!=nums.size() && nums[lo]==target-nums[i]) return {i+1,lo+1};
        }
        return {}; // not found
    }
};

// time complexity: O(NlogN) in worst (if elements are together in right extreme)
// space complexity: O(1)




