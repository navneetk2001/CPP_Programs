// Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

// Example 1:
// Input: 
// n = 5
// p[] = {1, 2, 3, 4, 5}
// Output: (((AB)C)D)
// Explaination: The total number of 
// multiplications are (1*2*3) + (1*3*4) + (1*4*5) = 6 + 12 + 20 = 38.
 
// Example 2:
// Input: 
// n = 3
// p = {3, 3, 3}
// Output: (AB)
// Explaination: The total number of multiplications are (3*3*3) = 27.



//Solution Approach :-
// Time Complexity: O(n3)
// Space: O(n2)
// this is just slight modification of MCM
// in MCM we have to only return  min mul here we have to return that seq of bracket in string
// so for that we will take cnt as well string cnt contains mini mul and string contain ans at that cnt

class Solution{
public:
  	pair<int,string> recur(int p[], int n, int low, int high, pair<int,string> dp[27][27]){
      	if(low==high){      	// base as MCM when we return 0 and string is char at that index
          	char ch='A'+low;    // char at index
          	string s="";
          	s+=ch;
          	return {0,s};
      	}
      	

      	if(dp[low][high].first!=-1){      	// now memozization part checking if that sub array we already cal
          	return dp[low][high];
      	}

      	pair<int,string> res;
       	res.first=INT_MAX;// as we have to minimize this as MCM
      
        // now trying all possiblity btw low to high and see where we can get mini result
      	for(int i=low;i<high;i++){
          	auto left=recur(p,n,low,i,dp);       // taking left part
          	auto right=recur(p,n,i+1,high,dp);   // taking right part
          
          	int tempRes=left.first+right.first+(p[low]*p[i+1]*p[high+1]);//same as MCM
          	if(res.first>tempRes){
              	res.first=tempRes;
              	res.second="("+left.second+right.second+")";
          	}
      	}	
      
      	return dp[low][high]=res;
      
  	}

   	string matrixChainOrder(int p[], int n){
        pair<int,string> dp[27][27];
        pair<int,string> empty;
        empty.first=-1;                // intilizing with empty and cnt is -1 for all intially

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
            	dp[i][j]=empty;
            }
        }
        
        int low=0, high=n-2;     // here from where we start putting bracket is low and upto high we can put 
         
        return recur(p,n,low,high,dp).second;
   }
};



//Second Solution :- Iterative Solution
// Just normal matrix multiplication      // in code, ff means first , ss means second 
string matrixChainOrder(int p[], int n){
    pair<int , string> dp[n][n] ;
    
    for(int gap = 1 ; gap<n ; gap++){
        for(int i = 0 ; i<n - gap; i++){
            int j = i + gap ;
            if(gap == 1){
                string res = "0" ;
                res[0] = 'A' + i;
                dp[i][j] = {0 , res} ; 
            }
            else{
                dp[i][j] = {INT_MAX, "-1"} ;
                for(int k = i+1 ; k<=j-1 ; k++){
                    int cost = p[i] * p[k] * p[j] + dp[i][k].ff + dp[k][j].ff ;
                    if(dp[i][j].ff > cost){
                       dp[i][j].ff = cost ; 
                       dp[i][j].ss = "(" + dp[i][k].ss + dp[k][j].ss + ")" ;
                    } 
                }
            }
        }
    }
    return dp[0][n-1].second ;
}




//Third Solution :-
class Solution{
public:
    pair<int, string> solve(int p[], int n, int low, int high, pair<int, string> dp[27][27])
    {
        if(low == high)
        {
            char ch = 'A' + low;
            string s = "" ; 
            s += ch;
            pair<int, string> pr = {0, s};
            return pr;
        }
        
        if(dp[low][high].first != -1)
            return dp[low][high];

        pair<int, string> ans;
        ans.first = INT_MAX;
        for(int i=low; i<high; i++)
        {
            pair<int, string> p1 = solve(p, n, low, i, dp);
            pair<int, string> p2 = solve(p, n, i+1, high, dp);
            
            int temp = p1.first + p2.first + (p[low] * p[i+1] * p[high+1]);
            if(ans.first > temp)
            {
                ans.first = temp;
                ans.second = "(" + p1.second + p2.second + ")";
            }
        }
        return dp[low][high] = ans;
    }

    string matrixChainOrder(int p[], int n){
        pair<int, string> dp[27][27];
        pair<int, string> empty; empty.first = -1;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = empty;
            }
        }
        return solve(p, n, 0, n-2, dp).second;
    }
};



