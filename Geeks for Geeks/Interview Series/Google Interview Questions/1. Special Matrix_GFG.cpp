Given N and a square matrix with dimensions NxN. Find the minimum number of moves required to make a matrix special. In a single move, you can select an arbitary element and increase/decrease it by 1.
A special matrix is defined as a matrix where at least one row or column that contains only special numbers.
A special number P is a non-negative integer for which the following quadratic equation has at least one negative integer root:
x2-(2*P)+x=0

Example 1:
Input:
N = 3
matrix[] = {(1, 2, 3), (4, 5, 6), (7, 8, 9)}
Output: 1
Explanation:
Increasing the second element in first
row will make it (1, 3, 3)

Example 2:
Input:
N = 2
arr[] = {(1,2), (1,3)}
Output: 0
Explanation:
First column is already special.



//Solution :-
class Solution{
  public:
    int minMoves(int N, vector<vector<int>>matrix){
        vector<int>arr;
        //All Possible P's in array
        for(int i=0;i<=50;i++){
        	arr.push_back((i*(i+1))/2);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<N;i++){     //Check for each row
        	for(int j=0;j<N;j++){
        		int val=matrix[i][j];
        		int least=INT_MAX;
        		for(auto it:arr){
        			least=min(least,abs(it-matrix[i][j]));
        		}
        		moves+=least;
        	}
        	ans=min(ans,moves);
        }

        for(int i=0;i<N;i++){     //Check for each column
        	for(int j=0;j<N;j++){
        		int val=matrix[j][i];
        		int least=INT_MAX;
        		for(auto it:arr){
        			least=min(least,abs(it-matrix[i][j]));
        		}
        		moves+=least;
        	}
        	ans=min(ans,moves);
        }
        return ans;
    }
};




//Optimization for above Solution :-
//The last loop isn't required we can use binary search for ans
class Solution{
  public:
    int minMoves(int N, vector<vector<int>>matrix){
        vector<int>arr;
        //All Possible P's in array
        for(int i=0;i<=50;i++){
        	arr.push_back((i*(i+1))/2);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<N;i++){     //Check for each row
        	int moves=0;
        	for(int j=0;j<N;j++){
        		int x = upper_bound(arr.begin(),arr.end(),matrix[i][j])-arr.begin();
        		moves+=min(abs(matrix[i][j]-arr[x]), abs(matrix[i][j]-arr[x-1]));
        	}
        	ans=min(ans,moves);
        }

        for(int i=0;i<N;i++){     //Check for each column
        	int moves=0;
        	for(int j=0;j<N;j++){
        		int x = upper_bound(arr.begin(),arr.end(),matrix[j][i])-arr.begin();
        		moves+=min(abs(matrix[j][i]-arr[x]), abs(matrix[j][i]-arr[x-1]));
        	}
        	ans=min(ans,moves);
        }
        return ans;
    }
};


