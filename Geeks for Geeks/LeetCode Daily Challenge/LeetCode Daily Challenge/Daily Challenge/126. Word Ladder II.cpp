https://leetcode.com/problems/word-ladder-ii/




//Solution Approach :-
class Solution {
public:
    vector<vector<string>>  ans;    //Stores all possible paths
    
    void DFS(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj, vector<string> &path) {
        path.push_back(beginWord);  //Push current word
        if(beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x : adj[beginWord])
            DFS(x, endWord, adj, path);
        
        path.pop_back();    //Pop current word to Backtrack
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adj;   //Adjacency List
        unordered_set<string> dict(wordList.begin(),wordList.end());   //Insert WordList in SET
        
        //STEP-1: Find min-depth using BFS
        queue<string> Q;    //For BFS traversal
        Q.push(beginWord);  //Push start node (beginWord)
        unordered_map<string, int> visited; //Key->String (Node)...Value->Level (Depth of traversal)
        visited[beginWord] = 0; //Start node will always be at level 0
        while(!Q.empty())
        {
            string curr = Q.front();
            Q.pop();
            string temp = curr;
            for(int i = 0; i < curr.size(); ++i)    //For all characters
            {
                for(char x = 'a'; x <= 'z'; ++x)    //Try all possible 26 letters
                {
                    if(temp[i] == x)    //Skip if letter is same as in original word
                        continue;

                    temp[i] = x;    
                    if(dict.count(temp) > 0)    //Check if new word is present in wordList
                    {
                        if(visited.count(temp) == 0)    //check if the new word was already visited
                        {
                            visited[temp] = visited[curr] + 1;
                            Q.push(temp);
                            adj[curr].insert(temp);
                        } 
                        else if(visited[temp] == visited[curr] + 1) //If already visited and new word is the child (We should always move down)
                            adj[curr].insert(temp);
                    }
                }
                temp[i] = curr[i];  //Revert back temp to curr
            }
        }
        //STEP-2: Find all possible paths at min-depth using DFS
        vector<string> path;
        DFS(beginWord, endWord, adj, path); //Find all possible paths with min-depth
        return ans; 
    }
};






//Second Solution :- 
// In fact, this problem can be solved with a very standard BFS process, whose structure could haven been written by you for many many times (using while loop and a queue).
// The following code is written in a very standard BFS method, which is easy to memorize.

// The only tricky thing you need to remember is this is a BFS of paths not words!
// So the element is the queue is a vector. That's it.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& words) {
        vector<vector<string>> ans;
        unordered_set<string> wordList(words.begin(),words.end());
        
        queue<vector<string>> paths;
        //wordList.insert(endWord);
        paths.push({beginWord});

        int level = 1;
        int minLevel = INT_MAX;

        //"visited" records all the visited nodes on this level these words will never be visited again after this level 
        //and should be removed from wordList. This is guaranteed by the shortest path.
        unordered_set<string> visited; 

        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {            //reach a new level
                for (string w : visited) wordList.erase(w);
                visited.clear();
                if (path.size() > minLevel){
                    break;
                }
                else{
                    level = path.size();
                }
            }
            string last = path.back();
            //find next words in wordList by changing each element from 'a' to 'z'
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordList.find(news) != wordList.end()) {
                    //next word is in wordList append this word to path, path will be reused in the loop so copy a new path
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }
};