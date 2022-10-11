// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:
// Input: triangle = [[-10]]
// Output: -10



//Solution Approach :-
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) 
    {
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



//Second Solution :-
// top-down 
int minimumTotal1(vector<vector<int>>& triangle) {
    vector<int> res(triangle.size(), triangle[0][0]);
    
    for (unsigned int i = 1; i < triangle.size(); i++){
        for (int j = i; j >= 0; j--) {
            if (j == 0){
                res[0] += triangle[i][j];
            }
            else if (j == i){
                res[j] = triangle[i][j] + res[j-1];
            }
            else{
                res[j] = triangle[i][j] + min(res[j-1], res[j]);
            }
        }
    }
    return *min_element(res.begin(), res.end());
}


//Third Solution :-
// bottom-up
int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> res = triangle.back();
    for (int i = triangle.size()-2; i >= 0; i--){
        for (unsigned int j = 0; j <= i; j++) {
            res[j] = triangle[i][j] + min(res[j], res[j+1]);
        }
    }
    return res[0];
}




