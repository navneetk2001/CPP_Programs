// Given an array of size N containing positive integers n and a number k,The absolute difference between values at indices i and j is |a[i] – a[j]|. There are n*(n-1)/2 such pairs and you have to print the kth smallest absolute difference among all these pairs.
 
// Example 1:
// Input : 
// N = 4
// A[] = {1, 2, 3, 4}
// k = 3
// Output : 
// 1 
// Explanation :
// The possible absolute differences are :
// {1, 2, 3, 1, 2, 1}.
// The 3rd smallest value among these is 1.
 
// Example 2:
// Input : 
// N = 2
// A[] = {10, 10}
// k = 1
// Output :
// 0



//Solution Approach :- 
int count(int a[], int n, int mid)
{
   int number=0;
   for(int i=0;i<n;i++){
       number+=upper_bound(a+i,a+n,a[i]+mid)-(a+i+1);
   }
   return number;
}
int kthDiff(int a[], int n, int k)
{
   sort(a,a+n);
   int low=a[1]-a[0];
   for(int i=0;i<n-1;i++){
       low=min(low,a[i+1]-a[i]);
   }
   int high=a[n-1]-a[0];
   while(low<high){
       int mid=(low+high)/2;
       if(count(a,n,mid)<k){
           low=mid+1;
       }else{
           high=mid;
       }
   }
   return low;
}


//Second Approach :- 
int kthDiff(int a[], int n, int k)
{
    sort(a, a+n);
    int high = a[n-1] - a[0];
    int low = a[1] - a[0];
    for(int i = 2; i < n; i++) {
        low = min(low, a[i] - a[i-1]);
    }
    
    auto count = [&] (int K) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += upper_bound(a+i, a+n, a[i]+K) - (a+i+1);
        }
        return cnt;
    };
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        int cnt = count(mid);
        if(cnt < k) low = mid + 1;
        else high = mid;
    }
    return low;
}


//Third Solution :-
int kthDiff(int a[], int n, int k)
{
    function<bool(int)> valid = [&](int mid) {
        int cnt=0;
        for(int i=0,j=0;i<n;i++) {
            int bound = a[i]+mid+1;
            while(j<n && a[j]<bound) {
                j++;
            }
            cnt += max<int>(0, j-i-1);
            if(cnt >= k) {
                return true;
            }
        }
        return false;
    };
    sort(a, a+n);
    int low=0, high = a[n-1]-a[0];
    while(low < high) {
        int mid=(low+high)>>1;
        bool flg = valid(mid);
        if(flg) {
            high=mid;
        }
        else {
            low=mid+1;
        }
    }
    return low;
}


//BruteForce Approach :-
int kthDiff(int a[], int n, int k)
{
   vector<int> ans;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           ans.push_back(abs(a[j]-a[i]));
       }
   }
   sort(ans.begin(),ans.end());
   return ans[k-1];
}