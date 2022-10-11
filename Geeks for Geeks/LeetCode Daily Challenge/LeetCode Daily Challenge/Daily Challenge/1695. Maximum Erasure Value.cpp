// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Example 1:
// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].

// Example 2:
// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].



//Solution Approach :-
// Idea:
// 	This problem is about to find the maximum sum of subarrray (where elements in subarray is unique) in an array.
// 	This is a classic Sliding Window problem which is simillar to this problem 3. Longest Substring Without Repeating Characters
// 	We use seen (HashMap) to keep track of last index of a number.
// 	We use sum to keep sum of sub array in range [l..r] so far where elements are unique.
// 	While extend right side r if we met an existed number then we move left side l until seen[nums[r]] + 1 and of course, we need to decrease sum corresponding.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> seen;
        int l = 0, sum = 0, ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            int x = nums[r];
            if (seen.find(x) != seen.end()) {
                int index = seen[x];
                while (l <= index) {  // Move the left side until index + 1
                    seen.erase(nums[l]);
                    sum -= nums[l];
                    l += 1;
                }
            }
            seen[x] = r;
            sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};



//Second Solution :- Sliding window and set
// We need to check every sub-array having unique elements and find the one having the maximum sum. Obviously, with the given constraints, we can't check every sub-array individually.
// We need to realise that we can choose the first element and keep extending the array till we find a duplicate. We can insert all the chosen elements till now into a hashset and check if the element already exists before inserting the next one. We will simultaneously also keep track of the sum of all chosen elements - cursum and maintain the max sum till now - ans
// When our next element nums[r] is already present in currently chosen subarray (hashset), then we must delete all the elements from the start till the duplicate. For this, we will need to maintain a left-pointer l denoting the left-most index of an element in currently chosen subarray.
// We will keep deleting nums[l] and simultaneously deducting it from cur_sum and incrementing l pointer till duplicate is deleted. Finally we add nums[r] to our hashset and cur_sum. We repeat till we reach the end.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {        
		int n=size(nums), cur_sum = 0, ans = 0, l = 0, r = 0;
		unordered_set<int> s;
		
		while(r<n){
			while(s.find(nums[r]) != end(s)){        // delete from current sub-array till there's a duplicate of nums[r]
				cur_sum -= nums[l]; 
				s.erase(nums[l++]);
			}
			cur_sum += nums[r]; 
			s.insert(nums[r++]);                      // pick nums[r] and update cur_sum
			ans = max(ans, cur_sum);                  // finally update ans to hold the maximum of all subarray sums till now
		}
		return ans;
	}
};




//Third Solution :- (using 2-Pointers and Frequency array)
//It's given that all the element in nums are in the range [1, 10000]. We can use a frequency-array with indices [1,10000] to denote if an element is already chosen.
//This method gave significant improvement in the runtime speed & memory of C++ (from ~360ms to <100ms). The improvement was negligible in case of python

int maximumUniqueSubarray(vector<int>& nums) {        
	int n = size(nums), cur_sum = 0, ans = 0, l = 0, r = 0;
    bool freq[10001]{false};
	
	while(r < n) {
		while(freq[nums[r]]){
			cur_sum -= nums[l], freq[nums[l++]] = false;
		}
		cur_sum += nums[r], freq[nums[r++]] = true;  
		ans = max(ans, cur_sum);    
	}
	return ans;
}