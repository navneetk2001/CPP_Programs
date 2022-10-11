// Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

// Example 1:
// Input: 1 2 3
//        4 5 6
// Output: 1 4 5 6
//         1 2 5 6 
//         1 2 3 6
// Explanation: We can see that there are 3 paths from the cell (0,0) to (1,2).

// Example 2:
// Input: 1 2
//        3 4
// Output: 1 2 4
//         1 3 4



//Solution Approach :- 
class Solution{
public:	
	vector<vector<int>> ans;
	void paths(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int>& arr)
	{
	    arr.push_back(grid[i][j]);
	    if(i+1 < n){  
	        paths(i+1,j,n,m,grid,arr);
	    }
	    if(j+1 < m){
	        paths(i,j+1,n,m,grid,arr);
	    }
	    if(i==n-1 && j==m-1){
	        ans.push_back(arr);
	    }
	    arr.pop_back();
	}
    
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> arr;
        paths(0,0,n,m,grid,arr);
        return ans;
    }
};



//Second Solution :-
class Solution
{
public:
     vector<vector<int>> outans;
     void dfs(int i,int j, vector<vector<int>>&grid,vector<int>path){
         if(i>=grid.size()||j>=grid[0].size()){
             return;
         }
         if(j==grid[0].size()-1&&i==grid.size()-1){
             path.push_back(grid[i][j]);
             outans.push_back(path);
             return;
         }
         path.push_back(grid[i][j]);
         dfs(i+1,j,grid,path);
         dfs(i,j+1,grid,path);
     }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
        vector<int>path;
        dfs(0,0,grid,path);
        return outans;
    }
};