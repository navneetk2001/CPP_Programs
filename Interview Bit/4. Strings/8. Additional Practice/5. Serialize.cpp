// You are given an array A of strings and we have to serialize it and return the serialized string.
// Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.
// For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.

// Input 1: A = ['scaler', 'academy']
// Output 1: scaler6~academy7~
// Explanation 1: Length of 'scaler' is 6 and academy is 7. So, the resulting string is scaler6~academy7~.

// Input 2: A = ['interviewbit']
// Output 2: interviewbit12~
// Explanation 2: Explained in the description above.


//Solution Approach :-
// For each string, find its serialized version. Then, append all the strings together.
// For finding the serialized version. Find the length of the string and then change the string to:
// (string) + (length) + '~', where + denotes concatenation.
// For languages like Java, remember to use StringBuffer for appending.
// For languages like C++, remember to use += operator while appending.
// Refer to the complete solution for more implementation details.


// First Method :-
string Solution::serialize(vector<string> &A) {
    int n=A.size();
    string ans="";
    for(int i=0;i<n;i++){
        int sz=A[i].size();
        ans+=A[i]+to_string(sz)+'~';
    }
    return ans;
}


//Second Method :-
string Solution::serialize(vector<string> &A) {
    string ans="";
    for(auto i:A){
        int big=i.size();
        ans+=i;
        ans+=to_string(big);
        ans+='~';
    }
    return ans;
}






