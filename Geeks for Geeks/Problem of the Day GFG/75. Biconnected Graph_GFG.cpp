// Given a graph with n vertices, e edges and an array arr[] denoting the edges connected to each other, check whether it is Biconnected or not.
// Note: The given graph is Undirected.

// Example 1:
// Input: n = 2, e = 1
// arr = {0, 1}
// Output: 1
// Explanation:
//        0
//       /
//      1
// The above graph is Biconnected.

// Example 2:
// Input: n = 3, e = 2
// arr = {0, 1, 1, 2}
// Output: 0
// Explanation:
//        0
//       /
//      1
//       \
//        2
// The above graph is not Biconnected.
 



//Solution Approach :-
// I think here biconnected means biconnected wrt to edges ,.i.e 2-edge 
// connected ,if you remove all edges of a vertex , you will definitely get 
// 1 additional disconnected component , so you check the minimum outdegree 
// of all nodes , if for any case you get 1 or 0 ,it's connectivity is 1 or 0 respectively 
// and not 2 ,hence return false.  

int biGraph(int arr[], int n, int e) {
    if(n==2&&e==1)
        return true;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<2*e;i+=2){
        adj[arr[i]].push_back(arr[i+1]);
        adj[arr[i+1]].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()<2)
            return false;
    }
    return true;
}


//Second Solution :-
//For a graph to be biconnected, they shoulld be connected and
//they shouldn't have any articulation point  :- i.e. if we remove any edge the graph should be one

// Simple Tarjan's Algorithm+Connected Parts check
// Using Tarjan's Algorithm Check if there exists any vertex that if removed will serve as an articulation point, if there is return false.
// Check the number of connected Components, if we say that all vertex can be reached from a single source, all the vertices should fall under one connected component and if they do not return false;

class Solution {
  public:
    int time;
    void DFS(int v, list<int>* adj, vector<bool> &vis, vector<int> &disc , vector<int> &low, vector<int> &parent, vector<bool> &AP){
        int children=0;
        vis[v]=true;
        disc[v]=time;
        low[v]=time;
        time++;
        for(auto nei: adj[v]){
            if(vis[nei]==false){
                parent[nei]=v;
                children++;
                DFS(nei,adj,vis,disc,low,parent,AP);
                low[v]=min(low[v],low[nei]);
                if(parent[v]==-1 && children>1){
                    AP[v]=true;
                }
                if(parent[v]!=-1 && low[nei]>=disc[v]){
                    AP[v]=true;
                } 
            }
            else if(nei!=parent[v]){
                low[v]=min(low[v],disc[nei]);
            }
        }
    }
    int biGraph(int arr[], int V, int e) {
        time=0;
        list<int> adj[V];
        for(int i=0;i<2*e;i+=2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        vector<bool> vis(V,false);
        vector<int> disc(V,0);
        vector<int> low(V,0);
        vector<int> parent(V,-1);
        vector<bool> AP(V,false);
        int connectedParts=0;
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                connectedParts++;
                DFS(i,adj,vis,disc,low,parent,AP);
            }
        }
        for(int i=0;i<V;i++){
            if(AP[i]==true){
                return false;
            }
        }
        return connectedParts==1;
    }
};



//Third Solution :-
void dfs(int u,  unordered_map<int,vector<int>>&m, vector<bool>&visited)
 {
     visited[u]=true;
     for(auto v:m[u])
     {
         if(!visited[v])dfs(v,m,visited);
     }
 }
 
int biGraph(int arr[], int n, int e) {
   //from every node we check whether we can reach every other node if not return 0
   unordered_map<int,vector<int>>m;
   for(int i=0;i<2*e;i+=2)
   {
       m[arr[i]].push_back(arr[i+1]);
       m[arr[i+1]].push_back(arr[i]);
   }
   
   for(int i=0;i<n;i++)
   {
       vector<bool>visited(n,false);
       visited[i]=true;
       dfs((i+1)%n,m,visited);
       for(auto i:visited)if(!i)return 0;
   }
   return 1;
}


