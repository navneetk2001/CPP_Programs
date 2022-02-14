class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
       int val;
        priority_queue<int> maxh;
        int n= nums.size();
        for (int i=0;i<n;i++)
        {
            maxh.push(nums[i]);
            {
                if (maxh.size()>k)
                    maxh.pop();
            }
        }
        return maxh.top();
        
    }
};