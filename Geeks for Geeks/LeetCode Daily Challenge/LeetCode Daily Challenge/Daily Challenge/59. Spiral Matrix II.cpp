// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]




//Solution Approach :-
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 1));
        int left = 0, right = n-1, top = 0, down = n-1, index = 1;
        
        while (left <= right && top <= down) {
            //first row
            for (int j = left; j <= right; j++) {
                ans[top][j] = index;
                index++;
            }
                
            top++;
            
            //last col
            for (int i = top; i <= down; i++) {
                ans[i][right] = index;
                index++;
            }
            
            right--;
            
            //last row
            for (int j = right; j >= left; j--) {
                ans[down][j] = index;
                index++;
            }
            
            down--;
            
            //first col
            for (int i = down; i >= top; i--) {
                ans[i][left] = index;
                index++;
            }
            
            left++;
        }
        return ans;
    }
};




//Second Solution :- 
class Solution {
public:
	vector<vector> generateMatrix(int n) {
	    int r1=0, r2=n-1;
	    int c1=0, c2=n-1;
	    int val=0;
	    
	    vector<vector<int>>v(n,vector<int>(n));
	    
	    while(r1<=r2 && c1<=c2){
	        for(int i=c1;i<=c2;i++){          //left to right move,row is fixed
	            v[r1][i] = ++val;
	        }
	       
	        for(int i=r1+1;i<=r2;i++){        //top to bootom move ,colomn is fixed
	            v[i][c2] = ++val;
	        }
	       
	        for(int i=c2-1;i>=c1;i--){        // right to left move,row is fixed
	            v[r2][i] = ++val;
	        }
	        
	        for(int i=r2-1;i>r1;i--){         // bottom to up move ,colomn is fixed
	            v[i][c1] = ++val;
	        }
	        r1++;
	        c1++;
	        r2--;
	        c2--;
	    }
	    return v;
	}
};