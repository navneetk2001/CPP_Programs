// Problem Description
// Given a sorted array A containing N integers both positive and negative.
// You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.
// Try to this in O(N) time.

// Problem Constraints
// 1 <= N <= 105.

// -103 <= A[i] <= 103


// Hint 1 
Try to separate the positive and negative numbers in two separated arrays.
And try to use the merge function used in merge sort to find a solution in linear time.


//Solution Approach
Simple solution is to first convert each array elements into its square and than apply any “O(nlogn)” sorting algorithm to sort the array elements.
Time complexity: O(NlogN)

Efficient solution is based on the fact that given array is already sorted. We do following two steps.
Divide the array into two part “Negative and positive “.
Use merge function to merge two sorted arrays into a single sorted array.
Time complexity: O(n)
Space complexity: O(n)



//First Method :-  //Wrong answer but method correct
vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>ans(n);
    int k=0;
    for(int k=0;k<n;k++){
        if(A[k]>=0) 
           break;
    }
    int i=k-1;
    int j=k;
    int index=0;
    while(i>=0 && j<n){
        if(A[i]*A[i] < A[j]*A[j]){
            //ans.push_back(A[i]*A[i]);
            ans[index]=A[i]*A[i];
            i--;
        }
        else{
            //ans.push_back(A[j]*A[j]);
            ans[index]=A[j]*A[j];
            j++;
        }
        index++;
    }

    while(i>=0){
        //ans.push_back(A[i]*A[i]);
        ans[index]=A[i]*A[i];
        i--;
        index++;
    }
    while(j<n){
        //ans.push_back(A[j]*A[j]);
        ans[index]=A[j]*A[j];
        j++;
        index++;
    }
    return ans;
}




//Second Method :-
vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    int i=0;
    int j=n-1;

    vector<int> v;  //creating a new vector

    while(i<=j){
        if(abs(A[i])>abs(A[j])){
            v.push_back(A[i]*A[i]);
            i++;
        }
        else{
            v.push_back(A[j]*A[j]);
            j--;
        }
    }

    reverse(v.begin(), v.end());
    return v;    
}



//Third Method :-
vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    vector <int>v;
    int i;
    for(i=0;i<n;i++)
    {
        A[i]=abs(A[i]);
    }
    sort(A.begin(),A.end());
    for(i=0;i<n;i++)
    {
        v.push_back(A[i]*A[i]);
    }
    return v;
}
