// Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 
// Example 1:
// Input: grid = {{0,1},{1,0},{1,1},{1,0}}
// Output: 1
// Explanation: The grid is-
// 			 0 1
// 			 1 0
// 			 1 1
// 			 1 0
// All lands are connected.

// Example 2:
// Input: grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output: 2
// Expanation: The grid is-
// 			0 1 1 1 0 0 0
// 			0 0 1 1 0 1 0 
// There are two islands one is colored in blue and other in orange.




//Solution Approach :-


class Solution {
  public:
  	void dfs(vector<vector<char>> &grid, int x, int y)
	{
	    if(x<0 || y<0 || x>=grid.size() || y>= grid[0].size() || grid[x][y]!='1'){
	    	return;
	    }
	    
	    grid[x][y] = '0';

	    //in leetcode we dont have to be worry about diagonal one here we have to take that one also
	    dfs(grid, x+1, y);
	    dfs(grid, x, y+1);
	    dfs(grid, x-1, y);
	    dfs(grid, x, y-1);
	    
	    // these are all the diagonal cases 
	    dfs(grid, x-1, y-1);
	    dfs(grid, x+1, y+1);
	    dfs(grid, x+1, y-1);
	    dfs(grid, x-1, y+1);
	}

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};




//Second Solution :-
int dx[] = { 0, 1, 1,  1,  0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1,  0,  1 };

class Solution {
  public:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int k = 0; k < 8; k++) {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1'){
                dfs(a, b, n, m, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), result = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == '0'){
                    continue;
                }
                result++;
                dfs(x, y, n, m, grid);
            }
        }
        return result;
    }
};



//Third Solution :-
void dfs(int r, int c,int n, int m, vector<vector<bool>>& vis, vector<vector<char>>&mat)
{
    if(r<0 || r>=n || c<0 || c>=m || vis[r][c]==true || mat[r][c]=='0'){
        return;
    }
    vis[r][c]=true;
    
    dfs(r+1,c,n,m,vis,mat);
    dfs(r,c+1,n,m,vis,mat);
    dfs(r-1,c,n,m,vis,mat);
    dfs(r,c-1,n,m,vis,mat);
    
    dfs(r-1,c-1,n,m,vis,mat);
    dfs(r+1,c+1,n,m,vis,mat);
    dfs(r-1,c+1,n,m,vis,mat);
    dfs(r+1,c-1,n,m,vis,mat);
  
}

int numIslands(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'&&vis[i][j]==false){
                dfs(i,j,n,m,vis,matrix);
                count++;
            }
        }
    }
    return count;
}