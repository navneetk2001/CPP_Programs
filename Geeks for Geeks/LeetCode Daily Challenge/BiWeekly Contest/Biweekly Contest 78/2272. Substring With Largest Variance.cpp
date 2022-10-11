// The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
// Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
// A substring is a contiguous sequence of characters within a string.


// Example 1:
// Input: s = "aababbb"
// Output: 3
// Explanation:
// All possible variances along with their respective substrings are listed below:
// - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
// - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
// - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
// - Variance 3 for substring "babbb".
// Since the largest possible variance is 3, we return it.

// Example 2:
// Input: s = "abcde"
// Output: 0
// Explanation:
// No letter occurs more than once in s, so the variance of every substring is 0.




//Solution Approach :-
class Solution {
public:
    // Time Complexity:- O(26*26*N)
    // Space Complexity:- O(26)
    int largestVariance(string s) {
        int ans = 0;
        vector<int> freq(26);
        for(auto& c:s){
            freq[c-'a']++;
        }
        
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a']){
                    continue;
                }
                for(int rev=1;rev<=2;rev++){
                   int cnt1 = 0,cnt2 = 0;
                    for(auto& c:s){
                        cnt1 += c==ch1;
                        cnt2 += c==ch2;
                        if(cnt1<cnt2){
                            cnt1 = cnt2 = 0;
                        }
                        if(cnt1>0 and cnt2>0){
                            ans = max(ans,cnt1-cnt2);
                        }
                    } 
                    reverse(s.begin(),s.end());
                }
                
            }
        }
        return ans;
    }
};



