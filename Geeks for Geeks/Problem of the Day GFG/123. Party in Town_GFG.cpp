// Geek town has N Houses numbered from 1 to N. They are connected with each other via N-1 bidirectional roads and an adjacency list adj is used to represent the connections. To host the optimal party, you need to identify the house from which the distance to the farthest house is minimum. Find this distance.

// Example 1:
// Input: 
// N = 4
// adj = {{2},{1,3,4},{2},{2}} 
// Output: 1
// Explaination: Party should take place at house number 2. Maximum distance from house number 2 is 1.

// Example 2:
// Input:
// N = 4
// adj = {{2},{1,3},{2,4},{3}}
// Output: 2
// Explanation: Party should take place at house number 2 or 3. So, the minimum distance between the farthest house and the party house is 2.




//Solution Approach :- using DFS 
/*here we will maintain a mx to find the maximum distance to all the houses using dfs and take the minimu,m of all thes maximums.*/

class Solution{
public:
	void dfs(int v,int p,vector<int>&dist,vector<vector<int>>&adj){
	    for(auto to:adj[v]){
	        if(to==p)continue;
	        dist[to]=dist[v]+1;
	        dfs(to,v,dist,adj);
	    }
	}

    int partyHouse(int N, vector<vector<int>> &adj){
        int mn=1e9+7;
        
	    for(int i=1;i<=N;i++){
	        vector<int>dist(N+1);
	        
	        dfs(i,0,dist,adj);
	        int mx=0;
	        for(int i=1;i<=N;i++){
	            mx=max(mx,dist[i]);
	        }
	        mn=min(mn,mx);
	    }
	    return mn;
    }
};



//Second Solution :- BFS
int partyHouse(int N, vector<vector<int>> &adj){
    int mx=INT_MAX;
    for(int i=1;i<=N;i++){
        vector<int>vis(N+1,0);
        queue<int>q;
        q.push(i);
        vector<int>dis(N+1,0);
 
        while(q.size()>0){
            int p=q.front();
            q.pop();
            vis[p]=1;
            for(auto &j:adj[p]){
                if(vis[j]==0){
                    dis[j]=dis[p]+1;
                    q.push(j);
                }
            }
              
        }

        int mx1=INT_MIN;
        for(int j=1;j<=N;j++){
            mx1=max(mx1,dis[j]);
        }
        mx=min(mx1,mx);
    }
    return mx;
}



//Third Solution :-
class Solution{
public:
    void trav(int &root,vector<bool> &vis,vector<vector<int>> &adj,vector<int> &distance){
        for(int &nextRoot:adj[root]){
            if((distance[root]+1)<distance[nextRoot] || vis[nextRoot]==false){
                distance[nextRoot]=1+distance[root];
                vis[nextRoot]=true;
                trav(nextRoot,vis,adj,distance);
            }
        }
    }

    int partyHouse(int N, vector<vector<int>> &adj){
        int res = INT_MAX;
        vector<int> distance(N+1,INT_MAX);
        
        for(int i=1;i<=N;i++){
            vector<bool> visited(N+1,false);
            distance[i]=0;
            distance[0]=0;
            visited[i] = true;
            trav(i,visited,adj,distance);
            res = min(res,*max_element(distance.begin(),distance.end()));
        }

        return res;
    }
};




//Fourth Solution :-
class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        int mi = INT_MAX;
        for(int i=1; i<=N; i++){
            vector<bool> vis(N+1, 0);
            int cnt = 0;
            
            queue<int> q;
            q.push(i);
            
            while(!q.empty())
            {
                int n = q.size();
                bool f = 0;
                while(n--){
                    int x = q.front();
                    q.pop();
                    if(vis[x]) continue;
                    
                    vis[x] = 1;
                    
                    for(auto y: adj[x]){
                        if(!vis[y]){
                            f = 1;
                            q.push(y);
                        }
                    }
                }
                if(!f) break;
                ++cnt;
            }
            mi = min(mi, cnt);
        }
        return mi;     
    }
};


