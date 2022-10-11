int Solution::solve(vector<int> &arr, int B) {
    int n=arr.size();
    int hi=n-1;
    int lo=0;
    
    int mid=lo+(hi-lo)/2;
    while(hi>=lo)
    {
        mid=lo+(hi-lo)/2;
        if(!(mid+1<n and mid-1>=0))
            break;
        if(arr[mid-1]<arr[mid] and arr[mid]<arr[mid+1])
            lo=mid+1;
        else if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
            break;
        else
            hi=mid-1;
    }

    int peak=mid;


    hi=peak;
    lo=0;
    mid=lo+(hi-lo)/2;
    while(hi>=lo)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]==B)
            return mid;
        else if(arr[mid]>B)
            hi=mid-1;
        else
            lo=mid+1;
    }


    hi=n-1;
    lo=peak+1;
    mid=lo+(hi-lo)/2;
    while(hi>=lo)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]==B){
            return mid;
        }
        else if(arr[mid]<B){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;
}
