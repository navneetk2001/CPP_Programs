// Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
// NOTE:
// A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

// Input 1:
//  A = [3, 9, 10, 20, 17, 5, 1]
//  B = 20
// Output 1: 3
// Explanation 1: B = 20 present in A at index 3

// Input 2:
//  A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
//  B = 30
// Output 2: -1
// Explanation 2: B = 30 is not present in A

//Hint 1
// First think of finding the bitonic point of the array (i.e the index of the maximum element of the array)
// Try to use the above fact for finding a solution to the problem.


//Solution Approach
// A simple solution is to do linear search. Time complexity of this solution would be O(N).

// An efficient solution is based on Binary Search. The idea is to find the bitonic point k which is the index of the maximum element of given sequence. If the element to be searched is greater than maximum element return -1, else search the element in both halves. Below is the step by step algorithm on how to do this.

// Find the bitonic point in the given array, i.e the maximum element in the given bitonic array. This can be done in log(N) time by modifying the binary search algorithm. You can refer to this post on how to do this.
// If the element to be searched is equal to the element at bitonic point then print the index of bitonic point.
// If the element to be searched is greater than element at bitonic point then element does not exist in the array.
// If the element to be searched is less than element at bitonic point then search for element in both half of the array using binary search.



// First Method :-
int Solution::solve(vector<int> &arr, int B) {
    int n=arr.size();
    int hi=n-1;
    int lo=0;
    int mid=lo+(hi-lo)/2;
    while(hi>=lo)
    {
        mid=lo+(hi-lo)/2;
        if(!(mid+1<n and mid-1>=0))
            break;
        if(arr[mid-1]<arr[mid] and arr[mid]<arr[mid+1])
            lo=mid+1;
        else if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
            break;
        else
            hi=mid-1;
    }
    
    int peak=mid;
    hi=peak;
    lo=0;
    mid=lo+(hi-lo)/2;
    while(hi>=lo){
        mid=lo+(hi-lo)/2;
        if(arr[mid]==B){
            return mid;
        }
        else if(arr[mid]>B){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }

    hi=n-1;
    lo=peak+1;
    mid=lo+(hi-lo)/2;
    while(hi>=lo){
        mid=lo+(hi-lo)/2;
        if(arr[mid]==B){
            return mid;
        }
        else if(arr[mid]<B){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;
}


//Second Method :-
int bitonic (vector<int> &A){
    int low = 0, high = A.size() - 1, res = -1;

    while (high >= low){
        int mid = low + (high - low) / 2;

        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){     // a value in the array is a bitonic point if it is greater than it's adjacent neighbours
            res = mid;
            return res;
        }        
        else if (A[mid] > A[mid - 1]){        // if the value is not a bitonic point and is greater than it's left adjacent value, then we update low as mid is currently on the increasing sequence 
            low = mid + 1;
        }
        else{                // else if the value is neither bitonic point nor greater than the left, then we update high as mid is currently on the decreasing sequence
            high = mid - 1;
        }
    }

    return res;
}

// simple binary search to search the value in the range A[0 ... bitonic_point]
int searchInInc (vector<int> &A, int bit, int B){
    int high = bit, low = 0, res = -1;

    while (high >= low){
        int mid = low + (high - low) / 2;

        if (A[mid] == B){      // if the element to be searched is found, we return index
            res = mid;
            return res;
        }
        else if (A[mid] > B){    // else we update high and low as per simple binary search
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return res; 
}

// simple binary search to search the value in the range A[bitonic_point ... A.size() - 1]
int searchInDec (vector<int> &A, int bit, int B){
    int high = A.size() - 1, low = bit, res = -1;

    while (high >= low){
        int mid = low + (high - low) / 2;

        if (A[mid] == B){
            res = mid;
            return res;
        }
        else if (A[mid] > B){
            low = mid + 1;
        }      
        else{
            high = mid - 1;
        }
    }

    return res; 
}

int Solution::solve(vector<int> &A, int B) {
    // calculate bitonic point and search for element in increasing and decreasing sequences
    int bit = bitonic(A);
    int inc = searchInInc(A, bit, B);
    int dec = searchInDec(A, bit, B);

    if (inc == -1 && dec == -1){           // if the value is neither found in increasing nor decreasing sequences
        return -1;
    }
    
    if (inc >= 0){      // if the value is found in increasing sequence
        return inc;
    }
    return dec;          // if the value is found in the decreasing sequence

}


//Third Method :-
int helper(vector<int>& arr, int si, int ei){
    int mid = (si+ei)/2;
    
    if(arr[mid-1]<arr[mid] && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(arr[mid-1]<arr[mid] && arr[mid] < arr[mid+1]){
        return helper(arr, mid+1, ei);
    }
    return helper(arr, si, mid-1);
}

int Solution::solve(vector<int> &A, int B) {
    int pos = helper(A, 0, A.size()-1);
    
    int index = lower_bound(A.begin(), A.begin()+pos, B) - A.begin();
    if(A[index]==B) {
        return index;
    }
    
    index = lower_bound(A.begin()+pos, A.end(), B, greater<int>()) - A.begin();
    if(A[index]==B) {
        return index;
    }
    
    return -1;
}



