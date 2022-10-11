// You are in an infinite 2D grid where you can move in any of the 8 directions
//     (x,y) to 
//     (x-1, y-1), 
//     (x-1, y)  , 
//     (x-1, y+1), 
//     (x  , y-1),
//     (x  , y+1), 
//     (x+1, y-1), 
//     (x+1, y)  , 
//     (x+1, y+1) 
// You are given a sequence of points and the order in which you need to cover the points.
// Give the minimum number of steps in which you can achieve it. You start from the first point.

// Input 1:
//  A = [0, 1, 1]
//  B = [0, 1, 2]

// Output 1: 2
// Explanation 1: Given three points are: (0, 0), (1, 1) and (1, 2). It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).


//First Solution :-
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int m=A.size();
    int n=B.size();
    
    int count=0;
    for(int i=1;i<m;i++){
        count+=max(abs(A[i]-A[i-1]), abs(B[i]-B[i-1]));
    }
    return count;
}




//Second Method :- 
class Solution {
    public:
        int coverPoints(vector<int> x, vector<int> y) {
            if (x.size() <= 1) return 0;
            assert(x.size() == y.size());
            int ans = 0;
            for (int i = 1; i < x.size(); i++) {
                ans += max(abs(x[i] - x[i-1]), abs(y[i] - y[i-1]));
            }
            return ans;
        }
};



//Third Method :- 
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n,a,b,distance = 0;
    for( n = 1 ; n < A.size(); n++)
         {
             a = (A[n] > A[n-1]) ? A[n] - A[n-1] : A[n-1] - A[n];
             b = (B[n] > B[n-1]) ? B[n] - B[n-1] : B[n-1] - B[n];
             if(a>b)
                distance += a;
            else
               distance += b;
            
         }
    return distance;
}
