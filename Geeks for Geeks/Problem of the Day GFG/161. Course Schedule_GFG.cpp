// There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
// Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.


// Example 1:
// Input: n = 2, m = 1
// prerequisites = {{1, 0}}
// Output: 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented
// your function correctly, then output would be 1 for all test cases.
// One possible order is [0, 1].

// Example 2:
// Input: n = 4, m = 4
// prerequisites = {{1, 0},
//                  {2, 0},
//                  {3, 1},
//                  {3, 2}}
// Output: 1
// Explanation:
// There are a total of 4 tasks to pick. To pick task 3 you should have finished
// both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0.
// So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3].
// Returning any of these order will result in a Output of 1.



//Solution Approach :-
vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
    vector<int> adj[n];
    for(int i = 0; i < m; i++) {
        int u = pre[i][1];
        int v = pre[i][0];
        
        adj[u].push_back(v);
    }
    
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++)
        for(int it: adj[i])
            indegree[it]++;
    
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while(q.empty() == false) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto it: adj[curr]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    
    if(ans.size() == n) return ans;
    else return {};
}



// Solution :- BFS
//Algorithm:
// If course x is necessary for course y, then have a directed arrow from x to y.
// Course having 0 in-degree can be done without any prerequisites. Push to queue.
// For every element in queue ( these will have 0 in-degree ), add to answer and whichever course's prerequisite they belonged to, decrease their indegree by 1.
// If the new in degree is 0, that means now that particular course can be done and its pre-req courses are done. Push to Queue.


vector<int> findOrder(int n, int m, vector<vector<int>> pr){
    queue<int> q;
    vector<vector<int>> allows(n);  //for adjacency list
    vector<int> indeg(n), ans;
    
    for(auto &p : pr){
        allows[p[1]].push_back(p[0]); //making adjacency list
        indeg[p[0]]++;                //calculating indegree
    }
    
    for(int i=0 ; i<n ; i++){
        if(indeg[i] == 0){   //if indegree is zero push it in queue
            q.push(i);     
        }
    }
        
    while(q.size()){
        int curr_c = q.front() ;
        q.pop() ;
        
        for(auto &neighbor : allows[curr_c]){
            indeg[neighbor]-- ;       //traversing the neighbour and recducing indegree by 1
            if(indeg[neighbor] == 0)
                q.push(neighbor) ;
        }
        ans.push_back(curr_c) ;
    }
    
    if(ans.size() != n){
        return vector<int>() ;
    }
    else{
        return ans ;
    }
}




//Second Solution :- 
//This question might be difficult for beginners, but simply its just asking to check if a directed graph cycle exists, and if it exits just return {}, and if it does not just return the topological sort of the graph.
class Solution{
 public:
   stack<int> topo;
   bool DFSRec(list<int>* adj, int s, bool visited[], bool recSt[]){
       visited[s] = true;
       recSt[s] = true;
       for(int u: adj[s]){
           if(visited[u] == false){
               if(DFSRec(adj, u, visited, recSt) == true){
                   return true;
               }
           }
           else if(recSt[u] == true){
               return true;
           }
       }
       recSt[s]=false;
       topo.push(s);
       return false;
   }

   vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
       list<int> adj[n];
       for(auto prereq: prerequisites){
           adj[prereq[1]].push_back(prereq[0]);
       }
       
       bool visited[n]={0}, recSt[n]={0};
       for(int i=0;i<n;i++){
           if(visited[i]==false){
               if(DFSRec(adj,i,visited,recSt)==true){
                   return {};
               }
           }
       }

       vector<int> res;
       while(topo.empty()==false){
           res.push_back(topo.top());
           topo.pop();
       }
       return res;
   }
};


