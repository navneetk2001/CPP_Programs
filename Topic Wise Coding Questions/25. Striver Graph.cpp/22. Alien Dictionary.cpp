https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary




//Solution Approach :- BFS + Topo SOrt
//Only need to make an adjacency list and then perform topo sort

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] ==0) q.push(i);
	    }
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);	        //node is in topo so, we'll remove it from indegree.

	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return topo;
	}
	
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        //create an adjacency list using given words
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int ptr =0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        
        //now perform topo sort
        vector<int> topo = topoSort(K, adj);

        //store answer in a string
        string ans = "";
        for(auto it : topo){
            ans += char(it + 'a');
        }
        return ans;
    }
};