// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Example 1:
// Input:  3 4
// 		   3 0
// 		   1 0
// 		   2 0
// Output: 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented
// your function correctly, then output would be 1 for all test cases.
// One possible Topological order for the graph is 3, 2, 1, 0.

// Example 2:
// Input:
// Output: 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented
// your function correctly, then output would be 1 for all test cases.
// One possible Topological order for the graph is 5, 4, 2, 1, 3, 0.



//Solution Approach :-
//1. Add all vertices to map
//2. count indegree of all nodes
//3. find the nodes with indegree zero and add them to queue
//4. now traverse till queue is not empty and when indegree of node becomes zero add it to your answer vector

class Solution{
	public:
	vector<int> topoSort(int v, vector<int> adj[]){
		vector<int>in(v,0);   //to store indegree of each node
		vector<int>ans;
		queue<int>q;

		for(int i=0;i<v;i++){
		    for(auto x:adj[i]){
		  		in[x]++;     //calculate indegree of each node
		    }
		}

		for(int i=0;i<v;i++){ 
			if(in[i]==0){ 
		  		q.push(i);        //push all nodes whose indegree is zero
			}
		}

		while(!q.empty()){
			int t=q.front();
			q.pop();
			
			ans.push_back(t);
			for(auto x:adj[t]){
	            in[x]--;             //decrementing inorder count of its adacent node by 1 after processing
	            if(in[x]==0){
	           		q.push(x);       //again push those whose inorder is zero
	            }
		    }
		 }
		return ans;
	}
};



//Second Solution :-
//We use a temporary stack. Don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack.

void dfsTopoSort(int u, vector<int> adj[], vector<int> &visited, stack<int> &st){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v])
            dfsTopoSort(v, adj, visited, st);
    }
    st.push(u);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfsTopoSort(i, adj, visited, st);
        }
    }
    
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}


//Third Solution :-
class Solution {
	public:
	
	vector<int> visited, result;
	void dfs(int u, vector<int> adj[]){
	    visited[u] = true;
	    for (int v : adj[u]) {
	        if (visited[v] == false){
	            dfs(v, adj);
	        }
	    }
	   result.push_back(u);
	}

	vector<int> topoSort(int n, vector<int> adj[]){
	    visited.resize(n);
	    visited.assign(n, 0);
	    for (int u = 0; u < n; u++) {
	        if (visited[u] == false){
	            dfs(u, adj);
	        }
	    }
	    reverse(result.begin(), result.end());
	    return result;
	}
};