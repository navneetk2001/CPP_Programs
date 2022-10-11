// In the game of Broken Blocks, the player is allowed to move on m x n blocks i.e. m levels and n stone blocks on each level such that one level is vertically above the previous level (as in a staircase), with some of its stone blocks replaced by wooden blocks.
// The player at the start of the game is present on the ground level (which should be considered as level 0 or it can be considered as level -1). The player can start from any of the blocks present on the level 0 and start moving further to next levels. The player can only move to the stone-block just above to the present stone-block or diagonally to the left or to the right. The player cant move on the same level.
// If the player steps on any of the wooden block (denoted by -1), he will fall off the board and die as the wood-block will not able to hold players weight. Each of the stone-block has some gold coins present on it (wooden blocks doesnt have any coins on them). If at any point the player cant move to further level due to any reason, the game ends and his present total coin score will be considered.
// The players aim is to collect as many gold coins as he can without falling off the board.
 

// Example 1:
// Input: matrix = {{2,5,6},{-1,3,2},{4,-1,5}}
// Output: 14
// Explanation: Assume 0-based indexing.The matrix is:
// 2 5 6 (level 0)
// -1 3 2 (level 1)
// 4 -1 5 (lever 2)
// The player can collect maximum number of coins by moving through:matrix[0][2] + matrix[1][1] + matrix[2][2] = 6 + 3 + 5 = 14 coins.

// Example 2:
// Input: matrix = {{-1,2,3,4},{5,-1,-1,2},{4,3,-1,-1}}
// Output: 11
// Explanation: 
// The matrix is:
// -1 2 3 4(level 0)
// 5 -1 -1 2(level 1)
// 4 3 -1 1(level 2)
// The player can collect maximum number of coins by moving through:a[0][1] + a[1][0] + a[2][0] = 2 + 5 + 4 = 11 coins.
 



//First Solution :- DP (Memoization)
class Solution {
public:
    int recFunc(int r , int c , vector<vector<int>> &m , vector<vector<int>> &dp){
        if(r >= m.size()) {
            return 0;
        }
        else if(c < 0 || c >= m[0].size() || m[r][c] == -1) {
            return 0;
        }
        else if(dp[r][c] != -1) {
            return dp[r][c];
        }
        
        int l1 = recFunc(r+1 , c , m , dp);
        int l2 = recFunc(r+1 , c-1 , m , dp);
        int l3 = recFunc(r+1 , c+1 , m , dp);
        
        dp[r][c] = max(max(l1 , l2) , l3) + m[r][c];
        return dp[r][c];    
    }

    int MaxGold(vector<vector<int>> &m){
        int r = m.size() , c = m[0].size();
        vector<vector<int>> dp(r , vector<int>(c , -1));
        
        int maxVal = INT_MIN;
        for(int i = 0 ; i < c ; i++){
            maxVal = max(maxVal , recFunc(0 , i , m , dp));
        }
        
        return maxVal;
    }
};



//Second Solution :-
//For every row starting from the bottom most row check what will be the max for the three possibilities if we move to the three possibilities below it.

class Solution {
    public:
    int MaxGold(vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                if(mat[i][j]!=-1){
                    mat[i][j] += max({j>0?mat[i+1][j-1]:0, mat[i+1][j], j+1<m?mat[i+1][j+1]:0, 0});
                }
            }
        }
        int mx = 0;
        for(int i=0; i<m; i++){
            mx = max(mx, mat[0][i]);
        }
        return mx;
    }
};