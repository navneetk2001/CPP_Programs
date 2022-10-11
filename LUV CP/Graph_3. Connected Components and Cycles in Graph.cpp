#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];


//count connected Components in a graph :-

void dfs(int vertex){
    vis[vertex] = true;
    for(int child : g[vertex]){
        if(!vis[child]){
            dfs(child);
        }
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

    /* count for connected component */
    int ct = 0;  
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        ct++;
    }	
    cout << ct << endl;


    /* check if cycle exists or not */
    bool isLoopExists = false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;
}





//Find Cycle in a graph :-
bool dfs(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExists = false;
    
    for(int child : g[vertex]){
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;

        isLoopExists |= dfs(child,vertex);
    }
    return isLoopExists;
}


