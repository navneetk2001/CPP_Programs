// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
// For example, given n = 3, a solution set is:
// "((()))", "(()())", "(())()", "()(())", "()()()"
// Make sure the returned list of strings are sorted.

//Solution Approach :- 
Again, think recursion.
At every step, you have 2 options :
1) Add ‘(‘ to the string.
2) Add ‘)’ to the string.
However, you need to make sure, that the number of closing brackets do not exceed number of opening brackets at any point of time.
Also, make sure that the number of opening brackets never exceeds n.


//First Solution :-
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

vector<string> Solution::generateParenthesis(int n) {
    vector<string> ans;  //"ans" vector to store the parentheses
    int close = n, open = n;  // close and open will keep the record of the brackets used
    string output = "";   //output will store the current string
    solve(ans, output, open, close);  //recursion called
    sort(ans.begin(),ans.end());
    return ans;
}


//Second Solution :- Iterative Approach 
vector<string> Solution::generateParenthesis(int A) {
    vector <set<string>>v;
    v.push_back({""});
    v.push_back({"()"});
    for(int i=2;i<=A;i++){
        set<string>temp;
        for(int k=1;k<i;k++){
            for(auto x : v[k]){
                for(auto y : v[i-k]){
                    temp.insert(y+x);
                    temp.insert(x+y);
                }
            }
        }
        for(auto x : v[i-1]){
                temp.insert("("+x+")");
        }
        v.push_back(temp);
    }
    vector<string> ans(v[v.size()-1].begin(),v[v.size()-1].end());
    return and;
}


//Third Solution :- 
void utilsgenparen(vector<string>sol,string sub,int open,int close,int n){
    if(sub.size()==2*n){
    	sol.push_back(sub);
    	cout<<sub<<' ';
    	return;
    }

    if(open<n){
        sub.push_back('(');
        utilsgenparen(sol,sub,open+1,close,n);
        sub.pop_back();
    }

    if(open>close){
        sub.push_back(')');
        utilsgenparen(sol,sub,open,close+1,n);
        sub.pop_back();
    }

    return;  
}

vector<string> Solution::generateParenthesis(int A) {
	vector<string>sol;
	string sub;    
	int open=0,close=0;
	utilsgenparen(sol,sub,open,close,A);    
    return sol;
}

