https://www.interviewbit.com/problems/region-in-binarymatrix/





//Solution Approach :- DFS/BFS
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,0,-1,1,-1};

int dfs(vector<vector<int>>& mat,int i,int j,int& row,int& column){
    if(i<0 || j<0 || i>=row || j>=column || mat[i][j]==0){
    	return 0;
    }
    
    mat[i][j] = 0;
    int ans = 1;
    for(int k=0; k<8; k++){
        int newx = i + dx[k];
        int newy = j + dy[k];
        
        ans += dfs(mat, newx, newy, row, column);
    }
    return ans;
}


int bfs(vector<vector<int>>& mat,int i,int j,int& row,int& column)
{
    queue<pair<int,int>> q;
    q.push({i,j});   //push current i and j index in queue
    mat[i][j] = 0;   //make it visited
    int cnt = 1;     //start counting from 1
                
    while(!q.empty()){
        pair<int,int> currIndex= q.front();
        q.pop();

        int x = currIndex.first;
        int y = currIndex.second;
        
        for(int k=0; k<8; k++){
            int newX = dx[k] + x;
            int newY = dy[k] + y;
            
            if(newX>=0 && newY>=0 && newX<row && newY<column && mat[newX][newY]==1)
            {
                cnt++;
                q.push({newX,newY});
                mat[newX][newY]=0;
            }
        }
    }
    
    return cnt;
}

int Solution::solve(vector<vector<int> > &mat) {
    int ans=0;
    int row=(int) mat.size();
    if(row==0) return 0;
    int column= mat[0].size();
        
    
    for(int i=0;i<row;i++){
	    for(int j=0;j<column;j++){
	        if(mat[i][j]==1){
	            ans = max(ans, bfs(mat, i, j, row, column));
	        }
	    }
	}
    return ans;
}

// Time Complexity = O(row* column)
// Space Complexity= O(row* column)


    

//Second Solution :- 
void dfs(vector<vector<int>> &A, vector<vector<bool>> &vis, int x[], int y[], int i, int j, int &c, int &ans, int n, int m){
    vis[i][j]=true;
    c++;
    ans = max(ans, c);

    for(int k=0;k<8;k++){
        int px = i + x[k];
        int py = j + y[k];
        if(px>=0 && px<n && py>=0 && py<m && !vis[px][py] && A[px][py]==1){
            dfs(A, vis, x, y, px, py, c, ans, n, m);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(), m=A[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int x[8] = {1,-1,0,0,1,1,-1,-1};
    int y[8] = {0,0,1,-1,1,-1,1,-1};
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 1 && !vis[i][j]){
                int c = 0;
                dfs(A,vis,x,y,i,j,c,ans,n,m);
            }
        }
    }
    return ans;
}




