// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]





//Solution Approach :-
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res;
        int first = -1, last = -1;
        
        //first occurence
        int start = 0, end = nums.size()-1;
        while(start <=end){
            int mid = start + (end-start)/2;
            if(target == nums[mid]){
                first = mid;
                end = mid - 1;
            }
            else if(target < nums[mid]){
                end= mid-1;
            }
            else{
                start = mid+1;            
            }
        }
        
        //last occurence
        start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]){
                last = mid;
                start = mid+1;
            }
            else if(target< nums[mid]){
                end = mid-1;
            } 
            else{
                start = mid+1;
            }
        }
        
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};