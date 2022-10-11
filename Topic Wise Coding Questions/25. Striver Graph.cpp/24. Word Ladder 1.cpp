https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder



//Solution Approach :-  BFS
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
{
    unordered_set<string> st(wordList.begin(),wordList.end());    //push all the words of vector in set
    st.erase(startWord);                                          //erase the startword from set if already present
    
    queue<pair<string, int>> q;            //queue to store word and steps to reach that word
    q.push({startWord,1});                 //push startWord with steps 1 in queue

    while(!q.empty())
    {
        string word = q.front().first;     //take the first word from queue
        int steps = q.front().second;      
        q.pop();

        if(word == targetWord){
        	return steps;
        }

        for(int i=0;i<word.size();i++){               //now start iterating for all the characters of word
        	char original = word[i];     
        	for(char ch = 'a'; ch <= 'z'; ch++){      //now start replacing the original character from a to z and check if that word is in the set or not 
        		word[i] = ch;

        		if(st.find(word) != st.end()){       //if that word is found in set then remove it from the set b/c there is no need to explore that word again
        			st.erase(word);
        			q.push({word, steps+1});        //now push that word in the set and increase the steps
        		}
        	}
        	word[i] = original;          //replace again the changed character with original character
        }
    }
    return 0;
}





//Second Solution :- 
int solve(string a, string b){
    int cnt = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]!=b[i]) cnt++;
        if(cnt>1) return 0;
    }
    return cnt==1;
}

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    vector<int> visited(wordList.size(), 0);
    queue<pair<string, int>> Q;
    Q.push({startWord, 0});
    
    while(!Q.empty())
    {
        pair<string, int> front = Q.front();
        Q.pop();
        string word = front.first;
        int steps = front.second;
        
        for(int i = 0;i<wordList.size();i++)
        {
            if(!visited[i] && solve(word, wordList[i])==1)
            {
                visited[i]=1;
                if(wordList[i]==targetWord) return steps+2;
                Q.push({wordList[i], steps+1});
            }
        }
    }
    return 0;
}

