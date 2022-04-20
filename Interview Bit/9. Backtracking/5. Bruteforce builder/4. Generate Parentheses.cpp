// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

//First Solution :-
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


//Second Solution :-
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
    
    void solve(int i,int j,int n,string s,vector<string>&ans){
        if(s.length()==n*2) 
        	ans.push_back(s);

        if(i<n) solve(i+1,j,n,s+"(",ans);
        if(j<i) solve(i,j+1,n,s+")",ans);
    }
};


//Third Solution :- 
class Solution {
public:
    // Same as generate BSTs
    vector<string> generateParenthesis(int n) {
        return help(1,n);
    }
    
    vector<string> help(int start, int end){
        if(start>end){
            return {""};
        }
        vector <string > ans ;
        for (int i = start ; i<=end ;i++){
            vector <string> InsideParenthesis = help(start,i-1);
            vector <string> OutsideParenthesis = help(i+1,end);
            for (auto l : InsideParenthesis){
                for (auto r : OutsideParenthesis){
                    string s="(";
                    s+=l;
                    s+=")";
                    s+=r;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};



//Fourth Solution :- 
class Solution {
public:
    bool go(string p,int n)
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(p[i]=='(') s.push(i);
            else
            {
                if(s.empty()) return false;
                s.pop();
            }
        }
        if(!s.empty()) return false;
        return true;
    }

    vector<string> generateParenthesis(int n)
    {
        int i,j,m;
        string s;
        vector<string>v;
        n+=n;
        m=1ll<<n;
        for(i=0;i<m;i++)
        {
            s.clear();
            for(j=0;j<n;j++)
            {
                if(((i>>j)&1)==1) s+="(";
                else s+=")";
            }
            if(go(s,n)==true) v.push_back(s);
        }
        return v;
    }
};

