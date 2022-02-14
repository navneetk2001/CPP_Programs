Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes much.very.program.this.like.i

Example 2:
Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr


//Solution :-
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string>st;
        string s="";
        for(int i=0;i<S.size();i++){
        	if(S[i]!='.'){
        		s+=S[i];
        	}
        	if(S[i]=='.'){
        		st.push(s);
        		s="";
        	}
        }
        st.push(s);
        string res="";
        while(!st.empty()){
        	string str=st.top();
        	st.pop();
        	res+=str+".";
        }
        res.pop_back();
        return res;
    } 
};