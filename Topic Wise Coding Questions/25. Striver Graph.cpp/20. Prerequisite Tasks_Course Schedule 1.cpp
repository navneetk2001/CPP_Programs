https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks




//Solution Approach :- BFS (TOPO SORT)
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    vector<int> in(N,0);
		vector<int>ans;
		queue<int>q;

		for(int i=0;i<N;i++){
		    for(auto x:adj[i])
		  		in[x]++;
		}

		for(int i=0;i<N;i++){ 
			if(in[i]==0)
		  		q.push(i);
		}

		while(!q.empty()){
			int t=q.front();
			q.pop();
			ans.push_back(t);
			for(auto x:adj[t]){
	            in[x]--;
	            if(in[x]==0){
	           		q.push(x);
	            }
		    }
		}
		
		if(ans.size() == N){
		    return true;
		}
		return false;
	}
};




//Solution Approach :- DFS (Detect cycle in a directed graph)
