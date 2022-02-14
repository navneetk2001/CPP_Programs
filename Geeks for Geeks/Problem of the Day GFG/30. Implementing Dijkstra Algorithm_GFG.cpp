// Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.

// Example 1:
// Input:
//      0
//   9 /
//    1
// S = 0
// Output:
// 0 9
// Explanation:
// The source vertex is 0. Hence, the shortest 
// distance of node 0 is 0 and the shortest 
// distance from node 9 is 9 - 0 = 9.
 
// Example 2:
// Input:
//      0
//   1 / \6
//    1   2
// S = 2
// Output:
// 4 3 0
// Explanation:
// For nodes 2 to 0, we can follow the path-
// 2-1-0. This has a distance of 1+3 = 4,
// whereas the path 2-0 has a distance of 6. So,
// the Shortest path from 2 to 0 is 4.
// The other distances are pretty straight-forward.




//We will be using priority queue :- and use pair <dist, node>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>dis(v,INT_MAX);
        dis[s]=0;  //source distance as 0
        priority_queue<pair<int,int>>pq;    //using pair <dist, node>
        pq.push({0,s});   //pushed starting node
        while(!pq.empty()){
        	int node=pq.top().second;
        	pq.pop();
        	for(int i=0;i<adj[node].size();i++){
        		int res=adj[node][i][0];
        		int wt=adj[node][i][1];
        		if(wt+dis[node] < dis[res]){
        			dis[res]=dis[node]+wt;
        			pq.push({-1*dis[res], res});
        		}
        	}
        }
        return dis;
    }
};