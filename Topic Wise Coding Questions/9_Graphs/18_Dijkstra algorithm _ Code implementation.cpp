#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

int selectMinVertex(vector<int>& value,vector<bool>& processed)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V])
{
	int parent[V];		//Stores Shortest Path Structure
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	vector<bool> processed(V,false);	//TRUE->Vertex is processed

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,processed);
		processed[U] = true;	//Include new Vertex in shortest Path Graph

		//Relax adjacent vertices (not yet included in shortest path graph)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX
			&& (value[U]+graph[U][j] < value[j]))
			{
				value[j] = value[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)










// Dijkstra Algorithm Code using priority queue....
#include<bits/stdc++.h>
using namespace std;
#define INF 99999

// function to create an edge
void addEdge(vector<pair<int, int>> graph[], int u, int v, int w){
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void dijkstras(vector<pair<int, int>> graph[], int src, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // use priority queue as min heap
    
    vector<int>dist(V, INF);    // distance vector
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    // normal BFS traversal
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        // traverse for the neighbors of u
        for(auto x : graph[u]){
            // x = {v, wt}
            int v = x.first;
            int wt = x.second;
            if(dist[v]>dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<"Vertex   Distance from src\n";
    for(int i=0; i<V; i++)
        cout<<i<<"\t"<<dist[i]<<endl;
}

int main(){
    int V = 9;
    vector<pair<int, int>> graph[V];
    addEdge(graph ,0, 1, 4); 
    addEdge(graph ,0, 7, 8); 
    addEdge(graph ,1, 2, 8); 
    addEdge(graph ,1, 7, 11); 
    addEdge(graph ,2, 3, 7); 
    addEdge(graph ,2, 8, 2); 
    addEdge(graph ,2, 5, 4); 
    addEdge(graph ,3, 4, 9); 
    addEdge(graph ,3, 5, 14); 
    addEdge(graph ,4, 5, 10); 
    addEdge(graph ,5, 6, 2); 
    addEdge(graph ,6, 7, 1); 
    addEdge(graph ,6, 8, 6); 
    addEdge(graph ,7, 8, 7); 

    dijkstras(graph, 0, 9);
}
