Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4



//Solution :-
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        int mid;
        while(lo<=hi)
        {
                mid=lo+(hi-lo)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }
                else if(nums[mid]<target)
                {
                    lo=mid+1;
                }
                else
                {
                     hi=mid-1;
                }
        }
        return lo;
    }
};