// Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
// is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.
// Note: You can choose more than 2 numbers.

// Input 1:
//     A = [   [1]
//             [2]    ]
// Output 1:
//     2
// Explanation 1: We will choose 2.

// Input 2:
// A = [   [1, 2, 3, 4]
//         [2, 3, 4, 5]    ]
// Output 2: We will choose 3 and 5.



//Hint :-
// No two adjacent elements should be taken ( Adjacent is defined by horizontally, vertically, diagonally ).
// so suppose we have 2 * N list :

// 1 |  2  |  3  | 4
// 2 |  3  |  4  | 5

// Now suppose we choose 2, then we can't choose the element just above it 1, 
//     the element next it 3, or the element diagonally opposite. 
// In other words, if we are on (x, y), then if we choose (x, y), we can't choose
// (x + 1, y), (x, y + 1) and (x + 1, y + 1). 

// Can you implement a brute force for this using recursion using the above fact ? 
// Can you memoize the bruteforce recursive solution ? 

//Approach :-
// V : 
// 1 |  2  |  3  | 4
// 2 |  3  |  4  | 5

// Lets first try to reduce it into a simpler problem. 
// We know that within a column, we can choose at max 1 element. 
// And choosing either of those elements is going to rule out choosing anything from the previous or next column. 
// This means that choosing V[0][i] or V[1][i] has identical bearing on the elements which are ruled out. 
// So, instead we replace each column with a single element which is the max of V[0][i], V[1][i].

// Now we have the list as : 
// 2 3 4 5

// Here we can see that we have reduced our problem into another simpler problem.
// Now we want to find maximum sum of values where no 2 values are adjacent. 
// Now our recurrence relation will depend only on position i and,
//  a "include_current_element" which will denote whether we picked last element or not.
  
// MAX_SUM(pos, include_current_element) = 
// IF include_current_element = FALSE THEN   
// 	max | MAX_SUM(pos - 1, FALSE) 
// 	    | 
// 	    | MAX_SUM(pos - 1, TRUE)

// ELSE    |
// 	MAX_SUM(pos - 1, FALSE) + val(pos) 




//Solution Approach :- Recursive + Memoization
#include<bits/stdc++.h>
int f(int i, vector<vector<int>> &A, vector<int> &dp){
    if(i<0){      //out of bound base case
        return 0;
    }
    
    if(dp[i]!=-1){
        return dp[i];
    }
    
    int a = max(A[0][i], A[1][i]) + f(i-2, A, dp);
    int b = f(i-1, A, dp);
    
    return dp[i] = max(a,b);
}

int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    vector<int>dp(n+1, -1);
    return f(n-1,A,dp);
}


//Solution Approach :- Tabulation
int Solution::adjacent(vector<vector<int> > &A) {
    int i,j,it;
    int n=A[0].size();
    vector<int> ans(n+1);

    ans[n]=0;
    ans[n-1]=max(A[0][n-1],A[1][n-1]);
    for(i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1],ans[i+2]+max(A[0][i],A[1][i]));
    }
    return ans[0];
}


//Solution :- Space-Optimized Solution :-
int Solution::adjacent(vector<vector<int> > &a) {
    int n = a[0].size();
    int ans[2]; int last=0;   int temp;
    ans[0] = 0;   ans[1] = 0;
    for(int i=0; i<n; i++){
        temp = ans[i%2];
        ans[i%2] = max(last, ans[i%2]);
        last = temp;
        ans[i%2] += (a[0][i]>a[1][i])?a[0][i]:a[1][i];
    }
    return (ans[0]>ans[1])?ans[0]:ans[1];
}