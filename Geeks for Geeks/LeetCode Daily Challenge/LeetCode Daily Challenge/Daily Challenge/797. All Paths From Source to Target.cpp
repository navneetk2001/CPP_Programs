// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Example 1:
// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

// Example 2:
// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]




//Solution Approach :-
class Solution {
public:
    // setting a few class variables, so that we do not have to pass them down all the time in the recursive dfs calls
    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>>& graph, int currNode = 0) {
        tmp.push_back(currNode);  	    // updating tmp

        if(currNode == target){ 		// and either updating res with it if target is met
        	res.push_back(tmp);
        }
        else{ 
        	for(int node: graph[currNode]){  		// or callling dfs again recursively
            	dfs(graph, node);
        	}
        }

		tmp.pop_back();                  // backtracking with tmp
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph);
        return res;
    }
};




//Second Solution :-
// If it asks just the number of paths, generally we can solve it in two ways.
// Count from start to target in topological order.
// Count by dfs with memo.
// Both of them have time O(Edges) and O(Nodes) space. Let me know if you agree here.
// I didn't do that in this problem, for the reason that it asks all paths. I don't expect memo to save much time. (I didn't test).
// Imagine the worst case that we have node-1 to node-N, and node-i linked to node-j if i < j.
// There are 2^(N-2) paths and (N+2)*2^(N-3) nodes in all paths. We can roughly say O(2^N).

void dfs(vector<vector<int>>& g, vector<vector<int>>& res, vector<int>& path, int cur) {
    path.push_back(cur);
    if (cur == g.size() - 1)
        res.push_back(path);
    else for (auto it: g[cur])
        dfs(g, res, path, it);
    path.pop_back();

}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
    vector<vector<int>> paths;
    vector<int> path;
    dfs(g, paths, path, 0);
    return paths;
}



//Third Solution :- ✔️ (BFS)
// We can start from the starting node 0 and traverse every possible next node from the current node. Whenever we reach the last node n-1, we will add the path till now into the final answer. This process can be implemented using a BFS traversal as -

// Initialize a queue of path of nodes with the node 0 inserted into it initially denoting the starting node in our traversal path from 0 to n-1
// Pop an element path from the queue
// Explore every child node of last node in the path. That is, we try every possible edge in graph from node at the end of current path. Each edge added to end of path gives us another path which will be added to queue for further exploration
// If the last node in path is n-1, we know that this is a valid source to target path in the graph. So, we add it to final list of paths
// We repeat this process until the queue is not empty, that is, until there are paths remaining to be explored.

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector<int>> result;
        int n = graph.size(), s = 0, e = n;

        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(auto g : graph[i]){
                adj[i].push_back(g);
            }
        }
        
        queue<vector<int>> q;
        vector<int> path;

        q.push({0});
        while(!q.empty()){
            path = q.front();
            q.pop();

            if(path.back() == n-1){
                result.push_back(path);
            }
            
            for(auto ele : adj[path.back()]){
                vector<int> temp = path;
                temp.push_back(ele);
                q.push(temp);
            }
        }
        return result;
    }
};