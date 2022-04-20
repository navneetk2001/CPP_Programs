// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false



//Solution Approach :- Sliding window + hashmap
class Solution {
public:
   bool checkInclusion(string s1, string s2) 
    {
        vector<int> cur(26), goal(26);

        for(char c : s1) 
            goal[c - 'a']++;

        for(int i = 0; i < s2.size(); i++) 
        {
            cur[s2[i] - 'a']++;

            if(i >= s1.size()) 
                cur[s2[i - s1.size()] - 'a']--;

            if(goal == cur) 
                return true;

        }
        return false;
    }
};


//Another Concept :- with Sliding window 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         if(s1.size() > s2.size())
            return false;
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        // check if the frequency of s1 is there in s2 with a window size equal to s1
        int i = 0;
        for(; i < s1.size(); i++) {
            // compute the frequency of each char for the first window
            ++s1_freq[s1[i] - 'a'];
            ++s2_freq[s2[i] - 'a'];
        }
        
        if(s1_freq == s2_freq)
            return true;
        // search the remaining windows
        for(; i < s2.size(); i++) {
            // remove the first char of current window and add the current char
            --s2_freq[s2[i - s1.size()] - 'a'];
            ++s2_freq[s2[i] - 'a'];
            if(s1_freq == s2_freq)
                return true;
        }
        return false;
    }
    
};


// Approach #1 Brute Force [Time Limit Exceeded] :-
// The simplest method is to generate all the permutations of the short string and to check if the generated permutation is a substring of the longer string.

public class Solution {
    boolean flag = false;
    
    public boolean checkInclusion(String s1, String s2) {
        permute(s1, s2, 0);
        return flag;
    }
    
    public String swap(String s, int i0, int i1) {
        if (i0 == i1)
            return s;
        String s1 = s.substring(0, i0);
        String s2 = s.substring(i0 + 1, i1);
        String s3 = s.substring(i1 + 1);
        return s1 + s.charAt(i1) + s2 + s.charAt(i0) + s3;
    }
    
    void permute(String s1, String s2, int l) {
        if (l == s1.length()) {
            if (s2.indexOf(s1) >= 0)
                flag = true;
        } else {
            for (int i = l; i < s1.length(); i++) {
                s1 = swap(s1, l, i);
                permute(s1, s2, l + 1);
                s1 = swap(s1, l, i);
            }
        }
    }
}


// Approach #2 Using sorting [Time Limit Exceeded]:
// Algorithm
// The idea behind this approach is that one string will be a permutation of another string only if both of them contain the same characters the same number of times. One string xx is a permutation of other string yy only if sorted(x)=sorted(y)sorted(x)=sorted(y).
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        s1 = sort(s1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (s1.equals(sort(s2.substring(i, i + s1.length()))))
                return true;
        }
        return false;
    }
    
    public String sort(String s) {
        char[] t = s.toCharArray();
        Arrays.sort(t);
        return new String(t);
    }
}

