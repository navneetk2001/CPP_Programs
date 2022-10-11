// Given a string A.
// Return the string A after reversing the string word by word.
// NOTE:
// A sequence of non-space characters constitutes a word.
// Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
// If there are multiple spaces between words, reduce them to a single space in the reversed string.


//Solution Approach
// One simple approach is a two-pass solution:
// First pass to split the string by spaces into an array of words
// Then second pass to extract the words in reversed order
// We can do better in one-pass. While iterating the string in reverse order, we keep track of a word’s beginning and end position.
// When we are at the beginning of a word, we append it.


// First Method :-
string Solution::solve(string s) {
    string ans="";
    int i,j,n=s.length();
    i=0;
    while(i<n){
        while(i<n && s[i]==' '){  // Do not include leading spaces
            i++;
        }
        
        j=i;
        while(j<n && s[j]!=' '){   //Till when we do not reach a space, means we are currently on a word
            j++;
        }
        
        ans=" "+s.substr(i,j-i)+ans;   // Here j is pointing to the next index of the ending of the current word, Due to this when passing length as 2nd parameter in substr fn, We pass j-i not j-i+1
        i=j+1;
    }

    // Remove leading spaces
    i=0;
    while(i<n && ans[i]==' '){
        i++;
    }
    ans=ans.substr(i);
    return ans;
}


//Second Method :-
class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string words;
        string ans = "";
        while(str >> words){
            ans = words + " " + ans;
        }
        return ans.substr(0,ans.size()-1);
    }
};


//Third Method :-
string Solution::solve(string A) {
    stringstream ss(A);
    stack<string> st;
    string word;
    while(ss>>word){
        st.push(word);
    }
    
    string op;
    while(st.size()){
        string s2=st.top();
        st.pop();
        op+=s2;
        op+=" ";
    }
    op.pop_back();
    return op;
}

//Fourth Method :-
void Solution::reverseWords(string &A) {
    
    int n = A.length();
    vector<string> curr; string res,temp;
    for(int i=0;i<n;i++){
        if(A[i]==' ' && A[i+1] != ' '){
            curr.push_back(temp);
            temp = "";
        }
        else if(A[i]== ' ' && A[i+1] == ' ')
            continue;
        else{
            temp += A[i];
        }
    }
    curr.push_back(temp);
    for(int i=curr.size()-1;i>0;i--){
        res += curr[i] + " ";
    }
    res += curr[0];
    A = res;
}


//Fifth Method :-
string Solution::solve(string s) 
{
    stack<string>stk;
    int n=s.length(),i=0;
    while(i<n)
    {
        string tmp="";
        while(i<n && s[i]!=' ')
        {
            tmp.push_back(s[i]);
            i++;
        }
        if(tmp!="")
        {
            stk.push(tmp);
        }
        i++;
    }
    s="";
    while(!stk.empty())
    {
        s+=stk.top();
        if(stk.size()>1)
        {
            s+=" ";
        }
        stk.pop();
    }
    return s;
}
