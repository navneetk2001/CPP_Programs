// Given a matrix of integers A of size N x M in which each row is sorted.
// Find an return the overall median of the matrix A.
// Note: No extra memory is allowed.
// Note: Rows are numbered from top to bottom and columns are numbered from left to right.
// Input 1:
//     A = [   [1, 3, 5],
//             [2, 6, 9],
//             [3, 6, 9]   ]
// Output 1:
//     5

//Hint 1
// We cannot use extra memory, so we can’t actually store all elements in an array and sort the array.
// But since, rows are sorted it must be of some use, right?
// Note that in a row you can binary search to find how many elements are smaller than a value X in O(log M).

//Solution Approach
// Say k = N*M/2. We need to find (k + 1)^th smallest element.
// We can use binary search on answer. In O(N log M), we can count how many elements are smaller than X in the matrix.
// So, we use binary search on interval [1, INT_MAX]. So, total complexity is O(30 * N log M).

// Note: This problem can be solve by using min-heap, but extra memory is not allowed.


// First Method :-
int Solution::findMedian(vector<vector<int> > &A) {
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int> > minpq;

    bool flag = true;
    int r = A.size();
    int c = A[0].size();

    for(int i=0;i<r;i++){
        for(int j =0;j<c;j++){   
            int ele = A[i][j];
            if(flag){
                minpq.push(ele);
                maxpq.push(minpq.top());
                minpq.pop();
                flag = false;
            }
            else{
                maxpq.push(ele);
                minpq.push(maxpq.top());
                maxpq.pop();
                flag = true;
            }
        }
    }

    if(flag){
        int ans = (minpq.top() + maxpq.top())/2;
        return ans;
    }
    else{
        return maxpq.top();
    }
}


//Second Method :-
int Solution::findMedian(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int mi=INT_MAX,ma=INT_MIN;
    
    for(int i=0;i<n;i++){
        mi=min(mi,a[i][0]);
    }
    
    for(int i=0;i<n;i++){
        ma=max(ma,a[i][m-1]);
    }

    int ind=((n*m)+1)/2;
    while(mi<ma)
    {
        int mid=mi+(ma-mi)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count=count+upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        }
        if(count<ind){
            mi=mid+1;
        }
        else{
            ma=mid;
        }
    }
    return mi;
}


//Third Method :-
int func(vector<int>& arr, int val){
    int len=0;
    int lo=0, hi=arr.size()-1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]<val){
            len=mid+1;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return len;
}

int Solution::findMedian(vector<vector<int>> &arr) {
    int n=arr.size(), m=arr[0].size();
    int lo=0, hi=INT_MAX;

    int ans=0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int count = 0;
        
        for(int i=0;i<n;i++){
            count+=func(arr[i],mid);
        }

        if(count<=(n*m)/2){
            lo=mid+1;
            ans=mid;
        }
        else hi=mid-1;
    }
    return ans;
}
