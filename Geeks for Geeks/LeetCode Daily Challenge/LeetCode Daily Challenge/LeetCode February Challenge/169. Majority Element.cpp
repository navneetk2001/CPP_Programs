// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2


//Solution Approach :- Brute Force Approach 



//Solution Approach :- Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,c=0;
        for(auto&i:nums){
            if(c==0) ele=i;
            if(ele==i)c++;
            else c--;
        }
        return ele;
        //moore's voting algo
    }
};



//Solution Approach :- Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
        int  maj = nums[0], cnt = 1;
        
        for(int i=1;i<n;++i)
        {
		    // If next element is same then increments the count, otherwise decrement
            if(nums[i] == maj)
                cnt++;
            else
                cnt--;
            
            if(cnt == 0)
            {
                maj = nums[i];
                cnt = 1;
            }
        }
        return maj;
    }
};


//Solution Approach :- Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp ;
        int N = nums.size() ;
        
        for(auto&k:nums)
        {
            mp[k]++ ;
            if(mp[k]>floor(N/2))
                return k ;
        }
        return -1 ;
    }
};


//Solution Approach :- Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans ;
        
        for(int i = 0; i< nums.size(); i++)
        {
            // storing frequency/occurences of  elements in a map
            m[nums[i]]++;
        }
        
        for(int i = 0; i< nums.size(); i++)
        {
		    // if freq of an element is greater than num.size()/2
            if(m[nums[i]] > (nums.size()/2))
            {
                ans =  nums[i];
            	break;
            }
        }
        return ans; 
    }
};


//Solution Approach :- Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); // sort the vector
        return nums[nums.size()/2];     // middle element will be the most frequent Element
    }
};