//Two Clique Problem (Check if Graph can be divided in two Cliques)

//A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other. Given a Graph, find if it can be divided into two Cliques.

// Examples:
// Input : G[][] =   {{0, 1, 1, 0, 0},
//                   {1, 0, 1, 1, 0},
//                   {1, 1, 0, 0, 0},
//                   {0, 1, 0, 0, 1},
//                   {0, 0, 0, 1, 0}};
// Output : Yes



//Approach :-
// This problem looks tricky at first, but has a simple and interesting solution. A graph can be divided in two cliques if its complement graph is Bipartitite. So below are two steps to find if graph can be divided in two Cliques or not. 
// 	Find the complement of Graph. Below is the complement graph is above shown graph. In complement, all original edges are removed. And the vertices which did not have an edge between them, now have an edge connecting them. 
// 	Return true if complement is Bipartite, else false. The above shown graph is Bipartite. Checking whether a Graph is Bipartite or no is discussed here.

// How does this work? 
// If complement is Bipartite, then graph can be divided into two sets U and V such that there is no edge connecting to vertices of same set. This means in original graph, these sets U and V are completely connected. Hence original graph could be divided in two Cliques.


//Solution Approach :-
// C++ program to find out whether a given graph can be converted to two Cliques or not.
#include <bits/stdc++.h>
using namespace std;

const int V = 5;

// This function returns true if subgraph reachable from src is Bipartite or not.
bool isBipartiteUtil(int G[][V], int src, int colorArr[]){
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex numbers and enqueue source vertex for BFS traversal
	queue <int> q;
	q.push(src);

	// Run while there are vertices in queue (Similar to BFS)
	while (!q.empty())
	{
		// Dequeue a vertex from queue
		int u = q.front();
		q.pop();

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v)
		{
			// An edge from u to v exists and destination v is not colored
			if (G[u][v] && colorArr[v] == -1)
			{
				// Assign alternate color to this adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can be colored with alternate color
	return true;
}

// Returns true if a Graph G[][] is Bipartite or not. Note that G may not be connected.
bool isBipartite(int G[][V])
{
	// Create a color array to store colors assigned to all vertices. Vertex number is used as index in
	// this array. The value '-1' of colorArr[i] is used to indicate that no color is assigned to
	// vertex 'i'. The value 1 is used to indicate first color is assigned and value 0 indicates second color is assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// One by one check all not yet colored vertices.
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}

// Returns true if G can be divided into
// two Cliques, else false.
bool canBeDividedinTwoCliques(int G[][V])
{
	// Find complement of G[][]
	// All values are complemented except diagonal ones
	int GC[V][V];
	for (int i=0; i<V; i++)
		for (int j=0; j<V; j++)
			GC[i][j] = (i != j)? !G[i][j] : 0;

	// Return true if complement is Bipartite
	// else false.
	return isBipartite(GC);
}

// Driver program to test above function
int main()
{
	int G[][V] = {{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};

	canBeDividedinTwoCliques(G) ? cout << "Yes" :
								cout << "No";
	return 0;
}





//Second Solution :-
int f=0;
void bipartite(int src, int par, int col, vector<int>&color, vector<int> g[]){
	vis[src]=col;

	for(auto x: g[src]){
        if(vis[x] == -1){   // If the color == -1 of it's nbrs then color
            bipartite(x,src,3-col,g,vis);
        }
        else if(x!=par and col == vis[x]){    // If the color of src and nbr is same return false
        	f=1;
        	break;
        }
    }
}

int main(){
	int v,e;
	cin>>v>>e;
	vector<int>g[v];
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}

	vector<int>reverse[v];   //reverse of graph -> adjacency list
    vector<int>dummy(v,0);
    for(int i=0;i<v;i++){
    	dummy[i]=1;
    	for(auto x:g[i]){
    		dummy[x]=1;
    	}

    	for(int j=0;j<v;j++){
    		if(dummy[j]==0){
    			reverse[i].push_back(j);
    			reverse[j].push_back(i);
    		}
    	}
    	dummy.clear();
    }

    vector<int>color(v,0);
 
	bipartite(0,0,1,color,reverse);
	if(!f){
		cout<<"Two Clique";
	}
	else{
		cout<<"Not Possible";
	}
}




