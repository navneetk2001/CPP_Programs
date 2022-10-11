// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:
// Input:
// 	4 4
// 	0 1
// 	1 2
// 	2 3
// 	3 3
// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:
// Input:
// Output: 0
// Explanation: no cycle in the graph



//Solution Approach :- Using Topological Sort
bool isCyclic(int V, vector<int> adj[]) {
    queue<int> q;
    vector<int>in(V,0);  //to store indegree of each node
    for(int i=0;i<V;i++){
   	    for(auto x:adj[i]){
   	  	    in[x]++;         //calculate indegree of each node
   	   }
    }

    for(int i=0;i<V;i++){
    	if(in[i]==0){
    		q.push(i);    //push all nodes whose indegree is zero
    	}
    }

    int count=q.size();    //C is count of all those nodes whose indegree is zero
    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        for(auto x:adj[t]){
            in[x]--;       //decrementing inorder count of its adacent node by 1 after processing
            if(in[x]==0){
           		q.push(x);    //again push those whose inorder is zero
           		count++;      //increment count if inorder is zero
            }
	    }
    }
    if(count==V) return false;   //if all nodes have indegree zero after processing then there will be no loop 
    else return false;           //if some nodes remain whose indegree is not zero then we will have a loop
}




//Solution Approach - Using BFS
bool isCyclic(int V, vector<int> adj[]) {
   bool *visited=new bool[V];
   for(int i=0;i<V;i++)
   {
       visited[i]=0;
   }
   queue<int> k;
   k.push(0);
   visited[0]=true;
   while(k.size()!=0)
   {
       int a=k.front();
       k.pop();
       for(int i=0;i<adj[a].size();i++)
       {
           if(visited[adj[a][i]]==true)
           {
               return true;
           }
           else
           {
               k.push(adj[a][i]);
               visited[adj[a][i]]=true;
           }
       }
   }
   return true;
}