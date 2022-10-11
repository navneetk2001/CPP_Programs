https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule




//Solution Approach :- BFS (TOPO SORT)
class Solution{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int> adj[n];
        for(int i = 0; i < m; i++) {
            int u = pre[i][1];
            int v = pre[i][0];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(q.empty() == false) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() == n){
            return ans;
        }
        else return {};
    }
};




//Solution Approach :- DFS (Topo Sort)