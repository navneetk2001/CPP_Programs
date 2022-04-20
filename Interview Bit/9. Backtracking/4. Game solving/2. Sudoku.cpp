// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.' 
// You may assume that there will be only one unique solution.

// Example :
// For the above given diagrams, the corresponding input to your program will be
// [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
// and we would expect your program to modify the above array of array of characters to
// [[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

//Solution Approach :- 
Classic backtrack problem.
Everytime you place an element x on row,col, you need to check if its still valid to put x on that position by double checking if x occurs more than once in the row or column or in its block. If not, you proceed by placing x, and call forward to check if a correct solution is possible with x in position row, col.
If a solution is possible, you return the current configuration and you are done. Otherwise you try other values.


//First Solution :- Approach :-

//FInd empty position on board :- if not found return true else if found start exploring that position
//start putting numbers from 1 to 9 at empty position and start checking 3 conditions
//condn 1:- Check in row
//condn 2:- Check in Column
//condn 3:- Check in the box

bool rowsafe(vector<vector<char>>& board, int row, int val ){
	for(int i=0;i<9;i++){
		if(board[row][i]==val) return false;
	}
	return true;
}

bool colsafe(vector<vector<char>>& board, int col, int val ){
	for(int i=0;i<9;i++){
		if(board[i][col]==val) return false;
	}
	return true;
}

bool boardsafe(vector<vector<char>>& board, int row, int col, int val ){
	int rowfactor = row-(row%3);
	int colfactor = col-(col%3);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i+rowfactor][j+colfactor]==val)
				return false;
		}
	}
	return true;
}

bool safe(vector<vector<char>>& board, int row, int col, int val){
	return rowsafe(board,row,val) && colsafe(board,col,val) && boardsafe(board,row,col,val);
}

bool solve(vector<vector<char>>& board){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(board[i][j]=='.'){
				for(char k='1';k<='9';k++){
					if(safe(board,i,j,k)){
						board[i][j]=k;
						if(solve(board)) return true;
						else 
							board[i][j]='.';
					}
				} 
				return false;
			}
		}
	}
	return true;
}

void Solution::solveSudoku(vector<vector<char>> &board) {
	if(board.size()==0 )
            return;
    solve(board);
}

//Second Solution :-
void find(vector<vector<char>> &board,vector<int> &unfilled,vector<vector<char>> &ans, bool&got,int idx)
    {    
        int i=unfilled[idx]/9;
        int j=unfilled[idx]%9;       
        
        vector<int> allowed(10);
        for (int l=0;l<10;l++)
            allowed[l]=1;
        
        for (int l=0;l<9;l++)
            if(board[i][l]!='.')
            allowed[(int)board[i][l]-48]=0;
        
        
        for (int k=0;k<9;k++)
            if(board[k][j]!='.')
            allowed[(int)board[k][j]-48]=0;
        
        for (int x=i-i%3;x<i-i%3+3;x++)
        for (int y=j-(j%3);y<j-(j%3)+3;y++)
        if(board[x][y]!='.')
            allowed[(int)board[x][y]-48]=0;
                
        
        for (int t=1;(got==false)&&(t<=9);t++)
        {
            if (allowed[t]==1)
            {
                board[i][j]=(char)(t+48);
                if (idx+1<unfilled.size())
                find(board,unfilled,ans,got,idx+1);
                else
                {
                    for (int k=0;k<9;k++)
                    for (int l=0;l<9;l++)
                        ans[k][l]=board[k][l];
                    got=true;
                    return;
                }
                board[i][j]='.';
            }
        }
        
        return;
        
    }
void Solution::solveSudoku(vector<vector<char> > &board) {
        bool got=false;
        //i, j should be in (box[3*(i/3)+(j/3)]), row[i], col[j];
        vector<vector<char>> ans(9,vector<char>(9));
        vector<int> unfilled;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                ans[i][j]=board[i][j];
    
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (board[i][j]=='.')
                    unfilled.push_back(9*i+j);
            
        find(board,unfilled,ans,got,0);
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                board[i][j]=ans[i][j];
        return;

    }


//Third Solution :- 
bool findEmptyLocation(int grid[N][N], int &row, int & col){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j] == '.'){
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool isSafeInRow(int grid[N][N], int row, int num){
	for(int i=0;i<N;i++){
		if(grid[row][i] == num){
			return false;
		}
	}
	return true;
}

bool isSafeInCol(int grid[N][N], int col, int num){
	for(int i=0;i<N;i++){
		if(grid[i][col] == num){
			return false;
		}
	}
	return true;
}

bool isSafeInGrid(int grid[N][N], int row, int col, int num){
	int rowFactor = row - (row%3);
	int colFactor = col - (col%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+rowFactor][j+colFactor] == num){
				return false;
			}
		}
	}
	return true;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	//is safe in row, col and box
	if(isSafeInRow(grid,row,num) and isSafeInCol(grid,col,num) and isSafeInGrid(grid,row,col,num)){
		return true;
	}
	return false;
}

bool solveSudoku(int grid[N][N]){
	int row,col;
	if(!findEmptyLocation(grid,row,col)){
		return true;
	}

	for(int i=1;i<=9;i++){
		if(isSafe(grid,row,col,i)){
			grid[row][col] = i;
			if(solveSudoku(grid)){
				return true;
			}
			grid[row][col] = 0;  //unassigned the value and check for further new value
		}
		return false;
	}
}


//Fourth Solution :-
bool check(int i,int j,int n,vector<vector<char> > &a,int k){
     for(int c = 0;c<n;c++){
         if(a[c][j] == k+'0' || a[i][c] == k+'0')return false; 
     }
     int x3 = sqrt(n);
     int x1 = i-i%x3,x2 = j-j%x3;
     for(int c1 = 0;c1<x3;c1++){
         for(int c2 = 0;c2<x3;c2++){
             if(a[c1+x1][c2+x2] == k+'0')return false; 
         }
     }return true;
 }
 bool sol(vector<vector<char> > &a,int n,int i,int j){
     if(i == n-1 && j==n)
          return true;
     if(j==n){
         j=0;i++;
     }
     if(a[i][j] != '.')
       return sol(a,n,i,j+1);
     for(int k = 1;k<=9;k++){
         if(check(i,j,n,a,k)){
             a[i][j] = k+'0';
             if(sol(a,n,i,j+1)) return true;

         } a[i][j] = '.';
     }  return false;    
 }
void Solution::solveSudoku(vector<vector<char> > &a) {
    int n = a.size();
    int m = a[0].size();
    sol(a,n,0,0);
}





// const int N = 9;
// bool findEmptyLocation(int grid[N][N], int &row, int & col){
// 	for(int i=0;i<N;i++){
// 		for(int j=0;j<N;j++){
// 			if(grid[i][j] == '.'){
// 				row = i;
// 				col = j;
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool isSafeInRow(int grid[N][N], int row, int num){
// 	for(int i=0;i<N;i++){
// 		if(grid[row][i] == num){
// 			return false;
// 		}
// 	}
// 	return true;
// }

// bool isSafeInCol(int grid[N][N], int col, char num){
// 	for(int i=0;i<N;i++){
// 		if(grid[i][col] == num){
// 			return false;
// 		}
// 	}
// 	return true;
// }

// bool isSafeInGrid(int grid[N][N], int row, int col, int num){
// 	int rowFactor = row - (row%3);
// 	int colFactor = col - (col%3);
// 	for(int i=0;i<3;i++){
// 		for(int j=0;j<3;j++){
// 			if(grid[i+rowFactor][j+colFactor] == num){
// 				return false;
// 			}
// 		}
// 	}
// 	return true;
// }

// bool isSafe(int grid[N][N], int row, int col, int num){
// 	//is safe in row, col and box
// 	if(isSafeInRow(grid,row,num) && isSafeInCol(grid,col,num) && isSafeInGrid(grid,row,col,num)){
// 		return true;
// 	}
// 	return false;
// }

// bool solveSudoku(int grid[N][N]){
// 	int row,col;
// 	if(!findEmptyLocation(grid,row,col)){
// 		return true;
// 	}

// 	for(int i=1;i<=9;i++){
// 		if(isSafe(grid,row,col,i)){
// 			grid[row][col] = i;
// 			if(solveSudoku(grid)){
// 				return true;
// 			}
// 			grid[row][col] = 0;  //unassigned the value and check for further new value
// 		}
// 		return false;
// 	}
// }

// void Solution::solveSudoku(vector<vector<char>> &A) {
// 	if (A.size() != N || A[0].size() != N)
//         return;

// 	int N = A.size();
// 	int grid[N][N];
// 	for(int i=0;i<N;i++){
// 		for(int j=0;j<N;j++){
// 			grid[i][j] = A[i][j] - '0';
// 		}
// 	}

//     solveSudoku(grid);
// }