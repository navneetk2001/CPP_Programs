// Given an integer array A of size N.
// You can pick B elements from either left or right end of the array A to get maximum sum.
// Find and return this maximum possible sum.


//First Approach :- 
int Solution::solve(vector<int> &A, int b) {
    int n=A.size();
    int currSum=0;
    for(int i=0;i<b;i++){
        currSum+=A[i];
    }
    int maxSum=currSum;
    int i=n-1, j=b-1;
    while(i>=0 && j>=0){
        currSum+=A[i--];
        currSum-=A[j--];
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}



//Second Approach :- 
int Solution::solve(vector<int> &A, int B) {
    if(B > A.size())
        return -1;
    
    int max_val = 0;
    for(int i=0;i<B;i++){
        max_val += A[i];
    }
    
    int j = B-1;
    int ans = max_val;
    for(int i=A.size()-1;i>A.size()-B-1;i--){
        ans = max(ans, max_val - A[j] + A[i]);
        max_val = max_val - A[j] + A[i];
        j--;
    }
    return ans;

}



//Third Method :- 
int Solution::solve(vector<int> &A, int B) {
    int ans = 0, n = A.size();
    
    for(int i = 0; i < B; i++) {
        ans += A[i];
    }
    
    int left = ans, right = 0, l_idx = B-1, r_idx = n-1;
    
    while(l_idx >= 0) {
        right += A[r_idx];
        left -= A[l_idx];
        ans = max(ans, left + right);
        l_idx--;
        r_idx--;
    }
    
    return ans;
}