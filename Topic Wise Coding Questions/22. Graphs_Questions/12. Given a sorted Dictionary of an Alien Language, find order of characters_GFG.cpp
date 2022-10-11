Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 
Example 1:
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output. Similarly we can find other orders.

Example 2:
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.




//Solution Approach :- Using Topological Sort using DFS
//we compare characters of strings in our dict from left to right if c1≠c2 then we know that c1<c2. So we create a directed graph with c1 and c2 nodes and edge from c1 to c2. after traversing through entire dict we get a DAG now just print topological sort of this DAG.

void dfs(int node,vector<int> adj[],bool vis[],string &ans){
   vis[node] = true;
   for(auto choice: adj[node]){
       if(!vis[choice]){
           dfs(choice,adj,vis,ans);
       }
   }

   char ch =(char)(node + 'a');
   ans = ch + ans;
}

string findOrder(string dict[], int N, int K) {
   vector<int> adj[K];
   
   for(int i = 0; i < N-1; i++){
       string str1 = dict[i];
       string str2 = dict[i+1];
       for(int j = 0; j < min(str1.length(),str2.length()); j++){
           if(str1[j] != str2[j]){
               adj[str1[j]-'a'].push_back(str2[j]-'a');
               break;
           }
       }
   }
   
   bool vis[K];
   for(int i = 0; i < K; i++){
       vis[i] = false;
   }
   
   string ans{};
   for(int i = 0; i < K; i++){
       if(!vis[i]){
           dfs(i,adj,vis,ans);
       }
   }
   
   return (ans);
}




//Second Solution :- Using Topological Sort using DFS
void dfs(int i,vector<int>adj[] , vector<int>&vis,stack<int>&st){
    vis[i]=1;
    
    for(auto x : adj[i]){
        if(vis[x]==0){
            dfs(x,adj,vis,st);
        }
    }
    
    st.push(i);
}

string findOrder(string dict[], int n, int k) {
    vector<int> vec[k];
    
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        
        int m = min(s1.length(),s2.length());
        for(int j=0;j<m;j++){
            if(s1[j]!=s2[j]){
                vec[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    string ans = "";
    stack<int> st;
    vector<int> visited(k,0);

    for(int i=0;i<k;i++){
        if(visited[i]==0){
            dfs(i,vec,visited,st);
        }
    }
    
    while(!st.empty()){
        char c = st.top() + 'a';
        ans = ans + c;
        st.pop();
    }

    return ans;
}


//Third Solution :- Using Topological Sort using BFS
class Solution{
    public:
    int cnt[26];
    queue<int> q;
    vector<int> edges[26];

    string findOrder(string dict[], int n, int k) {
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 1; i < n; i++) {
            int k1 = 0, k2 = 0;
            while (k1 < dict[i - 1].length() && k2 < dict[i].length()) {
                if (dict[i - 1][k1] != dict[i][k2]) {
                    k1 = dict[i - 1][k1] - 'a';
                    k2 = dict[i][k2] - 'a';
                    cnt[k2]++;
                    edges[k1].push_back(k2);
                    break;
                }
                k1++; 
                k2++;
            }
        }

        for (int u = 0; u < k; u++) {
            if (cnt[u] == 0){
                q.push(u);
            }
        }

        string result = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : edges[u]) {
                cnt[v]--;
                if (cnt[v] == 0)
                    q.push(v);
            }

            char ch = u + 'a';
            result += ch;
        }

        return result;
    }
};