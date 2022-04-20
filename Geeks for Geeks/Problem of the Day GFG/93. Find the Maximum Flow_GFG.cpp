// Given a graph with N vertices numbered 1 to N and M edges, The task is to find the max flow from vertex 1 to vertex N.
// In a flow network, the maximum flow of a path can't exceed the flow-capacity of an edge in the path.

// Example 1:
// Input:
// N = 5, M =  4
// Edges[]= { {1, 2, 1} , {3, 2, 2}, {4, 2, 3}, {2, 5, 5} }
// Output: 1 
// Explanation: 
// 1 - 2 - 3
//    / \
//   4   5 
// 1 unit can flow from 1 -> 2 - >5 
 

// Example 2:
// Input:
// N = 4 , M = 4
// Edges[] = { {1, 2, 8}, {1, 3, 10}, {4, 2, 2}, {3, 4, 3} }
// Output: 5 
// Explanation:
//   1 - 2 
//   |   |
//   3 - 4
// 3 unit can flow from 1 -> 3 -> 4
// 2 unit can flow from 1 -> 2 -> 4
// Total max flow from 1 to N = 3+2=5



//Solution Approach :-
int bfs(int source,int sink,vector<vector<int>> &g,int n,vector<int> &parent)
{
    queue<pair<int,int>> q;
    vector<bool> vis(n,0);
    q.push({source, INT_MAX});
    vis[source]=1;
    
    while(!q.empty())
    {
        source=q.front().first;
        int cap=q.front().second;
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(g[source][i] && !vis[i])
            {
                parent[i]=source;
                
                if(i==sink)
                    return min(cap,g[source][i]);
                    
                q.push({i,min(cap,g[source][i])});
                vis[i]=1;
            }
        }
    }
    return 0;
}
    
int ford_fulkerson(int source,int sink,vector<vector<int>> &g,int n)
{
    int flow=0;
    vector<int> parent(n,-1);
    
    int min_cap;
    while(min_cap=bfs(source,sink,g,n,parent))
    {
        flow+=min_cap;
        
        int u,v=sink;
        while(v!=source)
        {
            u=parent[v];
            g[u][v]-=min_cap;
            g[v][u]+=min_cap;
            v=u;
        }
    }
    return flow;
}

int solve(int n,int m,vector<vector<int>> e)
{
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    int i;
    
    for(i=0;i<m;i++)
    {
        g[e[i][0]][e[i][1]]+=e[i][2];
        g[e[i][1]][e[i][0]]+=e[i][2];
    }
    
    return ford_fulkerson(1,n,g,n+1);
}

