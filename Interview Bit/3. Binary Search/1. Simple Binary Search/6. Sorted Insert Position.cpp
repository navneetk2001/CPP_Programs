// Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.

// Input 1: A = [1, 3, 5, 6]
// B = 5
// Output 1: 2
// Explanation 1: 5 is found at index 2.

// Input 2: A = [1, 3, 5, 6]
// B = 2
// Output 2: 1
// Explanation 2: 2 will be inserted ar index 1.


// First Method :-
int Solution::searchInsert(vector<int> &A, int B) {
    int low = 0;
    int high = A.size()-1;
    int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]<B){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;

}
    

//Second Method :-
int Solution::searchInsert(vector<int> &A, int B) {
    int low = 0;
    int high = A.size() - 1;
    int ans = 0;
    if(B < A[low]) return 0;
    if(B > A[high]) return A.size();
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(A[mid] == B)
        {
            return mid;
        }
        else if (A[mid] > B)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(A[mid] < B)
        {
            low = mid + 1;
        }
    }
    return ans;
}






