// Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
// NOTE:
// A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


//Hint 1
First think of finding the bitonic point of the array (i.e the index of the maximum element of the array)

Try to use the above fact for finding a solution to the problem.


//Solution Approach
A simple solution is to do linear search. Time complexity of this solution would be O(N).

An efficient solution is based on Binary Search. The idea is to find the bitonic point k which is the index of the maximum element of given sequence. If the element to be searched is greater than maximum element return -1, else search the element in both halves. Below is the step by step algorithm on how to do this.

Find the bitonic point in the given array, i.e the maximum element in the given bitonic array. This can be done in log(N) time by modifying the binary search algorithm. You can refer to this post on how to do this.
If the element to be searched is equal to the element at bitonic point then print the index of bitonic point.
If the element to be searched is greater than element at bitonic point then element does not exist in the array.
If the element to be searched is less than element at bitonic point then search for element in both half of the array using binary search.



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
        while(hi>=lo)
        {
            mid=lo+(hi-lo)/2;
            if(arr[mid]==B)
                return mid;
            else if(arr[mid]>B)
                hi=mid-1;
            else
                lo=mid+1;
        }
        hi=n-1;
        lo=peak+1;
        mid=lo+(hi-lo)/2;
        while(hi>=lo)
        {
            mid=lo+(hi-lo)/2;
            if(arr[mid]==B)
                return mid;
            else if(arr[mid]<B)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return -1;
}




//Second Method :-
// function to calculate the bitonic point
// can be found out using binary search
int bitonic (vector<int> &A)
{
    int low = 0, high = A.size() - 1, res = -1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        // a value in the array is a bitonic point if it is greater than it's adjacent neighbours
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
        {
            res = mid;
            return res;
        }
        
        // if the value is not a bitonic point and is greater than it's left adjacent value, 
        // then we update low as mid is currently on the increasing sequence 
        else if (A[mid] > A[mid - 1])
            low = mid + 1;
        
        // else if the value is neither bitonic point nor greater than the left, then
        // we update high as mid is currently on the decreasing sequence
        else
            high = mid - 1;
    }

    return res;
}

// simple binary search to search the value in the range A[0 ... bitonic_point]
int searchInInc (vector<int> &A, int bit, int B)
{
    int high = bit, low = 0, res = -1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        // if the element to be searched is found, we return index
        if (A[mid] == B)
        {
            res = mid;
            return res;
        }

        // else we update high and low as per simple binary search
        else if (A[mid] > B)
            high = mid - 1;
        
        else
            low = mid + 1;
    }

    return res; 
}

// simple binary search to search the value in the range A[bitonic_point ... A.size() - 1]
int searchInDec (vector<int> &A, int bit, int B)
{
    int high = A.size() - 1, low = bit, res = -1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == B)
        {
            res = mid;
            return res;
        }

        // since the sequence is decreasing,
        // if mid value is greater than the element to be found,
        // we update low instead of high
        else if (A[mid] > B)
            low = mid + 1;

        // similarly, if the sequence is increasing,
        // we update high        
        else
            high = mid - 1;
    }

    // if the element is not found, we return -1
    return res; 
}

int Solution::solve(vector<int> &A, int B) {

    // calculate bitonic point and search for element in increasing and decreasing sequences
    int bit = bitonic(A);
    int inc = searchInInc(A, bit, B);
    int dec = searchInDec(A, bit, B);

    // if the value is neither found in increasing nor decreasing sequences
    if (inc == -1 && dec == -1)
        return -1;
    
    // if the value is found in increasing sequence
    if (inc >= 0)
        return inc;
    
    // if the value is found in the decreasing sequence
    return dec;

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
    // cout<<pos<<endl;
    
    int index = lower_bound(A.begin(), A.begin()+pos, B) - A.begin();
    if(A[index]==B) return index;
    
    index = lower_bound(A.begin()+pos, A.end(), B, greater<int>()) - A.begin();
    if(A[index]==B) return index;
    
    return -1;
}



