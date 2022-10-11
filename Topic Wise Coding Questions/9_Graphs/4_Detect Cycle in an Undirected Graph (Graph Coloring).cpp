//First Solution :- Using DFS

// Approach: Run a for loop from the first node to the last node and check if the node is visited. If it is not visited then call the function recursively which goes into the depth as known as DFS search and if you find a cycle you can say that there is a cycle in the graph.
// Basically calling the isCyclic function with number of nodes and passing the graph
// Traversing from 1 to number of nodes and checking for every node if it is unvisited
// If the node is unvisited then call a function checkForCycle, that checks if there is a cycle and returns true if there is a cycle.
// Now the function checkForCycle has the node and previous of the parent node. It will also have the visited array and the graph that has adjacency list
// Mark it as visited and then traverse for its adjacency list using a for loop.
// Calling DFS traversal if that node is unvisited call recursive function that checks if its a cycle and returns true
// If the previously visited node and it is not equal to the parent we can say there is cycle again and will return true
// Now if you have traveled for all adjacent nodes and all the DSF have been called and it never returned true that means we have done the DSF call entirely and now we can return false, that mean there is no DSF cycle


class Solution {
public:
    bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      	vis[node] = 1;
      	for(auto it: adj[node]) {
        	if(!vis[it]) {
          		if(checkForCycle(it, node, vis, adj)){
            		return true;
          		}
        	} 
        	else if(it != parent){    //if it is previously visited and it is not parent then there exists a cycle
          		return true;
        	}
      	}
      	return false;
    }

    bool isCycle(int V, vector < int > adj[]) {
      	vector<int> vis(V + 1, 0);
      	for(int i = 0; i < V; i++) {     //Check for every node i.e. may be there is multiple components present in the graph
        	if(!vis[i]) {
          		if(checkForCycle(i, -1, vis, adj)){    //here -1 is the parent node for curr node
          			return true;
          		}
        	}
      	}
      	return false;
    }
};




//Second Solution :- Using BFS
class Solution {
public:
   	bool isCyclic(int i, vector<int>* adj, vector<bool> &vis){
       	queue<pair<int, int>> q;
       	q.push({i, -1});
       	vis[i] = true;
       
       	while(!q.empty()){
           	int front = q.front().first;
           	int prev = q.front().second;
           	q.pop();
           
           	for(auto it: adj[front]){
               	if(!vis[it]){
                   	q.push({it, front});
                   	vis[it] = true;
               	}
               	else if(vis[it] && it != prev){
                   	return true;
               	}
           	}
       	}
       	return false;
   	}
   
   	bool isCycle(int n, vector<int> adj[]) {
      	vector<bool> vis(n, false);
      	
      	for(int i=0; i<n; i++){
          	if(!vis[i]){
              	if(isCyclic(i, adj, vis)){
              		return true; 
              	}
          	}
      	}
      	return false;
   	}
};




//Third Solution :- Using DFS
#include<bits/stdc++.h>
using namespace std;


bool isCyclic_util(vector<int> adj[],vector<bool> visited, int curr){
	if(visited[curr]==2){
		return true;
	}

	visited[curr]=1;
	bool flag=false;
    for(int j=0;j<adj[curr].size();j++){
    	if(visited[adj[curr][i]]==1)
    		visited[adj[curr][i]]==2;
    	else{
			flag=isCyclic_util(adj,visited,adj[curr][j]);
			if(flag==true){
				return true;
			}
		}
	}
	return false;
}


bool isCyclic(int N,vector<int> adj[]){
	vector<int> visited(N,0);
	bool flag=false;

	for(int i=0;i<N;i++){
		visited[i]=1;
		for(int j=0;j<adj[i].size();j++){
			flag=isCyclic_util(adj,visited,adj[i][j]);
			if(flag==true){
				return true;
			}
			visited[i]=0;
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

		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cout<<isCyclic(N,adj)<<endl;
	}
	return 0;
}
