// Given an array arr[] of n integers. Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.

// Example 1:
// Input: N=5
// arr[] = {2, 1, 3, 2, 3} 
// Output: 5
// Explanation: Total distinct elements in array is 3
// Total sub-arrays that satisfy the condition are:
// Subarray from index 0 to 2
// Subarray from index 0 to 3
// Subarray from index 0 to 4
// Subarray from index 1 to 3
// Subarray from index 1 to 4

// Example 2:
// Input: N=5
// arr[] = {2, 4, 4, 2, 4} 
// Output: 9




//Solution Approach :-
//Count of subarray with K distinct element = Count of subarray with atmost K distint element - Count of subarray with atmost (K-1) distinct element
int solve(int arr[],int n,int k){
    if(k==0){
    	return 0;
    }

    int i=0,j=0,cnt=0;
    unordered_map<int,int> mp;
    while(j<n){
        mp[arr[j]]++;
        while(mp.size()>k){
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
            	mp.erase(arr[i]);
            }
        	i++;
        }
        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}

int countDistinctSubarray(int arr[], int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    int k=s.size();
    return solve(arr,n,k)-solve(arr,n,k-1);
}




//Second Solution :-
int countDistinctSubarray(int arr[], int n){
    int i=0,j=0;
    int ans=0;
    unordered_map<int,int>um;
    unordered_set<int>us;

    for(int i=0;i<n;i++){
        us.insert(arr[i]);
    }
    int k=us.size();   //no of distinct element 
    
    for(int i=0;i<n;i++){
        um[arr[i]]++;
        while(um.size()>=k && j<=i){
            ans+=(n-i);
            um[arr[j]]--;

            if(um[arr[j]]==0){
            	um.erase(arr[j]);
            }
            j++;
        }
    }
    return ans;
}



//Third Solution :- Two Approaches: ( 0.14s) both O(N) Space and Time.
// The code is common till counting total distincts. Then SLIDING WINDOW is used , in both approaches.
// In first code, I have counted number of subarrays NOT containing distinct elements. Then returned Total Number of subArrays - Answer.
// In second code, I have counted number of subArrays containing distinct elements.

int countDistinctSubarray(int arr[], int n){
    unordered_map<int,int> m ;
    int s=0 ,needed , ans = 0 ;
    
    for(int i=0; i<n; i++){
        m[arr[i]]++ ;
    }
        
    needed = m.size() ;
    m.clear() ;
    
//--- Counting subarrays NOT containing all distincts---    
    
    for(int e=0; e<n ; e++){
        m[arr[e]]++ ;
        while(m.size() == needed){
            if(--m[arr[s]] == 0)
                m.erase(arr[s]) ;
            s++ ;
        }
        ans += (e-s+1);
    }
    
    return n*(n+1)/2 - ans ;
    
//----Counting subarrays containing all distincts----
    
    for(int e=0 ; e<n ; e++){
        m[arr[e]]++ ;
        while(m[arr[s]] != 1){
            m[arr[s]]-- ;
            s++ ;
        }
        if(m.size() == needed)
            ans += s+1 ;
    }
    return ans ;
}