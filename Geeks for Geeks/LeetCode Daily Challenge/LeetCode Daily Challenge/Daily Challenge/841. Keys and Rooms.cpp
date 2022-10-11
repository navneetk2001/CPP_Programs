




//Solution Approach :- BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>visited(rooms.size(),false);

        int n=rooms[0].size();
        for(int i=0;i<n;i++){
            q.push(rooms[0][i]);
        }
        visited[0]=true;

        while(!q.empty()){
            int x=q.front();
            if(!visited[x]){
                int sz=rooms[x].size();

                for(int i=0;i<sz;i++){
                    if(!visited[rooms[x][i]]){
                        q.push(rooms[x][i]);
                    }
                }
                visited[x] = true;
            }
            q.pop();
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};


//Second Solution :-
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int> dfs; 
    dfs.push(0);

    unordered_set<int>seen = {0};
    
    while(!dfs.empty()) {
        int i = dfs.top(); 
        dfs.pop();

        for(int j : rooms[i]){
            if(seen.count(j) == 0){
                dfs.push(j);
                seen.insert(j);
                if(rooms.size() == seen.size()){
                	return true;
                }
            }
        }
    }
    return rooms.size() == seen.size();
}



//Third Solution :- DFS
class Solution {
public:
    void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};