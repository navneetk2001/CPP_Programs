// Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// Note that even though we want you to return the new length, make sure to change the original array as well in place
// For example,
// Given input array A = [1,1,1,2],
// Your function should return length = 3, and A is now [1,1,2].


//Hint 
// You need to modify the original array itself. So you need to keep current like pointer which will point to the index of the array where you can store the next value.
// How can you define another pointer to keep track of next value?

//Solution Approach :-
// Notice that the array is sorted. This implies that all repetitions for an element are clustered together in the array.
// Try maintaining 2 pointers in the array:
// One pointer iterates over the array
// Other pointer only moves per occurrence of a value in the array.
// Now you need to make sure we choose atmost 2 occurrences per cluster of repetition in the array,
// We could probably just check **if A[i] != A[i+1] || A[i] != A[i+2] **
// So, the second pointer only moves when A[i] != A[i+1] || A[i] != A[i+2]


//First Solution
int Solution::removeDuplicates(vector<int> &nums) {
    int n=nums.size();
    int i = 1, j = 1;
    int cnt = 1;
    
    while (j < n) {
        if (nums[j] != nums[j-1]){
            cnt = 1;
            nums[i++] = nums[j];
        }
        else {
            if (cnt < 2){
                nums[i++] = nums[j];
                cnt++;
            }
        }
        ++j;
    }
    return i;
}


//Second Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int oIndex=0;
        int i=0;
        
        while(i<nums.size()){
            int sIndex=i;
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
            int length=i-sIndex+1;
            int freq=min(length,2);
            
            while(freq-- > 0){
                nums[oIndex]=nums[sIndex];
                oIndex++;
            }
            i++;
        }
        return oIndex;
    }
};


//Third Solution
//We can further simplify the above Sliding window solution to single pointer approach as:
class Solution {
public:
    int removeDuplicates(int[] nums) {
        int pivot = 0, cnt = 0;
        for(int num:nums){
            if(cnt<2 || num>nums[pivot-1]){
                nums[pivot]=num;
                if(pivot>0 && num>nums[pivot-1]){
                    cnt = 0;
                }
                pivot++;
            }
            cnt++;
        }
        return pivot;
    }
}


//Fourth Solution :-
int Solution::removeDuplicates(vector<int> &nums) {
    int n =nums.size();
    if(n < 3) {
        return n;
    }
    
    int indx = 2;
    for(int i =2; i< nums.size(); i++){
        if(nums[i] != nums[indx -2]){
            nums[indx] = nums[i];
            indx++;
        }
    }
    return indx;
}