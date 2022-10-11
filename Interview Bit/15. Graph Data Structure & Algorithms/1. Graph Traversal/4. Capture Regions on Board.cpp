https://www.interviewbit.com/problems/capture-regions-on-board/




//Solution Approach :- BFS
void solve(vector<vector<char>> &matrix){
    int row = matrix.size();
    if (row == 0){
        return;
    }
    int column = matrix[0].size();


    queue<pair<int, int>> q;     //To store all boundary 'O'
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (matrix[i][j] == 'O' && (i == 0 || j == 0 || i == row - 1 || j == column - 1)){   //Push all those elements which are present on boundary and are 0's
                q.push({i, j});
                matrix[i][j] = '^';     //Also make that as '^'
            }
        }
    }

    // all four direction move
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()){        // multisource BFS using queue
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){        // explore all four direction
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            //explore for all the adjacent 0's of queue
            if (newX >= 0 && newY >= 0 && newX < row && newY < column && matrix[newX][newY] == 'O'){    // inside boundary and it is 'O'
                q.push({newX, newY});
                matrix[newX][newY] = '^';
            }
        }
    }

    // change ('O' to 'X') and ('^' to 'O')
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (matrix[i][j] == '^'){
                matrix[i][j] = 'O';
            }
            else if (matrix[i][j] == 'O'){
                matrix[i][j] = 'X';
            }
        }
    }
}




//Second Solution :- DFS
// Let's think reverse solution so that solution is much simpler.
// If we can reach cell a cell 'O' from corner rows/column containing 'O' then this cell is not captured, otherwise it is captured.

void dfs(int x, int y, vector<vector<char>> &a, vector<vector<bool>> &captured, vector<vector<bool>> &vis){
    int m=a.size();
    int n=a[0].size();

    if(x<0 || x>=m || y<0 || y>=n){
        return;
    }

    if(vis[x][y]){
        return; 
    }
    else if(a[x][y]=='X'){
        return;
    }
    vis[x][y]=true;
    captured[x][y]=false;

    vector<int> dx{0,1,0,-1};
    vector<int> dy{1,0,-1,0};
    for(int k=0;k<4;k++){
        int i=x+dx[k];
        int j=y+dy[k];
        dfs(i,j,a,captured,vis);
    }
}

void Solution::solve(vector<vector<char>> &A) {
    int m=A.size();
    int n=A[0].size();

    vector<vector<bool>> captured(m,vector<bool> (n,true));
    vector<vector<bool>> vis(m,vector<bool> (n,false));

    for(int i=0;i<m;i++){
        dfs(i,0,A,captured,vis);
        dfs(i,n-1,A,captured,vis);
    }

    for(int j=0;j<n;j++){
        dfs(0,j,A,captured,vis);
        dfs(m-1,j,A,captured,vis);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(captured[i][j]){
                A[i][j]='X';
            }
            else{
                A[i][j]='O';
            }
        }
    }    
}


