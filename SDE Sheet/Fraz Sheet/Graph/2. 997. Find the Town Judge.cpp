https://leetcode.com/problems/find-the-town-judge/



//Solution Approach :- 
// Intuition:
// Consider trust as a graph, all pairs are directed edge.
// The point with in-degree - out-degree = N - 1 become the judge.

// Explanation:
// Count the degree, and check at the end.

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> count(N + 1, 0);
    for (auto& t : trust){
        count[t[0]]--, count[t[1]]++;
    }

    for (int i = 1; i <= N; ++i) {
        if (count[i] == N - 1){
        	return i;
        }
    }
    return -1;
}



//Second Solution :- 
int findJudge(int n, vector<vector<int>>& trust) {
	if(trust.empty() && n==1){        //this condition is to check if given input is empty but n==1
        return 1;
	}
	     
	vector<int> out(n+1,0);		//counts outdegree of a person or node     //outdegree means number of nodes that are trusted by given specific node 
	vector<int> in(n+1,0); 	    //counts indegree of a person or node 	   //indegree means number of nodes that trusts a given specific node
	
	for(auto edge : trust){		//loop counts indegree and outdegree
        out[edge[0]]++;
        in[edge[1]]++;
    }
	
	//if a node has outdegree==0 that means that node doesnot trust anyone and		//indegree ==n-1 that means all other nodes trusts this node except himself
	for(int i=0;i<=n;i++){
        if(out[i]==0 && in[i]==n-1){
            return i;
        }
    }

    return -1;		//if there is no such node return -1
}



//Third Solution :-  
int findJudge(int N, vector<vector<int>>& trust) {
  vector<vector<int>> knows(N + 1, vector<int>(N + 1));
  for (auto &t : trust) knows[t[0]][t[1]] = 1;
  return findCelebrity(N, knows);
}

int findCelebrity(int n, vector<vector<int>>& knows, int i = 1) {
  for (auto j = i + 1; j <= n; ++j) if (knows[i][j]) i = j;
  for (auto j = 1; j < i; ++j) if (knows[i][j]) return -1;
  for (auto j = 1; j <= n; ++j) if (i != j && !knows[j][i]) return -1;
  return i;
}