https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1




//Solution Approach :- one of the most intresting que if we want to learn recursion & backtracking approach 
//TYM COMP- o(n^m)             //SPACE COMP- o(n)+o(n);
// in this code will be filling one color on by one in case if all the vertices can be traversed from the given set of colors then then we will print result as TRUE that all vertices can be color by m.
// In case if all the vertices cannot be be traversed by the given no of color m then we will return FALSE.

bool is_valid(bool graph[101][101], int n, vector<int> &color, int k, int i){
    for(int j=0; j<n; j++){
        if(graph[i][j] and color[j] == k){   //if my neighbour has same color then return false
            return false;
        }
    }
    return true;
}


bool solve(bool graph[101][101], int m, int n, vector<int> &color, int i){
    if(i == n){   //you assigned the color to all the nodes
        return true;
    }
    
    for(int k=0; k<m; k++){
        if(is_valid(graph, n, color, k, i)){
            color[i] = k;         //Assign the color
            
            if(solve(graph, m, n, color, i+1)){   //now color the next node
                return true;
            }
            color[i] = -1;            //backtrack
        }
    }
    
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);               //Assigning color to each node, initially each assigned with -1
    return solve(graph, m, n, color, 0);    //take starting color to be assigned as 0, :->Each assigned as from 0 to m
}





//Second Solution :-
bool issafe(bool graph[101][101], vector<int> &visited, int node, int n, int col){
    for(int i=0;i<n;i++){
    	if(col!=node && graph[i][node] && visited[i]==col){
    		return false;
    	}
    }
	return true;
}

bool color(bool graph[101][101], vector<int> &visited, int m, int n, int node){
    if(node==n){
        return true;
    }
    
    for(int i=1;i<=m;i++){
        if(issafe(graph,visited,node,n,i)){
            visited[node]=i;
            if(color(graph,visited,m,n,node+1)){
            	return true;
            }
            visited[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> visited(n,0);
    return color(graph, visited, m, n, 0);
}




//Third Solution :- Solution using DFS. Time Taken: 0.05s
int *color;
vector<int> *adj;
bool dfs(int u,int col,int m){
    bool ans=true;
    for(auto it: adj[u]){
        if(!color[it]){
            bool flag=false;
            for(int i=1;i<=m && !flag;i++){
                if(i!=col){
                    color[it]=i;
                    flag|=dfs(it,i,m);
                    color[it]=-i;
                }
            }
            if(!flag){
                ans=false;
                break;
            }
        }else if(color[it]==col){
            ans=false;
            break;
        }
    }
    // BackTracking Part
    if(!ans){
        for(auto it: adj[u])
            if(color[it]<0)
                color[it]=0;
        return false;
    }
    for(auto it: adj[u])
        if(color[it]<0)
            color[it]*=-1;
    return true;
            
}
bool graphColoring(bool graph[101][101], int m, int n) {
    if(n<=m)
        return true;
    color = new int[n+1],adj = new vector<int>[n+1];
    for(int i=0;i<n;i++){
        color[i+1]=0;
        for(int j=i;j<n;j++)
            if(graph[i][j])
                adj[i+1].push_back(j+1),adj[j+1].push_back(i+1);
    }
    bool ans = true;
    for(int i=1;i<=n && ans;i++)
        if(!color[i]){
            color[i]=1;
            ans&=dfs(i,1,m);
        }
    delete [] color,adj;
    return ans;
}