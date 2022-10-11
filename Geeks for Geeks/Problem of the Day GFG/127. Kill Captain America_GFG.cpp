// Captain America is hiding from Thanos in a maze full of N rooms connected by M gates.
// The maze is designed in such a way that each room leads to another room via gates. All connecting gates are unidirectional. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
// Help Thanos find the number of rooms in which Captain America can hide. 

// Example 1:
// Input: N = 5 and M = 5
// V = [[1, 2], [2, 3], [3, 4], [4, 3], [5, 4]]
// Output: 2
// Explanation: We can look closesly after forming graph than captain america only can hide in a room 3 and 4 because they are the only room which have gates through them. So, answer is 2.

// Example 2:
// Input: N = 2, M = 1
// V = [[1, 2]]
// Output: 1




//Solution Approach :-
// The answer is the number of nodes(rooms) in a cycle. Specifically, the number of non-root nodes(can be reached) interconnected. But the exception is if there exists only one terminal node, the answer will be 1. We can find the answer by removing the connections from the root nodes in a loop until no root nodes exists in the graph. The remaining nodes will be the answer.
// Approach:
// 	1. Calculate the number of unique terminal nodes and if it is 1 return 1
// 	2. Create an array(let's say d) with the degree of each node (no. of edges pointing to that node)
// 	3. Make a queue and push nodes with degree 0 to the queue (all root nodes)
// 	4. Repeat the following steps while the queue is not empty.
// 		1. Store the front of the queue (let's say i) and pop the front.
// 		2. Iterate through all the edges of i with iterator let's say j
// 			1. Decrease the degree j by 1 (that means one connection of the root node is removed).
// 			2. if the j becomes a root node (degree of j is 0) then push j to the queue
// 	5. Return total no. of nodes - the number of nodes removed from the graph


int captainAmerica(int N, int M, vector<vector<int>> &V){
   	int n = N;
   	int d[N] = {};
   	vector<int> adj[N];
   	for(int i=0;i<M;i++){
       int u = V[i][0]-1, v = V[i][1]-1;
       adj[u].push_back(v);
   	}
   	queue<int> Q;
   	for (auto a : adj) {
       for (auto i : a) {
           d[i]++;
       }
   	}
   	int terminal = -1;
   	bool exists = true;
   	for (int i = 0; i < N; i++) {
       if (adj[i].empty()) {
           if(terminal == -1) terminal = i;
           else if(terminal != i) exists = false;
       }
       if (!d[i]) Q.push(i);
    }
    if (exists && terminal != -1) return 1;
    while(!Q.empty()) {
       n--;
       int v = Q.front();
       Q.pop();
        for (auto i : adj[v]) {
           d[i]--;
           if (!d[i]) Q.push(i);
        }
    }
    return n;
} 



//Second Solution :-
#define vi vector<int>
void make_graph(vector<vi> &V,vi* adj,vi* trans_adj){
    for(int i=0;i<V.size()-1;i++){
        adj[V[i][0]].push_back(V[i][1]);
        trans_adj[V[i][1]].push_back(V[i][0]);
    }
    
    return;
}

int outdeg(unordered_set<int> st,vi* adj){
    int out=0;
    for(auto i:st){
        for(int child:adj[i]){
            if(st.find(child)==st.end()) out++;
        }
    }
    
    return out;
}

void topo_dfs(int node,vi* adj,vi &vis,stack<int> &st){
    vis[node]=true;
    
    for(auto i:adj[node]){
        if(!vis[i]){
            topo_dfs(i,adj,vis,st);
        }
    }
    
    st.push(node);
    return;
}

void dfs(int node,vi* adj,vi &vis,unordered_set<int> &sett){
    vis[node]=true;
    sett.insert(node);
    
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i,adj,vis,sett);
        }
    }
    
    return;
}

int captainAmerica(int N, int M, vector<vector<int>> &V){
    // Code Here
    int out_0=0;
    int max_size=INT_MIN;
    
    vi adj[N+1];
    vi vis(N+1,false);
    stack<int> st;
    vi trans[N+1];
    
    make_graph(V,adj,trans);
    
    for(int i=1;i<N+1;i++){
        if(!vis[i]){
            topo_dfs(i,adj,vis,st);
        }
    }
    
    for(int i=0;i<N+1;i++){
        vis[i]=false;
    }
    
    
    while(!st.empty()){
        unordered_set<int> sett;
        if(!vis[st.top()]){
            dfs(st.top(),trans,vis,sett);
            
            if(outdeg(sett,adj)==0){
                int size=sett.size();
                //cout<<size;
                max_size=max(max_size,size);
                out_0++;
            }
        }
        st.pop();
    }
    
    if(out_0>1) return 0;
    return max_size;
}


//Third Solution :-
void dfs(int v,vector<int>& vis,vector<int> adj[]){
    vis[v] = true;
    for(auto& u:adj[v]){
        if(!vis[u]){
            dfs(u,vis,adj);
        }
    }
}

int captainAmerica(int N, int M, vector<vector<int>> &V){
    vector<int> adj[N+1],vis(N+1);
    for(int i=0;i<M;i++){
        int u = V[i][0],v = V[i][1];
        adj[v].push_back(u);
    }
    
    int mother = -1;
    
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            mother = i;
            dfs(i,vis,adj);
        }
    }
    
    fill(vis.begin(),vis.end(),0);
    dfs(mother,vis,adj);
    
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            return 0;
        }
    }
    
    for(int i=1;i<=N;i++){
        adj[i].clear();
    }
    for(int i=0;i<M;i++){
        int u = V[i][0],v = V[i][1];
        adj[u].push_back(v);
    }
    
    queue<int> q;
    q.push(mother);
    
    fill(vis.begin(),vis.end(),0);
    
    vis[mother] = true;
    
    int ans = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        ans++;
        for(auto& u:adj[v]){
            if(!vis[u]){
                q.push(u);
                vis[u] = true;
            }
        }
    }
    
    return ans;
}

