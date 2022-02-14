Given a string str of lowercase ASCII characters, Count the number of distinct continuous palindromic sub-strings which are present in the string str.

Example 1:

Input:
str = "abaaa"
Output:
5
Explanation : These are included in answer:
"a","aa","aaa","aba","b"



//Simple Approach :-
//1. Find all substring and Check each one by one for palindrome 
// But it will take O(n^3) time complexity


// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
      int n = s.length();
      bool a[n][n];
      memset(a, false, sizeof(a));
      unordered_set<string> p;
      
      for(int gap = 0; gap < n; gap++)
      {
          for(int i = 0, j = gap; i < n - gap; i++, j++)
          {
              if(s[i] == s[j])
              {
                  if(i == j)
                      a[i][j] = true;
                  else if(gap == 1)
                      a[i][j] = a[i][j - 1];
                  else
                      a[i][j] = a[i + 1][j - 1];
              }
              
              if(a[i][j])
                  p.insert(s.substr(i, j - i + 1));
          }
      }
      
      return p.size();
    }
};


// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends




//Second Method :- 
set<string>st;
bool isPalindrome(int i, int j, string &s, vector<vector<int>>&dp){
    if(i>=j) 
    return 1;

    if(dp[i][j]!=-1) 
    return dp[i][j];

    if(s[i]!=s[j]) 
    return dp[i][j] = 0;

    return dp[i][j] = isPalindrome(i+1,j-1,s,dp);
}

class Solution{
  public:
    int palindromeSubStrs(string s) {
      set<string>st;
      int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
                    st.insert(s.substr(i,j-i+1));
                }
            }
        }
        return st.size();
    }
};



//Third Method :-
// C++ program to find palindromic substrings of a string
#include <bits/stdc++.h>
using namespace std;

// Returns total number of palindrome substring of
// length greater then equal to 2
int CountPS(char str[], int n)
{
    // create empty 2-D matrix that counts all palindrome
    // substring. dp[i][j] stores counts of palindromic
    // substrings in st[i..j]
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // P[i][j] = true if substring str[i..j] is palindrome,
    // else false
    bool P[n][n];
    memset(P, false, sizeof(P));

    // palindrome of single length
    for (int i = 0; i < n; i++)
        P[i][i] = true;

    // palindrome of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            P[i][i + 1] = true;
            dp[i][i + 1] = 1;
        }
    }

    // Palindromes of length more than 2. This loop is
    // similar to Matrix Chain Multiplication. We start with
    // a gap of length 2 and fill the DP table in a way that
    // gap between starting and ending indexes increases one
    // by one by outer loop.
    for (int gap = 2; gap < n; gap++) {
        // Pick starting point for current gap
        for (int i = 0; i < n - gap; i++) {
            // Set ending point
            int j = gap + i;

            // If current string is palindrome
            if (str[i] == str[j] && P[i + 1][j - 1])
                P[i][j] = true;

            // Add current palindrome substring ( + 1)
            // and rest palindrome substring (dp[i][j-1] +
            // dp[i+1][j]) remove common palindrome
            // substrings (- dp[i+1][j-1])
            if (P[i][j] == true)
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1
                        - dp[i + 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j]
                        - dp[i + 1][j - 1];
        }
    }

    // return total palindromic substrings
    return dp[0][n - 1];
}

// Driver code
int main()
{
    char str[] = "abaab";
    int n = strlen(str);
    cout << CountPS(str, n) << endl;
    return 0;
}



//Fourth Method :-
// C++ program to count all distinct palindromic
// substrings of a string.
#include <bits/stdc++.h>
using namespace std;

// Returns total number of palindrome substring of
// length greater than equal to 2
int countPalindromes(string s)
{
    unordered_map<string, int> m;
    for (int i = 0; i < s.length(); i++) {

        // check for odd length palindromes
        for (int j = 0; j <= i; j++) {

            if (!s[i + j])
                break;

            if (s[i - j] == s[i + j]) {

                // check for palindromes of length
                // greater than 1
                if ((i + j + 1) - (i - j) > 1)
                    m[s.substr(i - j,
                        (i + j + 1) - (i - j))]++;

            } else
                break;
        }

        // check for even length palindromes
        for (int j = 0; j <= i; j++) {
            if (!s[i + j + 1])
                break;
            if (s[i - j] == s[i + j + 1]) {

                // check for palindromes of length
                // greater than 1
                if ((i + j + 2) - (i - j) > 1)
                    m[s.substr(i - j,
                        (i + j + 2) - (i - j))]++;

            } else
                break;
        }
    }
    return m.size();
}

// Driver code
int main()
{
    string s = "abbaeae";
    cout << countPalindromes(s) << endl;
    return 0;
}




//Fifth Method :-
class Solution{
 public:
   int palindromeSubStrs(string s)
   {    int n=s.size();
       unordered_set<string>set;
       
       for(int i=0;i<s.size();i++)
       {  
            string temp="";
            temp+=s[i];
       
           set.insert(temp);
           int l=i-1,r=i+1;
       while(l>=0 && r<n && s[l]==s[r])
       {
            temp =s.substr(l,r-l+1);
            set.insert(temp);
             l--;r++;
       }
       
        l=i,r=i+1;
       while(l>=0 && r<n && s[l]==s[r])
       {
            temp =s.substr(l,r-l+1);
            set.insert(temp);
             l--;r++;
       }
       }
      // for(auto i:set)cout<<i<<" ";
       return set.size();
       
   }
};




//
class Solution{
  public:
    int palindromeSubStrs(string s) {
        int n = s.length();
        set<string>st;
        string curr = "";
        
        //odd
        for(int i=0;i<n;i++){
            int left = i-1,right = i+1;
            while(left >= 0 and right < n){
                if(s[left] == s[right]){
                    curr = s.substr(left,right-left+1);
                    st.insert(curr);
                    left--;
                    right++;
                }
                else break;
            }
        }
        
        //even
        for(int i=0;i<n-1;i++){
            int left = i;
            int right = i + 1;
            if(s[left] == s[right]){
                while(left >= 0 and right < n){
                    if(s[left] == s[right]){
                        curr = s.substr(left,right-left+1);
                        st.insert(curr);
                        left--;
                        right++;
                    }
                    else break;
                }
            }
        }
        
        //individual characters
        for(auto x : s) {
            string curr = "";
            curr += x;
            st.insert(curr);
        }
        return st.size();
    }
};