https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1




//Solution Approach :-
//Function to find a solved Sudoku. 
bool issafe(int grid[N][N], int i, int j, int k){
    for(int c=0;c<9;c++){        //safe in row 
        if(grid[i][c]==k){
        	return false;
        }
    }
    for(int r=0;r<9;r++){        //safe in col
        if(grid[r][j]==k){
        	return false;
        }
    }

    int rs=(i/3)*3;
    int cs=(j/3)*3;
    for(int r=0;r<3;r++){        //safe in box
        for(int c=0;c<3;c++){
            if(grid[rs+r][cs+c]==k) return false;
        }
    }
    return true;
}

bool solve(int grid[N][N], int i, int j){
    if(i==N){
    	return true; 
    }
    if(j==N){
        i++;
        j=0;
    }
    if(grid[i][j]>0){
    	return solve(grid,i,j+1);
    }
    for(int k=1;k<=9;k++){
        if(issafe(grid,i,j,k)){
            grid[i][j]=k;
            if(solve(grid,i,j+1)){
            	return true;
            }
            grid[i][j]=0;
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N]){ 
    return solve(grid,0,0);    
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}




//Second Solution :-
bool valid(int sudoku[N][N],int row,int col,int val){
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==val){
        	return false;
        }
        if(sudoku[i][col]==val){
        	return false;
        }
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val){
        	return false;
        }
    }
    return true;
}

bool SolveSudoku(int sudoku[N][N]){ 
    for(int row=0; row<N; row++){
        for(int col=0;col<N; col++){
            if(sudoku[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(valid(sudoku, row, col, val)){
                        sudoku[row][col]=val;
                        if(SolveSudoku(sudoku)){
                            return true;
                        }
                        else{
                            sudoku[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]){
    for(int row=0; row< N; row++){
        for(int col=0; col< N; col++){
            cout<<grid[row][col]<<" ";
        }
    }
}




//Third Solution :-
bool check(int A[N][N], int a, int b, char k)
{
   	for (int i = 0; i < 9; i++){
       	if(A[i][b]==k or A[a][i]==k) return false;
   	}
   	
   	int rows,rowf,cols,colf;
	rows=a;
	rowf=a;
	rowf++;
	while(rows%3){
       	rows--;
	}
   	cols=b;
   	while(cols%3){
       	cols--;
   	}
   	while(rowf%3){
       	rowf++;
   	}
	colf=b;
	colf++;
	while(colf%3){
       	colf++;
	}
   	for (int i = rows; i < rowf; i++){
       	for (int j = cols; j < colf; j++){
           	if (A[i][j]==k){
               	return false;
           	}
       	}
   	}
   	return true;
}

bool prob(int A[N][N],int i,int j){
	if(i==9){
	   return true;
	}
	if(j==9){
		return prob(A,i+1,0);
	}
	if(A[i][j]){
		return prob(A,i,j+1);
	}
   	for (char k=1;k<=9;k++){
       	if(check(A,i,j,k)){
           	A[i][j]=k;
           	if(prob(A,i,j+1)){
               	return true;
           	}
           	A[i][j]=0; // backtrack...
       	}
   	}
   	return false;
}

bool SolveSudoku(int grid[N][N])  { 
   prob(grid,0,0);
}

void printGrid (int grid[N][N]) 
{
   	for(int i=0;i<N;i++){
       	for(int j=0;j<N;j++){
       		cout<<grid[i][j]<<" ";
       	}
   	}
}