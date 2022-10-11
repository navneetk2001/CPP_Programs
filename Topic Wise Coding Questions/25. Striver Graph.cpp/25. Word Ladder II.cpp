https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii




//Solution Approach :- 
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size() > level){    //erase all words that has been used in the previous levels to transform
                level++;
                
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }
            
            string word = vec.back();   
            if(word == endWord){       
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            
            for(int i=0;i<word.size();i++){               //now start iterating for all the characters of word
            	char original = word[i];     
            	for(char ch = 'a'; ch <= 'z'; ch++){      //now start replacing the original character from a to z and check if that word is in the set or not 
            		word[i] = ch;                         //replacing original char with char from 'a' to 'z'
    
            		if(st.count(word) > 0){               //if that word is found in set then 
            			vec.push_back(word);              //add that new element in the vector 
            			q.push(vec);                      //push that new vec in queue 
            			usedOnLevel.push_back(word);      //mark as visited on the level
            			vec.pop_back();                   //remove it so that you can get other words on the same level
            		}
            	}
            	word[i] = original;          //replace again the changed character with original character
            }
        }
        
        return ans;
    }
};


