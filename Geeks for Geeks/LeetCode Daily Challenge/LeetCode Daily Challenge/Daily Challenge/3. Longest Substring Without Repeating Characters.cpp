// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 



//Solution Approach :-
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxSize=0, i=0, j=0, n=s.size();
        while(j<n){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                maxSize = max(maxSize, j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxSize;
    }
};



//Second Solution :-
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        int start=0,res=0;
        for(int i=0;i<s.length();i++){
            
            if (index.find(s[i]) != index.end() && index[s[i]] >= start)
                 start = index[s[i]] + 1;
            
            index[s[i]] = i;
            res=max(res,i-start+1);
        }
        
        return res;
    }
};


