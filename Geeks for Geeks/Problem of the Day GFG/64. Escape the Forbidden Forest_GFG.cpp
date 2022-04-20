// Penelope and her classmates are lost in the Forbidden Forest and the Devil is out to get them. But Penelope has magical powers that can build bridges across the dangerous river and take her friends to safety. The only bridges that can withstand the Devil's wrath are the ones built between two similar trees in the forest. 
// Given str1 and str2 denoting the order of trees on either side of the river, find the maximum number of bridges that Penelope can build and save everyone from the Devil. 
// Note: Each tree in the forest belongs to one of the 3 categories represented by * or # or @

// Example 1:
// Input:
// str1 = "*@#*" 
// str2 = "*#"
// Output:
// 2
// Explanation:
// str1 = "*@#*" and str2 = "*#" 
// Two bridges can be built between the banks of the river in the following manner. 
// * @ # *
// |      |
// *     #


// Example 2:
// Input:
// str1 = "***"
// str2 = "##"
// Output:
// 0



//Solution Approach :-  It is longest Common Subsequence problem
class Solution{
   public:
   vector<vector<int>> dp;
   int rec(string &str1, string &str2,int i,int j){
       if(i<0 or j<0)return 0;
       
       if((i==0 or j==0) and (str1[i]==str2[j])) return 1;
       
       if(dp[i][j]!=-1)
           return dp[i][j];
           
       int ans=0;
       if(str1[i]==str2[j])
           ans = rec(str1,str2,i-1,j-1)+1;
       else
           ans = max(rec(str1,str2,i,j-1),rec(str1,str2,i-1,j));
           
       return dp[i][j] = ans;
   }
   
   int build_bridges(string str1, string str2)
   {
      int n1 = str1.size(); int n2 = str2.size();
      dp.resize(n1,vector<int>(n2,-1));
     return rec(str1,str2,n1-1,n2-1);
   }
};




//Second Solution :-
int solve(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1]==s2[j-1]) 
            	dp[i][j]= 1+dp[i-1][j-1];
            else 
            	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n1][n2];
}

int build_bridges(string str1, string str2)
{
    return solve(str1, str2);
}


