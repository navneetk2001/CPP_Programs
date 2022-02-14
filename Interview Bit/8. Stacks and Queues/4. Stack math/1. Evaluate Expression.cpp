// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Input 1:
//     A =   ["2", "1", "+", "3", "*"]
// Output 1:
//     9
// Explaination 1:
//     starting from backside:
//     *: ( )*( )
//     3: ()*(3)
//     +: ( () + () )*(3)
//     1: ( () + (1) )*(3)
//     2: ( (2) + (1) )*(3)
//     ((2)+(1))*(3) = 9

//Solution Approach :-
This is pretty much a simulation problem.
Think stack.
When you encounter an operator is when you need the top 2 numbers on the stack, perform the operation on them and put them on the stack.


//First Solution :-
int Solution::evalRPN(vector<string> &A) {
    stack<int>s;

    for(int i=0;i<A.size();i++){ 
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/"){ 
            int temp=s.top();   //Collect First integer
            s.pop();            //Remove First integer

            int temp1=s.top();  //Collect Second integer
            s.pop();            //Remove Second integer

            if(A[i]=="+") 
                s.push(temp+temp1);
            if(A[i]=="-") 
                s.push(temp1-temp);
            if(A[i]=="*") 
                s.push(temp*temp1);
            if(A[i]=="/") 
                s.push(temp1/temp); 
        }
        else{
            s.push(stoi(A[i])); 
        }
    }
    return s.top();
}



//Second Solution :-
int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if((A[i][0]>='0'&&A[i][0]<='9')||A[i].size()!=1)
        {
            int m=A[i].size();
            int val=0;
            if(A[i][0]!='-')
            {for(int j=0;j<m;j++)
            {val=val*10+(A[i][j]-'0');}}
            else
            {
               for(int j=1;j<m;j++)
            {val=val*10+(A[i][j]-'0');} 
            val=-1*val;
            }
            st.push(val);
            continue;
        }
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        
        if(A[i][0]=='+')
        a=a+b;
        if(A[i][0]=='-')a=b-a;
        if(A[i][0]=='*')a=a*b;
        if(A[i][0]=='/')a=b/a;
        st.push(a);
        
    }
    return st.top();
}



//Third Solution :-
int Solution::evalRPN(vector<string> &A) {
    stack<string>k;
for(int i = 0; i < A.size(); i++)
    if(A[i] == "/" || A[i] == "*" || A[i] == "+" || A[i] == "-") {
        int y = stoi(k.top());k.pop();
        int x = stoi(k.top());k.pop();
        switch(A[i][0]) {
            case '+':  k.push(to_string(x + y));break;
            case '-':  k.push(to_string(x - y));break;
            case '*':  k.push(to_string(x * y));break;
            case '/':  k.push(to_string(x / y));break;
        }
    }
    else k.push(A[i]);
    
return stoi(k.top());
    
}

