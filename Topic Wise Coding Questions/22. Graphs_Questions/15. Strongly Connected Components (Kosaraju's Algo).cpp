// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

// Example 1:
// Input:
// Output: 3
// Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph

// Example 2:
// Input:
// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.




//Steps :-
1. Input Graph 
2. Reverse Graph
3. Order vector
4. DFS in Input Graph
5. DFS in Reverse Graph



//Solution Approach :-
vector<int> order;
void dfs(int node , vector<int> G[] , vector<int> &vis , bool flag){
    vis[node]=1;
    for(auto e : G[node]){
        if(!vis[e]){
            dfs(e , G , vis , flag);
        }
    }
    if(flag){ 
    	order.push_back(node);
    }
}

int kosaraju(int V, vector<int> G[])
{
   int SCCs=0;
   vector<int> T[V];
   vector<int> vis(V , false);
   
    for(int i=0;i<V;i++) {
        for(auto n : G[i]){
            T[n].push_back(i);
        }
    }

    for(int i=0;i<V;i++) {
        if(!vis[i]){ 
       		dfs(i , G , vis , true);
       	}
    }

    for(int i=0;i<V;i++){ 
   		vis[i]=false;
   	}
   
    for(int i=order.size()-1;i>=0;i--) {
       if(!vis[order[i]]) {
           SCCs++;
           dfs(order[i] , T , vis , false);
       }
   }
   
   return SCCs;
}



//Second Solution :-

// create a reverse graph.
// take a stack 
// run dfs on original graphs and after loop add that node to stack
// run dfs on reverse graph in order of the stack
// return number of time you need to run dfs

class Solution {
public:
    stack<int> S;
	bool visited[5000];
	vector<int> reversed_edges[5000];
	void dfs(int u, vector<int> edges[], bool push) {
	    visited[u] = true;
	    for (int& v : edges[u]) {
	        if (visited[v] == false)
	            dfs(v, edges, push);
	    }
	    if (push)
	        S.push(u);
	}
    int kosaraju(int n, vector<int> edges[]) {
        int cnt = 0;
        for (int u = 0; u < n; u++) {
            for (int& v : edges[u])
                reversed_edges[v].push_back(u);
        }
        memset(visited, false, sizeof(visited));
        for (int u = 0; u < n; u++) {
            if (visited[u] == false)
                dfs(u, edges, true);
        }
        memset(visited, false, sizeof(visited));
        while (!S.empty()) {
            int u = S.top();
            S.pop();
            if (visited[u] == false) {
                cnt++;
                dfs(u, reversed_edges, false);
            }
        }
        return cnt;
    }
};



//Third Solution  :-
void dfs(int V, vector<int> adj[], stack<int> &st, vector<bool> &visited, int i){
    visited[i] = true;
    for(auto &v : adj[i]){
        if(visited[v] == false){
            dfs(V, adj, st, visited, v);
        }
    }
    st.push(i);
}

void dfs2(int V, vector<int> adj[], vector<bool> &visited, int i){
    visited[i] = true;
    for(auto &v : adj[i]){
        if(visited[v] == false){
            dfs2(V, adj,visited, v);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited (V, false);
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            dfs(V, adj, st, visited, i);
        }
    }
    vector<int> transpose[V];
    for(int i = 0;i < V; i++){
        visited[i] = false;
        for(auto &e : adj[i]){
            transpose[e].push_back(i);
        }
    }
    int cnt = 0;
    while(!st.empty()){
        int curr = st.top();
        if(visited[curr] == false){
            dfs2(V, transpose, visited, curr);
            cnt++;
        }
        st.pop();
    }
    return cnt;
}



