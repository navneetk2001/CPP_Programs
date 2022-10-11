https://www.interviewbit.com/problems/path-in-directed-graph/



//Solution Approach :- BFS
bool bfs(int v, vector<int> adj[], int dest, queue<int> &q, vector<int> &vis){
    vis[v] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto it : adj[curr]){
            if(!vis[it]){
                vis[it] = 1;
                if(it == dest){
                    return true;
                }
                q.push(it);
            }
        }        
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(auto it : B){
        adj[it[0]].push_back(it[1]);
    }
    
    vector<int> vis(A+1,0);
    queue<int> q;
    q.push(1);
    
    if(bfs(1, adj, A, q, vis)){
        return true;
    }
    else{
        return false;
    }
}




//Second Solution :- DFS
void dfs(int src , vector<int> adj[], vector<int> &vis){
    vis[src] = 1;
    for(auto it: adj[src]){
        if(vis[it] == 0){
            dfs(it, adj, vis);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(auto it : B){
        adj[it[0]].push_back(it[1]);
    }
    
    vector<int> vis(A+1,0);
    
    dfs(1, adj, vis);
    return vis[A];
}




//Third Solution :-
void findPath(vector<vector<int>> &graph, vector<int>&visited,int &ans, int i,int A)
{
    if(ans)
        return;
    if(i == A)
    {   
        ans = 1;
        return;
    }
    
    if(visited[i] == 1)
        return;
    
    visited[i] = 1;
    for(auto j : graph[i])
    {
        if(!visited[j])
            findPath(graph,visited,ans,j,A);
    }
    return;
}

int Solution::solve(int A, vector<vector<int>> &B) 
{
    vector<int> visited(A+1, 0);
    vector<vector<int>> graph(A+1);
    
    for(int i =0;i<B.size();i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
    }
    int ans = 0;
    findPath(graph,visited,ans,1,A);
    return ans;
}



//Fourth Solution :-
int Solution::solve(int A, vector<vector<int> > &B) {
	map<int,vector<int>> mp;
	int n = B.size();
	vector<int> visited(A+1,0);
	
	for(int i=0; i<n; i++){
	    mp[B[i][0]].push_back(B[i][1]);
	}

	stack<int> st;
	st.push(1);
	while(!st.empty()){
	    int v = st.top();
	    if(v==A){
	        return 1;
	    }
	    st.pop();
	    visited[v] = 1;
	    if(mp.find(v)!=mp.end()){
	        for(int j=0; j<mp[v].size();j++){
	            if(visited[mp[v][j]]==0){
	                st.push(mp[v][j]);
	            }
	        }
	    }
	}
	return 0;
}