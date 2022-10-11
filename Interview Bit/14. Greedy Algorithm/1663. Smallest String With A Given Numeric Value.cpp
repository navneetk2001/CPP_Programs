https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/




//Solution Appoach :-
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');     //filling n places if string with all a for smallest possible lexicographic string
        k -= n;                //Also decrease n from k total points
        
        while(k > 0){                 
            res[n-1] += min(25, k);     //starting to fill the string from last
            k -= min(25, k);
            n--;
        }
        return res;
    }
};

