// Given a string A of parantheses  ‘(‘ or ‘)’.
// The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.
// An string is valid if:
// Open brackets must be closed by the corresponding closing bracket.
// Open brackets must be closed in the correct order.

// Example Input :
// Input 1:
//  A = "())"
// Input 2:
//  A = "((("

// Example Output :
// Output 1: 1
// Output 2: 3


//Hint :-
// First try to find a solution to check whether a string is valid or not.
// For each extra ')' at any time we need to add a corresponding ‘(‘ at the start of string.
// Try to use the above fact to find a solution to the problem.

//Solution Approach :-
// We keep the track of balance of the string i:e the number of ‘(‘ minus the number of ‘)’. A string is valid if its balance is 0, and also every prefix has non-negative balance.
// Now, consider the balance of every prefix of A. If it is ever negative (say, -1), we must add a ‘(‘ bracket at the beginning. Also, if the balance of S is positive (say, +P), we must add P times ‘)’ brackets at the end.


// First Method :-
int Solution::solve(string A) {
    int left=0;
	int right=0;

	for(int i=0;i<A.size();i++){
		if(A[i]=='(')
			left++;
		else{ 
			if(left>0){
				left--;
			}
			else{
				right++;
			}
		}
	}

	return left+right;
}


//Second Method :-
int minAddToMakeValid(string s){
	stack<char>st;

	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st.push(s[i]);
		}
		else{ 
			if(!st.empty() && st.top()=='('){
				st.pop();
			}
			else{
				st.push(')');
			}
		}
	}

	return st.size();
}


//Third Method :-
int Solution::solve(string A) {
    int left = 0, cnt = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '('){
            left++;
        }
        else{
            if(left == 0){
                cnt++;
            }
            else{
                left--;
            }
        }
    }
    return cnt + left;
}
