#include<bits/stdc++.h>
using namespace std;

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