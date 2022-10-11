// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 
// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

// Example 2:
// Input: n = 1
// Output: 1


//This is very similar to N-Queens problem, with the only difference being that we are required to return count instead of all the solution boards. But both the solutions are almost the same.


✔️ Solution - I (Backtracking)
// This is a common backtracking problem. We can see than the number of ways to place a N queens on a NxN board can get very large since we have N^2 choices at first, then N^2 -1, N^2 -2 and so on... leading to overall time complexity of O(N^2N).
// But, we dont need to explore all O(N^2) options each time. Firstly, we have N Queens and all must be placed such that no queen attacks the other queen. This means, on each row only one queen can be placed and then we can move to the next row.
// So for each row we will to place one queen without violating the constraint and then move on to the next row. This will be repeated till all N queens have been placed. We will use the check method to ensure that the queen is safe to placed at (i, j). If all N queens have been placed, we have got our first solution.
// To get all the other possible solutions, we will need to remove the previously placed queen and try if its possible to place the queen on the same row at some other column, i.e, we need to backtrack. This will give us all the possible ways to place N queens on the board as per the given constraints.


int totalNQueens(int n) {
	vector<vector<bool>> board(n, vector<bool>(n, false));
	return solve(board, 0);
}

bool check(vector<vector<bool>>& board, int row, int col) {
	int n = size(board);
	for(int i = 0; i <= row; i++) {
		if(board[i][col]) return false; // checking if any queen already placed on same column previously
		// checking if all diagonals are safe -
		if(row - i >= 0 && col - i >= 0 && board[row - i][col - i]) return false;
		if(row - i >= 0 && col + i <  n && board[row - i][col + i]) return false;
	}
	return true;
}    
int solve(vector<vector<bool>>& board, int row) {
	if(row == size(board)) return 1;
	int count = 0;
	for(int col = 0; col < size(board); col++)           
		if(check(board, row, col)){          // check if we can place at (row, col)
			board[row][col] = true;          // place the queen at (row, col)
			count += solve(board, row + 1);  // explore for the next row. The function will return 1 if all N queens get placed for current combination
			board[row][col] = false;         // backtrack - remove previously placed queen and try for different columns
		}                                
	return count;
}

// Time Complexity : O(N!), we have N choices in the first row, N-1 in the second row, N-2 in the next and so on... which brings overall time complexity to O(N!)
// Space Complexity : O(N*N). Required for board and recursive stack.



✔️ Solution - II (Backtracking O(N) Space)
// We don't need to simulate the exact board since we only require number of solutions and not the exact board solutions themselves.
// Here, we only keep track of queen placements on each of n columns, 2n-1 diagonals and 2n-1 anti-diagonals. This will eliminate the need to iterative check function and reduc space usage

int totalNQueens(int n) {
	vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
	return solve(col, diag, anti_diag, 0);
}
   
int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
	int n = size(col), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){        // check if (row, column) is safe
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;      // place at (row, column)
			count += solve(col, diag, anti_diag, row + 1);                                  // explore for the next row
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;     // backtrack
		}                                
	return count;
}

//Time Complexity : O(N!)
//Space Complexity : O(N), for recursive stack and col, diag, anti_diag



✔️ Solution - III (Backtracking + Bitset O(N))
//Slight optimization using bitset in C++, although it won't make much of difference in space usage since it's dominated by recursive stack space usage.

int totalNQueens(int n) {
	bitset<17> col, diag, anti_diag;
	return solve(col, diag, anti_diag, 0, n);
}  
int solve(bitset<17>& col, bitset<17>& diag, bitset<17>& anti_diag, int row, int n) {
    if(row == n) return 1;
    int count = 0;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = 1;    // place at (row, column)
			count += solve(col, diag, anti_diag, row + 1, n);                          // explore for the next row. 
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = 0;    // backtrack
		}                                
	return count;
}

//Time Complexity : O(N!)
//Space Complexity : O(N), for recursive stack



✔️ Solution - IV (Backtracking + Bit-Manipulation)
//Direct bit-manipulation instead of using bitset -

int totalNQueens(int n, int row = 0, int col = 0, int diag = 0, int anti_diag = 0) {
    if(row == n) return 1;
    int count = 0;
	for(int column = 0; column < n; column++) {
        int col_mask = 1 << column, diag_mask = 1 << row + column, anti_diag_mask = 1 << row - column + n - 1;
        if(!(col & col_mask) && !(diag & diag_mask) && !(anti_diag & anti_diag_mask))
			count += totalNQueens(n, row + 1, col | col_mask, diag | diag_mask, anti_diag | anti_diag_mask);
    }
	return count;
}

// Time Complexity : O(N!)
// Space Complexity : O(N)



//5th Solution :-
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, true);
        vector<bool> antiD(2*n-1, true);
        vector<bool> mainD(2*n-1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, mainD, antiD, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& mainD, vector<bool> &antiD, int &count) {
            if (i == row.size()) { //filled all the rows with queens
                count++;
                return;
            }
           for (int j = 0; j < col.size(); j++) {
             if (col[j] && mainD[i+j] && antiD[i+col.size()-1-j]) {
                 row[i] = j; 
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = false;
                 dfs(i+1, row, col, mainD, antiD, count);
                 //backtracking
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = true;
          }
        }
    }
};