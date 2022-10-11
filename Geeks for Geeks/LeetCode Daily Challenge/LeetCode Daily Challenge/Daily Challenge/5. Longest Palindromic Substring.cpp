// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

// Example 1:
// Input: S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest palindrome string present in the given string is "aabbaa".



//Solution Approach :-
class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
    }
};


//Second Solution :-
int expand(string s,int i,int j){
    while(i>=0 && j<s.size() && s[i]==s[j]){
        j++;
        i--;
    }
    j--;
    i++;
    
    return j-i+1;
}

string longestPalindrome(string s){
    int l=0,r=0,ans,n=s.size();
    reverse(s.begin(),s.end());
    
    for(int i=0;i<n;i++){
        int res1 = expand(s,i,i+1);
        int res2 = expand(s,i,i);
        
        ans = max(res1,res2);
        if(r-l<ans){
            l = i-(ans-1)/2;
            r = i+(ans)/2;
        }
    }
    return s.substr(l,r-l+1);
}



//Third Solution :-
string longestPalindrome(string s){
  	int start = 0, len = 0;
    int n = s.size(), l, r ;
    
    for(int i=0; i<n; i++){
        l = i, r = i;           // Odd Length strings
        while( l>=0 && r<n && s[l] == s[r]){
        	l--; r++; 
        }
        if(r-l-1 > len){
        	len = r-l-1; 
        	start = l+1;
        }
        
        l = i-1, r = i;         // Even Length strings
        while( l>=0 && r<n && s[l] == s[r]){
        	l--; r++;
        }
        if(r-l-1 > len){
        	len = r-l-1; 
        	start = l+1;
        }
    }

    return s.substr(start, len); 
}



//Fourth Solution :-  Long code but simple approach ans easy to understand using 2d dp table
class Solution{   
public:
    string longestPalindrome(string str)
    {
        int n = str.length();
        int dp[n][n];
        int maxLength=1;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                dp[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }

        for(int i=0;i<n;i++)
        {
            if(str[i]==str[i+1])
            {
                dp[i][i+1] = 1;
                if(maxLength<2)
                {
                start = i;
                end = i+1;
                maxLength = 2;
                }
            }
        }

        for(int i=2;i<n;i++){
            for(int j=0,k=i;j<n-i,k<n;j++,k++){
                if(str[j]==str[k] && dp[j+1][k-1]==1)
                {
                    dp[j][k] = 1;
                    if(maxLength<abs(k-j+1))
                    {
                    start = j;
                    end = k;
                    maxLength = max(maxLength,abs(k-j+1));
                    }
                }
            }
        }

        return str.substr(start,end-start+1);
    }
};




//C++ Brute Force Solution :-> 
bool isPalindrome(string S){
   int i = 0, j = S.size() - 1;
   while(i < j){
       if(S[i++] != S[j--]){
           return false;
       }
   }
   return true;
}

string longestPalindrome(string S){
   	if(S.size() == 1) return S;
	int n = S.size();
	string result = "";
   
   for(int i = 0; i < n-1; i++){
       for(int j = 1; j <= n-i; j++){
           if(isPalindrome(S.substr(i,j))){
               if(result.size() < j){
                   result = S.substr(i,j);
               }
           }
       }
   }
   return result;
}