// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

// Example 1:
// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.

// Example 2:
// Input: matrix = [[1,-1],[-1,1]], target = 0
// Output: 5
// Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

// Example 3:
// Input: matrix = [[904]], target = 0
// Output: 0




//Solution Approach :-
class Solution {
public:
	// TIME COMPLEXITY:- O(N*M^2)
	// SPACE COMPLEXITY:- O(N*M)
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        // store prefix sum for each row
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        int ans = 0;
        unordered_map<int,int> mp;    // map to store prefix sum of rows for a particular range of columns
        
        for(int start=0; start<m; start++){
            for(int end =start; end<m; end++){
                // we are considering columns b/w {start,end}
                mp.clear();        // clear previous entries
                mp[0]++;
                
                int sum = 0;         // add sum for each row b/w the given range of columns
                for(int i=0; i<n; i++){    // add sum for this row b/w {start,end}
                    int curr = mat[i][end];    // curr stores sum of current row of matrix b/w given range of columns
                    
                    if(start > 0){
                        curr -= mat[i][start-1];
                    }
                    sum += curr;                    // sum of matrix elements upto now b/w given range
                    ans += mp[sum - target];        // increment answers
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};



//Second Solution :- 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        
        for (int i = 0; i < m; i++){     //Calculates prefix sum for each row
            for (int j = 1; j < n; j++){
                A[i][j] += A[i][j - 1];
            }
        }

        unordered_map<int, int> counter;     //map to store count of subarrays
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};



//Second Solution :- ❌ Solution - I (Brute-Force Approach) [Rejected]
//Let's start with the most basic approach to this problem. Take all the submatrices possible for the given matrix and check if their sum is equal to target.

int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
	int res = 0, m = size(A), n = size(A[0]);
	// calculate sum of each submatrix and check if it is equal to target
	for(int rowStart = 0; rowStart < m; rowStart++){
		for(int rowSize = 1; rowStart + rowSize <= m; rowSize++){
			for(int colStart = 0; colStart < n; colStart++){
				for(int colSize = 1; colStart + colSize <= n; colSize++){
					if(SUM(A, rowStart, rowSize, colStart, colSize) == target){
						res++;
					}
				}
			}
		}
	}
	return res;    
}

// Calculates the sum of a submatrix with given bounds
int SUM(vector<vector<int> > &A, int rStart, int rSize, int cStart, int cSize){
	int subMatrixSum = 0;
	for(int i = rStart; i < rStart + rSize; i++){
		for(int j = cStart; j < cStart + cSize; j++){
			subMatrixSum += A[i][j];
		}
	}
	return subMatrixSum;
}
// Time Complexity : O((M*N)^3), where M is the number of rows and N is the number of columns in the given matrix.
// Space Complexity : O(1)




//✔️ Solution - II (Compute prefix sum for each Row or Column)
// We can optimize the above approach by reducing the time complexity of the SUM function in the above solution. We know that in a given array, the sum of range [i,j] can be calculated by prefixSum[j] - prefixSum[i - 1]. We can use this to optimize the solution.
// After computing prefix sum for each row of matrix (you can do it for column as well), we can get the sum of a given range in O(1) time. Thus, for any submatrix of the main matrix, we just need to iterate over all its rows and we can get sum of given range ([colStart, colEnd]) in O(1) time.
// We just start from row 0, calculate the sum for that row for the range [colStart, colEnd].
// Extend the sum by perform step-1 for row 1, row 2, ... and so on till last row.
// Repeat this process for every [colStart, colEnd] combination.

int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
	int res = 0, m = size(A), n = size(A[0]);
	// calculating prefix sum for each row of matrix
	for (int row = 0; row < m; row++){
		for (int col = 1; col < n; col++){
			A[row][col] += A[row][col - 1];
		}
	}
	// calculate sum of each submatrix and check if it is equal to target
	for (int colStart = 0; colStart < n; colStart++) {
		for (int colEnd = colStart; colEnd < n; colEnd++) {
			for(int rowStart = 0; rowStart < m; rowStart++){
				int sum = 0;
				for(int rowEnd = rowStart; rowEnd < m; rowEnd++){
					sum += A[rowEnd][colEnd] - (colStart ? A[rowEnd][colStart - 1] : 0);
					if(sum == target) res++;
				}
			}
		}
	}
	return res;    
}
// Time Complexity : O((M*N)^2), where M is the number of rows and N is the number of columns in the given matrix.
// Space Complexity : O(1), since we are modifying the given matrix itself. If we use a new prefix sum matrix, the space complexity would be O(M*N).




//Third Solution :- ✔️ Solution - III (Further Optimization in Solution - II)
// We can further optimize the solution by using hashmap. The optimization done here is similar to the one in solution of 560. Subarray Sum Equals K.
// Basically, we will be maintaining a running submatrix sum starting from row 0 till m, for a given [colStart, colEnd] range. Each sum value and number of its occurence will be stored in hashmap. If there's a submatrix which was found such that cursum at that time was equal to present sum (cursum) - target, then we are sure that there were occurences of submatrices which had sum equal to target and the count is given by mp[cursum - target].
// If the explanation didn't make the approach clear, I really suggest you to try the 560. Subarray Sum Equals K problem and read the hashmap solution. It took me some time reading that before I was able to clearly understand this solution.

int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
	int res = 0, m = size(A), n = size(A[0]);
	for (int row = 0; row < m; row++)
		for (int col = 1; col < n; col++)
			A[row][col] += A[row][col - 1];
	//         cursum, occurences
	unordered_map<int, int> mp;
	for (int colStart = 0; colStart < n; colStart++) {
		for (int colEnd = colStart; colEnd < n; colEnd++) {
			int cursum = 0;
			mp = {{0, 1}};
			for(int row = 0; row < m; row++){
				cursum += A[row][colEnd] - (colStart ? A[row][colStart - 1] : 0);    
				// mp[sum-target] will give number of submatrices found having sum as 'sum - target'
				res += mp[cursum - target];
				mp[cursum]++;
			}
		}
	}
	return res;    
}
// Time Complexity : O(N*N*M), where M is the number of rows and N is the number of columns in the given matrix.
// Space Complexity : O(N)
