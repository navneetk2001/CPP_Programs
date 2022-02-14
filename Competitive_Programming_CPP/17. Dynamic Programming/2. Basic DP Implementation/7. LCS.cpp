Longest Common Subsequence (LCS) :- 
--------------------------------------
s1 = "ABCD"
s2 = "ABEDG"

O/P :- 3 (ABD) present in both


#include<iostream>
#include<climits>
using namespace std;

//Recursive case
int LCS(string s1, string s2, int i, int j){
	//base case
	if(i==s1.length() or j==s2.length()){
		return 0;
	}

	//rec case
	if(s1[i]==s2[j]){
		return 1+lcs(s1,s2,i+1,j+1);
	}
	
	int op1=lcs(s1,s2,i+1,j);
	int op2=lcs(s1,s2,i,j+1);

	return max(op1, op2);
} 

//Top Down dp solution :- 
int LCS_dp(string s1, string s2, int i, int j, vector<vector<int>> &dp){
	//base case
	if(i==s1.length() or j==s2.length()){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	//rec case
	if(s1[i]==s2[j]){
		return dp[i][j] =1+lcs(s1,s2,i+1,j+1,dp);
	}
	
	int op1=lcs(s1,s2,i+1,j,dp);
	int op2=lcs(s1,s2,i,j+1,dp);

	return dp[i][j] =max(op1, op2);
} 


int main(){
    string s1="ABCD"
    string s2="ABEDG"

	cout<<LCS(s1,s2,i,j)<<endl;
    
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));

	cout<<LCS_dp(s1,s2,i,j,dp)<<endl;

	return 0;
}
