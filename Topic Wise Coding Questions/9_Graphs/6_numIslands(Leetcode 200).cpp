int numIslands(vector<vector<char>>&grid){
	int rows=grid.size();
	int cols=grid[0].size();

	if(rows==0){
		return 0;
	}

	int no_of_islands=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(grid[i][j]=='1'){
				mark_current_island(grid,i,j,rows,cols);
				no_of_islands+=1;
			}
		}
	}
	return no_of_islands;
}


void mark_current_island(vector<vector<char>>&matrix, int i, int j, int r, int c){
	if(x<0 || x>=r || y<0 || y<=c || matrix[x][y]!='1')
		return;
    
    //Mark current cell as visited
	matrix[x][y]='2';

	//Make recursive calls in all 4 adjacent directions
	mark_current_island(matrix,x+1,y,r,c); //Down
	mark_current_island(matrix,x,y+1,r,c); //Right
	mark_current_island(matrix,x-1,y,r,c); //Top
	mark_current_island(matrix,x,y-1,r,c); //Left
}