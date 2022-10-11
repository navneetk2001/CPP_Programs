https://leetcode.com/problems/accounts-merge/




//Solution Approach :- Union Find 
class Solution {
public:
    int parents[1001];                // why 1001? becoz it is max length of accounts, see constraints (1 <= accounts.length <= 1000)
    
    int findpar(int parents[], int to_find){         // function to find original parent
        while(parents[to_find] != to_find){
            to_find = parents[to_find];
        }
        return to_find; 
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_to_id;           // Link each email to their respective orginal parent, // we will do it by linking each email to its unique id
        
        for(int i = 0; i < accounts.size(); i++){      // traversing from each row
            parents[i] = i;                            // intially we don't know anything, so every parent is unique id of itself
            
            for(int j = 1; j < accounts[i].size(); j++){                       // why we start from 1? becoz emails starting from this place
                if(email_to_id.find(accounts[i][j]) != email_to_id.end()){     // we check if this particular email already got their unique id, if yes then we link it to its original parent unique id
                    int parent1 = findpar(parents, i);
                    int parent2 = findpar(parents, email_to_id[accounts[i][j]]);
                    
                    parents[parent1] = parent2;
                }
                else{             // if not find, then just give it to exsiting parent
                    email_to_id[accounts[i][j]] = parents[i];
                }
            }
        }
            
        // Now, we create a map that store all email id with their unique ids
        //            id,  vector of all emails
        unordered_map<int, vector<string>> resultant_map;
        
        for(auto it: email_to_id){
            int uniq_id = findpar(parents, it.second); 
            resultant_map[uniq_id].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        for(auto it: resultant_map){
            vector<string> email = it.second;
            sort(email.begin(), email.end());                // question demand in sorted order
          
            email.insert(email.begin(), accounts[it.first][0]);                // inserting name in starting with the help of unique id
            ans.push_back(email);
        }
        return ans;
    }
};




//Second Solution :- DFS
// We can state the above approach in following steps -
// Form an undirected acyclic graph with emails as node. This can be represented as adjacency list graph. Each email node from same account will be connected & have an edge with one other email from same account. For eg. If E1, E2, E3 are emails of an account, E1 forms edge with E2 and E2 forms edge with E3.
// Start with each account, take an email from that account(let's say 1st email) & traverse over the component of that email. Each email traversed will belong to the person of this account (since they form a connected component). We can use DFS/BFS for traversing the component of graph. We will sort the list emails found in this traversal and it in final list of merged accounts along with the person name at beginning.
// We also mark each of these email as seen so we dont iterate over them again and form a duplicate.
// We repeat the process for all accounts. Finally, we would have traversed over every email and if an email was present in multiple accounts, it will be merged into list of emails belonging to same person.


class Solution {
public:
    void dfs(string& email) {
        seen.insert(email);
        ans.back().push_back(email);
        for(auto& adjEmail : G[email]) {
            if(!seen.count(adjEmail)) {
                dfs(adjEmail);        
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {        
        for(auto& acc : A){                         
            for(int i = 2; i < size(acc); i++){              // create graph with email as nodes and,
                G[acc[i]].push_back(acc[i-1]),              // add edges between adjacent nodes of same account
                G[acc[i-1]].push_back(acc[i]);
            }
        }
        
        for(auto& acc : A){ 
            if(!seen.count(acc[1])) {                       // If an email from a account is not previously seen,
                ans.push_back({acc[0]});                    // create new account & insert person's name
                dfs(acc[1]);                                // perform dfs to find all his emails & add it to the list
                sort(begin(ans.back())+1, end(ans.back())); // sort the emails
            }            
        }
        
        return ans;
    }
private:
    unordered_map<string, vector<string>> G;  // adjacency list graph with email as nodes and edges between adjacent email of same account
    unordered_set<string> seen;               // to mark an email as visited in DFS
    vector<vector<string>> ans;               // final answer after merging accounts
};




//Third Solution :- 
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};




//Fourth Solution :-
//Just check whether you have already received a matching email before or not. If there is a matching email before, add rest of the entries there, otherwise make a new entry for the newer details
class Solution {
 public:
   vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
       map<string, int>m;
       vector<pair<string, set<string>>> a;
       for(auto &i:details){
           int p = -1;
           for(auto it=i.begin()+1; it != i.end(); ++it){
               if(m.find(*it)!=m.end()){
                   p = m[*it];
                   break;
               }
           }
           if(p==-1) p=a.size(), a.emplace_back(i[0], set<string>());
           for(auto it=i.begin()+1; it != i.end(); ++it){
               a[p].second.emplace(*it);
               m[*it] = p;
           }
       }
       
       vector<vector<string>> ans(a.size());
       for(int i=0;i<a.size();i++){
           ans[i] = {a[i].first};
           ans[i].insert(ans[i].end(), a[i].second.begin(), a[i].second.end());
       }
       sort(ans.rbegin(), ans.rend()); /* Some how reverse sorting here works to pass the test case 56 XD */
       return ans;
   }
};