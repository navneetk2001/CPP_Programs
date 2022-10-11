//https://practice.geeksforgeeks.org/problems/eventual-safe-states/1



//Solution Approach :- Approach 1 : using BFS (Topo Sort)
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++) {    //Reverse the edges of adjacency list and store it in adjRev
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        //Perform topo sort
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> safeNodes;    //to store safe nodes
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            safeNodes.push_back(curr);
            
            for(auto it: adjRev[curr]) {
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};




//Second Solution :- using DFS (Cycle Detection)
class Solution {
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]){                //when the node is not visited prev
                if(dfsCheck(it, adj, vis, pathVis, check) == true){
                    check[node] = 0;     //so this node has become the part of the cycle
                    return true;
                }
            }
            else if(pathVis[it]){   //if the node has been visited previously but it has to be visited on the same path
                check[node] = 0;    //this node also became the part of the cycle
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};        //for dfs visited array
        int pathVis[V] = {0};    //for dfsPath visited array
        int check[V] = {0};      //for checking if that node is a part of cycle or not
        vector<int> safeNodes;   //to store safe nodes
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i] == 1){    //Now checking if that array is a part of cycle or not, if not include in safeNodes
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


