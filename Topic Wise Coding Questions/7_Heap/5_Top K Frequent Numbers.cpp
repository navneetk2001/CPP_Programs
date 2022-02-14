typdef pair<int,int> pi;
typdef pair<int,pair<int,int>> ppi;
class Solution {
public:
    void top_K_Frequent_Numbers(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(auto i=mp.begin();i!=mp.end();i++){
            minh.push({i.second,i.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size()>0){
            cout<<minh.top().second<<" ";
            minh.pop();
        }
    }
};