https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands





//Solution Approach :- DFS + Constructive thinking
void dfs(int i,int j,int x0,int y0,vector<vector<int>>& grid,int n,int m,vector<pair<int,int>>& coordinates){
	if(i<0 or j<0 or i>=n or j>= m or grid[i][j] != 1){
		return;
	}

	coordinates.push_back({i-x0,j-y0});
	grid[i][j] = 0;

	dfs(i, j+1, x0,y0,grid,n,m,coordinates);
	dfs(i-1, j, x0,y0,grid,n,m,coordinates);
	dfs(i+1, j, x0,y0,grid,n,m,coordinates);
	dfs(i, j-1, x0,y0,grid,n,m,coordinates);
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                vector<pair<int,int>> v;
                dfs(i,j,i,j,grid,n,m,v);
                st.insert(v);
            }
        }
    }
    return st.size();
}







//Second Solution :-
// Traverse the graph using the Depth-First Search Algorithm and check for the land(1's).
// Apply DFS on that land and mark each of the land in the islands as visited.
// While traversing the graph using the Depth-First Search, create a string which record the recursive traversal and the directions.
// After traversing the islands, return the string and store the string in a set such that no duplicate string can be stored in the set.
// At last, return the size of set in which the strings are stored.

string dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, string direction){
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
        return "O";
    }

	if(visited[row][col] == true || grid[row][col] == 0){
	   return "O";
	}
	
	visited[row][col] = true;
	
	string up = dfs(grid, visited, row - 1, col, "U");
	string down = dfs(grid, visited, row + 1, col, "D");
	string left = dfs(grid, visited, row, col - 1, "L");
	string right = dfs(grid, visited, row, col + 1, "R");
	
	return direction + up + down + left + right;
}

int countDistinctIslands(vector<vector<int>>& grid) {
	if(grid.size() == 0){
	   return 0;
	}
	
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	set<string> unique;
	
	for(int i = 0;i < grid.size();i++){
	   for(int j = 0;j < grid[0].size();j++){
	       if(grid[i][j] == 1 && visited[i][j] == false){
	           string str = dfs(grid, visited, i, j, "X");
	           unique.insert(str);
	       }
	   }
	}
	return unique.size();
}





//Third Solution :-  //Both BFS and DFS
class Solution {
public:
    set<vector<pair<int,int>>> final_set;
    
    void bfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int row , int col,int rowSize , int colSize){
        vector<pair<int,int>> temp;
        queue<pair<int,int>> q;
        q.push({row , col});
        vis[row][col] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            temp.push_back({r-row,c-col});
            
            if(r-1 >= 0 && grid[r-1][c] == 1 && vis[r-1][c] == -1){
                q.push({r-1 , c});
                vis[r-1][c] = 1;
            }
            
            if(c-1 >= 0 && grid[r][c-1] == 1 && vis[r][c-1] == -1){
                q.push({r , c-1});
                vis[r][c-1] = 1;
            }
            
            if(r+1 < rowSize && grid[r+1][c] == 1 && vis[r+1][c] == -1){
                q.push({r+1 , c});
                vis[r+1][c] = 1;
            }
            
            if(c+1 < colSize && grid[r][c+1] == 1 && vis[r][c+1] == -1){
                q.push({r , c+1});
                vis[r][c+1] = 1;
            }
        }
        final_set.insert(temp);
    }
    
    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis ,int base_row , int base_col, int row , int col, int rowSize , int colSize , vector<pair<int,int>>& temp){
        if(row < 0 || col < 0 || row >= rowSize || col >= colSize || grid[row][col] == 0 || vis[row][col] != -1){
            return;
        }
        else{
            vis[row][col] = 1;

            temp.push_back({row - base_row , col-base_col});

            dfs(grid , vis , base_row , base_col , row - 1 , col , rowSize , colSize , temp);
            dfs(grid , vis , base_row , base_col , row , col - 1 , rowSize , colSize , temp);
            dfs(grid , vis , base_row , base_col , row + 1 , col , rowSize , colSize , temp);
            dfs(grid , vis , base_row , base_col , row , col + 1 , rowSize , colSize , temp);

            return;
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , -1));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    //bfs(grid , vis , i , j , n , m);
                    
                    vector<pair<int,int>> temp;
                    dfs(grid , vis , i , j , i , j , n , m , temp);
                    final_set.insert(temp);
                    temp.clear();
                }
            }
        }

        return final_set.size();
    }
};
