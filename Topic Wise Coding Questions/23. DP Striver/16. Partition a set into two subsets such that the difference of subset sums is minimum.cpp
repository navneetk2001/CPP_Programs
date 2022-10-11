https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :-  Tabulation 
int minSubsetSumDifference(vector<int>& arr, int n){
    int totSum=0;
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    int k=totSum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){   //base case
        dp[i][0] = true;
    }
     
    if(arr[0]<=k){               //second base case
        dp[0][arr[0]] = true;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
            if(arr[ind]<=target){
                taken = dp[ind-1][target-arr[ind]];
            }
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    int mini =1e8;
    for(int s1=0;s1<=totSum;s1++){
        if(dp[n-1][s1] == true){
            int s2= totSum-s1;
            mini = min(mini, abs(s2-s1));
        }
    }
    return mini;
} 



//Second Solution :- Space Optimized Solution 
int minSubsetSumDifference(vector<int>& arr, int n){
    int totSum=0;
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    int k=totSum;
    vector<bool> prev(k+1,0);
    
    prev[0] = true;
    
    if(arr[0]<=k){
        prev[arr[0]] = true;
    }
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,0);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
            if(arr[ind]<=target){
                taken = prev[target-arr[ind]];
            }
        
            cur[target]= notTaken | taken;
        }
        prev = cur;
    }
    
    int mini =1e8;
    for(int s1=0;s1<=totSum;s1++){
        if(prev[s1] == true){
            int s2= totSum-s1;
            mini = min(mini, abs(s2-s1));
        }
    }
    return mini;
}

