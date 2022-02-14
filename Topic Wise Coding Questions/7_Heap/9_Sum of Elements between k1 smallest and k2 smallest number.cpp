class Solution {
public:
    int sum(vector<int>& nums,int k1, int k2){
        int first=findKthSmallest(nums,k1);
        int second=findKthSmallest(nums,k2);
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>first && nums[i]<second){
                sum+=arr[i];
            }
        }
        return sum;
    }


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