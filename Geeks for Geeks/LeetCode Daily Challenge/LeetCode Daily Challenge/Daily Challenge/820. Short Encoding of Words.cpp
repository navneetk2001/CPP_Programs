// A valid encoding of an array of words is any reference string s and array of indices indices such that:
// words.length == indices.length
// The reference string s ends with the '#' character.
// For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
// Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

// Example 1:
// Input: words = ["time", "me", "bell"]
// Output: 10
// Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
// words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
// words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
// words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

// Example 2:
// Input: words = ["t"]
// Output: 2
// Explanation: A valid encoding would be s = "t#" and indices = [0].




//First Solution :- Map + Sorting
// Approach:
// We can write only one word in encoded string for that word and all its suffixes.
// For example :
// Words freetime, time and me can be encoded as freetime# and the nums array [0,4,6]. So we take only the parent string and exclude all its suffixes in encoded string.
// We sort the array from longest to the shortest. So that no word before one word can be its suffix (As length of suffix < length of word)
// Now we enter all the words in a hash map to keep track which words are included in the encoded string.
// We run a loop where we add length of the word + 1(for #) to the ans if the word is present in hash map.
// Next we run another loop where we find all the suffix of the word and make their count 0 in the map as they will be already covered by its parent string.
// Finally return the ans.


class Solution {
public:
    // Compare function for the condition of the sorting i.e. according to decreasing length 
    static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        
        //sorting the array in decreasing length sequence
        sort(words.begin(), words.end(), compare);

        //Entering each word in hash map.
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        //For each word if it exist in hash map then add its length+1 to ans as # is also included.
        for(int i=0; i<words.size(); i++){
            int k = words[i].size();
            if(mp[words[i]] >0){
                ans += (k+1);
            }
            
            //Deleting record of any suffix of the word from hash map as it is already covered.
            for(int j=k-1; j>=0; j--){
                string s = words[i].substr(j, k-j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};



//Second Solution :-
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size() > b.size();});
        
        for(string &s:words){
            if(ans.find(s + "#") == string::npos){
                ans += s + "#";
            }
        }
        return ans.size();
    }
};



//Third Solution :- Tries Solution
struct TrieNode{
    TrieNode* children[26]{};
    int count{};               //how many active children
    
    TrieNode* get(char c){
        //already inserted
        if(children[c - 'a']){
            return children[c - 'a'];
        }
        else{
            count++;
            return children[c - 'a'] = new TrieNode();
        }
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode(); 
        unordered_map<TrieNode*, int> res; //from a word trie end node to the length of the word
        for(string &w: words){
            TrieNode *cur = root;
            //insert it into the Trie
            for(int i = w.size() - 1; i >= 0; i--)
                cur = cur->get(w[i]);
            if(cur->count == 0) res[cur] = w.size() + 1;
        }
        int ans = 0;
        for(const auto &[node, len]: res)
            if(node->count == 0) ans += len;
        return ans;
    }
};

