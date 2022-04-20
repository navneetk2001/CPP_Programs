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


//Hint :-


//Solution Approach :- 



//First Solution :- Backtracking Approach :-
//1. Place yourself at starting point
//2. Explore all the paths possible from the starting point
//3. Insert your element at only correct possible position and once inserted move on to smaller problem
//4. Once you reach base case you print your solution
//5. Once you explore all paths from one point, backtrack to your previous point


//Solution
bool isSafe(vector<vector<int>>board, int x, int y, int n){
    for(int i = 0; i<x; i++){  //same column
        if(board[i][y] == 1){
            return false;
        }
    }
    
    int row = x, col = y;
    while(row >= 0 && col >= 0){ //upper left diagonal
        if(board[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }
    
    row = x, col = y;
    while(row >= 0 && col < n){   //upper right diagonal
        if(board[row][col] == 1){
            return false;
        }
        row--;
        col++;
    }
    
    return true;
}

void solve(int x, int n, vector<vector<int>> &board, vector<vector<string>> &result){
    if(x == n){
        vector<string> vt;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 1){
                    vt[i][j]='Q';
                }
                else{
                    vt[i][j]='.';
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

vector<vector<string> > Solution::solveNQueens(int n) {
    vector<vector<string>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    solve(0, n, board, result);
    //sort(result.begin(), result.end());
    return result;
}


//Second Solution :- 
bool isPossible(vector<string>& v, int cx, int cy) {
	int n = v.size();

	for(int i = 0; i < n; i++) {
	    if(v[cx][i] == 'Q') return false;
	}   
	for(int i = 0; i < n; i++) {
	    if(v[i][cy] == 'Q') return false;
	}
	int i = cx, j = cy;

	while(i >= 0 && j >= 0) {
	    if(v[i][j] == 'Q') return false;
	    i--, j--;
	}

	i = cx, j = cy;
	while(i >= 0 && j < n) {
	    if(v[i][j] == 'Q') return false;
	    i--, j++;
	}

	return true;
}

void solve(int n, int currRow, vector<vector<string>>& ans, vector<string>& v) {

	if(currRow == n) {
	    ans.push_back(v);
	    return;
	}

	for(int i = 0; i < n; i++) {
	    if(isPossible(v, currRow, i) == true) {
	        v[currRow][i] = 'Q';
	        solve(n, currRow + 1, ans, v);
	        v[currRow][i] = '.';
	    }
	}
}

vector<vector<string>> Solution::solveNQueens(int A) {
	int n = A;    
	vector<string> v;    
	for(int i = 0; i < n; i++) {
	    string temp = "";
	    for(int j = 0; j < n; j++) {
	        temp += ".";
	    }
	    v.push_back(temp);
	} 

	vector<vector<string>> ans;
	solve(n, 0, ans, v);
	return ans;
}


//Third Solution :-
bool isSafe(vector<string> &board, int row, int col, int N){
    // Check for previous rows
    for(int i=col;i>=0;i--)
        if(board[row][i] == 'Q')
            return false;
    // Check for upper diagonal leftwards....
    for(int i=col, j=row; i>=0 && j>=0; i--,j--)
        if(board[j][i] == 'Q')
            return false;
    // Check for lower diagonal leftwards....
    for(int i=col, j=row; i>=0 && j<N; i--,j++)
        if(board[j][i] == 'Q')
            return false;
    return true;
}

void solve(vector<string> temp, int col, int size, vector<vector<string>> &board){
    if(col == size){
        board.push_back(temp);
    }
    for(int i=0;i<size;i++){
        if(isSafe(temp, i, col, size)){
            temp[i][col] = 'Q';
            solve(temp, col+1, size, board);
            temp[i][col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> board;
    if(A == 2 || A == 3)
        return board;

    string s(A,'.');
    vector<string> temp(A,s);
    solve(temp, 0, A, board);
    return board;
}
