// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false




//Solution Approach :-
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(m == 0){
            return false;
        }

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            } 
            else{
                i++;
            }
        }
        return false;
    }
};




//Second Solution :-
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        int i = m - 1;
        int j = 0;
        
        while (i>=0 && j<n){
            if (mat[i][j] == target) return true;
            else if (mat[i][j] < target) j++;
            else i--;
        }
        return false;
    }
};




//Third Solution :-
BINARY SEARCH SOLUTION

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        int lo, hi, mid;
        
        for (int i=0; i<m; i++){
            if (mat[i][0]<=target && mat[i][n-1]>=target){
                lo = 0;
                hi = n - 1;
				if (lo==hi && mat[i][lo]==target) return true;
                while (lo < hi){
                    mid = (lo + hi) / 2;
                    if (mat[i][mid] == target) return true;
                    else if (mat[i][mid] < target) lo = mid + 1;
                    else hi = mid;
                }
            }
        }
        return false;
    }
};