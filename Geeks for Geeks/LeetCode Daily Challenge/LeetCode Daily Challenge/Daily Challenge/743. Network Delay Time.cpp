//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.


// Example 1:
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

// Example 2:
// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1

// Example 3:
// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1



//First Solution :- Using Dijkstra
typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii> > g(n + 1);
        for (const auto& t : times) {
            g[t[0]].emplace_back(t[1], t[2]);
        }
        
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
		vector<bool> vis(n + 1, false);
        
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.emplace(0, k);
        int u, v, w;
        
        while (!pq.empty()) {
            u = pq.top().second; 
            pq.pop();
			
            if (vis[u]) {
                continue;
            }
            
			vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};




//Second Solution :- Using Bellman Ford Algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};



//Third Solution :- Using BFS
class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
        return (a.second < b.second); 
    } 

    void dfsutil(int src , vector<vector<pair<int,int>>>& adj, vector<bool>& visited ,vector <int>& receiving_time , int t){
        receiving_time[src] = t;
        visited[src] = true;
        
        for(int i =0 ; i<adj[src].size() ; ++i){
            int nei = adj[src][i].first ; 
            int time = adj[src][i].second;
            
            if(!visited[nei]){
                 dfsutil(nei , adj ,visited , receiving_time , t+time);
            }
            else if(visited[nei] && receiving_time[nei] > t+time ){
                dfsutil(nei , adj, visited , receiving_time , t+time);
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <int> receiving_time (N+1 , INT_MAX );
        receiving_time[0] = 0;
        
        vector<vector<pair<int,int>>> adj(N+1);
        vector <bool> visited(N+1 , false);
        visited[0]=true;
        
        for(auto& time : times){
            adj[time[0]].push_back(make_pair(time[1] , time[2]));
        }
        
        for(int i =1 ; i< N+1 ; ++i){
            sort(adj[i].begin() , adj[i].end() , sortbysec);
        }
        
        dfsutil(K , adj ,visited ,receiving_time , 0);
         
        for(int i =1 ; i<visited.size() ; ++i){
            if(!visited[i]){
                return -1;
            }
        }
         
        return *max_element(receiving_time.begin() , receiving_time.end());
    }
};


