// Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

// Example 1:
// Input:
// R=4
// C=5
// M=[[1,2,-1,-4,-20],
// [-8,-3,4,2,1],
// [3,8,10,1,3],
// [-4,-1,1,7,-6]]
// Output: 29
// Explanation: The matrix is as follows and the blue rectangle denotes the maximum sum rectangle.

// Example 2:
// Input:
// R=2
// C=2
// M=[[-1,-2],[-3,-4]]
// Output:
// -1
// Explanation:Taking only the first cell is the optimal choice.



//Solution Approach :-
class Solution {
  public:
	int kadane(vector<int> v,int n){
	    int mx = INT_MIN;
	    int untill = 0;

	    for(int i=0;i<n;i++){
	        untill += v[i];
	        if(untill>mx){ 
	        	mx= untill;
	        }
	        if(untill<0){ 
	        	untill = 0;
	        }
	    }
	    return mx;
	}

    int maximumSumRectangle(int m, int n, vector<vector<int>> M) {
        int maxi = INT_MIN;
        for(int i=0;i<m;i++){
            vector<int> res(n,0);
            for(int j=i;j<m;j++){
                for(int col=0;col<n;col++){
                    res[col] += M[j][col];
                }
                maxi = max(maxi,kadane(res,n));
            }
        }
        return maxi;
    }
};


// Approach :-
// Easy to Understand, O(C*C*R) Time and O(R*C) Space

// Really great problem, can be solved by selecting starting and ending columns ( O(C*C) ) then using kadanes algorithm for finding largest sum of contiguous rows in between those 2 columns we selected.
// Sum of a row can be found with pre-calculations, thus helping us find Largest Sum of contiguous rows in O(R)…..bringing the total time complexity to O(R*C*C).
// We can do same for columns instead of rows to make time complexity O(C*R*R) interchangeably


//Third Solution :- Use prefix-sum array and Kadane's algorithm.
int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
	vector<vector<int>> acc(R, vector<int>(C + 1));
	int glo = INT_MIN;

	// prefix-sum array
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			acc[i][j + 1] = acc[i][j] + M[i][j];
		}
	}
			
	for (int i = 0; i < C; ++i){
		for (int j = i; j < C; ++j){
			// kadane
			int loc = 0;
			for (int k = 0; k < R; ++k){
				// use prefix-sum to avoid repeated accumulation.
				loc += acc[k][j + 1] - acc[k][i]; 
				glo = max(glo, loc);
				loc = max(loc, 0);
			}
		}
	}

	return glo;
}
