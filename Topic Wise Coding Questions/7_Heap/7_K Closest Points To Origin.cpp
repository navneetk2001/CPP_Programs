typdef pair<int,pair<int,int>> ppi;
class Solution {
public:
    void K_Closest_Points_to_Origin(vector<int>& arr, int k) {
        priority_queue<ppi> maxh;
        for(int i=0;i<n;i++){
            maxh.push({arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1], {arr[i][0],arr[i][1]}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()>0){
            pair<int,int>p=maxh.top().second;
            cout<<p.first<<" "<<p.second<<" ";
            maxh.pop();
        }
    }
};