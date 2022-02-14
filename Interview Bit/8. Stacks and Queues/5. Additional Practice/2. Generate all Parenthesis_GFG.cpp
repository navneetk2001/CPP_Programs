Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


// First Method :-
int Solution::isValid(string A) {
    stack<char> a;
    a.push('0');
    int n=A.length();
    for(int i=0;i<n;i++){
        if((A[i]=='}' && a.top()=='{') || (A[i]==']' && a.top()=='[') || (A[i]==')' && a.top()=='(')) a.pop();
        else a.push(A[i]);
    }
    if(a.size()==1) return 1;
    else return 0;
}


//Second Method :-
int Solution::isValid(string A) {
     stack<char> s;
    int i = 0;
    int N = A.size();
    
    for(i = 0; i<N; i++){
        if(A[i] == '(' || A[i] == '{' || A[i] == '[') s.push(A[i]);
        else if(A[i] == ')'){ //can use switch case also
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '(') s.pop();
            else return 0;
        }
        else if(A[i] == '}'){
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '{') s.pop();
            else return 0;
        }
        else if(A[i] == ']'){
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '[') s.pop();
            else return 0;
        }
    }
    return s.empty();
}

//Third Method :-
int Solution::isValid(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> st;
    
    for (auto ii = A.cbegin(); ii !=A.cend(); ++ii) {
        char symbol = *ii;
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            st.push(symbol);
        } else if (!st.size()) {
            return 0;
        } else if ((symbol == ')' && st.top() == '(') ||
                    (symbol == ']' && st.top() == '[') ||
                    (symbol == '}' && st.top() == '{')) {
            st.pop();
            continue;
        } else {
            return 0;
        }
    }
    
    if (st.size()) {
        return 0;
    }
    return 1;
}



