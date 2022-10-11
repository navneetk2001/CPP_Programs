// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
// Example 1:
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Example 2:
// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Example 3:
// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.




//Solution Approach :-
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long int &count, long long int start, long long int mid, long long int end){
        long long temp[end-start+1];
        long long int i=start;
        long long int j=mid+1;
        long long int k=0;
        while(i<=mid && j<=end){
            if(arr[i]>arr[j]){
                temp[k++]=arr[j++];
                count+= mid-i+1;
            }
            else{
                temp[k++]=arr[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        
        for(long long int i=start; i<=end; i++){
            arr[i]=temp[i-start];
        }
    }
    void mergeSort(long long arr[], long long int &count, long long int start, long long int end){
        if(start<end){
            long long int mid=(start+end)/2;
            mergeSort(arr,count,start,mid);
            mergeSort(arr,count,mid+1,end);
            
            merge(arr,count,start,mid,end);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = 0;
        mergeSort(arr,count,0,N-1);
        return count;
    }

};



//Second Solution :-
class Solution{
 public:
   // arr[]: Input Array
   // N : Size of the Array arr[]
   // Function to count inversions in the array.
   
   long long int inversionCount(long long arr[], long long N)
   {
       /*
       * Bruteforce solution : O(N^2)->Time ,O(1)->space
       long long int inv_count = 0;
       for (int i = 0; i < N - 1; i++)
           for (int j = i + 1; j < N; j++)
               if (arr[i] > arr[j]){
                   inv_count++;
               }
 
       return inv_count; */
       
       //Optimal solution : O(NlogN)
       long long int temp[N];
       return _mergeSort(arr, temp, 0,N-1);
   }
   long long int _mergeSort(long long int arr[], long long int temp[], long long int left, long int right)
   {
       long long int mid, inv_count = 0;
       if (right > left) {
           mid = (right + left) / 2;
           inv_count += _mergeSort(arr, temp, left, mid);
           inv_count += _mergeSort(arr, temp, mid + 1, right);
           inv_count += merge(arr, temp, left, mid + 1, right);
       }
       return inv_count;
   }
   long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid,long long int right){
       long long int i, j, k;
       long long int inv_count = 0;
     
       i = left; /* i is index for left subarray*/
       j = mid; /* j is index for right subarray*/
       k = left; /* k is index for resultant merged subarray*/
       while ((i <= mid - 1) && (j <= right)) {
           if (arr[i] <= arr[j]) {
               temp[k++] = arr[i++];
           }
           else {
               temp[k++] = arr[j++];
               inv_count = inv_count + (mid - i);
           }
       }
       while (i <= mid - 1)
           temp[k++] = arr[i++];
   
       while (j <= right)
           temp[k++] = arr[j++];
    
       for (i = left; i <= right; i++)
           arr[i] = temp[i];
     
       return inv_count;
   }
   
};




//Third Solution :- Using Fenwick tree
vector<ll> bit;
    void update(ll i){
        for(;i<=500000;i+=i&-i)
            bit[i]++;
    }
    ll sum(ll i){
        ll ans=0;
        for(;i>0;i-=i&-i)
            ans+=bit[i];
        return ans;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        bit.resize(500001);
        vector<ll> v(arr,arr+n);
        sort(v.begin(),v.end());
        map<ll,ll> mp;
        ll x=1,zero=0,ans=0;
        for(ll i:v){
           if(!mp.count(i))
                mp[i]=x++;
        }
        for(ll i=0;i<n;i++)
           arr[i]=mp[arr[i]];
        for(ll i=n-1;i>=0;i--){
            if(arr[i]==0)
                zero++;
            else{
                ans+=zero+sum(arr[i]-1);
                update(arr[i]);
            }
        }
        return ans;
    }