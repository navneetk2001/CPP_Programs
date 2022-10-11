// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]



//Solution Approach :-
class Solution {
public:
    void solve(vector<string>& ans, string &s, int open, int close){
        if(open==0 and close==0){      //Base Case - if open and close == 0, output has a leaf node -> push it to ans vector
            ans.push_back(s);
            return;
        }

	    //if open is not equal to zero first we'll call open parentheses
        if(open>0){
        	s.push_back('(');
            solve(ans, s, open-1, close);
            s.pop_back();
        }
        
		//then we'll recursively start calling close brackets in combination
        
        if(close>0){
        	if(close > open){
	        	s.push_back(')');
	            solve(ans, s, open, close-1);
	            s.pop_back();
	        }  
        }    
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;  //"ans" vector to store the parentheses
        int close = n, open = n;  // close and open will keep the record of the brackets used
        string output = "";   //output will store the current string
        solve(ans, output, open, close);  //recursion called
        return ans;
    }
};



//Second Solution :-
class Solution {
public:
    void solve(vector<string>& ans, string output, int open, int close){
        if(open==0 and close==0){      //Base Case - if open and close == 0, output has a leaf node -> push it to ans vector
            ans.push_back(output);
            // return;
        }
	    //if open is not equal to zero first we'll call open parentheses
        if(open>0){
            solve(ans, output+ "(", open-1, close);
        }
        
		//then we'll recursively start calling close brackets in combination
        if(close>open){
            solve(ans, output+ ")", open, close-1);
        }      
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;  //"ans" vector to store the parentheses
        int close = n, open = n;  // close and open will keep the record of the brackets used
        string output = "";   //output will store the current string
        solve(ans, output, open, close);  //recursion called
        return ans;
    }
};



