// Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
// Example:
// Input :
//     A : [1 3 5] 
//     k : 4
// Output : YES
// as 5 - 1 = 4
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem
// Try doing this in less than linear space complexity.

//Hint 
// The naive approach obviously is exloring all combinations of 2 integers using 2 loops and then checking their difference.
// But can we use the fact that the array is sorted?
// What if we have 2 pointers both pointing towards the start of the array?

//Solution Approach :-
// Let us first look at why 2 pointer approach works here.
// A naive 2 loop approach would be:

// for (int i = 0; i < len; i++) {
//   for (int j = i + 1; j < len; j++) {
//     if (A[j] - A[i] > diff) break; // No need going forward as the difference is going to increase even further. 
//     if (A[j] - A[i] == diff) return true; 
//   }
// }
// Now, let us say that for i = I, we we exploring j.

// At j = J - 1, our difference D1 was less than diff
// At j = J, our difference D2 exceeded diff.
// When i = I + 1, our A[i] increases ( as the array is sorted ).
// So, for j = J - 1, the differece will be smaller than D1
// (which is even more smaller to diff.)
// Which means we do not need to explore j <= J - 1
// and we can begin exploring directly from j = J.
// So, j only keeps moving in forward direction and never needs to come back as i increases.

// Let us use that in a solution now:

// int j = 0; 
// for (int i = 0; i < len; i++) {
//   j = max(j, i+1);
//   while (j < len && (arr[j] - arr[i] < diff)) j += 1;
//   if (arr[j] - arr[i] == diff) return true;
// }


//First Solution
int Solution::diffPossible(vector<int> &A, int B) {
    int N = A.size() - 1;
    int i = 0, j = 1;
    while(i < N && j <= N){
        if(i == j) j++;
        int diff = A[j] - A[i];
        if(diff == B) {
            return 1;
        }
        else if(diff < B) j++;
        else i++;
    }
    return 0;
}


//Second Solution
int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
	B = abs(B);

	for(int i=0; i<n-1; i++) {
	    int high = n-1;
	    int low = i+1;
	    int mid;

	    while(low<=high) {
	        mid = (low+high)/2;
	        if(A[mid] - A[i] > B) {
	            high = mid-1;
	        }
	        
	        else if(A[mid] - A[i] < B) {
	            low = mid+1;
	        }
	        
	        else {
	            return 1;
	        }
	    }
	}
	return 0;
}


//Third Solution
int Solution::diffPossible(vector<int> &a, int k) 
{
    int i=0,j=1;
    while(i<a.size() && j<a.size())
    {
        if(i!=j && a[j]-a[i]==k)
        {
            return 1;
        }
        else if(a[j]-a[i]<k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

//Fourth Solution :-
int Solution::diffPossible(vector<int> &A, int B) {
    int n,i,j=n-1;
    n=A.size();
    for(i=0;i<n-1;i++)
    {
        
        for(j=n-1;j>i;j--)
        {
            if(A[j]-A[i]==B)
            {
                return 1;
            }
            else if(A[j]-A[i]<B)
            {
                break;
            }
            
        }
    }
    return 0;
}


