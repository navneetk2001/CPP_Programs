// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

// Example 1:
// Input:
// S = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
// Explanation:
// ABC
// AB C
// A BC
// A B C
// These are the possible combination of "ABC".
 

// Example 2:
// Input: S = "AB"
// Output: (A B)(AB)




//Solution Approach :-
vector<string> res;
void perm(string &S, int i, string curr){
    if(i == S.size()){
        res.push_back(curr);
        return;
    }
    if(i)
    perm(S, i + 1, curr + " " + S[i]);
    perm(S, i + 1, curr + S[i]);
    
}

vector<string> permutation(string S){
    perm(S, 0, "");
    return res;
}




//Second Solution :-
void solve(vector<string>&ans,string s,int n,int i,string temp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    if(s[i]==' '){
        solve(ans,s,n,i+1,temp+' ');
        solve(ans,s,n,i+1,temp);
        return;
    }
    else {
        solve(ans,s,n,i+1,temp+s[i]);
        return;
    }
    return;
}

vector<string> permutation(string S){
    vector<string>ans;
    string s;
    int n=S.length();
    for(int i=0;i<n;i++){
        s+=S[i];
	    if(i!=n-1){
	    	s+=' ';
	    }
    }
     
    solve(ans,s,s.length(),0,"");
    return ans;
}


//Third Solution :- Iterative, bitmasks
vector<string> permutation(string S){
    vector <string> v;
    int n = S.size(), len = 1<<(n-1);
    
    for(int i=len-1; i>=0; i--){
        string s = "";
        for(int j=n-2; j>=0; j--){
            s += S[n-j-2];
            if(i&(1<<j)){
                s += " ";
            }
        }
        s += S[n-1];
        v.push_back(s);
    }
    return v;
}
