// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
// 	Every adjacent pair of words differs by a single letter.
// 	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// 		sk == endWord
// 	Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Example 1:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

// Example 2:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.




//Solution Approach :-
//So, all this problem is asking us to do, is find a shortest path from our start word to end word using only word inside our list. Now any time you think, find the shortest sequence you should immediately think, alright i need to use some shortest path algorithm like Breadth-First-Search.
//So, in a typicall Breadth-First-Search we utilize the queue and it's going to store each string that in our sequence & then we also going to have integer value called changes which will be eventually return from our function, which will keep track how many changes do we have in the sequence.
//So, we intialize our queue that have starting word inside of it i.e. "be", then our changes variable is going to start at 1, this is because at minimum we going to have starting word in our minimum. And finally we have a set which will keep track's of node that have been visited, in this case we just keeping track of string that we have already added inside our queue.


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> st,words;
        st.insert(beginWord);

        for(string s:wordList){
            words.insert(s);
        }
        
        q.push(beginWord);   //insert begin in queue
        int res=0;

        while(q.size()){
            int n = q.size();
            res++;
            for(int i=0;i<n;i++){
                string s = q.front();   //store front element of queue
                if(s==endWord){         //check if its equal to end element
                    return res;
                }
                q.pop();              //pop it from queue
                string t;
                for(int i=0;i<s.size();i++){
                    t=s;
                    for(int j='a';j<='z';j++){     //Now change each char in word at a time and see if its preent in wordlist 
                        t[i]=j;
                        if(words.count(t) and !st.count(t)){
                            q.push(t);           //if present push in queue and set to store unique elements
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};



//Second Solution :-
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};



//Third Solution :-

class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string> &wordList){
    	unordered_set<string> s(wordList.begin(), wordList.end());

    	if(s.find(endWord) == s.end()) return 0;   // if our destination is not present in our list, return 0
    	int cnt = 0;	      // to count the number of nodes/steps needed to reach the destination word
    	queue<string> q;
    	q.push(beginWord);	  // push the starting node into queue, as we did in BFS [beginWord is our root]
    	
    	while(!q.empty()){
    		auto size = q.size();
    		cnt++;
    		while(size--){
    			auto currWord = q.front(); q.pop();
    			// find the next word which can be formed after currWord by changing it's letter(s)
    			for(int i = 0; i < currWord.size(); ++i){
    				string tmp = currWord;
    				// try to change each character, make a new word find in set
    				for(char ch = 'a'; ch <= 'z'; ++ch){
    					tmp[i] = ch;			// makin' newWord
    					// if new word is same as curr word simply ignore
    					if(tmp.compare(currWord) == 0) continue;
    					if(tmp.compare(endWord) == 0) return cnt + 1;	// found the endWord return cnt

    					// if we find the newWord is present in our map. put in the queue 
                        // as the next destination node, which will help is to reach our endWord
                        if(s.find(tmp) != s.end()){
                        	q.push(tmp);		// push the newWord or a node into queue 
                        	s.erase(tmp);		// remove that word, cuz it's taken into the queue
                        }
    				}
    			}
    		}
    	}
    	return 0;
    }
};

Time Complexity : O(N * L * 26), where N : size of wordList
Space Complexity : O(N), where L : len of words