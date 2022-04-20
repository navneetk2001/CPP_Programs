Given an array A of N length. We need to calculate the next smallest greater element for each element in a given array. If the next greater element is not available in a given array then we need to fill -10000000 at that index place.

Example 1:
Input : arr[] = {13, 6, 7, 12}
Output : _ 7 12 13 
Explanation: Here, at index 0, 13 is the greatest value in given array and no other array element 
is greater from 13. So at index 0 we fill '-10000000'.

Example 2:
Input : arr[] = {6, 3, 9, 8, 10, 2, 1, 15, 7} 
Output :  7 6 10 9 15 3 2 _ 8
Explanation: Here, at index 7, 15 is the greatest value in given array and no other array element is greater from 15. So at index 7 we fill '-10000000'.



//Solution Approach :-
int* greaterElement(int arr[], int n){
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}

	for(int i=0;i<n;i++){
	    auto indx=s.upper_bound(arr[i]);
	    if(indx!=s.end())
	   		arr[i]=*indx;
	    else
	   		arr[i]=-10000000;
	}
	return arr;
}



//Second Solution :-
int upperBound(int arr[], int start, int end, int val){
    int N = end;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(arr[mid] <= val){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    
    if(arr[start] <= val || start < 0 || start >= N){
        return -10000000;
    }
    
    return arr[start];
}

int* greaterElement(int arr[], int n){
    int temp[n];
    int* ans = new int[n];
    
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    
    sort(temp, temp + n);
    
    for(int i = 0; i < n; i++){
        ans[i] = upperBound(temp, 0, n, arr[i]);
    }
    
    return ans;
}