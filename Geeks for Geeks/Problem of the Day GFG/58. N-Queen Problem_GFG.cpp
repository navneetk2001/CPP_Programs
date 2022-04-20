// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

// Example 1:
// Input:
// 1
// Output:
// [1]
// Explaination: Only one queen can be placed in the single cell available.

// Example 2:
// Input:
// 4
// Output:
// [2 4 1 3 ] [3 1 4 2 ]
// Explaination: These are the 2 possible solutions.


//Backtracking Approach :-
//1. Place yourself at starting point
//2. Explore all the paths possible from the starting point
//3. Insert your element at only correct possible position and once inserted move on to smaller problem
//4. Once you reach base case you print your solution
//5. Once you explore all paths from one point, backtrack to your previous point


//Solution
class Solution{
public:
    bool isSafe(vector<vector<int>>board, int x, int y, int n){
        for(int i = 0; i<x; i++){  
            if(board[i][y] == 1){
                return false;
            }
        }
        
        int row = x, col = y;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }
        
        row = x, col = y;
        while(row >= 0 && col < n){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col++;
        }
        
        return true;
    }

    void solve(int x, int n, vector<vector<int>> &board, vector<vector<int>> &result){
        if(x == n){
            vector<int> vt;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(board[i][j] == 1){
                        vt.push_back(j+1);
                    }
                }
            }
            result.push_back(vt);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(isSafe(board, x, col, n)){
                board[x][col] = 1;
                solve(x+1, n, board, result);
                board[x][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        solve(0, n, board, result);
        sort(result.begin(), result.end());
        return result;
    }
};




//Second Solution :- Coding Ninjas
int board[11][11];
bool isPossible(int n, int row, int col){
	for(int i=row-1;i>=0;i--){  //same column
		if(board[i][col] == 1){
			return false;
		}
	}

	for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){  //upper left diagonal
		if(board[i][col] == 1){
			return false;
		}
	}

	for(int i=row-1,j=col+1; i>=0 && j<0; i--,j++){  //upper right diagonal
		if(board[i][col] == 1){
			return false;
		}
	}
	return true;
}

void nQueenHelper(int n, int row){
	if(row==n){   //we have reached some solution then print the board matrix and return
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j] == 1){
					cout<<board[i][j]<<" ";
				}
			}
		}
		cout<<endl;
		return;
	}

	//place at all possible positions and move to smaller problem
	for(int j=0;j<n;j++){
		if(isPossible(n,row,j)){
			board[row][j] = 1;
			nQueenHelper(n,row+1);
			board[row][j] = 0;
		}
	}
	return;
}


class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        //vector<vector<int>>ans;
        memset(board,0,sizeOf(board));
        nQueenHelper(n,0);
    }
};
