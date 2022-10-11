// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:
// Input:
// 	4 4
// 	0 1
// 	1 2
// 	2 3
// 	3 3
// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:
// Input:
// Output: 0
// Explanation: no cycle in the graph



//Solution Approach :- Using DFS
// recStack is maintained that is initially false
    // It get true when node enters the recursion and get false again when recusive call is over.
    // If it remains true i.e it does not got out of recusion hence there exist a loop.
	// the idea is basically to maintain a visited vector and order vector when recursion call is back then and make order vector 0 if we found order vector 0 then no cycle…


class Solution {
  public:
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &order,int src)
    {
        vis[src]=1;
        order[src]=1;
       
        for(auto x:adj[src])
        {
            if(!vis[x])
            {
                if(dfs(adj,vis,order,x))
                    return true;
            }
            else if(order[x])
                return true;
        }
       
        order[src]=0;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        vector<int> order(v,0);
         
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                bool f=dfs(adj,vis,order,i);
                if(f)
                    return true;
            }
        }
        return false;
    }
};