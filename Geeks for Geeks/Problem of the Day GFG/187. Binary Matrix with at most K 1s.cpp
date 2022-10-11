// Given a binary matrix M with R rows and C columns, where each element of the matrix will be 0 or 1. Find the largest square that can be formed with center (i, j) and contains atmost K 1’s. There are Q queries, a single query has two integers denoting the centre (i,j) of the square.

// Example 1:
// Input: R = 4, C = 5
// M = {{1, 0, 1, 0, 0} 
//      {1, 0, 1, 1, 1} 
//      {1, 1, 1, 1, 1} 
//      {1, 0, 0, 1, 0}}
// K = 9, Q = 1
// q_i[] = {1}
// q_j[] = {2}
// Output: 3
// Explanation: Maximum length square with center at (1, 2) that can be formed is of 3 length from (0, 1) to (2, 4).

// Example 2:
// Input: R = 3, C = 3
// M = {{1, 1, 1} 
//      {1, 1, 1} 
//      {1, 1, 1}}
// K = 9, Q = 2
// q_i[] = {1, 2}
// q_j[] = {1, 2}
// Output : 3 1




//Solution Approach :-
class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        // code here
          vector<vector<int>> sum(R+1, vector<int>(C+1));
        
        for(int i=1; i<=R; i++) 
        for(int j=1; j<=C; j++) 
        sum[i][j] = M[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
         
        // Result vector
        vector<int> res(Q);
        
        //Proceed on queries.
        for(int q=0; q<Q; q++) {
            int x = q_i[q]+1, y = q_j[q]+1, val = M[x-1][y-1], side = 1;
            
            while(x-side>=0 and y-side>=0 and x<=R and y<=C) {
                val = sum[x][y] + sum[x-side][y-side] - sum[x-side][y] - sum[x][y-side];
                
                if(val <= K) res[q] = side;
                else { 
                    break;
                }
                
                x += 1; y += 1;
                side += 2;
            }
            
        }
        return res;
    }
};




//Second Solution :- Binary search // 2D prefix sum // TC = 0.03sec.
int sumRegion(vector<vector<int> >&mat, int row1, int col1, int row2, int col2){
     bool x = false;
     bool y = false;
     int sum = mat[row2][col2];
     if(col1-1>=0){
          sum -= mat[row2][col1-1];
          x = true;
     }
     if(row1-1>=0){
          sum -= mat[row1-1][col2];
          y = true;
     }
     if(x && y){
          sum += mat[row1-1][col1-1];
     }
     return sum;
}

int help(vector<vector<int>> &mat, int r, int c, int rc, int cc, int k){
     int l = 0;

     //calculating sort length upto which square can formed formed.
     int ri = min(rc, min(cc, min(r-rc-1, c-cc-1))); 
     int ans=0;
     while(l<=ri){
          int mid = l + (ri-l)/2;

          //calculating upper-left cell and lower-right cell index
          int row1 = rc + -1*mid, col1 = cc + -1*mid, row2 = rc + mid, col2 = cc + mid;
          int x = sumRegion(mat, row1, col1, row2, col2);
          if(x<=k){
              ans = row2-row1+1;
              l = mid+1;
          }
          else{
              ri = mid-1;
          }
     }
     return ans;
}

vector<int> largestSquare(vector<vector<int>> &mat, int r, int c, int k, int q, int q_i[], int q_j[]) {
     //computing 2D prefix sum.

     for(int i=1; i<r; i++) mat[i][0] += mat[i-1][0];
     for(int j=1; j<c; j++) mat[0][j] += mat[0][j-1];
  
     for(int i=1; i<r; i++){
          for(int j=1; j<c; j++){
               mat[i][j] += mat[i][j-1]+ mat[i-1][j] - mat[i-1][j-1]; 
          }
     }
     vector<int> ans(q,0);

     // query 
     for(int i=0; i<q; i++){
          int rc = q_i[i];
          int cc = q_j[i];
          ans[i] = help(mat,r,c, rc, cc, k);
     }
     return ans;
}

