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

		bfs(0,adj,visited,N);
		cout<<endl;
	}
}


void bfs(int start, vector<int> adj[], bool *visited, int N){
	queue<int>q;
	q.push(start);
	visited[start]=true;

	while(!q.empty()){
		int curr=q.front();
		q.pop();
		cout<<curr<<" ";
		for(int i=0;i<adj[curr].size();i++){
		    if(visited[adj[curr][i]]==false){
		    	q.push(adj[curr][i]);
		    	visited[adj[curr][i]]=true;
		    }
	    }
	}
}