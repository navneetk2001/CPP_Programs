class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp((n),vector<int> (m));
        int count = 0;  //counts number of square matrices with all 1's
        //Fill 1st row
        for(int i=0;i<m;++i)
        {
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }
        //Fill 1st col
        for(int i=1;i<n;++i)
        {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        
        //Now fill all other cells
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(matrix[i][j]==1)
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                count+=dp[i][j];
            }
        }
        return count;
    }
};