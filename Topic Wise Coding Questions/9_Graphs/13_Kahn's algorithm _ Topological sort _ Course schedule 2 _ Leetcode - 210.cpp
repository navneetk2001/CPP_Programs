vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
	int n=prerequisites.size();
	vector<vector<int>>adj(numCourses);
	vector<int>indegree(numCourses,0);  //store indegree of eack node

	//Make adjacency list
	for(int i=0;i<n;i++){
		adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
		indegree[prerequisites[i][0]]+=1;
	}

	//Kahn's algorithm
	vector<int>ans;
	if(KahnsAlgo(adj,numCourses,indegree,ans))
		return ans;

	vector<int>empty;
	return empty;
}


bool KahnsAlgo(vector<vector<int>>& adj, int n, vector<int>& indegree, vector<int>& ans){
	//Step-2 :- Take a queue and push all vertices with indegree=0
	queue<int>q;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i]==0)
		{
			q.push[i];
		}
	}

	//Step-3: Process all nodes with indegree=0 and keep decrementing other node's indegree while processing
	int count =0;
	while(!q.empty){  //Keep a count of no of processed nodes (for cycle detection in graph)
		int curr=q.front();
		q.pop();

		//Decrement the indegree of all the adjacent vertices
		for(auto a: adj[curr]){
			indegree[a]-=1;
			if(indegree[a]==0){
				q.push(a);
			}
		}
		ans.push_back(curr);  //Push current node (forms topological ordering)
		count+=1;   //keep count of no of processed vertices
	}
	if(count!=n){ //No of processed nodes!= No of nodes
		return false; //Graph is not a DAG
	}
	return true;
}