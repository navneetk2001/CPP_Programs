// Given a sorted array A consisting of duplicate elements.
// Your task is to remove all the duplicates and return a sorted array of distinct elements consisting of all distinct elements present in A.
// But, instead of returning an answer array, you have to rearrange the given array in-place such that it resembles what has been described above.
// Hence, return a single integer, the index(1-based) till which the answer array would reside in the given array A.
// Note: This integer is the same as the number of integers remaining inside A had we removed all the duplicates.
// Look at the example explanations for better understanding.

// Input 1:
// A = [1, 1, 2]
// Output 1:
// 2

// Input 2:
// A = [1, 2, 2, 3, 3]
// Output 2:
// 3

//Hint 
// You need to modify the original array itself. So you need to keep current like pointer which will point to the index of the array where you can store the next value.
// How can you define another pointer to keep track of next value?

//Solution Approach :-
// Notice that the array is sorted.
// This implies that all repetitions for an element are clustered together in the array.
// **Try maintaining 2 pointers in the array: **
// One pointer iterates over the array and
// Other pointer only moves per occurrence of a value in the array.
// Now you need to make sure we choose only one occurrence per cluster of repetition in the array, we could probably just check if A[i] != A[i+1].
// So, the second pointer only moves when A[i] != A[i+1]


//First Solution
int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0)
       return 0;
    
    int i = 0;
    for(int j = 1; j < A.size(); j++){
        if(A[j] != A[i]){
            i++;
            A[i] = A[j];
        }
    }
    return i+1;
}


//Second Solution
int Solution::removeDuplicates(vector<int> &A){
    int n = A.size();
    
    int count = 0 ;                  // we have to return the index
    for(int i = 0 ; i < n ; i++){
        if(i < n - 1 && A[i] == A[i+1]){
            continue;
        }
        else{
            A[count] = A[i];
            count++;
        }
    }
    return count;
}


//Third Solution
int Solution::removeDuplicates(vector<int> &A) {
   
   int n = A.size();
   if(n==0 || n==1) return n;
   int j = 0;
   for(int i=0;i<n-1;i++){
       if(A[i]!=A[i+1]){
           A[j++] = A[i];
       }
   }
   A[j++] = A[n-1];
   return j;
}


