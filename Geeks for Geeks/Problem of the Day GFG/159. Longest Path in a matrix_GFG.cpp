Given a n*m matrix, find the maximum length path (starting from any cell) such that all cells along the path are in strictly increasing order.
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1).
 
Example 1:
Input: matrix = {{1,2,9},{5,3,8},{4,6,7}}
Output: 7
Explanation: The longest increasing path is {1,2,3,6,7,8,9}.

Example 2:
Input: matrix = {{3,4,5},{3,2,6},{2,2,1}}
Output: 4
Explanation: The longest increasing path is {3,4,5,6}.




//Solution Approach :- Memoization
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int path(vector<vector<int>>& matrix , int n , int m , int x ,int y ,vector<vector<int>> &dp){
    if(x < 0 || y <0 || x>=n || y>=m){
        return 0 ;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    int val = 1 ;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i] ;
        int ny = y + dy[i] ;
        if(nx >= 0 && ny >= 0  && nx < n && ny < m && matrix[nx][ny] > matrix[x][y]){
            val = max(val , 1 + path(matrix , n , m, nx ,ny,dp)) ;
        }
    }
    return dp[x][y] = val ;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n= matrix.size()  , m= matrix[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
    
    int ans = 0; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<m ;j++){
            ans = max(ans , path(matrix , n , m, i , j , dp)) ;
        }
    }
    return ans ;
}



//Second Solution :- BFS Solution Using queue
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int d[] = {1, 0, -1, 0, 1};
        vector<vector<int>> dp(m, vector<int>(n));
        queue<pair<int, int>> que;
        int ma = 0;
        
        for (int i = 0; i < m; ++i)
        	for (int j = 0; j < n; ++j)
        	{
        		if (dp[i][j])
        			continue;
        		
        		que.push({i, j});
        		dp[i][j] = 1;
        		
        		while (que.size())
        		{
        			int i = que.front().first;
        			int j = que.front().second;
        			que.pop();
        			
        			for (int k = 0; k < 4; ++k)
        			{
        				int ii = i + d[k];
        				int jj = j + d[k + 1];
        				
        				if (0 <= ii && ii < m && 0 <= jj && jj < n && matrix[i][j] < matrix[ii][jj])
        				{
        					if (dp[ii][jj] < dp[i][j] + 1)
        					{
        						dp[ii][jj] = dp[i][j] + 1;
        						que.push({ii, jj});
        						
        						ma = max(ma, dp[ii][jj]);
        					}
        				}
        			}
        		}
        	}
        
        return ma;
    }
};


