// Given an sorted array A of size N. Find number of elements which are less than or equal to B.
// NOTE: Expected Time Complexity O(log N)


//Solution Approach
Naive Approach:

Search whole array linearly and count elements which are less then or equal to B.

Efficient approach: As the whole array is sorted we can use binary search to find result.

Case 1: When B is present in array, the last position of B is the result.
Case 2: When B is not present in array, we ignore right half if B is greater than mid. If B is smaller than mid, we ignore left half. We always end up with case where B is present before middle element.





// First Method :-
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int high=n-1, low=0,count=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]<=B){
            count=mid+1;
            low=mid+1;
        }
        if(A[mid]>B) 
            high=mid-1;

    }
    return count;
}



//Second Method :-
int Solution::solve(vector<int> &A, int B) {
    return upper_bound(A.begin(),A.end(),B)-A.begin();
}


//Third Method :-
int Solution::solve(vector<int> &a, int b){
    int l=0,h=a.size(),m,x=-1,y=-1;
    while(l<=h){
        m=l+(h-l)/2;
        if(a[m]<=b){y=m; l=m+1;}
        else h=m-1;
    }
    if(y!=-1) return y+1;
    else return 0;

}

// Fourth Method :- Recursion


