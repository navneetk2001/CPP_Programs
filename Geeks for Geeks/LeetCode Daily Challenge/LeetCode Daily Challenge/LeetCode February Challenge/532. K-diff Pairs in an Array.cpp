Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
	0 <= i, j < nums.length
	i != j
	nums[i] - nums[j] == k
	Notice that |val| denotes the absolute value of val.


Example 1:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).



//Solution :-
We can say nums[i]-nums[j] = k   
    => nums[i] + k = nums[j]
Now, we can use the binary search intuition to search nums[j] in right side of the array
// Time Complexity :- O(nlogn)   // Space Complexity :- O(n)  
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());    //sort the array first
        set<pair<int,int>>st;              //use set to store unique value
        int n=nums.size();                 // size of array

        for(int i=0;i<n;i++){
        	int lo=i+1;
        	int hi=n-1;         
        	int f=-1;            //flag for checking
        	while(lo<=hi){       //using binary search intuition to search nums[i] + k in right side of the array
        		int mid=(lo+hi)/2;
        		if(nums[mid]==(nums[i]+k)){     //search nums[i] + k
        			f=1;
        			break;
        		}
        		else if(nums[mid]<(nums[i]+k)){
        			lo=mid+1;
        		}
        		else{
        			hi=mid-1;
        		}
        	}
        	if(f==1){
        		st.insert({nums[i], nums[i]+k});
        	}
        }

        return st.size();
    }
};



//Another Approach :- 
//We can use the concept of hashing and search nums[i]+k in hashmap
// Time Complexity :- O(n)   // Space Complexity :- O(n)   
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums)
            mp[i]++;
        int ans=0;
        for(auto x:mp)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(mp.find(x.first+k)!=mp.end())
                ans++;
        }
        
        return ans;
    }
};