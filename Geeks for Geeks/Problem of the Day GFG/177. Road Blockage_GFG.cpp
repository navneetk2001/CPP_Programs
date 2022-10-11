// There are N cities in Geekland numbered 0, 1,.., N - 1. There are (N-1) bidirectional roads, the ith road connects city Edge[i][0] and Edge[i][1]. You can consider the length of each road as 1 unit. At least one path can be found between any two cities in Geekland.
// People of Geekland love ordering from Amazon. Its warehouse is located in city 0. But there is a rebel group in the country that can block any road and disrupt deliveries. 
// Geek is a software engineer at Amazon. He wants to develop a software that discards all the cities where delivery is not possible due to road blockage. For the remaining cities, the software calculates the maximum distance an item has to travel from city 0 to the customer living in any connected city x. 
// You are given Q queries; in the ith query, the road connecting city query[i][0] and query[i][1] is blocked by the rebel group. Help Geek to find the maximum distance for each query.

// Example 1:
// Input:
// N = 5, Q = 2
// Edge[][] = {{0, 1},
//             {0, 2},
//             {1, 3},
//             {1, 4}}
// query = {{0, 1},
//          {1, 4}}
// Output:
// 1 2
// Explanation: 
// Geekland looks like:
//             0
//            / \
//          1    2
//        /   \
//      3      4
// Query 1: the road connecting (0,1) is blocked. Only people living in city 0 and 2 can place delivery orders. For city 0, distance = 0. For city 2, distance = 1. Maximum (city 0, city 1) = 1
// Query 2: The road connecting (1, 4) is blocked. Only people living in city 0,1,2 and 3 can place delivery orders.For city 0, distance = 0. For city 1, distance = 1. For city 2, distance = 1.For city 3, distance = 2. A maximum distance of 2 has to be travelled for people of city 3. 0 -> 1 -> 3

// Example 2:
// Input: N = 3, Q = 1
// Edge[][] = {{0, 1}, 
//             {0, 2}}
// query[][] = {{0, 1}}
// Output: 1
// Explanation: Geekland looks like: 
//               0
//             /   \
//            1     2



//Solution Approach :- Official GFG
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 4;
vector<int> g[MAXN];
bool vis[MAXN];
int tim;
int beg[MAXN];
int ind[MAXN];
int tour[MAXN];
int lev[MAXN];

void init(int n) {
    tim = 1;
    for (int i = 0; i <= 2 * n + 2; i++) {
        vis[i] = false;
        g[i].clear();
        beg[i] = 0;
        ind[i] = 0;
        tour[i] = 0;
        lev[i] = 0;
    }
}

//create an euler tourof the tree having the level of each element as the array element
void dfs(int s) {
    vis[s] = true;
    beg[s] = tim;
    tour[tim] = lev[s];
    tim++;

    for (auto x : g[s])
        if (!vis[x]) { // if it is unvisited 
            lev[x] = lev[s] + 1;
            dfs(x);
        }

    ind[s] = tim;
    tour[tim] = lev[s];
    tim++;
}

class Solution {
  public:
    vector<int> solve(int N, int Q, vector<vector<int> > &Edge, vector<vector<int> > &query) {
        // initialize and clear all the vector and variable
        init(N);
        
        // build graph
        for (auto it : Edge) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        tim = 1;
        dfs(0);

        vector<int> pref(tim + 1), suf(tim + 1);
        for (int i = 1; i < tim; i++) {
            pref[i] = max(pref[i - 1], tour[i]);
        }
        for (int i = tim - 1; i >= 1; i--) {
            suf[i] = max(suf[i + 1], tour[i]);
        }

        vector<int> answer(Q);
        
       // check maximum of some prefix and suffix to answer the query.
        for (int i = 0; i < Q; i++) {
            int node = query[i][0];
            if (lev[query[i][1]] > lev[query[i][0]]) node = query[i][1];

            answer[i] = max(pref[beg[node] - 1], suf[ind[node] + 1]);
        }
        return answer;
    }
};

int main(){
    int n,q; cin>>n>>q;
    vector<vector<int>> adj;
    vector<vector<int>> query;
    
    for(int i=0; i<n-1; ++i){
        vector<int> temp;
        for(int j=0; j<2; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    
    for(int i=0; i<q; ++i){
        vector<int> temp;
        for(int j=0; j<2; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        query.push_back(temp);
    }
    
   Solution obj;
   vector<int> res = obj.solve(n,q,adj, query);
   for(auto x : res)cout<<x<<" ";
   cout<<"\n";
    
}