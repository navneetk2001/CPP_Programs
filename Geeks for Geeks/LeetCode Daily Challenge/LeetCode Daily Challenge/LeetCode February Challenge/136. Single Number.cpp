Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1


//Solution :- Using XOR Approach :- 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_num=nums[0];
        for(int i=1; i<nums.size(); i++){
            single_num^=nums[i];
        }
        return single_num;
    }
};

//Approach 2: - Using Sort Function

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


//Approach 3 :- Using map
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



//Another Approach :-
//temp = 2a + 2b + 2c
//sum = 2(a+b+c)
//required no :- sum - temp