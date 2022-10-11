// The minions are very elitist in nature. If minion x admires minion y, then y thinks too highly of himself and does not admire x back. Also, if x admires y, x also admires everyone that y admires.
// All the minions are going to be present at the Villain Con. They want to make sure that they do not dress in the same color as someone who admires them. 
// There are N minions and M relations between them. The relations are given in a 2D array mat. Each relation is given in xi , yi format where yi admires xi. Find the minimum number of different colours that the minions will be dressing in. 

// Example 1:
// Input: 
// N = 5, M = 6
// mat = {{1, 3}, 
//        {2, 3}, 
//        {3, 4}, 
//        {1, 4}, 
//        {2, 5}, 
//        {3, 5}}
// Output: 3
// Explaination: If we assign red colour to 1 and 2, green colour to 3, and blue colour to 4 and 5, then every minion will have different coloured dresses from the one who admires them.

// Example 2:
// Input:
// N = 3, M = 2
// mat = {{1,3},{2,3}}
// Output: 2
// Explanation: If we assign red colour to 1 and 2, and green colour to 3, then the condition is satisfied.




//Solution Approach :-    //APPROACH 1
class Solution{
public:
    int dp[100001];
    int helper(list<int>* adj, int node, int V){
        if(dp[node]!=0){
            return dp[node];
        }
        int res=1;
        for(auto nei: adj[node]){
            res=max(res,1+helper(adj,nei,V));
        }
        return dp[node]=res;
    }
    int minColour(int N, int M, vector<int> mat[]) {
        list<int> adj[N+1];
        for(int i=0;i<M;i++){
            adj[mat[i][1]].push_back(mat[i][0]);
        }
        int res=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            res=max(res,helper(adj,i,N));
        }
        return res;
    }
}; 



/*-----------------------------------------------------------------------*/
//Second Solution :-  Topological Sort
class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]){
        list<int> adj[N+1];
        
        vector<int> gettingAdmiration(N+1,0);
        for(int i=0;i<M;i++){
            adj[mat[i][1]].push_back(mat[i][0]);
            gettingAdmiration[mat[i][0]]++;
        }
        int color=0;
        queue<int>q;
        for(int i=1;i<=N;i++){
            if(gettingAdmiration[i]==0){  //NO ADMIRATION RECIEVED
                q.push(i);
            }
        }
        if(q.empty()){
            return 0;
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int f=q.front();
                q.pop();
                for(auto nei: adj[f]){
                    indegree[nei]--;
                    if(indegree[nei]==0){
                        q.push(nei);
                    }
                }
            }
            color++; 
        }
        return color;
    }
};



//Third Solution :-
int minColour(int N, int M, vector<int> mat[]) {
    vector<int> adj[N+1];
    vector<int> indegree(N+1, 0);
    for(int i = 0; i < M; i++) {
        int v = mat[i][1];
        int u = mat[i][0];
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while(q.empty() == false) {
        count++;
        while(q.empty() == false) {
            int curr = q.front();
            q.pop();
            for(auto it: adj[curr]) {
                indegree[it]--;
            }
            indegree[curr] = -1;
        }
        for(int i = 1; i <= N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }        
    }

    return count;    
}