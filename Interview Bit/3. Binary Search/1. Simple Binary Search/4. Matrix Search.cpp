// Given a matrix of integers A of size N x M and an integer B.

// Write an efficient algorithm that searches for integar B in matrix A.

// This matrix A has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than or equal to the last integer of the previous row.
// Return 1 if B is present in A, else return 0.

// Note: Rows are numbered from top to bottom and columns are numbered from left to right.



//Solution Approach :-
If you write down the numbers of row 1 followed by numbers in row2, row3 and so on, do you think the resulting array would be sorted ?
If yes, how do you search for a number efficiently in a sorted array ?



//First Method :-
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n=A.size();
    int m=A[0].size();
    int i=0, j=m-1;
    while(i<n && j>=0){
        if(A[i][j]==B){
            return true;
        }
        if(A[i][j]>B){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}



//Second Method :-
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    if(!A.size()) return false;

    int n=A.size();
    int m=A[0].size();

    int lo=0;
    int hi=(n*m)-1;

    while(lo<=hi){
        int mid=(lo + (hi-lo)/2);
        if(A[mid/m][mid%m] == B){
            return true;
        }
        if(A[mid/m][mid%m] < B){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return false;

}


//Third Method :-
