https://www.interviewbit.com/problems/water-flow/



//Solution Approach :-  BFS
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, int &row, int &column, vector<vector<int>> &matrix){
    while (!q.empty()){
        //get both x and y coordinates
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // explore 4 directions
        for (int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            // voilate boundary condition or lake is already visited
            if (newX < 0 || newY < 0 || newX >= row || newY >= column || visited[newX][newY] == true){
                continue;
            }

            // lake flow from lower to higher heights according to questions
            if (matrix[x][y] <= matrix[newX][newY]){
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}


int Solution::solve(vector<vector<int> > &matrix) {
    int row = matrix.size();
    if (row == 0){
        return 0;
    }
    int column = matrix[0].size();

    // to check lake touched or not
    vector<vector<bool>> blue_visited(row, vector<bool>(column, false));
    vector<vector<bool>> red_visited(row, vector<bool>(column, false));

    //do multilevel queue
    queue<pair<int, int>> qBlue, qRed;

    // store blue and red lake touched index in respective queue
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (i == 0 || j == 0){
                qBlue.push({i, j});
                blue_visited[i][j] = true;
            }
            if (i == row - 1 || j == column - 1){
                qRed.push({i, j});
                red_visited[i][j] = true;
            }
        }
    }

    // explore all possible cell that touched
    bfs(qBlue, blue_visited, row, column, matrix);
    bfs(qRed, red_visited, row, column, matrix);

    // get the result if both lake touched
    int ans = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (blue_visited[i][j] && red_visited[i][j]){
                ans++;
            }
        }
    }

    return ans;
}





//Second Solution :-
// Intuition -> make the sea of both pacific and atlantic
// then store false , if from that cell it is not possible to water to flow to their respective
// sea , as the (left and top bottom will be possible from boundary to pacific)
// similarly (right and bottom boundary will be make it to atlantice ocean )
// then run dfs from all that posssible paths answer will be that cell which has true in both pacific and atlantic

int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};

void dfs(vector<vector<int>> &grid , vector<vector<bool>> &sea , int i , int j , int m , int n ){
    if(i<0 || j<0 || i>=m || j>=n ){
        return ;
    }
   
    for(int k=0;k<4;k++){
        int newi=i+dx[k];
        int newj=j+dy[k];
       
        if(newi>=0 && newj>=0 && newi<m && newj<n && sea[newi][newj]==false){
            if(grid[newi][newj]>=grid[i][j]){
                sea[newi][newj]=true;
                dfs(grid , sea , newi , newj , m , n );
            }
        }
    }
    return;
}

int Solution::solve(vector<vector<int> > &grid) {
    int m=grid.size();
    int n=grid[0].size();
   
    vector<vector<bool>> blue(m , vector<bool>(n , false));
    vector<vector<bool>> red(m , vector<bool>(n , false));
   
    for(int i=0;i<m;i++){
        blue[i][0]=true;
        red[i][n-1]=true;
    }
   
    for(int i=0;i<n;i++)
    {
        blue[0][i]=true;
        red[m-1][i]=true;
    }
   
    // store the values in the i.j , as that cell is reachable to respective sea or not
    // apply dfs for boundary
    // apply dfs for each boundary taking left side and top as blue lake
    // right and bottom as red lake
   
    for(int i=0;i<m;i++){
        dfs(grid , blue , i , 0 , m ,n);
    }
   
    for(int i=0;i<n;i++){
        dfs(grid , blue , 0 , i , m , n);
    }
   
    for(int i=0;i<m;i++){
        dfs(grid , red , i , n-1 , m ,n);
    }
   
    for(int i=0;i<n;i++){
        dfs(grid , red , m-1 , i , m , n);
    }
   
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(red[i][j]==true && blue[i][j]==true){
                ans++;
            }
        }
    }
   
    return ans;
   
}




//Third Solution :-
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> ans;
    if(matrix.size()<1){
    	return ans;
    }

    vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
    vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
    
    for(int col=0; col<matrix[0].size(); col++){
        fnc(matrix,0,col,INT_MIN,pacific);
        fnc(matrix,matrix.size()-1,col,INT_MIN,atlantic);
    }
    
    for(int row = 0;row<matrix.size();row++){
        fnc(matrix,row,0,INT_MIN,pacific);
        fnc(matrix,row,matrix[0].size()-1,INT_MIN,atlantic);
    }
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(pacific[i][j]==1 && atlantic[i][j]==1){
                vector<int> v(2);
                v[0]=i;
                v[1]=j;
                ans.push_back(v);
            }
        }
    }
    return ans;
}

void fnc(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& ocean){
    if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()){
        return;
    }
    if(ocean[i][j]==1){
        return;
    }
    if(matrix[i][j]<prev){
        return;
    }
    
    ocean[i][j]=1;
    
    fnc(matrix,i+1,j,matrix[i][j],ocean); 
    fnc(matrix,i-1,j,matrix[i][j],ocean);
    fnc(matrix,i,j+1,matrix[i][j],ocean);
    fnc(matrix,i,j-1,matrix[i][j],ocean);
}