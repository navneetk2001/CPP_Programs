https://leetcode.com/problems/word-break/description/



//Solution Approach :- Recursion
//What we are doing here is we are searching for each substring in the dictionary and if it
//is found then we will search for next remaining substring

class Solution {
public:
	bool solve(string &s, unordered_map<string,int> &mp, int index){
		if(index == s.length()){
			return true;
		}

		string temp;
	    for(int i = index; i<s.length(); i++){
	        temp += s[i];
	        
	        if(mp.find(temp) != mp.end()){   //if word exist then search for remaining word
	            if(solve(s, mp, i+1)){
	            	return 1;
	            }
	        }
	    }
	    return 0;
	}

	bool wordBreak(string s, vector<string>& wordDict){
	    int n = s.length();
	    unordered_map<string,int> mp;
	    for(auto &i: wordDict){
	        mp[i]++;
	    }

	    return solve(s,mp,0);
	}
};




//Solution Approach :- Memoization
class Solution {
public:
	int dp[303];
	bool solve(string &s, unordered_map<string,int> &mp, int index){
		if(index == s.length()){
			return true;
		}

		if(dp[index] != -1){
			return dp[index];
		}

		string temp;
	    for(int i = index; i<s.length(); i++){
	        temp += s[i];
	        
	        if(mp.find(temp) != mp.end()){   //if word exist then search for remaining word
	            if(solve(s, mp, i+1)){
	            	return dp[index] = true;
	            }
	        }
	    }
	    dp[index] = false;
	    return dp[index];
	}

	bool wordBreak(string s, vector<string>& wordDict) 
	{
	    int n = s.length();
	    memset(dp, -1, sizeof(dp));
	    unordered_map<string,int> mp;
	    for(auto &i: wordDict){
	        mp[i]++;
	    }

	    return solve(s,mp,0);
	}
};




//Solution :- Tabulation
int dp[303];
bool solve(string s, unordered_set<string> &st) {
	int n = s.size();
    for(int i = n-1;i>=0;i--){
    	string temp;
    	for(int j=i;j<n;j++){
    		temp+=s[j];
    		if(st.find(temp) != st.end()){
    			dp[i] = dp[j+1];
    		}
    	}
    	dp[i] = 0;
    }
    return dp[0];
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    unordered_map<string,int> mp;
    for(auto &i: wordDict){
        mp[i]++;
    }

    return solve(s,mp,0);
}



//Solution :- BFS
//The question is simply to check if there is a path from 0 to 9. The most efficient way is traversing the graph using BFS with the help of a queue and a hash set. The hash set is used to keep track of the visited nodes to avoid repeating the same work.
//For this problem, the time complexity is O(n^2) and space complexity is O(n), the same with DP. This idea can be used to solve the problem word break II. We can simple construct the graph using BFS, save it into a map and then find all the paths using DFS.

bool wordBreak(string s, unordered_set<string> &dict) {
    // BFS
    queue<int> BFS;
    unordered_set<int> visited;
    
    BFS.push(0);
    while(BFS.size() > 0)
    {
        int start = BFS.front();
        BFS.pop();
        if(visited.find(start) == visited.end())
        {
            visited.insert(start);
            for(int j=start; j<s.size(); j++)
            {
                string word(s, start, j-start+1);
                if(dict.find(word) != dict.end())
                {
                    BFS.push(j+1);
                    if(j+1 == s.size())
                        return true;
                }
            }
        }
    }
    
    return false;
}



//Solution :- Tries
class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isEnd=false;
    
    void insert(string word) {
        Trie* node=this;
        for(char c : word){
            if(node->children.find(c)==node->children.end())
                node->children[c]=new Trie();
            node=node->children[c];
        }
        node->isEnd=true;
    }
        
    bool search(string word) {
        Trie* node=this;
        for(char c : word){
            if(node->children.find(c)==node->children.end())
                return false;
            node=node->children[c];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string word : wordDict)
            trie.insert(word);
        
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        
        for(int len=1; len<=s.size(); len++){
            for(int i=0; i<len; i++){
                if(dp[i] && trie.search(s.substr(i, len-i)))
                    dp[len]=true;
            }
        }
        return dp[s.size()];
    }
};