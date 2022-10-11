https://leetcode.com/problems/evaluate-division/




//Solution Approach :-  
class Solution {
public:
	map<string, vector<pair<string, double>>> mp;

	void dfs(string s, string d, set<string> &vis, double &ans, double temp){
        if(vis.find(s) != vis.end()){
        	return;
        }
        else{
	        vis.insert(s);
	        if(s == d){
	        	ans = temp;
	        	return;
	        }
	        else{
	        	for(auto it : mp[s]){
	        		dfs(it.first, d, vis, ans, temp * it.second);
	        	}
	        }
	    }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> res;
        for(auto q: queries){
            string p1 = q[0];
            string p2 = q[1];
            set<string> vis;
            double ans = -1.0;

            if(mp.find(p1) == mp.end() && mp.find(p2) == mp.end()){
                res.push_back(-1.0);
                continue;
            }
            dfs(p1, p2, vis, ans, 1.0);
            res.push_back(ans);
        }
        return res;
    }
};





//Second Solution :-  DFS
// Make a directed graph.
// If there is a/b = 2, then edge a->b has weight = 2 and edge b->a has weight 0.5.
// After forming a weighted directed graph process each query trying to find a path between startNode and endNode.
// If path found, running product kept during DFS will be your answer.
// TC = O(VQ), where V = Vertices on your graph and Q = No. of queries.

class Solution {
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string, bool> visited;
    double queryAns;

public:
    bool dfs(string startNode, string endNode, double runningProduct){
        if(startNode == endNode and adjList.find(startNode)!=adjList.end()) {
            queryAns = runningProduct;
            return true;
        }
        
        bool tempAns = false;
        visited[startNode] = true;
        
        for(int i = 0; i < adjList[startNode].size(); i++){
            if(!visited[adjList[startNode][i].first]){
                tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct*adjList[startNode][i].second);
                if(tempAns){
                    break;
                }
            }
        }
        
        visited[startNode] = false;
        
        return tempAns;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        
        for(int i = 0; i < n ; i++){
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});      //for opposite path
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        
        for(int i = 0; i < m ; i++){
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);            
            if(pathFound){
            	ans[i] = queryAns;
            }
            else{
            	ans[i] = -1;
            }
        }
        return ans;
    }
};




//Third Solution :- Union Find Solution 
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> map;
        vector<double> res;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node();
                map[s2] = new Node();
                map[s1] -> value = values[i];
                map[s2] -> value = 1;
                map[s1] -> parent = map[s2];
            } else if (map.count(s1) == 0) {
                map[s1] = new Node();
                map[s1] -> value = map[s2] -> value * values[i];
                map[s1] -> parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node();
                map[s2] -> value = map[s1] -> value / values[i];
                map[s2] -> parent = map[s1];
            } else {
                unionNodes(map[s1], map[s2], values[i], map);
            }
        }

        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
                res.push_back(-1);
            else
                res.push_back(map[query.first] -> value / map[query.second] -> value);
        }
        return res;
    }
    
private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node()  {parent = this;}
    };
    
    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }
    
    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
};




//Fourth Solution :- BFS
class Solution {
    double evaluate(unordered_map<string, vector<pair<string, double>>> &graph, vector<string> &query) {
        auto startNode = query[0];
        auto endNode = query[1];
        
        if (graph.find(startNode) == graph.end()) {
            return -1;
        }
        
        if (graph.find(endNode) == graph.end()) {
            return -1;
        }
        
        queue<pair<string, double>> que;
        unordered_set<string> visited;
        
        que.push({startNode, 1});
        visited.insert(startNode);
        
        while (!que.empty()) {
            auto frontItem = que.front();
            que.pop();
            
            auto currNode = frontItem.first;
            auto currValue = frontItem.second;
            
            if (currNode == endNode) {
                return currValue;
            }
            
            for (auto nodeObj: graph[currNode]) {
                auto node = nodeObj.first;
                auto weight = nodeObj.second;
                if (visited.insert(node).second) {
                    que.push({node, currValue * weight});
                }
            }
        }
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto fromNode = equations[i][0];
            auto toNode = equations[i][1];
            double weight = values[i];
            
            graph[fromNode].push_back({toNode, weight});
            graph[toNode].push_back({fromNode, 1 / weight});
        }
        
        vector<double> answers;
        for (auto query: queries) {
            answers.push_back(evaluate(graph, query));
        }
        
        return answers;
    }
};




//Solution :- Floyd Warshall
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int i = 0;
    unordered_map<string, int> map;
    for (auto e : equations)
    {
        if (map.find(e[0]) == map.end())
            map[e[0]] = i++;
        if (map.find(e[1]) == map.end())
            map[e[1]] = i++;
    }

    vector<double> ans;
    vector<vector<double>> dp(map.size(), vector<double>(map.size(), -1));
    for (int i = 0; i < equations.size(); i++)
    {
        int u = map[equations[i][0]];
        int v = map[equations[i][1]];
        dp[u][v] = values[i];
        dp[v][u] = 1 / values[i];
    }

    int o = 0;
    while (o < dp.size())
        dp[o][o++] = 1;

    for (int k = 0; k < dp.size(); k++)
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp.size(); j++)
            {
                if (dp[i][k] == -1 || dp[k][j] == -1)
                    continue;
                if (dp[i][j] == -1)
                    dp[i][j] = dp[i][k] * dp[k][j];
                else
                    dp[i][j] = min(dp[i][j], dp[i][k] * dp[k][j]);
            }
        }

    for (auto i : queries)
    {
        if (map.find(i[0]) == map.end() || map.find(i[1]) == map.end())
        {
            ans.push_back(-1);
            continue;
        }

        int u = map[i[0]];
        int v = map[i[1]];
        if (u == v)
            ans.push_back(1);
        else if (dp[u][v] != -1)
        {
            ans.push_back(dp[u][v]);
        }
        else if (dp[u][v] == -1)
        {
            if (dp[v][u] != -1)
                ans.push_back(1 / dp[v][u]);
            else
                ans.push_back(-1);
        }
    }
    return ans;
}




//Solution :-
// At first, it is really tricky to identify that the problem can be solved using graph algorithms. After knowing this too, one can understand the algorithm, but implementing this might again be a tedious job.
// If you have idea about the Floyd-Warshall algorithm, it might help. But not knowing this algorithm won't be a trouble here.
// For those who know the algorithm, you can relate that, here we are not calculating the shortest distance, but the quotient. Suppose the shorted distance between A and E using Floyd Warshall comes out to be A->B-> C->D->E. Also, we know that we can calculate A/E by calculating (A/x) * (x/E) if (A/x) and (x/E) is known. Hence, using the algorithm, we can get path from A to E {A->B->C->D->E} , and value A/E as (A/B) * (B/C)* (C/D) * (D/E).

// The basic algorithm for this problem has 3 steps:
// Make an adjacency List
// Calculate for all the combinations possible
// Add the output for all the queries in vector and return.

/* Adjacency list =>
    NOTE 1: We understand that the adjacency list should show edge between strings.
    NOTE 2: It is a weighted directed graph.
        i.e. a/b = 2.0 needs to be represented as (a---2.0--->b) 
    
    Every element should point to its divisor and the value.
    So, we use map for creating the list with key as the dividend string
    The value associated is a pair of string and double value.
    Since one key have multiple associated values, we make the value also as a map object.
    
    ........
    When creating a list, 
    suppose a/b = 2.0
    => a/b = 2.0 , b/a = 1/2.0 , a/a = 1.0, b/b = 0
    Hence for each edge, add these three combinations in the map.
    => mp[a][b] = 2.0, mp[b][a] = 1/2.0 , mp[a][a] = 1.0, mp[b][b] = 2.0
            
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {       
        unordered_map <string, unordered_map <string, double>> mp;
        for(int i = 0; i<equations.size(); i++){
            double v = values[i];

            mp[equations[i][0]][equations[i][1]] = v;
            mp[equations[i][1]][equations[i][0]] = 1/v;
            mp[equations[i][0]][equations[i][0]] = 1.0;
            mp[equations[i][1]][equations[i][1]] = 1.0;
        }
        
        /* To solve the queries, 
            mp[a][b] = a/b value  & mp[b][c] = b/c value
         	=> mp[a][c] should equal a/c value  = (a/b) * (b/c) value
         	=> mp[a][c] = mp[a][b] * mp[b][c] 
        */
        
        for(auto i: mp){
            for(auto j : mp[i.first]){
                for(auto k: mp[i.first])
                    mp[j.first][k.first] = mp[j.first][i.first] * mp[i.first][k.first];
            }
        }
        
        /* Solving Queries one by one */
        vector <double> v;
        for(auto i: queries){
            string from = i[0];
            string to = i[1];
            if((mp.find(from)!=mp.end()) && (mp[from].find(to)!=mp[from].end())){
                v.push_back(mp[from][to]);
            }
            else{
                v.push_back(-1.0);
            }
        }
        
        return v;
    }
};