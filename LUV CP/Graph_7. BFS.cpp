#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int vis[N];
int level[N];


//BFS :- Gives shortest path from the source vertex
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout << cur_v <<" ";   //print the order in bfs

        for(int child : g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] =  level[cur_v] + 1;
            }
        }
    }
}


int main(){
	int n;           //n :- vertices , m:- edges
	cin>>n;

    for(int i=0;i<n-1;i++){   //iterate for number of edges
    	int v1, v2;
    	cin >> v1 >> v2;
    	g[v1].push_back(v2);
    	g[v2].push_back(v1);
    }

    bfs(1);
}
