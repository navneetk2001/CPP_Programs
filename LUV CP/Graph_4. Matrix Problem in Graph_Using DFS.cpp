https://leetcode.com/problems/flood-fill/

//DFS Solution :-
class Solution {
public:
    void dfs(int i, int j, int init, int newColor, vector<vector<int>> &image){
        int n = image.size(), m=image[0].size();
        if(i<0 || j<0) return;
        if(i>= n || j>=m) return;
        if(image[i][j] != init) return;

        image[i][j] = newColor;

        dfs(i+1, j, init, newColor, image);
        dfs(i-1, j, init, newColor, image);
        dfs(i, j+1, init, newColor, image);
        dfs(i, j-1, init, newColor, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor!=color){
            return dfs(sr,sc,initialColor,color,image);
        }
        return image;
    }
};



//BFS Solution :-
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        
        queue<pair<int,int>> pq;
        pq.push({sr,sc});
        visited[sr][sc]=1;
        
        while(pq.size()>0){
            int i=pq.front().first;
            int j=pq.front().second;
            
            pq.pop();
            
            if(i-1>=0&&image[i-1][j]==image[i][j]&& visited[i-1][j]==0)
            {
                visited[i][j]=1;
                pq.push({i-1,j});
            }
            
            if(j-1>=0&&image[i][j-1]==image[i][j]&& visited[i][j-1]==0)
            {
                visited[i][j-1]=1;
                pq.push({i,j-1});
            }
            
            if(i+1<image.size()&&image[i+1][j]==image[i][j]&& visited[i+1][j]==0)
            {
                visited[i+1][j]=1;
                pq.push({i+1,j});
            }

            if(j+1<image[0].size()&&image[i][j+1]==image[i][j]&& visited[i][j+1]==0)
            {
                visited[i][j+1]=1;
                pq.push({i,j+1});
            }

            image[i][j]=newColor;
        }
        return image;
    }
};





//329. Longest Increasing Path in a Matrix
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


//❌ Solution - I (Recursive Brute-Force Approach) [TLE]
int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };   // all the moves available to us - top, down, left, right
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxPath = 1; // atleast one cell can always be selected in the path
    // explore each cell of matrix to find longest path achievable from that cell and finally return the maximum
    for(int i = 0; i < size(matrix); i++){
        for(int j = 0; j < size(matrix[0]); j++){
            maxPath = max(maxPath, solve(matrix, i, j));                
        }
    }
    return maxPath;
}

int solve(vector<vector<int>>& mat, int i, int j){
    int MAX = 1;        // max length of path starting from cell i,j of matrix
    
    for(int k = 0; k < 4; k++){               // choosing all the 4 moves available for current cell
        int new_i = i + moves[k][0], new_j = j + moves[k][1];
        // bound checking as well as move to next cell only when it is greater in value
        if(new_i < 0 || new_j < 0 || new_i >= size(mat) || new_j >= size(mat[0]) || mat[new_i][new_j] <= mat[i][j]) continue;
        // MAX will be updated each time to store maximum of path length from each move
        MAX = max(MAX, 1 + solve(mat, new_i, new_j));
    }         
    return MAX;
}



//✔️ Solution - II (Recursive with Dynamic Programming - Memoization) [Accepted]

int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int> > dp; // dp[i][j] will store maximum path length starting from matrix[i][j]
int maxPath, n, m;

int longestIncreasingPath(vector<vector<int>>& matrix) {
    maxPath = 0, n = size(matrix), m = size(matrix[0]);
    dp.resize(n, vector<int>(m));
    // calculating maximum path from each cell and at last returning the maximum length
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            maxPath = max(maxPath, solve(matrix, i, j));            
        }
    }
    return maxPath;
}

int solve(vector<vector<int>>& mat, int i, int j){
    if(dp[i][j]) return dp[i][j];    // return if result is already calculated
    dp[i][j] = 1;                    // minimum path from each cell is always atleast 1
    // choosing each possible move available to us
    for(int k = 0; k < 4; k++){ 
        int new_i = i + moves[k][0], new_j = j + moves[k][1];
        // bound checking as well as move to next cell only when it is greater in value
        if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m || mat[new_i][new_j] <= mat[i][j]) continue;
        // max( current optimal, select current + optimal solution after moves[k] from current cell
        dp[i][j] = max(dp[i][j], 1 + solve(mat, new_i, new_j));
    }         
    return dp[i][j];
}



✔️ Concise Solution - II

int dp[200][200]{}; // constraints are small enough that we can just set them to MAX
int maxPath, n, m;
int longestIncreasingPath(vector<vector<int>>& matrix) {
    maxPath = 0, n = size(matrix), m = size(matrix[0]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            maxPath = max(maxPath, solve(matrix, i, j, -1));            
        }
    }
    return maxPath;
}
int solve(vector<vector<int>>& mat, int i, int j, int prev){
    if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
    if(dp[i][j]) return dp[i][j];
    return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
                                solve(mat, i - 1, j, mat[i][j]),
                                solve(mat, i, j + 1, mat[i][j]),
                                solve(mat, i, j - 1, mat[i][j]) });       
}






//417. Pacific Atlantic Water Flow
https://leetcode.com/problems/pacific-atlantic-water-flow/








//463. Island Perimeter
https://leetcode.com/problems/island-perimeter/


