https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1




//Solution Approach :- //try to picture the recursion tree, at every point, there are two choices, add an opening or a closing
void paran(int n, int open, int close, string s, vector<string> &ans){
    if(open==n && close==n){       // when opening and closing reaches n, we have one of our ans strings
        ans.push_back(s);
        return;
    } 

    if(open<n){
        paran(n, open+1, close, s+"(", ans);
    }
    
    if(close<open){
        paran(n, open, close+1, s+")", ans);
    }
}

vector<string> AllParenthesis(int n) {
    vector<string> ans;
    paran(n, 0,0,"",ans);
    return ans;
}



//Second Solution :-
void solve(int open, int close, string op, vector<string> &ans){
	if(open==0 & close==0){
	   	ans.push_back(op);
	   	return;
	}
	if(open != 0){
		string op1 = op;
		op1.push_back('(');
		solve(open-1,close,op1,ans);
	}
	if(close > open){
		string op2 = op;
		op2.push_back(')');
		solve(open,close-1,op2,ans);
	}
	return;
}

vector<string> AllParenthesis(int n) {
	vector<string> ans;
	int open = n;
	int close = n;
	string op = "";

	solve(open, close, op, ans);
	return ans;
}




//Third Solution :-     
void recGenBracers( vector<string> &vStr, string &str, int n1, int n2, int &n)
{
    if(n*2 == str.length()){
        vStr.push_back(str);
        return;
    }

    if(n1>0){
        str = str + '(';
        recGenBracers(vStr, str, n1-1, n2, n);
        str.pop_back();
    }
        
    if(n2>0){
        if(n1<n2){
            str = str + ')';
            recGenBracers(vStr, str, n1, n2-1, n);
            str.pop_back();
        }
    }
}

vector<string> AllParenthesis(int n) {
    vector<string> vStr;
    string str = "";
    int n1 = n;
    int n2 = n;

    recGenBracers(vStr, str, n1, n2, n);
    return vStr;
}



