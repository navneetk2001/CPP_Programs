// Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.
// The longest path problem for a general graph is not as easy as the shortest path problem because the longest path problem doesn’t have optimal substructure property. In fact, the Longest Path problem is NP-Hard for a general graph. However, the longest path problem has a linear time solution for directed acyclic graphs. The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting. 
// We initialize distances to all vertices as minus infinite and distance to source as 0, then we find a topological sorting of the graph. Topological Sorting of a graph represents a linear ordering of the graph (See below, figure (b) is a linear representation of figure (a) ). Once we have topological order (or linear representation), we one by one process all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance of current vertex.



//Solution Approach :-
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 

vector<int> order;

void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first])
            topo(x.first,vis,g);
    }
    order.push_back(src);
}


int32_t main() {
    
    int v,e;
    cin>>v>>e;

    int src;
    cin>>src;

    vector<vector<pair<int,int> > > g(v);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,g);                    
        }                                  
    }
    
    vector<int> dist(v);
    for(int i=0;i<v;i++) dist[i] = INT_MIN;
    dist[src] = 0;
    for(int i=v-1;i>=0;i--){
        if(dist[order[i]]!=INT_MIN){
            for(auto x:g[order[i]]){
                int v = dist[x.first];
                int w = x.second;
                int u = dist[order[i]];
                if(u + w > v)
                    dist[x.first] = u + w;
            }
        }
    }
    for(int i=0;i<v;i++){
        if(i!=src and dist[i]!=INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }
    
    return 0;

}
    
//Second Solution :- 

// Following is complete algorithm for finding longest distances. 
// 1) Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite. 
// 2) Create a topological order of all vertices. 
// 3) Do following for every vertex u in topological order. 
// ………..Do following for every adjacent vertex v of u 
// ………………if (dist[v] < dist[u] + weight(u, v)) 
// ………………………dist[v] = dist[u] + weight(u, v) 


// A C++ program to find single source longest distances in a DAG
#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#define NINF INT_MIN
using namespace std;

class AdjListNode {
	int v;
	int weight;

public:
	AdjListNode(int _v, int _w)
	{
		v = _v;
		weight = _w;
	}
	int getV() { return v; }
	int getWeight() { return weight; }
};

class Graph {
	int V; // No. of vertices'
	list<AdjListNode>* adj;
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V); // Constructor
	~Graph(); // Destructor

	void addEdge(int u, int v, int weight);
	void longestPath(int s);
};

Graph::Graph(int V){ // Constructor
	this->V = V;
	adj = new list<AdjListNode>[V];
}

Graph::~Graph(){ // Destructor
	delete [] adj;
}


void Graph::addEdge(int u, int v, int weight){
	AdjListNode node(v, weight);
	adj[u].push_back(node);         // Add v to u's list
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		AdjListNode node = *i;
		if (!visited[node.getV()]){
			topologicalSortUtil(node.getV(), visited, Stack);
		}
	}

	// Push current vertex to stack which stores topological sort
	Stack.push(v);
}

// The function to find longest distances from a given vertex.
// It uses recursive topologicalSortUtil() to get topological sorting.
void Graph::longestPath(int s){
	stack<int> Stack;
	int dist[V];

	bool* visited = new bool[V];
	for (int i = 0; i < V; i++){
		visited[i] = false;
	}

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++){
		if (visited[i] == false){
			topologicalSortUtil(i, visited, Stack);
		}
	}

	// Initialize distances to all vertices as infinite and distance to source as 0
	for (int i = 0; i < V; i++){
		dist[i] = NINF;
	}
	dist[s] = 0;
	// Process vertices in topological order
	while (Stack.empty() == false) {
		int u = Stack.top();    // Get the next vertex from topological order
		Stack.pop();

		// Update distances of all adjacent vertices
		list<AdjListNode>::iterator i;
		if (dist[u] != NINF) {
			for (i = adj[u].begin(); i != adj[u].end(); ++i){
				if (dist[i->getV()] < dist[u] + i->getWeight()){
					dist[i->getV()] = dist[u] + i->getWeight();
				}
			}
		}
	}

	// Print the calculated longest distances
	for (int i = 0; i < V; i++)
		(dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
	
	delete [] visited;
}

int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with following mappings:
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are longest distances from source vertex "<< s << " \n";
	g.longestPath(s);

	return 0;
}






