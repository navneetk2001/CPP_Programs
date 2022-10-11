// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
// A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.
// A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. Note that it is possible to color a cycle graph with even cycle using two colors. For example, see the following graph. 
// It is not possible to color a cycle graph with odd cycle using two colors. 


// Example 1:
// Input: 
	    // 3 2
		// 0 1
		// 1 2
// Output: 1
// Explanation: The given graph can be colored in two colors so, it is a bipartite graph.

// Example 2:
// Input:
// Output: 0
// Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 





//Algorithm :-
// Algorithm to check if a graph is Bipartite: 
// One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem. 

// Following is a simple algorithm to find out whether a given graph is Bipartite or not using Breadth First Search (BFS). 
// 	1. Assign RED color to the source vertex (putting into set U). 
// 	2. Color all the neighbors with BLUE color (putting into set V). 
// 	3. Color all neighbor’s neighbor with RED color (putting into set U). 
// 	4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
// 	5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 




//Solution Approach :-
class Solution{
public:
    bool bipartitate_check(int src,vector<int> adj[], vector<int> &color ){
        if(color[src] == -1){  // If the color of src == -1 color it    
        	color[src] =1;
        }
        
        // Travel through it's neighbours
        for(auto it: adj[src]){
            if(color[it] == -1){   // If the color == -1 of it's nbrs then color
                color[it] = 1- color[src];
                if(!bipartitate_check(it, adj, color)){    // Call the dfs again
                	return false;
                }
            }
            else if(color[it] == color[src]){    // If the color of src and nbr is same return false
            	return false;
            }
        }
        
        return true;     // Return true if different color
    }

	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> color(v, -1);   // Declare the color array
	    
	    for(int i=0;i<v;i++){    // Travel for each components
	        if(color[i] == -1){    // If the color[i] is -1 then call check bipartiate graph function 
	            if(!bipartitate_check(i,adj,color)) {
	            	return false;
	            }
	        }
	    }
	    return true;
	}
};



//Second Solution :-
class Solution{
public:
    bool bipartitate_check(int src,vector<int> adj[], vector<int> &color )
    {
        queue<int> q;  // Make a queue
        q.push(src); // Push the src node
        
        color[src] =1;    // Color the src node with 1
        
        while(!q.empty()){    // Travel till queue not empty
            int node= q.front();
            q.pop();
            
            for(auto it: adj[node]) {   // Explore the nodes of the front node
                if(color[it] == -1){    // If the nbrs color == -1 then color them with the different color
                    color[it] = 1- color[node];
                    q.push(it);
                }
                
                else if(color[it] == color[node]) {     // If the scr node and curr node same color return false
                	return false;
                }
            }
        }
        return true;
    }


	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> color(v, -1);     // Declare the color array
	    
	    for(int i=0;i<v;i++){    // Travel for each components
	        if(color[i] == -1) {      // If the color[i] is -1 then call check bipartiate graph function 
	            if(!bipartitate_check(i,adj,color)){ 
	            	return false;
	            }
	        }
	    }
	    return true;
	}
};



//Third Solution :- If Odd cycle length then not a bipartite graph else if even cycle length then a bipartite graph

//      Col :- color ,    par:- parent
int f=0;
void dfs(int src, int par, int col, vector<vector<int>>&g, vector<int>&vis){
	vis[src]=col;

	for(auto x: g[src]){
        if(vis[x] == -1){   // If the color == -1 of it's nbrs then color
            dfs(x,src,3-col,g,vis);
        }
        else if(x!=par and col == vis[x]){    // If the color of src and nbr is same return false
        	f=1;
        	break;
        }
    }
}

int main(){
    f=0;
	dfs(1,0,1,g,vis);
	if(f){
		cout<<"Not Bipartite";
	}
	else{
		cout<<"Bipartite";
	}
}


//Fourth Solution :- 
bool isBipartite(int V, vector<int>graph[]){
    unordered_map<int,int> color;
    for(int j=0;j<V;j++){
        if(color[j]!=0){
        	continue;
        }
        
        queue<int> q;
        q.push(j);
        color[j]=1;

        while(q.size()){
            int curr = q.front();
            q.pop();
            for(auto x:graph[curr]){
                if(color[x]==0){
                    if(color[curr]==1){
                    	color[x]=2;
                    }
                    else{ 
                    	color[x]=1;
                    }
                    q.push(x);
                    continue;
                }
                if(color[x]==color[curr]){
                	return false;
                }
            }
        }
    }
    return true;
}