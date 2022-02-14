class Solution {
public:
    void K_Closest_Numbers(vector<int>& nums, int k, int val) {
        priority_queue<pair<int,int>> maxh;
        int n= nums.size();
        for (int i=0;i<n;i++)
        {
            maxh.push({abs(nums[i]-val),nums[i]});
            {
                if (maxh.size()>k)
                    maxh.pop();
            }
        }
        while(maxh.size()>0){
            cout<<maxh.top().second<<" ";
            maxh.pop();
        }
    }
};