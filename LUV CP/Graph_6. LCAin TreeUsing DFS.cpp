#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int par[N];

//count connected Components in a graph :-

void dfs(int v, int par=-1){
    par[v] = p;
    for(int child : g[v]){
        if(child == par) continue;
        dfs(child, vertex);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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

    int x, y;
    cin>>x>>y;

    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int mn_len = min(path_x.size(), path_y.size());

    int lca = -1;
    for(int i=0;i<mn_len;i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;
}
