https://leetcode.com/problems/network-delay-time/





//Solution Approach :- Dijktra Algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            pair<int,int> t=pq.top();
            pq.pop();

            for(pair<int,int> it:adj[t.second]){
                if(dist[it.first]>t.first+it.second){
                    dist[it.first]=t.first+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        int res=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            res=max(res,dist[i]);
        }
		return res;
	}
};




//Second Solution :- Bellman Ford ALgorithm
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
        for (int i = 1; i <= N; i++){
            maxwait = max(maxwait, dist[i]);
        }
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};



//Third Solution :- BFS
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dist(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k]=0;

        while(!q.empty())
        {
            int t=q.front();
            q.pop();

            for(pair<int,int> it:adj[t]){
                if(dist[it.first] > dist[t] + it.second){
                    dist[it.first] = dist[t] + it.second;
                    q.push(it.first);
                }
            }
        }

        int res=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            res=max(res,dist[i]);
        }
        return res;
    }
};
