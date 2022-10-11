// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b. 

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

// Example 3:
// Input: s1 = "", s2 = "", s3 = ""
// Output: true



//Solution Approach :-
//Approach-1 (Recursion + Memoization (i, j, k))
class Solution {
public:
    int m, n, N;
    int t[101][101][201];
    bool check(string s1, string s2, string s3, int i, int j, int k) {
        if(i >= m && j >= n && k >= N){     //base case
            return true;
        }
        
        if(k >= N){      //other string didn't get consumed whole
            return false;
    	}
            
        if(t[i][j][k] != -1){
            return t[i][j][k];
        }
        
        return t[i][j][k] = ((s1[i]==s3[k] && check(s1, s2, s3, i+1, j, k+1)) || (s2[j]==s3[k] && check(s1, s2, s3, i, j+1, k+1)));
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        return check(s1, s2, s3, 0, 0, 0);
    }
};




//Approach-2 (Recursion + Memoization (i, j))
class Solution {
public:
    int m, n, N;
    int t[101][101];
    
    bool check(string s1, string s2, string s3, int i, int j) {
        if(i >= m && j >= n && i+j >= N) //solution
            return true;
        
        if(i+j >= N){       //other string didn't get consumed whole
            return false;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        //Note that, k is same for both calls because it increases in both cases  //Also, at any time k = i + j;
        return t[i][j] = ((s1[i]==s3[i+j] && check(s1, s2, s3, i+1, j)) || (s2[j]==s3[i+j] && check(s1, s2, s3, i, j+1)));
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        if(m + n != N){
            return false;
        }
        
        return check(s1, s2, s3, 0, 0);
    }
};



//Approach - 3 (Bottom Up : Time and Space : O(m*n))
class Solution {
public:   
    bool check(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(m + n != N){
            return false;
        }
        
        int t[m+1][n+1];        //t[i][j] = true; //means, s1[0..i] and s2[0...j] interleaves with s3 till (i+j)
        
        t[0][0] = true;         //length of s1 = 0, s2 = 0 and s3 = 0 + 0, i.e. 0 . So obviously it's interleaved :-)
        
        for(int j = 1; j<n+1; j++){      //When s1 is of 0 length, we can interleave only when s2 forms s3
            t[0][j] = t[0][j-1] && s2[j-1]==s3[j-1];
        }
        
        for(int i = 1; i<m+1; i++){        //When s2 is of 0 length, we can interleave only if s1 forms s3
            t[i][0] = t[i-1][0] && s1[i-1]==s3[i-1];
        }
        
        
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                int k = i + j - 1;
                
                bool s1_equals_s3  = t[i-1][j] && s1[i-1] == s3[k]; //Try with s1
                bool s2_equals_s3  = t[i][j-1] && s2[j-1] == s3[k]; //Try with s2
                
                t[i][j] = s1_equals_s3 || s2_equals_s3 ;
            }
        }
        
        return t[m][n];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3);
    }
};




//Approach - 4 (Bottom Up : Space O(n), Time O(m*n) : Converting Approach-3 to O(n) space approach)
class Solution {
public:   
    bool check(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(m + n != N){
            return false;
        }
        
        bool t[n+1];
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 && j == 0) {
                    t[j] = true;
                } 
                else if(i == 0) {
                    t[j] = t[j-1] && s2[j-1]==s3[i+j-1];
                } 
                else if (j == 0){
                    t[j] = t[j] && s1[i-1]==s3[i+j-1];
                } 
                else{
                    t[j] = (t[j-1] && s2[j-1]==s3[i+j-1]) || (t[j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        
        return t[n];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3);
    }
};


