// You are given a matrix having n rows and m columns. The special property of this matrix is that some of the cells of this matrix are blocked i.e. they cannot be reached. Now you have to start from the cell (1,1) and reach the end (n,m) provided during the journey you can move horizontally right from the current cell or vertically down from the current cell. Can you answer the number of ways you can traverse the matrix obeying the above constraints starting from (1,1) and ending at (n,m).
 
// Example 1:
// Input: n = 3, m = 3, k = 2,
// blocked_cells = {{1,2},{3,2}}.
// Output: 1
// Explanation: There is only one path from (1,1) to(3,3) which is (1,1)->(2,1)->(2,2)->(2,3)->(3,3).

// Example 2:
// Input: n = 5, m = 5, k = 1,
// blocked_cells = {{5,5}}
// Output: 0
// Explanation: There is no path to reach at (5,5) beacuse (5,5) is blocked.



//Solution Approach :-
const unsigned int mod = 1e9 + 7;
    
int FindWays(int n, int m, vector<vector<int>>arr){
    vector<vector<int>>temp(n, vector<int>(m, 0));
    for(int i = 0; i < arr.size(); i++){
        temp[arr[i][0] - 1][arr[i][1] - 1] = -1;
    }
    
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(temp[i][j] == -1){
                dp[i][j] = 0;
            }
            
            else if(i == 0 and j == 0){
                dp[i][j] = 1;
            }
            
            else{
                int right = 0, down = 0;
                if(j > 0)
                    right = dp[i][j - 1];
               if(i > 0)
                    down = dp[i - 1][j];
                    
               dp[i][j] = (right + down) % mod;
            }
        }
    } 
    return dp[n - 1][m - 1];
}


//Second Solution :-
int mod= 1e9+7;
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	   map<pair<int, int>, bool> mp;
	   vector<vector<int>> dp(n, vector<int>(m, 0));
	   for(auto i: blocked_cells) mp[{i[0]-1, i[1]-1}]=1;
	   for(int i=0; i<n; i++){
	       for(int j=0; j<m; j++){
	           if(mp[{i, j}]==1) {
	               dp[i][j]=0;
	           }
	           else if(i==0 && j==0){
	               dp[i][j]=1;
	           }
	           else{
	               if(i>0) dp[i][j] += dp[i-1][j];
	               if(j>0) dp[i][j] += dp[i][j-1];
	           }
	       }
	   }
	   return dp[n-1][m-1]%mod;
	}