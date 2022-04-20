// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.

// Example 1:
// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,-3}}
// Output: 1
// Explanation: The graph contains negative weight cycle as 0->1->2->0 with weight -1,-2,-3.

// Example 2:
// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,3}}
// Output: 0
// Explanation: The graph does not contain any negative weight cycle.




//Approach :-
// using bellman ford algorithm :- For negative weight cycle
/* if after n-1 iterations still there is some relaxation happens in 
the nth iteration then that graph will definitely have negative weight cycle*/


//Solution Approach :-
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n,INT_MAX);
	    dis[0]=0;
	    int i,j;
	    
	    for(i=0;i<n-1;i++){
	        for(auto e:edges){
	            int u=e[0],v=e[1],d=e[2];
	            
	            if(dis[u]!=INT_MAX && dis[u]+d<dis[v]){
	                dis[v]=dis[u]+d;
	            }
	        }
	    }
	    
	    for(auto e:edges){     //detection for negative weight cycle 
	        int u=e[0],v=e[1],d=e[2];
	        if(dis[u]!=INT_MAX && dis[u]+d<dis[v]){
	            return 1;
	        }
	    }
	    
	    return 0;
	}
};


//Second Solution :-
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int>dist(n,1000000007);
    dist[0]=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(auto e:edges){
            int u=e[0];
            int v=e[1],
            w=e[2];
            if(dist[u]+w<dist[v]){
            	dist[v]=dist[u]+w;
            	flag=1;
            }
        }
        if(i==n-1&&flag)
        	return 1;
    }
    return 0;
}



//Third Solution :-
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> dis(n,1e6);
    dis[0]=0;
    for(int i=1;i<n;i++){
        for(auto &p:edges){
            if(dis[p[0]]+p[2]<dis[p[1]]){
                dis[p[1]]=p[2]+dis[p[0]];
            }
        }
    }
    for(auto &p:edges){
        if(dis[p[0]]+p[2]<dis[p[1]]){ 
        	return 1;
        }
    }
    return 0;
}


//Fourth Solution :- BFS
class Solution{	
public:
	void makeGraph(vector<vector<int>>& edges, vector<vector<int>> adj[]){
    	for(auto vec: edges){
        	adj[vec[0]].push_back({vec[1], vec[2]});
    	}
	}

	int bfs(int nd, int n, vector<vector<int>> adj[]){
    	queue<pair<int,int>> q;
    	q.push({nd, 0});
    	vector<bool> vis(n, false);
    	while(!q.empty()){
        	int node = q.front().first, dist = q.front().second; q.pop();
        	vis[node] = true;
        	for(auto vec: adj[node]){
            	int nodes = vec[0], d = vec[1];
            	if(!vis[nodes]){
                	q.push({nodes, dist+d});
            	}
            	else{
                	if(dist+d < 0)  return 1;
            	}
        	}
    	}
    	return 0;
	}

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    	vector<vector<int>> adj[n];
    	makeGraph(edges, adj);
    	for(int i=0;i<n;i++){
        	if(bfs(i, n, adj) == 1) return 1;
    	}
    	return 0;
	}
};