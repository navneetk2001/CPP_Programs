// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

// Example 1:
// Input:  5 5
//         0 4
//         1 2
//         1 4
//         2 3
//         3 4 
// Output: 1
// Explanation: 1->2->3->4->1 is a cycle.

// Example 2:
// Input: 
// Output: 0
// Explanation: No cycle in the graph.



//Solution Approach :- Using DFS
// recStack is maintained that is initially false
    // It get true when node enters the recursion and get false again when recusive call is over.
    // If it remains true i.e it does not got out of recusion hence there exist a loop.
	// the idea is basically to maintain a visited vector and order vector when recursion call is back then and make order vector 0 if we found order vector 0 then no cycle…


class Solution {
  public:
    bool dfs(vector<int> adj[], vector<bool> &vis, int src, int par)     //par ->parent node
    {
        vis[src]=true;
       
        for(auto x:adj[src]){
            if(!vis[x]){
                if(dfs(adj,vis,x,src)){
                    return true;
                }
            }
            else if(x!=par){
                return true;
            }
        }
       
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> vis(v,false);
         
        for(int i=0;i<v;i++){    //This loop for disconnected graph if present
            if(!vis[i])
            {
                bool f = dfs(adj,vis,i,-1);
                if(f)
                    return true;
            }
        }
        return false;
    }
};



//Seond Solution :- BFS
bool detectCycle(int s, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> nodeParent;
    nodeParent.push({s, -1});
    visited[s] = 1;

    while(!nodeParent.empty()){
        int node = nodeParent.front().first;
        int parent = nodeParent.front().second;
        nodeParent.pop();

        for(auto u : adj[node]){
            if(!visited[u]){
                visited[u] = 1;
                nodeParent.push({u, node});
            }
            else if(u != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(detectCycle(i, adj, visited)){
                return true;
            }
        }
    }
    return false;
}
