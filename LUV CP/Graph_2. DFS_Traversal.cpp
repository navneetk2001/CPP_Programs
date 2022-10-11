#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    //Take action on vertex after entering the vertex
    for(int child : g[vertex]){
        //Take action on child before entering the child node
        dfs(child);
        //Take action on child after exiting the child node
    }
    //Take action on vertex before exiting the vertex
}


void dfs(int vertex){
    vis[vertex] = true;
    for(int child : g[vertex]){
        if(!vis[child]){
            dfs(child);
        }
    }
}


int main(){
	int n,m;           //n :- vertices , m:- edges
	cin>>n>>m;

    for(int i=0;i<m;i++){   //iterate for number of edges
    	int v1, v2;
    	cin >> v1 >> v2;
    	g[v1].push_back(v2);
    	g[v2].push_back(v1);
    }	
}



