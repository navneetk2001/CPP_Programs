// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

// Example 1:
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.  "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

// Example 2:
// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]




//Solution Approach :- 2 HashMaps
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;

    int i=0;
    for(string s : words){
        map<char,char> a;
        map<char,char> b;

        for(i=0;i<pattern.size();i++){
            if(!a[pattern[i]]){
            	a[pattern[i]]=s[i];
            }
            else if(a[pattern[i]]!=s[i]){
            	break;
            }

           	if(!b[s[i]]){
           		b[s[i]]=pattern[i];
           	}
            else if(b[s[i]]!=pattern[i]){
            	break;
            }
        }
        if(i==pattern.size()){
        	ans.push_back(s);
        }
    }
    return ans;
}




//Second Solution :-  ALGORITHM
// So I created a Found_Pattern Function which will return the numeric pattern of the pattern and all words and then we are comparing is the numeric pattern of Pattern and words[i] are similar than we will push words[i] in our answer Vector.
// So how we are creating the numeric pattern of Pattern and words[i].
// So I take an unordered_map and a vector to store the numeric pattern.

// Inside the found pattern function what i am doing.
// If string is empty we will return empty vector.
// I am iterating the string and if the ith character is not present in the map I am inserting that character in map with an index (ind) , after for every unique character i am incrementing ind.
// And, if that character is already present than we will push the index that we assigned to that char on inserting.
// After Generating the Pattern.
// Return the numeric pattern (v) and compare it with pattern vector.
// Hope the idea is clear how we are generating pattern

// let see some example what patten we get for some string according to above algorithm.
// ["abc ","  deq "," mee "," aqq "," dkd "," ccc"]
//   123     123      122     122      121     111
// PATTERN
//    "abb"
//     122
// So, we can clearly see 2 words have same pattern that is 122

class Solution {
public:
    vector<int> found_Pattern(string pattern){
        if(pattern.size() == 0){	   // if string is empty return empty vector.
            return {};
        }
        
        vector<int> v;

        int ind = 0;		// ind variable for keeping track of unique characters
        unordered_map<char,int> mp;

        for(int i = 0; i<pattern.size(); ++i){
           	if(mp.find(pattern[i]) == mp.end()){        // if character not present in map, insert the char with an index, increment index because for next unique character the index should be differnt.
               	mp.insert({pattern[i],ind++});
			   	// also  push the index to v(numeric  pattern vector),    mp[pattern[i]] gives the key to that character, here key is ind(which we are giving to every unique character)
               	v.push_back(mp[pattern[i]]);
           	}
            else{  			// if char is already in map than push index mapped to that character into the vector
                v.push_back(mp[pattern[i]]);
            }
        }
        return v;		// return numeric pattern
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> v = found_Pattern(pattern);		// store numeric patten of Pattern string in v
        
        int n = words.size();
        vector<string> ans;
        
        for(int i = 0; i<n; ++i){
            vector<int> pattern_word = found_Pattern(words[i]);		// iterating and comparing pattern of each word with v(numeric pattern of Pattern)
            
            if(v == pattern_word){			// if matched add words[i] to answer vector
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};





//✔️ Solution - I (Two Maps)
// A word will match pattern only when -
// Every letter word[i] can be mapped to a unique letter pattern[i]
// For this, we can use a hashmap to map every letter from word to pattern. To ensure that the every character mapping is unique, i.e, multiple word[i] are not mapped to same pattern[i], we will also maintain a reverse mapping from pattern to word.

vector<string> findAndReplacePattern(vector<string>& words, string p) {        
	vector<string> ans;
	for(auto& w : words) {
		if(match(w, p)) {
			ans.push_back(w);
		}
	}
	return ans;
}

bool match(string& w1, string& w2) {
	unordered_map<char, char> w1_to_w2, w2_to_w1;
	for(int i = 0; i < size(w1); i++) 
		if( (w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i]) || (w2_to_w1.count(w2[i]) && w2_to_w1[w2[i]] != w1[i]) ) {
			return false; 
		}
		else{
			w1_to_w2[w1[i]] = w2[i],
			w2_to_w1[w2[i]] = w1[i];
		}
	return true;
}

// Time Complexity : O(N*L), where N is the number of words and L is the length of each word.
// Space Complexity : O(N*L)



//✔️ Solution - II (Single Map)
//We can also solve it using a single map. We will map letters from word to pattern as done in the above solution. Once all letters are mapped, we will re-iterate over the mappings and ensure that each word[i] is only mapped to a unique character in pattern[i].

vector<string> findAndReplacePattern(vector<string>& words, string p) {        
	vector<string> ans;
	for(auto& w : words){
		if(match(w, p)){
			ans.push_back(w);
		}
	}
	return ans;
}

bool match(string& w1, string& w2) {
	unordered_map<char, char> w1_to_w2;
	for(int i = 0; i < size(w1); i++)
		if(w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i])  return false; 
		else w1_to_w2[w1[i]] = w2[i];
	
	bitset<26> visited;
	for(auto& pair : w1_to_w2) 
		if(visited[pair.second - 'a']) return false;
		else visited[pair.second - 'a'] = true;
	return true;
}

//Time Complexity : O(N*L)
//Space Complexity : O(N*L)



//✔️ Solution - III (Normalise & Compare)
//This solution is referred from @lee215's post. In this solution, we can convert each string to a base / standard pattern and then compare them. Here, we are converting all occurences of first found character to a, second all occurences of second found character to b, then c and so on...
//For eg. Consider the words "mmnpoq" and "ppqqqz". We can convert these into - "aabcde" and "aabbbc". Since they are not equal, we can say both these words don't match.
//Similarly, the words "mnpqrr" and "xyzabb" can be converted into "abcdee" and "abcdee" respectively. Since they are equal, we say that these two words match.

vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {        
	vector<string> ans;
	string p = normalise(pattern);
	for(auto& w : words) 
		if(p == normalise(w)) ans.push_back(w);
	return ans;
}

string normalise(string w) {
	unordered_map<char, char> mp;
	char c = 'a';
	for(auto ch : w) 
		if(!mp.count(ch)) mp[ch] = c++;
	for(auto& ch : w) ch = mp[ch];
	return w;
}

// Time Complexity : O(N*L)
// Space Complexity : O(N*L)