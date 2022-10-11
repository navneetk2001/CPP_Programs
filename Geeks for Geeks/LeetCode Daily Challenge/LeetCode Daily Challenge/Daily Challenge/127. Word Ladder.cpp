




//Solution Approach :-
class Solution {
public:
	int diff(string a, string b){     //calculates difference between 2 given strings
		int count = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				count++;
			}
		}
		return count;
	}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> m;

        for(int i = 0; i < wordList.size(); i++){    //making an adjacency list using given words
        	for(int j = i+1; j < wordList.size(); j++){
        		if(diff(wordList[i], wordList[j]) == 1){    //if it's possible neighbours
        			m[wordList[i]].push_back(wordList[j]);
        			m[wordList[j]].push_back(wordList[i]);
        		}
        	}
        }

        for(int i = 0; i < wordList.size(); i++){    //here we are also including begin word because we haven't included begin word in above adj list
    		if(diff(beginWord, wordList[i]) == 1){    //if it's possible neighbours
    			m[beginWord].push_back(wordList[i]);
    			m[wordList[i]].push_back(beginWord);
    		}
        }

		queue<pair<string, int>> q;
		q.push({beginWord,1});
		set<string> visited;

		visited.insert(beginWord);

		while(!q.empty()){                //Doing a simple bfs
			string x = q.front().first;
			int level = q.front().second;
			q.pop();

			vector<string> p = m[x];    //searching its neighbours
			for(string s : p){
				if(visited.find(s) == visited.end()){    //if it's not visited
					q.push({s, level+1});
					visited.insert(s);

					if(s == endWord) return level+1;
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





//Third Solution :-  Bi-Directional BFS
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> s1;
		unordered_set<string> s2;
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if(!dict.count(endWord)) return 0;
		int len=beginWord.size();
		int ans=0;
		s1.insert(beginWord);
		s2.insert(endWord);
		while(!s1.empty() && !s2.empty()){
			ans++;
			if(s1.size()>s2.size()){
				swap(s1,s2);
			}
			unordered_set<string> cur;
			for(string w:s1){
				for(int i=0;i<len;i++){
					char temp=w[i];
					for(char x='a';x<='z';x++){
						w[i]=x;
						if(s2.count(w)){
							return ans+1;
						}
						if(!dict.count(w))continue;
						dict.erase(w);
						cur.insert(w);
					}
					w[i]=temp;

				}
			}

			s1=cur;

		}

		return 0;

	}
};