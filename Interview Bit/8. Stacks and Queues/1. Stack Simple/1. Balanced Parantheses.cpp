// Given a string A consisting only of '(' and ')'.
// You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.

// Example Input:
// Input 1:
//  A = "(()())"
// Input 2:
//  A = "(()"

// Example Output:
// Output 1:
//  1
// Output 2:
//  0


//Hint :-
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
// The problem can be solved by using a stack.

//Solution Approach :-
// Algorithm:
// Declare a character stack S.
// Now traverse the expression string exp.
// If the current character is a starting bracket ‘(‘ then push it to stack.
// If the current character is a closing bracket ‘)’ then pop from stack and if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
// After complete traversal, if there is some starting bracket left in stack then “-1”
// Time Complexity: O(len(A))
// Auxiliary Space: O(len(A)) for stack.


//First Solution :-
int Solution::solve(string A) {
    int n=A.length();

    stack<char> st;
    st.push('0');
    
    for(int i=0;i<n;i++){
        if(A[i]==')' && st.top()=='('){
            st.pop();
        }
        else st.push(A[i]);
    }

    if(st.size()==1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Second Solution :-
int Solution::solve(string A) 
{
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            s.pop();
        }
    }
    return s.empty();
    
}


//Third Solution :-
int Solution::solve(string A) {
    int l=A.length();int count=0;int i;
    for(i=0;i<l;i++){
        if(A[i]=='(')
        count++;
        else{
            count--;
            if(count<0)
            return 0;
        }
    }
    if(count!=0)
    	return 0;
    else
    	return 1;
}




