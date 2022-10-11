https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//First Solution :- Using Recursion
int f(int i, int j, vector<vector<int>>& triangle, int n){
    if(i==n-1){
        return triangle[i][j];
    }
    int down = triangle[i][j] + f(i+1,j,triangle,n);
    int diagonal = triangle[i][j] + f(i+1,j+1,triangle,n);
    
    return min(down, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0,0,triangle,n);
}


//Second Solution :- Memoization 
int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    if(i==n-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down = triangle[i][j] + f(i+1,j,triangle,n,dp);
    int diagonal = triangle[i][j] + f(i+1,j+1,triangle,n,dp);
    
    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
	return f(0,0,triangle,n,dp);
}


//Third Solution :- Tabulation 
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){                //base case 
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}



//Fourth Solution :- Space Optimized Solution 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
        	dp[i]=triangle[n-1][i];   //our initial dp array will be same as last row of triangles
        }

        for(int i=n-2; i>=0; --i){
            for (int j=0; j<triangle[i].size(); ++j){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};



//Fifth Solution :- Space Optimized Video
int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    return front[0];
}