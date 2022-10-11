// Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1]. 

// Example:
// Input: edges = {{0,1},{0,3},{1,2},{3,2}}, 
// n = 4, s = 0, d = 2
// Output: 2
// Explanation: There are two ways to reach at 2 from 0. These are-
// 1. 0->1->2
// 2. 0->3->2




//Solution Approach :- 
// Steps:
// 1. If source=distance then we got a new path.
// 2. We traverse all the edges if we found any edge starting with source ,we call the function on that edge  and its destination as new source.

int dfs(int s, int d, vector <int> adj[]){
    if(s == d){
        return 1;
    }
    int c = 0;
    for(auto &i:adj[s]){
        c += dfs(i, d, adj);
    }
    return c;
}

int possible_paths(vector<vector<int>>edges, int n, int s, int d){
    vector <int> adj[n+1];
    for(auto &i:edges){
        adj[i[0]].push_back(i[1]);
    }
    return dfs(s, d, adj);
}




//Second Solution :-
void dfs(int s, int d, vector <int> adj[], int &c){
    if(s == d){
        c += 1;
        return;
    }
    for(auto &i:adj[s])
        dfs(i, d, adj, c);
}

int possible_paths(vector<vector<int>>edges, int n, int s, int d){
    int c = 0;
    vector <int> adj[n+1];
    for(auto &i:edges)
        adj[i[0]].push_back(i[1]);
    dfs(s, d, adj, c);
    return c;
}



//Third Solution :-
void dfs(vector<int> adj[], int u, vector<int> &vis, stack<int> &st) {
    vis[u] = 1;
    for(int v: adj[u]){
        if(!vis[v]){
        	dfs(adj, v, vis, st);
        }
    }
    st.push(u);
}

int solve(vector<int> adj[], int n, int s, int d) {
    vector<int>vis(n, 0);
	stack<int>st;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(adj, i, vis, st);
		}
	}

	vector<int> path(n, 0);
	path[s] = 1;
	while(!st.empty()){
		int u = st.top();
		st.pop();
	    for(int v: adj[u]){
	    	path[v] += path[u];    
	    }
	}
	return path[d];
}

int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	vector<int> adj[n];
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0], v = edges[i][1];
	    adj[u].push_back(v);
	}
	return solve(adj, n, s, d);
}

