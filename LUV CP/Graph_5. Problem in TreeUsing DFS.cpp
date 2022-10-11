#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];


//count connected Components in a graph :-

void dfs(int vertex, int par=0){
    for(int child : g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1; 

        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1)       
    }
}


int main(){
	int n,e;           //n :- vertices , m:- edges
	cin>>n>>e;

    for(int i=0;i<e;i++){   //iterate for number of edges
    	int v1, v2;
    	cin >> v1 >> v2;
    	g[v1].push_back(v2);
    	g[v2].push_back(v1);
    }

    dfs(1);    

    for(int i=1;i<=n;i++){
        cout<<depth[i] << " "<<height[i]<<endl;
    }
}
