// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:
// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall.
// Note: There are only a single source and a single destination.
 
// Example 1:
// Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0 
// 3 0 0 0 3 
// 3 3 3 3 3 
// 0 2 3 0 0 
// 3 0 0 1 3 
// There is no path to reach at (3,1) i,e at destination from (4,3) i,e source.

// Example 2:
// Input: grid = {{1,3},{3,2}}
// Output: 1
// Explanation: The grid is-
// 1 3
// 3 2
// There is a path from (0,0) i,e source to (1,1) i,e destination.
 



//Solution Approach :-
class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    bool DFS(vector<vector<int>> &grid, int i, int j){
        int n = grid.size();
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 0){
               continue;
            }
            
            if(grid[r][c] == 2){
               return true;
            }
            
            if(DFS(grid, r, c)){
               return true;
            }
        }
        return false;
    }
   
    bool is_Possible(vector<vector<int>>& grid){
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if (DFS(grid, i, j)){
                       return true;
                    }
                }
            }
        }
        return false;
    }
};



//Second Solution :-
bool solve(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 or j < 0 or i >= n or j >= m) {
        return false;
    }
    
    if(grid[i][j] == 2) {
        return true;
    }
    
    if(grid[i][j] == 0  or grid[i][j] == 9) {
        return false;
    }
    
    int ch = grid[i][j];
    grid[i][j] = 9;
    
    // explore all path
    int op1 = solve(grid, i+1, j);
    int op2 = solve(grid, i, j+1);
    int op3 = solve(grid, i-1, j);
    int op4 = solve(grid, i, j-1);
    
    grid[i][j] = ch;
    
    return op1 or op2 or op3 or op4;
}

bool is_Possible(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                if(solve(grid, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}



//Third Solution :- BFS Solution
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

bool isSafe(int x,int y,vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    if(x>=n or x<0 or y>=m or y<0){
    	return 0;
    }
    return 1;
}

bool is_Possible(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    int x=-1,y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                x=i,y=j;
                break;
            }
        }
        if(x!=-1 and y!=-1){
        	break;
        }
    }

    bool vis[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=0;
        }
    }
    
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        int px=q.front().first;
        int py=q.front().second;
        q.pop();

        if(grid[px][py]==2){
            return 1;
        }
        for(int i=0;i<4;i++){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if(isSafe(nx,ny,grid) and grid[nx][ny]!=0 and !vis[nx][ny]){
                vis[nx][ny]=1;
                q.push({nx,ny});
            } 
        }
    }
    return 0;
}