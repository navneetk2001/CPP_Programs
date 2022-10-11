



//Solution Approach :-
class Solution {
public:
    void dfs(int i, vector<int> list[] , vector<int> &vis){
        vis[i]=1;
        for(auto child : list[i]){
            if(vis[child]==0){
                dfs(child, list, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> list[V];
        int n= adj.size();
        int m= adj[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i!=j && adj[i][j]==1){
                    list[i].push_back(j);
                }
            }
        }

        int ans=0;
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i, list, vis);
            }
        }
        return ans;
    }
};




//Second Solution :- Union_Find
int numProvinces(vector<vector<int>> adj, int V) {
    vector<int>par(V),rank(V);
    for(int i=0;i<V;i++){
        par[i]=i;
        rank[i]=1;
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 || adj[j][i]==1){
                uni(i,j,par,rank);
            }
        }
    }
    unordered_set<int>us;
    for(auto i:par){
        us.insert(find(i,par));
    }
    return us.size();
}

int find(int a,vector<int>&par){
    int cur =a ;
    while(cur!=par[cur]){
        par[cur]=par[par[cur]];
        cur=par[cur];
    }
    return cur;
}

void uni(int a,int b,vector<int>&par , vector<int>&rank){
    int para = find(a,par);
    int parb= find(b,par);
    if(para==parb)return ;
    if(rank[parb]>rank[para])swap(para,parb);
    par[parb]=para;
    rank[para]+=parb;
}  




//Third Solution :- BFS
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int province=0;

        for(int i=0; i<V; i++){
            if(adj[i][i] == 1){
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    
                    adj[v][v] = -1;
                    for(int j = 0; j < V ; j++){
                        if(adj[v][j] == 1 && adj[j][j] != -1){
                            q.push(j);
                        }
                    }
                }
                province++;
            }
        }
        return province;
    }
}; 



//Fourth Solution :-
class Solution {
public:
   void dfs(vector<vector<int>> &adj, int V, int st,vector<bool> &vis){
        vis[st]=true;
        for(int i=0;i<V;i++){
            if(adj[st][i]==1){
                if(!vis[i]){
                    dfs(adj,V,i,vis);
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V,false);
        int res=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,V,i,vis);
                res++;
            }
        }
        return res;
    }
};


