// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

// Example 1:
// Input: K = 3
// arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation:Above test case has 3 sorted arrays of size 3, 3, 3
// arr[][] = [[1, 2, 3],[4, 5, 6], [7, 8, 9]]
// The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].

// Example 2:
// Input: K = 4
// arr[][]={{1,2,3,4}, {2,2,3,4}, {5,5,6,6}, {7,8,9,9}}
// Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4
// arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6]  [7, 8, 9, 9 ]]
// The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].




//Solution Approach :- Using Min Priority Queue (C++)
typedef pair<int, pair<int, int>> ppi;
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    vector<int> res;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
       
    for (int i=0; i<K; i++) {
        pq.push({arr[i][0], {i, 0}});
    }
       
    while(!pq.empty()) {
        ppi minNode = pq.top();
        pq.pop();
           
        res.push_back(minNode.first);
           
        int arrIdx = minNode.second.first;         //ith array
        int arrSubIdx = minNode.second.second+1;   //jth element of ith array
           
        if (arrSubIdx < arr[arrIdx].size()) {
            pq.push({arr[arrIdx][arrSubIdx], {arrIdx, arrSubIdx}});   
        }
    }
       
    return res;
}




//Second Solution :-
vector<int> mergeKArrays(vector<vector<int>> arr, int K){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            pq.push(arr[i][j]);
        }
    }
    
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}




//Third Solution :-

class Solution{
public:
    typedef pair<int, int> pi;
    vector<int> mergeKArrays(vector<vector<int>> nums, int k){
        vector<int> ans;
        vector<int> cnt(k,0);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i= 0; i<k; i++){
           pq.push(make_pair(nums[i][0], i));
        }
       
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
           
            cnt[p.second]++;
            if(cnt[p.second] < nums[p.second].size()){
                pq.push(make_pair(nums[p.second][cnt[p.second]], p.second));
            }
        }
        return ans;
    }
};


