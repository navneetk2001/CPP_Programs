// You are given an array of words where each word consists of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:
// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

// Example 2:
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

// Example 3:
// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.





//Solution Approach :- 	
//This problem is a variation of longest increasing subsequence(LIS), here only change is that we need to compare 2 string and check if they differ by only one char or not
//We also need to sort the given array on the basis of length , because it has been told that we need to choose sequence 

//IDEA : It is same as LIS, which can be easily understood, let me explain the use of check function. The check function would take the 2 strings and as mentioned in the question, the successive string only differs by 1 character. This modification allows the idea of O(N) complexity of helper/check function. The check function would simply count the difference in number of characters of the two strings. If the difference is 1, then it returns true and the condition holds true, and returns false otherwise.

class Solution {
public:
    int check(string s, string t){
        int m = s.length(), n = t.length(), i = 0, j = 0, missing = 0;
        if(n != m+1){
        	return false;
        }
        
        for(int i=0; i<n; i++){
            if(t[i] == s[j]){     // if no character is missing, continue to check
            	j++;
            }
            else{
                if(!missing){    // if we found a missing character, update the variable
                	missing = 1;
                }
                else{            // if number of missing character is >=2 return false
                	return false;
                }
            }
        }
        return true;
    }
    
    static bool cmp(const string& s, const string t){      //compare function to compare string on the basis of length
        return s.length() < t.length();
    }
    
    int longestStrChain(vector<string>& v) {
    	if(v.size()==1){
    		return 1;
    	}
        sort(v.begin(), v.end(), cmp);         //sort the given array on the basis of length
        vector<int> dp(v.size(), 1);           //A DP array to store the LIS
        int ans = 0;                           //store maximum value in the ans variable

        for(int i=1; i<v.size(); i++){
            for(int j=0; j<i; j++){
                int x = v[i].length(), y = v[j].length();
                if(y+1 == x && check(v[j], v[i]) && dp[i] < dp[j]+1){     //same as LIS
                	dp[i] = dp[j]+1;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};



//Second Solution :- Using Hashmap
bool cmp(string &a, string &b){     // Utility function to sort array on basis of length.
    return a.length() < b.length();
}

int longestStrChain(vector<string> &arr){
    sort(arr.begin(), arr.end(), cmp);             // Sort 'ARR' on basis on length of strings.

    unordered_map<string, int> mp;               // Hashmap to store length of string chain ending at a string.
    int maxChain = 0;                              // Variable to store length of longest string chain.

    for (int j = 0; j < arr.size(); j++){
        int chainLength = 1;         // Variable to store longest chain ending at index 'j'.

        
        for (int i = 0; i < arr[j].length(); i++){          // Remove each character of the j'th string one-by-one.
            string s = arr[j].substr(0, i) + arr[j].substr(i + 1);    // Generate string 'S' by removing character at index 'i'.
            
            if (mp.find(s) != mp.end()){              // Check if 'S' already exists in hash-map.
                chainLength = max(chainLength, 1 + mp[s]);               // If exists then update chainLength.
            }
        }
        mp[arr[j]] = chainLength;                   // Insert in hash-map.
        maxChain = max(maxChain, chainLength);      // Update the overall maximum chain length.
    }
    return maxChain;
}




//Third Solution :- Brute Force DFS
bool isChain(string &prev, string &cur) {
  for (auto i = 0, j = 0; i < prev.size(); ++j) {
    if (prev[i] == ' ' || prev[i] == cur[j]) ++i;
    if (j - i == 2) return false;
  }
  return true;
}

int dfs(vector<vector<string>> &w, string pr) {
  int res = pr.size();
  if (res == w.size()) return res;
  for (auto word : w[pr.size()]) {
    if (isChain(pr, word)) res = max(res, dfs(w, word));
  }
  return res;
}

int longestStrChain(vector<string>& words, int res = 1) {
  vector<vector<string>> w(16, vector<string>());
  for (auto word : words) w[word.size() - 1].push_back(word);
  for (auto i = 0; i < 16; ++i) res = max(res, dfs(w, string(i, ' ')) - i);
  return res;
}