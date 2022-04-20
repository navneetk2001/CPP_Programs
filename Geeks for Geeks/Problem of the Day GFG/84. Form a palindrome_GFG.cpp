Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Example 1:
Input: abcd
Output: 3
Explanation: Here we can append 3 characters in the beginning,and the resultant string will be a palindrome ("dcbabcd").

Example 2:
Input: aba
Output: 0
Explanation: Given string is already a pallindrome hence no insertions are required.


//Solution Approach :-
class Solution{   
public:
    int rec(int l, int r, string s){
    	if(l>=r){
    		return 0;
    	}
    	int ans;
    	if(s[l]==s[r]){
    		ans = rec(l+1,r-1,s);
    	}
    	else{
    		ans=min(rec(l+1,r,s), rec(l,r-1,s)) + 1;
    	}
    	return ans;
    }
    
    int findMinInsertions(string s){
        int n=s.size();
        return rec(0,n-1,s);
    }
};


//Second Solution :-   memoization
class Solution{   
public:
	int dp[500][500];
    int rec(int l, int r, string s){
    	if(l>=r){
    		return 0;
    	}
    	int ans;
    	if(dp[l][r]!=-1){
    		return dp[l][r];
    	}
    	if(s[l]==s[r]){
    		ans = rec(l+1,r-1,s);
    	}
    	else{
    		ans=min(rec(l+1,r,s), rec(l,r-1,s)) + 1;
    	}
    	dp[l][r]=ans;
    	return ans;
    }
    
    int findMinInsertions(string s){
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,s);
    }
};



//Third Solution :-
class Solution{   
public:
    int lcs(string s1,string s2,int n,int m){
       int t[m+1][n+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<m+1;j++){
               if(i==0 or j==0){
                   t[i][j]=0;
               }
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<m+1;j++){
               if(s1[i-1]==s2[j-1]){
                   t[i][j]= 1+t[i-1][j-1];
               }else{
                   t[i][j]= max(t[i-1][j],t[i][j-1]);
               }
           }
       }
       return t[n][m];
    }
    int findMinInsertions(string s1){
        string s2= s1;
        reverse(s2.begin(),s2.end());
        int n= s1.length();
        int ans= lcs(s1,s2,n,n);
        return n-ans;
    }
};