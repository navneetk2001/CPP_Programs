Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Example 1:
Input:

Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:

Output: 0
Explanation: no cycle in the graph




class Solution {
  public:
    bool isCyclicUtil(int v, vector<bool>&visited, vector<bool>&recStack, vector<int>adj[]){
    	//if current vertex is not visited
    	if(visited[v]==false){
    		//marking current node as visited and part of recursion stack
    		visited[v]=true;
    		recStack[v]=true;
    
    		//calling function recursively for all the vertices
    		//adjacent to this vertex
    		for(int i=0;i<(int)adj[v].size();i++){
    			if(!visited[adj[v][i]]){
    				if(isCyclicUtil(adj[v][i], visited, recStack, adj))
    					return true;
    			}
    			else if(recStack[adj[v][i]])
    				return true;
    		}
    	}
    	//removing the vertex from recursion stack
    	recStack[v]=false;
    	return false;
}
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //marking all vertices aa not visited andnot a part of recursion stack
        vector<bool>visited(V,false);
        vector<bool>recStack(V,false);
    
        //calling the recursive helper function to detect cycle in different dfs trees
        for (int i = 0; i < V; ++i)
        {
        	if(isCyclicUtil(i,visited,recStack,adj))
        		return true;
        }
        return false;
    }
};