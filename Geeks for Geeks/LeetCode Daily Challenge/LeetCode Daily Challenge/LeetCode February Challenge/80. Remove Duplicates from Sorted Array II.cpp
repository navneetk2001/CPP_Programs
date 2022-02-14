// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
// Return k after placing the final result in the first k slots of nums.
// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.


// Example 1:
// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).


//First Solution :-
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    int n=nums.size();
	    int i = 1, j = 1;
		int cnt = 1;
		while (j < n) 
		{
		    if (nums[j] != nums[j-1])
		    {
		        cnt = 1;
		        nums[i++] = nums[j];
		    }
		    else 
		    {
		        if (cnt < 2) 
		        {
		            nums[i++] = nums[j];
		            cnt++;
		        }
		    }
		    ++j;
		}
		return i;
	}
};


//Second Solution :-
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int oIndex=0;
        int i=0;
        
        while(i<nums.size())
        {
            int sIndex=i;
            while(i<nums.size()-1 && nums[i]==nums[i+1])
            {
                i++;
            }
            int length=i-sIndex+1;
            int freq=min(length,2);
            
            while(freq-- > 0)
            {
                nums[oIndex]=nums[sIndex];
                oIndex++;
            }
            i++;
        }
        return oIndex;
    }
};


//Third Solution :-
//We can further simplify the above Sliding window solution to single pointer approach as:
class Solution {
    public int removeDuplicates(int[] nums) {
        int pivot = 0, cnt = 0;
        for(int num:nums){
            if(cnt<2 || num>nums[pivot-1]){
                nums[pivot]=num;
                if(pivot>0 && num>nums[pivot-1])
                    cnt = 0;
                pivot++;
            }
            cnt++;
        }
        return pivot;
    }
}