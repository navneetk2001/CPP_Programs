// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]




//Solution Approach :- 
class Solution {
public:
    vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        for(int i=row;i>=0;--i){                            // check col
            if(board[i][col] == 'Q') return false;
        }

        for(int i=row,j=col; i>=0 && j>=0; --i,--j){        // check left diagonal
            if(board[i][j] == 'Q') return false;
        }

        for(int i=row,j=col; i>=0 && j<board.size(); --i,++j){        //check right diagonal
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void dfs(vector<string> &board, int row){
        if(row == board.size()){        // exit condition
            ret.push_back(board);
            return;
        }

        for(int i=0;i<board.size();++i){            // iterate every possible position
            if(is_valid(board,row,i)){
                board[row][i] = 'Q';                // make decision
                dfs(board,row+1);                   // next iteration
                board[row][i] = '.';                // back-tracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        if(n <= 0){
        	return {{}};
        }
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
};