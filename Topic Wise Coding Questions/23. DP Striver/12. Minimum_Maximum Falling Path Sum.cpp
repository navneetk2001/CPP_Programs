https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int i, int j, vector<vector<int>>& matrix){
    if(j<0  || j>=matrix[0].size()){
        return -1e8;
    }
    if(i==0){
        return matrix[i][j];
    }

    int up = matrix[i][j] + f(i-1,j,matrix);
    int ld = matrix[i][j] + f(i-1,j-1,matrix);
    int rd = matrix[i][j] + f(i-1,j+1,matrix);
    
    return max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi, f(n-1, j, matrix));
    }
    return maxi;
}



//Second Solution :- Memoization 
int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(j<0  || j>=matrix[0].size()){
        return -1e8;
    }
    if(i==0){
        return matrix[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int up = matrix[i][j] + f(i-1,j,matrix,dp);
    int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);
    
    return dp[i][j]=max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi, f(n-1, j, matrix,dp));
    }
    return maxi;
}


//Third Solution :- Tabulation 
int getMaxPathSum(vector<vector<int> > &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0; j<m; j++){      // Initializing first row - base condition
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
        }
    }
    
    int maxi = -1e8;
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}



//Fourth Solution :- Space Optimized Solution 
int getMaxPathSum(vector<vector<int> > &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m,0), cur(m,0);    
    for(int j=0; j<m; j++){           // Initializing first row - base condition
        prev[j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            cur[j] = max(up, max(leftDiagonal,rightDiagonal));
        }
        
        prev = cur;
    }
    
    int maxi = -1e8;
    for(int j=0; j<m;j++){
        maxi = max(maxi,prev[j]);
    }
    
    return maxi;
}


