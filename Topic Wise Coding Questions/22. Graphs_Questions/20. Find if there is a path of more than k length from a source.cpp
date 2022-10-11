// Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex such that the distance from source to that vertex is atleast ‘k’ length.
 
// Example:
// Input  : Source s = 0, k = 58
// Output : True
// There exists a simple path 0 -> 7 -> 1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4 Which has a total distance of 60 km whichis more than 58.

// Input  : Source s = 0, k = 62
// Output : False

// In the above graph, the longest simple
// path has distance 61 (0 -> 7 -> 1-> 2 -> 3 -> 4 -> 5-> 6 -> 8, so output should be false for any input greater than 61.




//Solution Approach :-
// One important thing to note is, simply doing BFS or DFS and picking the longest edge at every step would not work. The reason is, a shorter edge can produce longer path due to higher weight edges connected through it.
// The idea is to use Backtracking. We start from given source, explore all paths from current vertex. We keep track of current distance from source. If distance becomes more than k, we return true. If a path doesn’t produces more than k distance, we backtrack.
// How do we make sure that the path is simple and we don’t loop in a cycle? The idea is to keep track of current path vertices in an array. Whenever we add a vertex to path, we check if it already exists or not in current path. If it exists, we ignore the edge.


// Program to find if there is a simple path with weight more than k
#include<bits/stdc++.h>
using namespace std;


bool solve(int src, int k,vector<pair<int,int>>g[], vector<bool> &vis){
	vis[src] = true;
	if (k <= 0){         // If k is 0 or negative, return true;
		return true;
	}
    
    for(auto x:g[src]){
    	int u=x.first;
    	int w=x.second;

    	if(vis[u]==true){
    		continue;
    	}
    	if(w>=k){
    		return true;
    	}
    	if(solve(u,k-w,g,vis)){
    		return true;
    	}
    }

    vis[src] = false;
	return false;
}

int main(){
	int v,e;
	cin>>v>>e;

	int k;
	cin>>k;
    
    vector<pair<int,int>>g[v+1];
    for(int i=0;i<e;i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	g[x].push_back({y,w});
    	g[y].push_back({x,w});
    }
    vector<bool>vis(v+1,false);
    cout<<solve(1,k,g,vis);
    
	return 0;
}

