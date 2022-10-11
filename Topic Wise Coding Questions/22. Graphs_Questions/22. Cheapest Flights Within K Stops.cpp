// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Example 2:
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

// Example 3:
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.




//Solution Approach :- C++ dp code :- Bellman Ford Algorithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        for(int i = 0; i <= k+1; i++){
            dp[i][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= k+1; i++){
            for(auto &f: flights){     //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX){
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
                }
            }
        }
        
        return (dp[k+1][dst] == INT_MAX)? -1: dp[k+1][dst];
    }
};



//Second Solution :-
// 1. put all flights into a prices map -> Map<Integer, Map<Integer, Integer>>
// 	// source city : Map<destination city, price>
// 2. init a min pq -> each object in pq should be an int array with
// 	top[0] = current total price
// 	top[1] = current source city
// 	top[2] = max distance to destination allowed
// 	pq compares each object by total price so far
// 3. add original source city to pq with price = 0 & distance allowed = k + 1
// 4. while exists cities to explore
// 	--> get min object then remove it from pq
// 	--> get current total price, current source city & distance to destination allowed from min object
// 	--> if current source == destination (obviously distance from original source to current source [which is destination] is less than k) -> return current total price
// 	else find (from prices map) all connected flights that fly from current source + calculate new price, new current source & new distance + add them to pq
// 5. If no city left to explore and no flight that fits criteria found till now, return -1


typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>vp(n);
        for(const auto&f:flights){ 
        	vp[f[0]].emplace_back(f[1],f[2]);
        }

        priority_queue<ti,vector<ti>,greater<ti>>pq;
        pq.emplace(0,src,K+1);

        while(!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();
            
            if(u==dst)  return cost;
            if(!stops)  continue;
            for(auto to:vp[u]){
                auto [v,w] = to;
                pq.emplace(cost+w,v,stops-1);
            }
        }
        return -1;
    }
};



//Third Solution :-  Gives TLE
void solve(vector<vector<int>>& adj, vector<vector<int>>& cost,int src,int dst, int k, int &fare,int totCost,vector<bool>&visited)
{
    if(k<-1)
        return;
    if(src==dst)
    {
        fare=min(fare,totCost);
        return;
    }
    visited[src]=true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(!visited[adj[src][i]] && (totCost+cost[src][adj[src][i]] <= fare))
        {
            solve(adj,cost,adj[src][i],dst,k-1,fare,totCost+cost[src][adj[src][i]],visited);
        }
    }
    visited[src]=false;
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        
        vector<bool> visited(n+1,false);
        int fare=INT_MAX;
        solve(adj,cost,src,dst,k,fare,0,visited);
        
        if(fare==INT_MAX){
            return -1;
        }
        return fare;
    }
};