//Bipartite Graph :- If a graph has odd length cycle, then it is not a bipartite graph
//But, if it doesn't have an odd length cycle, then it will be a bipartite graph.(It doesn't necessarily mean that it should have an even length cycle)


//First Solution :- DFS
class Solution {
public:
    bool bipartiteDfs(int node, int col, vector<int> adj[], int color[]) {
        color[node] = col;
    
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                if(bipartiteDfs(it, !col, adj, color) == false) {  //if the adjacent node is not yet colored then you will give the opposite color of the node
                    return false; 
                }
            } 
            else if(color[it] == col) {    //is the adjacent guy hving the same color, then someone did color it before on the other path
                return false; 
            }
        }
        return true; 
    }
    

    bool isBipartite(int n, vector<int>adj[]){
        int color[n];
        memset(color, -1, sizeof color);
    
        for(int i = 0; i < n; i++) {    //check for all components of graph
            if(color[i] == -1) {
                if(!bipartiteDfs(i, 0, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};





//Second Solution :- BFS
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int> q;
    q.push(src); 

    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {                  //if the adjacent node is not yet colored then you will give the opposite color of the node
                color[it] = 1 - color[node];       //assigning opposite color to its adjacent node
                q.push(it);                        //now push it in the queue
            } 
            else if(color[it] == color[node]) {   //is the adjacent guy having the same color, then someone did color it before on the other path
                return false; 
            }
        }
    }
    return true; 
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color);

    for(int i = 0; i < n; i++) {    //check for all components of graph
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}




//Third Solution  :- DFS
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {  //if the adjacent node is not yet colored then you will give the opposite color of the node
                return false; 
            }
        } 
        else if(color[it] == color[node]) {    //is the adjacent guy hving the same color, then someone did color it before on the other path
            return false; 
        }
    }
    return true; 
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 

    for(int i = 0;i<n;i++) {     //check for all components of graph
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
