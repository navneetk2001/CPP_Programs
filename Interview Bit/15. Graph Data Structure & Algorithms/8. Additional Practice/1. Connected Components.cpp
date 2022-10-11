https://www.interviewbit.com/problems/connected-components/





//Solution Approach :-
#include <bits/stdc++.h>
void dfs(int vertex, vector<int> adj[], vector<bool> &vis){
    vis[vertex] = true;
    for(int child : adj[vertex]){
        if(!vis[child]){
            dfs(child, adj, vis);
        }
    }
}

int Solution::solve(int n, vector<vector<int>> &B) {
    vector<int> adj[n+1];
    for(auto it : B){
        int u =it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(n+1);
    int ct = 0;  
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        dfs(i, adj, vis);
        ct++;
    }
    return ct;
}




//Second Solution :-
int find(int parent[],int x){
    if(x!=parent[x])
    {
        parent[x] = find(parent,parent[x]);
    }
    return parent[x];
}
int Solution::solve(int A, vector<vector<int>> &B) {
    int parent[A+1], count=0;
    
    for(int i=1;i<=A;i++){
        parent[i]=i;
    }

    for(int i=0;i<B.size();i++){
        int x = find(parent, B[i][0]);
        int y = find(parent, B[i][1]);
        if(x == y){
        	count++;
        }
        parent[x]=y;
    }
    int c=A+count-B.size();
    return c;
}






//Third Solution :-
const int N =100005;
vector<int> adj[N], visited(N);

void clean(int n){
    for(int i=0; i<=n; ++i){
        adj[i].clear();
        visited[i]=0;
    }
}

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSRec(int s){
    visited[s] = 1;
    for(int u: adj[s]){
        if(visited[u]==0) DFSRec(u);
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    clean(A);
    for(int i = 0; i <B.size(); i++){
        addEdge(B[i][0], B[i][1]);
    }
    int count = 0;
    for(int i = 1; i<=A; i++){
        if(visited[i]==0){
            DFSRec(i);
            count++;
        }
    }
    return count;
}
