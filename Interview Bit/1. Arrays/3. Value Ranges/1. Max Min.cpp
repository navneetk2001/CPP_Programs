// Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.
// NOTE: You should make minimum number of comparisons.


// Hint1
//Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.


// Solution Approach
//Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

// Pair MaxMin(array, array_size)
//    if array_size = 1
//       return element as both max and min
//    else if arry_size = 2
//       one comparison to determine max and min
//       return that pair
//    else    /* array_size  > 2 */
//       recur for max and min of left half
//       recur for max and min of right half
//       one comparison determines true max of the two candidates
//       one comparison determines true min of the two candidates
//       return the pair of max and min
// Time Complexity: O(n)
// Total number of comparisons: let number of comparisons be T(n). T(n) can be written as follows:
// Algorithmic Paradigm: Divide and Conquer

//   T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
//   T(2) = 1
//   T(1) = 0
// If n is a power of 2, then we can write T(n) as:
//    T(n) = 2T(n/2) + 2 
// After solving above recursion, we get

//   T(n)  = 3n/2 -2 
// Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.



// First Approach :-
int Solution::solve(vector<int> &A) {
    int min=A[0];
    int max=A[0];
    for(int i=0;i<A.size();i++){
        if(min>A[i])
            min=A[i];
        if(max<A[i])
            max=A[i];
            
    }
    return max+min;
}


//Second Approach :-
int Solution::solve(vector<int> &A) {
   int n=A.size();
   int x=*max_element(A.begin(),A.end());
   int y=*min_element(A.begin(),A.end());
   return x+y;
}