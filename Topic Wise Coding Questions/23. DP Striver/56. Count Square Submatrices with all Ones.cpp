https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos




//First Solution :-  Tabulation (Based on intuition)
int countSquares(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){     //first column same as it is
        dp[i][0] = matrix[i][0];
    }
    for(int j=0;j<m;j++){     //first row same as it is
        dp[0][j] = matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum += dp[i][j];
        }
    }
    return sum;
}






//Second Solution :-
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m,0));
    
    int total{arr[0][0]};
    dp[0][0]=arr[0][0];

    for(int i=1;i<n;i++){
        dp[i][0] = arr[i][0], total += arr[i][0];
    }
    for(int j=1;j<m;j++){
        dp[0][j] = arr[0][j], total += arr[0][j];
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]){
                dp[i][j] = 1+min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
            else{
                dp[i][j]=0;
            }
            total += dp[i][j];
        }
    } 
    return total;
}