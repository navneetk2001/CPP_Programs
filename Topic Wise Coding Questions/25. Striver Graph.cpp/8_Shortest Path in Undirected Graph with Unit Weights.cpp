



//Here it is given as undirected graph with weight of each edge as 1 or yoou can take no weight
//We need to find the shortest distance to each node from source node


//First Solution :- BFS
void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++){
		dist[i] = INT_MAX; 
	}

	queue<int> q;
	dist[src] = 0;
	q.push(src); 

	while(!q.empty()){ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	
	for(int i = 0;i<N;i++){
		cout << dist[i] << " "; 
	}
}



 