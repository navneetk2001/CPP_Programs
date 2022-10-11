// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.

// Example 2:
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0




//Solution Approach :- DFS
int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
        grid[i][j] = 0;
        return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int max_area = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
            	max_area = max(max_area, AreaOfIsland(grid, i, j));
            }
        }
    }
    return max_area;
}



//Second Solution :- BFS
class Solution {
public:
    int dir[5]= {0, 1, 0, -1, 0};
    bool valid(int x, int y, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
        	return true;
        }
        return false;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       	int n = grid.size();
       	int m = grid[0].size();
        int maxm = INT_MIN;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int c=0;
                if(grid[i][j]){
                    
                    queue<pair<int,int>>q;
                    grid[i][j]=0;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        auto src = q.front();
                        q.pop();
                        c++;

                        for(int i = 0;i<4;i++){
	                        int dx = dir[i]+src.first;
	                        int dy = dir[i+1]+src.second;
                            
                            if(valid(dx,dy,grid)){
                                q.push({dx,dy});
                                grid[dx][dy]=0;
                            }
                        }
                    }
                  
                }
                maxm = max(maxm,c);
            }
        }
        return maxm;
    }
};





//Third Solution :-
class Solution {
public:
    vector<int> areaOfIsland;
    
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        int area = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int u = p.first;
            int v = p.second;
            
            if (u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == 1) {
                grid[u][v] = 2;
                area++;
                q.push({u - 1, v});
                q.push({u + 1, v});
                q.push({u, v - 1});
                q.push({u, v + 1});
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) 
                    areaOfIsland.push_back(bfs(grid, i, j));
        
        int maxArea = 0;
        for (int curArea : areaOfIsland)
            maxArea = max(maxArea, curArea);
        return maxArea;
    }
};