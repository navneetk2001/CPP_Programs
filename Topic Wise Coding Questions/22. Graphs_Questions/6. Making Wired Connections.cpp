//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:
// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Example 2:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2

// Example 3:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.



//Solution Approach :-
// Goal: We need to connect all the computers (directly or indirectly). We have to return the minimum number of operations that are required to connect the computers. An operation consists of removing a cable between two directly connected computers and put it between two disconnected computers.
// This problem is a simple variation of counting the number of islands.
// We know that the minimum number of edges required for a graph with n nodes to remain connected is n - 1. Similarly, if there are k components in a disconnected graph, then we need at least k - 1 edges to connect every component.
// With that in our mind, we will start with our base condition. If the number of edges in the graph is greater than n - 1 or not. If not, we will return -1.
// Next, we will count the number of components (k). As I already mentioned, we will need k - 1 operations to connect the computers (components). And that is our answer!
// We can also solve this using Union-Find approach and count the number of components. I solved this problem using DFS and the code is shown below.


class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1){  
            return -1;
        }

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(auto v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int components = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                components++;
            }
        }
        
        return components - 1;
    }
};



//Second Solutions :- UNION FIND APPROACH | UNION-FIND | UNION BY RANK WITH PATH COMPRESSION

class Solution {
public:
    int get(int x, vector<int> &parent){
        return parent[x] = parent[x] == x? x: get(parent[x], parent);
    }

    void merge(int l, int r, vector<int> &parent, vector<int>&rank){
        l = get(l, parent);
        r = get(r, parent);
        
        if(rank[l] == rank[r]) 
        	rank[l]++;
        if(rank[l] > rank[r]) 
        	parent[r] = l;
        else 
        	parent[l] = r;
        return ;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        if(totalEdges < n-1) return -1;
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            merge(u,v, parent, rank);
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) count++;
        }
        
        return count-1;
    }
};