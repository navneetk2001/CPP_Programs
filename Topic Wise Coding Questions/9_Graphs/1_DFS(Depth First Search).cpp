#include<bits/stdc++.h>
using namespace std;


void dfs(int start, vector<int>g[],bool *visited){
	visited[start]=true;
	cout<<start<<" ";

	for(int i=0;i<g[start].size();i++){
		if(visited[g[start][i]]==false){
			dfs(g[start][i],g,visited);
		}
	}
}


int main(){
	int T;
	cin>>T;

	while(T--){
		int N,E;
		cin>>N>>E;

		vector<int>g[N];
		bool visited[N];
		memset(visited,false,sizeof(visited));

		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;

			g[u].push_back(v);
			g[v].push_back(u);
		}

		dfs(0,g,visited);
		cout<<endl;
	}
}


