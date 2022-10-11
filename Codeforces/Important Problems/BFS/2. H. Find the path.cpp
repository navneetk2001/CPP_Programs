https://codeforces.com/gym/101992/problem/H





//Solution Approach :- BFS
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f;


int main(){
	freopen("path.in", "r", stdin);
	
	int t;
    cin>>t;

    while(t--){
    	int n, m, src, l, k;
    	cin>>n>>m>>src>>l>>k;

    	vector<pair<int,int>> adj[n+1];

    	for(int i=1;i<=m;i++){
    		int x,y,z;
    		cin>>x>>y>>z;

    		adj[x].push_back({y,z});
    		adj[y].push_back({x,z});
    	}

    	queue<int>q;
    	q.push(src);

    	int vis[n]={};
    	vis[src] = 1;

    	int ans = 0;
    	while(!q.empty()){
	    	int a = q.front();
	    	q.pop();

	    	for(auto it : adj[a]){
	    		if(!vis[it.first]){
	    			vis[it.first]=vis[a]+1;
	    			q.push(it.first);
	    		}
	    		if(vis[a]<=k){
	    			ans=max(ans,it.second);
	    		}
	    	}
	    }
	    cout<<ans<<endl;
    }
    return 0;
}





//Second Solution :- 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f;


int dis[N], u[N], v[N], w[N];
vector<int> adj[N];    //adjacency list



void bfs(int src, int n){
    for(int i=1;i<=n;i++){
    	dis[i]=-1;
    }

    dis[src]=0;
    queue<int>q;
    q.push(src);
    
    while(!q.empty()){
    	int a = q.front();
    	q.pop();

    	for(auto it : adj[a]){
    		if(dis[it]==-1){
    			dis[it]=dis[a]+1;
    			q.push(it);
    		}
    	}
    }
}


int main(){
	freopen("path.in", "r", stdin);

	int t;
    cin>>t;

    while(t--){
    	int n, m, src, L, k;
    	cin>>n>>m>>src>>L>>k;

    	for(int i=1;i<=n;i++){
    		adj[i].clear();
    	}

    	for(int i=1;i<=m;i++){
    		cin>>u[i]>>v[i]>>w[i];

    		adj[u[i]].push_back(v[i]);
    		adj[v[i]].push_back(u[i]);
    	}

    	bfs(src,n);

    	int ans = 0;
    	for(int i=1;i<=m;i++){
    		if(min(dis[u[i]], dis[v[i]]) < k){
    			ans=max(ans, w[i]);
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}
