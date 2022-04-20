// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

// For example:
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:
// Input: columnTitle = "A"
// Output: 1

// Example 2:
// Input: columnTitle = "AB"
// Output: 28

// Example 3:
// Input: columnTitle = "ZY"
// Output: 701



//Solution Approach :-
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle){
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a  
            //number like it's going to be C)

            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};



//Second Solution :-
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result=0;
        for(int i = 0; i < columnTitle.size(); i++){
            result*=26;
            result+=(columnTitle[i]-'A'+1);
        }
        return result;
    }
};

