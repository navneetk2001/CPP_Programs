Given an string A. The only operation allowed is to insert  characters in the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.

Output Format:-
Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".

//Hint :-
Try to learn about LPS array used in KMP string matching algorithm. Modify your string and compute its LPS array to derive the answer

//Solution Approach :-
Each index of LPS array contains the longest prefix which is also a suffix. Now take the string and reverse of a string and combine them with a sentinal character in between them and compute the LPS array of this combined string. Now take the last value of the LPS array and subtract it with the length of the original string, This will give us the minimum number of insertions required in the begining of the string .


// First Method :-
vector<int> prefix_function(string s) {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int Solution::solve(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    auto kmp = prefix_function(s + '#' + rev_s).back();
    string add = s.substr(kmp, s.size() - kmp);
    //reverse(add.begin(), add.end());
    return s.size()-kmp;
}


//Second Method :-
int Solution::solve(string A) {
    int n= A.length();
    int palen;
    int count=0;
    for(int i=0;i<n;i++){
        palen=0;
        for(int j=0;j<=(n-i)/2;j++){
            if(A[j]==A[n-i-j-1])
              continue;
              else
              {palen=1;
              break;}
        }
       if(palen==1)
            count++;
       else
            break;
       
    }
    return count;
}

//Third Method :-
int Solution::solve (string A) {
    int start = 0, end = A.length() - 1, rec = A.length () - 1;
    while (start < end) {
        if (A [start] == A [end]) {
            start ++;
            end --;
        } else {
            start = 0;
            rec --;
            end = rec;
        }
    }
    return A.length () - rec - 1;
}
