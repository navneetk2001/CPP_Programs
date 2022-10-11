// Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.
// You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.
// Return the maximum number of edges you can remove.


// Input 1:
//  A = 6
//  B = [ [1, 2]
//        [1, 3]
//        [1, 4]
//        [3, 5]
//        [4, 6]
//      ]
// Output 1: 2
// Explanation 1:
//       1
//     / | \
//    2  3  4
//       |   \
//       5    6
//  Maximum number of edges we can remove is 2, i.e (1, 3) and (1, 4)

// Input 2:
//  A = 2
//  B = [ [1, 2] ]
// Output 2: 0
// Explanation 2: We can't remove any edges.


//Hint :-
//As we need connected components that have even number of vertices so when we get one component we can remove the edge that connects it to the remaining tree and we will be left with a tree with even number of vertices which will be the same problem but of smaller size.
//Try running Depth First Search (DFS) on the given tree to calculate the total number of such component.

//Solution Approach :- 
// As we need connected components that have even number of vertices so when we get one component we can remove the edge that connects it to the remaining tree and we will be left with a tree with even number of vertices which will be the same problem but of smaller size, we have to repeat this algorithm until the remaining tree cannot be decomposed further in the above manner.
// We will traverse the tree using DFS which will return the number of vertices in the component of which the current node is the root.
// If a node gets an even number of vertices from one of its children then the edge from that node to its child will be removed and result will be increased by one and if the returned number is odd then we will add it to the number of vertices that the component will have if the current node is the root of it.
// Such that we can calculate the maximum number of nodes we can remove.


//First Solution :-
// Algorithm: 
	// do dfs and keep track of nodes in subtree (countSubtreeNodes)
	// if countSubtreeNodes is even then we can detach that subtree
	// else we keep that in tree and add the value nodes in subtree to the total nodes

int Solution::solve(int V, vector<vector<int>> &edges) {
	vector<int> *adjList = new vector<int>[V+1];   // create an adjacency list and insert all the edges
	for(vector<int>edge: edges) {
		int u = edge[0], v = edge[1];
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
		
	vector<bool> ok(V+1, false);
	int total = 0;    // keep track of total edges removed, passed as a reference
	
	void dfs(vector<int>*&, vector<bool>&, int, int&);
	dfs(adjList, ok, 1, total);
	
	return total;   // return max total edges removed
}

int dfs(vector<int> *&adjList, vector<bool> &ok, int u, int &total) {
	ok[u] = true;            // mark the node as visited
	int nodesInTree = 1;     // total nodes in current tree considering u as a root :-> 1, considering the node itself
	
	for(int v: adjList[u]) {
		if(!ok[v]) {       // if neighbour(v) is not visited
			int nodesInSubtree = dfs(adjList, ok, v, total);    // find nodes in that subtree (tree starting from v)
			if(nodesInSubtree%2 == 0){    // if even then we can detach that subtree, means we can remove the edge
				++total;
			}
			else{     // else that nodes of subtree should remain in current tree where root is u
				nodesInTree += nodesInSubtree;
			}
		}	
	}
	return nodesInTree;
}


//Second Solution :-
int Solution::solve(int A, vector<vector<int>> &B) 
{
    if(A<=3){
        return 0;
    }
   
    int parent[A+1]={0};     //to store parent of each node i
    parent[1]=-1;
    
    int edges[A+1]={0};        //to store number of edges in the subtree with root i
    for(int i=0;i<B.size();i++)
    {
        parent[B[i][1]]=B[i][0];
        edges[B[i][0]]++;
    }
    for(int i=A;i>1;i--){
        edges[parent[i]]+=edges[i];
    }
    int ans=0;
    
    for(int i=2;i<=A;i++)
    {
        if(edges[i]%2==1)
            ans++;
    }
    return ans;
}


//Third Solution :- 
const int maxN = 1e5 + 5;
vector g[maxN];
int res = 0;

// Utility method to do DFS of the graph and count edge removal
int dfs(int u, int par) {
    int currComponentNode = 0;

    //  iterate over all neighbor of node u
    for (auto v: g[u]) {
        if(v == par){
            continue;
        }
        // Count the number of nodes in a subtree
        int subtreeNodeCount = dfs(v, u);

        // if returned node count is even, disconnect the subtree and increase result by one.
        if (subtreeNodeCount % 2 == 0)
            res++;

        //  else add subtree nodes in current component
        else
            currComponentNode += subtreeNodeCount;
    }

    // number of nodes in current component and one for current node
    return (currComponentNode + 1);
}

int Solution::solve(int A, vector > &B) {
    assert(A%2 == 0 && A <= 1e5);
    for(int i = 1; i <= A; i++){
        g[i].clear();
    }
    for(int i = 0; i < B.size(); i++){
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);
    }
    res = 0;
    // calling the dfs from node-1 and making its parent as -1
    dfs(1, 0);
    return res;
}

