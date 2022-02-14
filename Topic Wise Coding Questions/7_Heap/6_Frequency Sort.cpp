typdef pair<int,int> pi;
typdef pair<int,pair<int,int>> ppi;
class Solution {
public:
    void Frequency_Sort(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> maxh;
        for(auto i=mp.begin();i!=mp.end();i++){
            maxh.push({i.second,i.first});
        }

        while(maxh.size()>0){
            int freq=maxh.top().first;
            int ele=maxh.top().second;
            for (int i = 1; i <= freq; ++i)
            {
                cout<<ele<<" ";
            }
            maxh.pop();
        }
    }
};