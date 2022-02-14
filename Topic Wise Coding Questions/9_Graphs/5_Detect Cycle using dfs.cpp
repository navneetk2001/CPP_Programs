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

		cout<<dfs(0,0)<<endl;
	}
	return 0;
}

bool dfs(int node, int par){
	vis[node]=1;

	for(int child :ar[node]){
		if(vis[child]==0){
			if(dfs(child,node)==true){
				return true;
			}
		}
		else{
			if(child!=par){
				return true;
			}
		}
	}
	return false;
}