// Given a string A denoting an expression. It contains the following operators '+', '-', '', '/'.
// Chech whether A has redundant braces or not.
// NOTE: A will be always a valid expression.

//Solution Approach :-
// If we somehow pick out sub-expressions surrounded by ( and ), then if we are left with () as a part of the string, we know we have redundant braces.
// Lets take an example:
// (a+(a+b))
// We keep pushing elements onto the stack till we encounter ')'. When we do encounter ')', we start popping elements till we find a matching '('. 
// If the number of elements popped do not correspond to '()', we are fine and we can move forward. 
// Otherwise, voila! Matching braces have been found. 
// Some Extra Hints:
// Try to run your code on test cases like (a*(a))  and (a) ??


//First Solution :-
int Solution::braces(string A) {
	stack<char>st;
	bool ans=false;
	for(int i=0;i<A.size();i++){
		if(A[i]=='+' or A[i]=='-' or A[i]=='*' or A[i]=='/'){
			st.push(A[i]);
		}
		else if(A[i]=='('){
			st.push(A[i]);
		}
		else if(A[i]==')'){
			if(st.top()=='('){
				ans=true;
			}
			while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/'){
				st.pop();
			}
			st.pop();
		}
	}
	return ans;
}



//Second Solution :-
int Solution::braces(string A){
	int n=A.length(),flag=0;
	stack<char>s;

	for(int i=0;i<n;i++)
	{
		if(A[i]==')')
		{
			int count=0;
			while(s.top()!='('){
				s.pop();
				count++;
			}
			if(count<=1){
				flag++; 
				break;
			}
			s.pop();
		}
		else
			s.push(A[i]);
	}
	if(flag)
		return 1;
	else
		return 0;
}


//Third Solution :-
int Solution::braces(string A) {
    stack<char> stackOperations;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] != ')') stackOperations.push(A[i]) ;
        else {
            if(stackOperations.empty()) return false;
            if(stackOperations.top() == '(') return true;
            int count  =0;
            while(!stackOperations.empty()) {
                count++;
                auto last = stackOperations.top();
                stackOperations.pop();
                if(last == '(') break;
            }
            if(count < 3) return 1;
        }
    }
    return false;
    // stack<char> stackOperations;
    // string path;

    // for (auto ai : A){
    //   int cnt = 0;
    //   if (ai != ')') {
    //     stackOperations.push(ai);
    //   }
    //   else {
    //     if (stackOperations.empty())
    //       return 0;
        
    //     char top = stackOperations.top();
    //     if (top == '(')
    //       return 1;

        
    //     while (!stackOperations.empty()) {
    //       cnt++;
    //       top = stackOperations.top();
    //       stackOperations.pop();
    //       if (top == '(')
    //         break;
    //     }
        
    //     if(cnt <= 2) return 1;
    //   }
    // }
    // return 0;
}

