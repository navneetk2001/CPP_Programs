We have N persons sitting on a round table. Any person can do a handshake with any other person.
     1
2         3
     4
Handshake with 2-3 and 1-4 will cause cross.
In how many ways these N people can make handshakes so that no two handshakes cross each other. N would be even. 

Example 1:
Input:
N = 2
Output:
1
Explanation:
{1,2} handshake is
possible.

Example 2:
Input:
N = 4
Output:
2
Explanation:
{{1, 2}, {3, 4}} are the
two handshakes possible.
{{1, 3}, {2, 4}} is another
set of handshakes possible.


//Solution :-
class Solution{
public:
    int count(int n){
        int dp[n+1];
    	memset(dp,0,sizeof(dp));
    
    	dp[0]=1;
    	for(int i=2;i<=n;i+=2){
    		for(int j=0;j<i;j+=2){
    			dp[i]+=dp[j]*dp[i-2-j];
    		}
    	}
    	return dp[n];
    }
};




//Solution :-
// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n+1];

    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    // Fill entries in catalan[] using recursive formula
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }

    // Return last entry
    return catalan[n];
}

// Returns count of ways to connect n points on a circle
// such that no two connecting lines cross each other and
// every point is connected with one other point.
unsigned long int countWays(unsigned long int n)
{
   // Throw error if n is odd
   if (n & 1)
   {
      cout << "Invalid";
      return 0;
   }

   // Else return n/2'th Catalan number
   return catalanDP(n/2);
}
