https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1





//Solution Approach :- Naive Solution
//We will keep two pointers, say p1 and p2, each in two arrays. A counter to keep track of whether we have reached the kth position. Start iterating through both arrays. If array1[p1] < array2[p2], move p1 pointer ahead and increase counter value. If array2[p2] <array1[p1], move p2 pointer ahead and increase counter. When the count is equal to k, return the element in which condition makes the counter value equal to k.

int kthElement(int arr1[], int arr2[], int n, int m, int k){
    int ans = 0;
    int i = 0, j = 0;
    
    while((i < n or j < m) and i + j < k){
        if(i < n and j < m){
            if(arr1[i] < arr2[j])
                ans = arr1[i++];
            else
                ans = arr2[j++];
        }
        else if(i < n){
            ans = arr1[i++];
        }
        else if (j < m){
            ans = arr2[j++];
        }
    }
    return ans;
}




//Solution :- 
int kthElement(int arr1[], int arr2[], int n, int m, int k){
    int i = 0, j = 0;
    int cnt = 0, ans = 0;
    
    while(i < n and j < m){
        if(cnt == k){
            break;
        }

        if(arr1[i] < arr2[j]){
            cnt++;
            ans = arr1[i];
            i++;
        }
        else{
            cnt++;
            ans = arr2[j];
            j++;
        }
    }

    if(cnt < k){
        while(i < n){
            if(cnt == k){
                break;
            }
            ans = arr1[i++];
            cnt++;
        }
    }

    if(cnt < k){
        while(j < m){
            if(cnt == k){
                break;
            }
            ans = arr2[j++];
            cnt++;
        }
    }
    return ans;
}






//Second SOlution  :-
int kthElement(int arr1[], int arr2[], int n, int m, int k){
    int low = min(arr1[0], arr2[0]);
    int high = max(arr1[n-1], arr2[m-1]);
    
    while(low <= high){
        int mid = (low + high)/2;
        
        int pos = upper_bound(arr1,arr1+n,mid)-arr1;
        pos = pos + upper_bound(arr2,arr2+m,mid)-arr2;
        
        if(pos < k){
        	low=mid+1;
        }
        else{
        	high = mid - 1;
        }
        
    }
    return low;
}



//Third Solution :-
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}




