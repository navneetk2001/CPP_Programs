https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/#

// In Geekland, there are a total of N cities numbered from 0 to (N-1). These are connected by M bidirectional roads. The ith road connects two distinct cities Edge[i][0] and Edge[i][1].
// However, the country is at war and is divided into political groups. The group that each city supports is depicted by a color. For the ith city, col[i] contains that color where col is a string containing alphabets only.
// The king of Geekland wants to restore peace. He knows that if people of three given colors unify without any other groups' interference they will be powerful enough to stop the war.
// You are given Q queries; in the ith query, you are given 3 distinct colours query[i][0], query[i][1], and query[i][2] . For each query find whether there exists a path in Geekland such that only the city with these three colors comes in the way.
// Note: Ensure that each of the 3 colors should appear at least once to form a powerful alliance. It is possible that the given query has some color that is not present in the entire Geekland, in that case the answer should be "NO".

// Example 1:
// Input:
// N = 6, M = 7, 
// Q = 3
// col = "abdebc"
// Edge[][] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 2}, {2, 4}, {4,5}}
// query = {"abc", "aec", "azc"}
// Output:
// YES
// NO
// NO
// Explanation: 
// Query 1: "abc"
// there exists a path 0 -> 1 -> 4 -> 5 which only consists of colours a, b and c.
// Query 2: "aec"
// There is no such path which will contain only a,e,c colours. 
// Query 3: "azc" 
// There is no such path which will contain only a,z,c colours. 






//Solution Approach :- 
class Solution {
public:
	void dfs(int node, vector<int> adj[], int vis[], string &col, set<char> &st){
		vis[node] = 1;
		for(auto it:adj[node]){
			if(!vis[it] && col[it] == col[node]){
				dfs(it, adj, vis, col, st);
			}
			else if(col[it] != col[node]){
				st.insert(col[it]);  //store the adjacent nodes but don't call dfs for it
			}
		}
	}

    vector<string> solve(int N, int M, int Q, string col, vector<vector<int>> &Edge, vector<string> &query) {
        int dp[26][26][26] = {0};
        vector<int> adj[N];
        for(auto it : Edge){
        	adj[it[0]].push_back(it[1]);
        	adj[it[1]].push_back(it[0]);
        }

        int vis[N] = {0};

        for(int i=0; i<N; i++){
        	if(!vis[i]){
        		set<char> st;
        		dfs(i, adj, vis, col, st);

        		for(auto it1 : st){
        			for(auto it2 : st){
        				dp[col[i] - 'a'][it1-'a'][it2-'a'] = 1;
        			}
        		}
        	}
        }

        vector<string> ans;
        for(auto it : query){
        	char a = it[0] - 'a';
        	char b = it[1] - 'a';
        	char c = it[2] - 'a';
        	if(dp[a][b][c] || dp[a][c][b] || dp[b][a][c] || dp[b][c][a] || dp[c][a][b] || dp[c][b][a]){
        		ans.push_back("YES");
        	}
        	else{
        		ans.push_back("NO");
        	}
        }
        return ans;
    }
};




