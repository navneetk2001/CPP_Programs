// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment or decrement an element of the array by 1.
// Test cases are designed so that the answer will fit in a 32-bit integer.

// Example 1:
// Input: nums = [1,2,3]
// Output: 2
// Explanation: Only two moves are needed (remember each move increments or decrements one element): [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

// Example 2:
// Input: nums = [1,10,2,9]
// Output: 16




//Solution Approach :-
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size()-1;
        int count = 0;

        while(start < end){
            count += nums[end] - nums[start]; 

            start++;
            end--;
        }
        return count;
    }
};



//First Approach :-
// In this approach we just find the median after sorting the array which is nums[n/2] and add the absolute difference of the elements in the array with the median.
// Time Complexity : O(n logn) for sort + O(n) for loop = O(n logn), Space complexity : O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2]; // Finding median
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median); //Adding absolute difference
        }
        return steps;
    }
};




// Second Approach :
// If we notice carefully the median is always inside the range of nums[i] ans nums[n-1-i] elements. Now for any value x in the range the total steps needed to reach x for both the numbers is (x - nums[i]) + (nums[n-1-i] - x) = nums[n-1-i] - nums[i]. So it is clear that the steps does'nt depend on the median. So if we just simply add the diffences of nums[i] ans nums[n-1-i] from i =0 to i =n/2 (Because after that elements will repeat) we will get the required answer.
// For the same reason we didn't need the mean of the middle values in first approach in case of n is even.
// So after sorting the array just add the differences of first and last element one by one i.e. nums[i] ans nums[n-1-i] from i =0 to i =n/2
// Time Complexity : O(n logn) for sort + O(n/2) for loop = O(n logn), Space complexity : O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
    }
};




// Third Approach :- O(N)
// There is a function with syntax nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this. For more details google it.
// In this problem we don't need full array sorted we just need the median which is the n/2 th element in the sorted array. So this can be achived by nth_element(nums.begin(), nums.begin()+(n/2), nums.end()). After that continue as in first approach.
// The advantage of this approach is that the time complexity becomes O(n) as nth_element is O(n) fuction unlike sort.
// Time Complexity : O(n) for finding median + O(n) for loop = O(n), Space complexity : O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};


