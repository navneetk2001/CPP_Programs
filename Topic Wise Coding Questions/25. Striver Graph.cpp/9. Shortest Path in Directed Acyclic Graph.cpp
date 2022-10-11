https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/




//Here it is given as Directed Acyclic Graph with weighted edge
//We need to find the shortest distance from each node from source node


//First Solution :- DFS
//Step1 : -find topo sort either by dfs or bfs
//Step2 :- Start popping node from stack one by one and start relaxing the dege one by one

class Solution {
  public:
    void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                findTopoSort(it.first, vis, st, adj); 
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        //Step 1 :- Find topo sort for the given graph
        int vis[N] = {0};
    	stack<int> st; 
    
    	for (int i = 0; i < N; i++) {
    		if(!vis[i]) {
    			findTopoSort(i, vis, st, adj);     //find order of topo sort in graph
    		}
    	}
    	
    	vector<int> dist(N); 
    	for (int i = 0; i < N; i++) {
    		dist[i] = 1e9; 
    	}

    	//Step2 :- Start popping node from stack one by one and do the distance thing      
        int src = 0;
    	dist[0] = 0;       //source distance marked as 0
    
    	while(!st.empty()){  
    		int node = st.top(); 
    		st.pop(); 
     
    		for(auto it : adj[node]) {
    		    int v = it.first;
    		    int wt = it.second;
    		    
		        if(dist[node] + wt < dist[v]) {
		            dist[v] = dist[node] + wt; 
		        }
		    }
    	}
    	
    	for(int i=0;i<N;i++){
    	    if(dist[i] == 1e9){
    	        dist[i] = -1;
    	    }
    	}
    	return dist;
    }
};









//Second Solution :- 
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}

void shortestPath(int src, int N, vector<pair<int,int>> adj[]) { 
	int vis[N] = {0};
	stack<int> st; 

	for (int i = 0; i < N; i++) {
		if(!vis[i]) {
			findTopoSort(i, vis, st, adj);     //find order of topo sort in graph
		}
	}
			
	int dist[N]; 
	for (int i = 0; i < N; i++) {
		dist[i] = 1e9; 
	}

	dist[src] = 0;       //source distance marked as 0

	while(!st.empty()){  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) {    //if the node has been reached previously
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) {
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
	}
}


int main(){ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 
	return 0; 
} 