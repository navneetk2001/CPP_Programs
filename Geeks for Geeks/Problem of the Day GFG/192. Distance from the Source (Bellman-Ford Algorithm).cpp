// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.
 

// Example 1:
// Input:
// E = [[0,1,9]]
// S = 0
// Output:  0 9
// Explanation: Shortest distance of all nodes from source is printed.

// Example 2:
// Input:
// E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
// S = 2
// Output: 1 6 0
// Explanation:
// For nodes 2 to 0, we can follow the path-2-0. This has a distance of 1.
// For nodes 2 to 1, we cam follow the path-2-0-1, which has a distance of 1+5 = 6,




//Solution Approach :-
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);
        dist[S]=0;
        
        for(int i=0; i<V-1; i++){
            for(auto it : adj){
                if(dist[it[0]] + it[2] < dist[it[1]]){
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        return dist;
    }
};



//Second Solution :-
vector<int> bellman_ford(int V, vector<vector<int>> adj, int S) {
	vector<int> dist(V,1e8);
	vector<int> visited(V,0);
	dist[S]=0;

	for(int i=0; i<V-1; i++){
       	for(auto it : adj){
           	int u = it[0];       //source
           	int v = it[1];       //dest
           	int w = it[2];       //weight
           	
           	if(dist[v]> (dist[u]+w)){
           		dist[v]=dist[u]+w;
           	}
       	}
   	}
   	return dist;
}



//Third Solution :-
vector <int> bellman_ford(int V, vector<vector<int>> adj, int src) {
    vector<int> dist(V,1e8);
    
    dist[src] = 0;

    for(int i=0; i<V-1; i++){
       	for (int j = 0; j < adj.size(); j++){
        	int u = adj[j][0];  
        	int v = adj[j][1];
        	int w = adj[j][2];
        	if(dist[v] > dist[u]+w){
            	dist[v] = dist[u]+w;
        	}
	    }
    }
    return dist;
}




//Fourth Solution :- Dijkstra's Algorithm
vector<int> bellman_ford(int V, vector<vector<int>> a, int S) {
    vector<int> dist(V, 100000000);
    vector<vector<pair<int,int>>> adj(V);
    
    for(vector<int> &v : a){
        adj[v[0]].push_back({v[1], v[2]});
    }

    dist[S] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});

    while(!pq.empty()){
        int d = pq.top().first, node = pq.top().second;
        pq.pop();

        for(auto child_pair : adj[node]){
            int newD = d + child_pair.second;
            if(newD < dist[child_pair.first]){
                dist[child_pair.first] = newD;
                pq.push({newD, child_pair.first});
            }
        }
    }
    return dist;
}



//Fifth Solution :-
//I optimized the standard Bellman Ford technique. Time taken is 0.47s for algorithms in the comments, but mine takes 0.06s ! 
//Even though worst case Time Complexity is same for both , i.e O(E*V), but mine doesn't check all edges. This comes at the cost of Space. 

vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
    vector<int> ans(v,1e8) ;
    vector<vector<pair<int,int>> > adj(v) ;
    for(auto &edge: edges){
        adj[edge[0]].push_back({edge[1],edge[2]}) ;
    }
    
    ans[s] = 0 ;
    vector<bool> vis(v,false) ;
    for(int i=0 ; i<v-1 ; i++){
        int mv = -1, mvv = INT_MAX ;
        for(int j=0 ; j<v ; j++){
            if(vis[j] == false && mvv > ans[j]){
                mvv = ans[j] ;
                mv = j ;
            }
        }
        vis[mv]=true ;
        for(auto &p: adj[mv]){
            ans[p.first] = min(ans[p.first],ans[mv]+p.second) ;
        }
    }
    return ans ;
}