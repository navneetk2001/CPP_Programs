https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/




//Solution Approach :- 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int n = words.size();
        int m = words[0].size();
        vector<int> ans;

        int total = n * m;
        if(s.size() < total){    //edge case
            return ans;
        }

        unordered_map<string,int> freq, mp;
        for(int j=0; j<words.size(); j++){   //store frequency of all the words in the map
            freq[words[j]]++;
        }

        for(int i=0; i<=s.size()-total; i++){    //iterate for all the possible length in string s
            mp = freq;                //copy map each time for re-checking all the present indexes
            
            int k;
            for(k=0; k<n; k++){         //iterate now to check if all the words are present in the map or not
                string temp = s.substr(i + k*m, m);
                // cout<<temp<<" "<<i<<endl;
                if(mp.count(temp) == 0){
                    break;
                }
                else{
                    if(mp[temp]!=0){
                        mp[temp]--;
                    }
                    else{
                        break;
                    }
                }
            }
            if(k==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};




//Second Solution :- 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        unordered_map<string, int> counts;
        vector<int> indexes;
        for (string word : words){
        	counts[word]++;
        }

        int n = s.length(), num = words.size();
        if (n == 0 || num == 0) return indexes;

        int len = words[0].length();
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};





//Third Solution :- Approach : We are using Hashing & Sliding Window Technique to solve the above problem.
// Let’s see the steps :
// Declare a map wordCount which stores all words count
// Select a window of size wordsWindow (total number of characters produced if all the words are concatenated).
// Check if that window is possible to build using our wordCount map.
// If True, add the starting index to our result vector
// Increasing the window by 1 & check until we are able to select wordsWindow size window.

class Solution {
public:
    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
        for(int j=0; j<s.size(); j+=wordLen) {
            string w = s.substr(j, wordLen);
            if(wordCount.find(w) != wordCount.end()) {
                if(--wordCount[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while(i + wordsWindow <= sLen) {
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};