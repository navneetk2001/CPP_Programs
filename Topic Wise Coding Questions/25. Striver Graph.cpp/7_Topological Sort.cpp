//Topological Sort :- Linear Ordering of Vertices such that whenever there is an edge b/w u->v, u appears before v in that ordering
//Topological Sort :- It is only for directed acyclic graph.
//It is also used to check cycles in a directed graph. (by reverse logic)


//First Solution :- DFS
class Solution{
  	void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
	    vis[node] = 1;

	    for (auto it: adj[node]) {
	     	if (!vis[it]) {
	        	findTopoSort(it, vis, st, adj);
	      	}
	    }
	    st.push(node);
  	}

  public:
    vector<int> topoSort(int N, vector<int> adj[]) {
      	stack<int> st;
      	vector<int> vis(N, 0);

      	for (int i = 0; i < N; i++) {
        	if (vis[i] == 0) {
          		findTopoSort(i, vis, st, adj);
        	}
      	}
      	
      	vector<int> topo;
      	while (!st.empty()) {
        	topo.push_back(st.top());
        	st.pop();
      	}
      	return topo;

    }
};



//Second Solution :- BFS
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
      queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};