// Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 
// Example 1:
// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output: 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.

// Example 2:
// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output: 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 
// There are two islands one is colored in blue and other in orange.



:-> this question is :- Counting the number of connected components in a grid or graph

//Solution Approach :- 
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>= grid[0].size() || grid[x][y]!='1')
        return;
        
        grid[x][y] = '0';
        //in leetcode we dont have to be worry about diagonal one
        //here we have to take that one also
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


    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};


//Second Solution :- Using visited array and dfs
void dfs(vector<vector<char>>&grid,int i,int j,int row,int col,vector<vector<bool>>&visited)
{
    if(i<0 || i>=row || j<0 || j>=col || grid[i][j]=='0' || visited[i][j]==true)
     	return;
     
    visited[i][j]=true;     
    //visit dfs in all 8 dirn
    dfs(grid,i-1,j,row,col,visited);
    dfs(grid,i+1,j,row,col,visited); 
    dfs(grid,i,j+1,row,col,visited);
    dfs(grid,i,j-1,row,col,visited);
    dfs(grid,i+1,j+1,row,col,visited);
    dfs(grid,i+1,j-1,row,col,visited);
    dfs(grid,i-1,j-1,row,col,visited);
    dfs(grid,i-1,j+1,row,col,visited);
}


// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
   // Code here
   int row=grid.size();
   int col=grid[0].size();
   int count=0;
   vector<vector<bool>> visited(row, vector<bool>(col, false));
   
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
          if(visited[i][j]==false && grid[i][j]=='1')
          {
           dfs(grid,i,j,row,col,visited);
           count++;
          }
       }
       }
   return count;
}