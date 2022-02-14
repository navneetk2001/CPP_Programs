// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


//We have to find the length of longest subarray which contains equal number of zeros and ones



//Brute Force Generating subarrays :-
//We will generate all subarray and find maximum length of equal zeros and ones
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
		int maxlen = 0;
		
        for (int i = 0; i < nums.size(); i++){
            int zeroes = 0, ones = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0){
                    zeroes++;
                }
                else{
                    ones++;
                }
                if (zeroes == ones){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};



//Optimal solution :-
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int sum = 0,mx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=1;
            }
            
            if(sum==0){
                    mx=max(mx,i + 1);
            }
            else if(mp.find(sum) != mp.end()){
                    mx = max(mx,i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return mx;
    }
};



//APPROACH 3 : Using Array

// We use a variable sum, which is used to store the relative number of ones and zeros encountered so far.
// sum is incremented by one whenever a 1 is encountered and decremented by one whenever a 0 is encountered.
// We traverse the array nums from the beginning.
// If at any index, sum becomes zero, it means that we've encountered equal number of zeros and ones from the beginning till the current index.
// And at any index, we encounter a sum that's already been encountered at some previous index, it means that the number of 0's and 1's are equal between the indices corresponding to the equal sum values.
// We keep track of the indices that correspond to the same sum with maximum difference between the indices to find the maximum length of the subarrays with equal number of 0's & 1's.
// Now, sum can range between -n (When all elements are zeros) to +n (When all elements are ones).
// Thus, we make use of an array arr of size 2n+1 to keep a track of the all values of sum encountered so far.
// We make an entry containing the current element's index in the arrarr for a new sum encountered everytime.
// Whenever, we encounter the same sum again, we determine the length of the subarray lying between the indices corresponding to the same sum values.

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		vector<int> arr(2*nums.size() + 1, INT_MIN);
		arr[nums.size()] = -1;
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
			if (arr[sum + nums.size()] >= -1)  maxLen = max(maxLen, i - arr[sum + nums.size()]);
			else  arr[sum + nums.size()] = i; 
        }
        return maxLen;
    }
};


