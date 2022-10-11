// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =         {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
 
// Example 2:
// Input:
// N = 4
// mat[][] =         {{10, 20, 30, 40}
//                    {15, 25, 35, 45}
//                    {24, 29, 37, 48}
//                    {32, 33, 39, 50}}
// K = 7
// Output: 30
// Explanation: 30 is the 7th smallest element.




//Solution Approach :-
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
    for(int i=0;i<n;i++){
        pq.push({mat[i][0],{i,0}});
    }
    
    int ans=0;
    while(k--){
        auto x=pq.top(); pq.pop();
        ans = x.first;

        int r=x.second.first;
        int c=x.second.second;
        if(c+1 < n){
            pq.push({mat[r][c+1],{r,c+1}});
        }
    }
    return ans;
}



//Second Solution :-
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v.push_back(mat[i][j]);
        }
    }

    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(v[i]);
    }
    
    for(int i=k;i<v.size();i++){
        if(pq.top()>v[i]){
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}




//Third Solution :-
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0], high = mat[n-1][n-1], mid;

    while(low <= high){
        mid = low + (high - low)/2;
        int count = 0;
        for(int i=0; i<n; i++){
           count = count + upper_bound(mat[i], mat[i]+n, mid) - mat[i];
        }
        if(count < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}