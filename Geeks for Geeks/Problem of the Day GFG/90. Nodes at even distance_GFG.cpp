// Given a connected acyclic graph with n nodes and n-1 edges, count the pair of nodes that are at even distance(number of edges) from each other.

// Example 1:
// Input:
// n = 3
// graph = {{}, {2}, {1, 3}, {2}}
// Output: 1
// Explaination: Here there are three pairs {1,2},{1,3} and {2,3} and only {1,3} has even distance between them.
// i.e           1
//              /
//             2
//            /
//           3

// Example 2:
// Input:
// n = 5
// graph = {{}, {2,4}, {1,3}, {2}, {1,5}, {4}}
// Output: 4
// Explaination: There are four pairs {1,3},{1,5},{2,4} and {3,5} which has even distance.



//Solution Approach :- simple dfs :-
void dfs(vector<int>graph[], int node, int dist[], bool vis[], int c){
	if(vis[node]){
		return;
	}

	vis[node]=1;
	dist[node]=c;
	for(auto e:graph[node]){
		if(!vis[e]){
			dfs(graph,e,dist,vis,c+1);
		}
	}
}


class Solution{
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        bool vis[n+1]={false};
        int dist[n+1]={0};
        dfs(graph,1,dist,vis,0);
        int even=0, odd=0;
        for(int i=1;i<=n;i++){
        	if(dist[i]%2==0){
        		even++;
        	}
        	else{
        		odd++;
        	}
        }
        return odd*(odd-1) + even*(even-1);
    }
};




//Second Solution :- Simple BFS
int countOfNodes(vector<int> graph[], int n)
{
    vector<bool>visited(n+1, 0);
    queue<int>q;
    int red=0,black=0;
    q.push(1);
    visited[1]=true;
    int level=0;

    while(!q.empty())
    {
        int sz=q.size();
        if(level%2==0)black+=sz;
        else red+=sz;
        while(sz--){
            int node=q.front();
            q.pop();
            for(int i=0; i<graph[node].size(); i++)
            {
                if(!visited[graph[node][i]])
                {
                    q.push(graph[node][i]);
                    visited[graph[node][i]]=true;
                }
            }
        }
        level++;
    }
    return ((red*(red-1))/2)+((black*(black-1))/2);
}






//Third Solution :- DP
//marking the even and odd level using 0 and 1 respectively and counting the no. of valid pairs after completion of dfs
class Solution{
    void dfs(int s , vector<int>graph[] , vector<int> &dp , int par , int d){
        dp[d]++;
        for(int i = 0 ; i < graph[s].size() ; i++){
            if(graph[s][i] != par){
                dfs(graph[s][i] , graph , dp, s , 1 - d);
            }
        }
       
    }
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        // code here
        vector<int>dp(2 , 0);
        dfs(1 , graph , dp , -1 , 0);
        return ((dp[0] * (dp[0] - 1)) + (dp[1] * (dp[1] - 1))) / 2;
        
   
    }
};


