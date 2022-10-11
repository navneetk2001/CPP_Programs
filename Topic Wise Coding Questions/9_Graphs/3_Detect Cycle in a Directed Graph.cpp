//First Solution :-
class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
      	vis[node] = 1;
      	dfsVis[node] = 1;
      	
      	for(auto it: adj[node]) {
        	if (!vis[it]) {
          		if (checkCycle(it, adj, vis, dfsVis)){
          			return true;
          		}
        	}
        	else if (dfsVis[it]) {  //if marked 1 in both, dfsVis and Vis then return true
          		return true;
        	}
      	}
      	dfsVis[node] = 0;   //make it unvisited 
      	return false;
    }

public:
    bool isCyclic(int N, vector < int > adj[]) {
      	int vis[N], dfsVis[N];
      	memset(vis, 0, sizeof vis);
      	memset(dfsVis, 0, sizeof dfsVis);

      	for (int i = 0; i < N; i++) {
        	if (!vis[i]) {
          		if (checkCycle(i, adj, vis, dfsVis)) {
            		return true;
          		}
        	}
      	}
      	return false;
    }
};




//Second Solution :- Using BFS(Kahn's Algo) Topological Sort
class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
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

	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
};




//Third Solution :-
#include<bits/stdc++.h>
using namespace std;

bool isCyclic_util(vector<int> adj[],vector<bool> visited, int curr){
	if(visited[curr]==true)
		return true;

	visited[curr]=true;
	bool flag=false;
    for(int j=0;j<adj[curr].size();j++){
			flag=isCyclic_util(adj,visited,adj[curr][j]);
			if(flag==true){
				return true;
			}
			visited[i]=false;
		}
	return false;
}


bool isCyclic(int N,vector<int> adj[]){
	vector<bool> visited(N,false);
	bool flag=false;

	for(int i=0;i<N;i++){
		visited[i]=true;
		for(int j=0;j<adj[i].size();j++){
			flag=isCyclic_util(adj,visited,adj[i][j]);
			if(flag==true){
				return true;
			}
			visited[i]=false;
		}
	}
	return false;
}



int main(){
	int T;
	cin>>T;

	while(T--){
		int N,E;
		cin>>N>>E;

		vector<int> adj[N];
		bool visited[N];
		memset(visited,false,sizeof(visited));

		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;

			adj[u].push_back(v);
		}

		cout<<isCyclic(N,adj)<<endl;
	}
	return 0;
}


