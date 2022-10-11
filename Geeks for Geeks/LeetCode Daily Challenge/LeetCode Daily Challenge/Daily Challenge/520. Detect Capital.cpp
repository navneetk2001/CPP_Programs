// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

// Example 1:
// Input: word = "USA"
// Output: true

// Example 2:
// Input: word = "FlaG"
// Output: false



//Solution Approach :-  Approach -1 
class Solution {
public:
    bool isCap(char c)
    {
        return (c >= 'A' && c <= 'Z');
    }

    bool isSmall(char c){
        return (c >= 'a' && c <= 'z');
    }

    bool detectCapitalUse(string word) 
    {
        int cap, small;
        cap = small = 0;
        
        for(char c: word)
        {
            cap += isCap(c);
            small += isSmall(c);
        }
        if(cap == word.size() || small == word.size()) 
            return true;
        
        if(small == word.size()-1 && isCap(word[0])) 
            return true;
        
        return false;
    }
};




//Solution Approach :-  Approach -2
class Solution {
public:
    bool isCap(char c){
        return (c >= 'A' && c <= 'Z');
    }
    
    bool isSmall(char c){
        return (c >= 'a' && c <= 'z');
    }
    
    bool detectCapitalUse(string word) {
        int cap, small;
        cap = small = 0;
        if(word.size()<2)
          return true;
        
        if(isCap(word[0]) and isCap(word[1]))
        {
             for(int i=2;i<word.size();i++)
             {
                 if(isSmall(word[i]))
                  return false;
             }
        }
        else{
             for(int i=1;i<word.size();i++)
             {
                 if(isCap(word[i]))
                     return false;
             }
        }
        
        return true; 
    }
};


