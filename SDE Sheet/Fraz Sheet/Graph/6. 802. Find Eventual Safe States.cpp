// https://leetcode.com/problems/find-eventual-safe-states/




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




//Third Solution :- 
// Intuition:
// Idea here is to reverse direction of all edges. And then perform simple topo sort.
// This is because we need to start from nodes with outdegree = 0 (Terminal Nodes), and then move backwards to find safe nodes.
// We cannot do move do backward BFS, due to which we need to reverse edges. So, outdegree becomes indegree , and we can easily do topo sort using this.
// Reversing edges will help us in classifying TERMINAL NODES => indegree is zero,
// and all safe nodes i.e nodes reachable from terminal nodes, that are not in a cycle. Also, doing topo sort will exclude all nodes that are present in a cyclic path.
// So, topo sort will give us the all nodes that are either terminal or there is a path to terminal nodes.

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<vector<int>> adj(n);
	vector<int> indegree(n, 0);
	int i = 0;
	
	// Reverse Edges of graph
	for(auto& g : graph) {
		for(auto& it : g) {
			adj[it].push_back(i);
			indegree[i]++;
		}
		i++;
	}

	// Topo Sort
	queue<int> q;

	for(int i=0; i<n; i++) {
		if(indegree[i] == 0) q.push(i);
	}

	vector<int> safeNodes;
	while(q.size()) {
		int node = q.front(); 
		q.pop();

		safeNodes.push_back(node);

		for(auto& adjnode : adj[node]) {
			if(--indegree[adjnode] == 0){
				q.push(adjnode);
			}
		}
	}

	sort(safeNodes.begin(), safeNodes.end());
	return safeNodes;
}




//Second Solution :- Cycle Detection (Using DFS)
// Intuition :-> 
// In normal (standard) cycle detection using DFS we use two visited array, one to check overall visited and one to check visited for a path.
// So Idea is to modify it a little bit & we use a single array of int, which store the state of a node.
// Here we mark node as unsafe : if node is part of cycle. Otherwise we mark it as safe. Unsafe is when a node is already visited overall as well in dfs path.
// Thus, all nodes that are not present in a cycle are Safe nodes and we return those nodes in sorted order.

/*	States of a Node : 
	0 -> Unvisited
	1 -> Visited
	2 -> Safe
	3 -> Unsafe (Part of a cycle)
*/

bool detectCycle(vector<vector<int>>& graph, vector<int>& state, int node) {
	state[node] = 1;

	for(auto& adjnode : graph[node]) {
		if(state[adjnode] == 0) {
			if(detectCycle(graph, state, adjnode)) {
				state[node] = 3;
				return true;
			}
		}
		else if(state[adjnode] != 2) {
			state[node] = 3;
			return true;
		}
	}
	state[node] = 2;
	return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> state(n, 0);

	for(int i=0; i<n; i++) {
		if(state[i] == 0) {
			detectCycle(graph, state, i);
		}
	}

	vector<int> safeNodes;
	for(int i=0; i<n; i++) {
		if(state[i] == 2) {
			safeNodes.push_back(i);
		}
	}
	return safeNodes;
}



//Third Solution :- 
class Solution {
public:
    
    bool DFSRec(int s, vector<bool>&visited, vector<bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[s] = true;
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[s] = true;
            }
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        vector<bool>visited(n, false), dfsVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};




//Solution :-  topological sorting with dp
bool dfs(vector<vector<int>>& graph, vector<int> &dp, int src) {
   if(dp[src]){
       return 1 == dp[src];
   }

    dp[src] = -1;             // by default mark it as "cannnot be topologically sorted"
    for(auto node : graph[src]){
        if(false == dfs(graph, dp, node)){
            return false;
        }
    }
    return dp[src] = 1;        // next node with zero outdegree
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int total_nodes = graph.size();
    vector<int> result, dp(total_nodes, 0);
    for(int i = 0; i < total_nodes; i++){
        if(dfs(graph, dp, i)){
            result.push_back(i);
        }
    }
    
    return result;
} 