// Given two strings A and B. Find minimum number of times A has to be repeated such that B is a Substring of it. If B can never be a substring then return -1.

// Example 1:
// Input:
// A = "abcd"
// B = "cdabcdab"
// Output: 3
// Explanation: Repeating A three times (“abcdabcdabcd”),
// B is a substring of it. B is not a substring of A when it is repeated less than 3 times.

// Example 2:
// Input:
// A = "ab"
// B = "cab"
// Output : -1
// Explanation: No matter how many times we repeat A, we can't get a string such that B is a substring of it.



//Solution Approach :-
class Solution {
  public:
    int minRepeats(string A, string B) {
        string str = A;
        int moves = 1;
        while(A.size()<B.size()){
            A+=str;
            moves++;
        }
        if(A.find(B)!=-1){    //check if B becomes a substring of A
            return moves;
        }

        A+=str;
        moves++;
        if(A.find(B)!=-1){
            return moves;
        }
        else{
            return -1;
        }
    }
};



//Second Solution :-
class Solution {
    static int minRepeats(String A, String B) {
        int c=1;
        String str=A;
       while(c!=1000){
            if(str.contains(B)){
               return c;
           }
           str=str+A;
           c++;
          
       }
       return -1;
    }



//Third Solution :- Based on KMP
vector<int> f(string s){
    vector<int> dp(s.length()+1,0);
    int start=0,end=1;
    while(end<s.length())
    {
        if(s[start]==s[end])
        {
            start++;
            dp[end]=start;
            end++;
        }
        else
        {
            if(start==0)
                dp[end++]=0;
            else
                start=dp[start-1];
        }
    }
    
    return dp;
}

bool f1(string s,string B)
{
    vector<int> v=f(B);
    int i=0,j=0;
    while(i<s.length())
    {
        // cout<<j<<endl;
        if(s[i]==B[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0)
                i++;
            else
                j=v[j-1];
        }
        if(j>=B.length())
            return true;
    }
    return false;
}

int minRepeats(string A, string B) {
    string s;
    int ans=0;
    while(s.length()<B.length()){
        s+=A;
        ans++;
    }

    if(f1(s,B)){
        return ans;
    }
    
    if(f1(s+A,B)){
        return ans+1;
    }
    return -1;
}
