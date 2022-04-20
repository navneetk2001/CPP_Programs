// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2



//Solution Approach :- Using maps  :- Time complexity : O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
       int sum=0;
       unordered_map<int,int>mp;
       int count=0;
       for(int i=0;i<nums.size();i++)
       {
            sum+=nums[i];
            if(sum==k)
            	count++;
            count+=mp[sum-k];
            mp[sum]++;
       }
       return count;
    }
};


//Approach :- BruteForce Soln  :->  Time complexity : O(n^3)
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}


// Approach :- Using Cumulative Sum  :->Time complexity : O(n^2)
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
}


//Approach 3: Without Space :->Time complexity : O(n^2)
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}


