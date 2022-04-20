// Given an array of integers A, every element appears twice except for one. Find that single one.
// NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1


//Hint :-
Let us look at every bit position.
Every number that occurs twice will either contribute 2 ‘1’s or 2 ‘0’s to the position.
The number that occurs once-‘X’ will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.
So:
If X has 1 in that position, we will have odd number of 1s in that position.
If X has 0 in that position, we will have odd number of 0s in that position.
Can you think of a solution using the above observation?

//Solution Approach :- 
We have noticed that if X has 1 in that position, we will have odd number of 1s in that position.
If X has 0 in that position, we will have odd number of 0 in that position.
If you look at the bit operators, XOR is exactly what we need.
XOR will return 1 only on two different bits. So if two numbers are the same, XOR will return 0.
Finally, there is only one number left.
A ^ A = 0 and A ^ B ^ A = B.
So, all even occurences will cancel out using XOR.


//First Solution :-
int Solution::singleNumber(const vector<int> &A) {
    int single_num=A[0];
    for(int i=1; i<A.size(); i++){
        single_num^=A[i];
    }
    return single_num;
}

//Second Solution :- Using Sort Function
Time Complexity: - O(NLogN + N)
Space Complexity: - O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        for(int x=0;x<nums.size();x++){
            if(nums[x] != nums[x+1]){
                return nums[x];
            }
            else{
                x++;
            }
        }
        return -1;
    }
};



//Third Solution :- Using map
class Solution {
public:
	int singleNumber(vector& nums) {
		unordered_map<int,int>mp;
		// Base case
		if(nums.size()==0){
			return 0;
		}

		if(nums.size()==1){
			return nums[0];
		}

		for(int i=0;i<nums.size();i++){
			mp[nums[i]]++;
		}

		int ans=0;
		for(auto x: mp){
			if(x.second <2){
				ans = x.first;
			}
		}
		
		return ans;
	}
};


