#include<bits/stdc++.h>
using namespace std;

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


bool isCyclic_util(vector<int> adj[],vector<bool> visited, int curr){
	if(visited[curr]==2)
		return true;

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