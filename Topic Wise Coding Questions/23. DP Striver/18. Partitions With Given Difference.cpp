https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


//First Solution :- Using Recursion
int f(int ind, int target, vector<int> &num){
    if(ind==0){    //base case
        if(target==0 && num[0]==0) return 2;
        if(target==0 || target == num[0]) return 1;
        return 0;
    }

    int nontake=f(ind-1, target, num);
    int take = 0;
    if(num[ind]<=target){
        take=f(ind-1, target-num[ind], num);
    }

    return (take + nontake)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it : arr){
        totSum += it;
    }
    
    if((totSum - d < 0) || (totSum-d)%2) return false;
    return f(n-1, (totSum-d)/2, arr);
}



//Second Solution :- Memoization 
const int mod =1e9+7;
int f(int ind, int target, vector<int> &num, vector<vector<int>> &dp){
    if(ind==0){    //base case
        if(target==0 && num[0]==0) return 2;
        if(target==0 || target == num[0]) return 1;
        return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];
    
    int nontake=f(ind-1, target, num, dp);
    int take = 0;
    if(num[ind]<=target){
        take=f(ind-1, target-num[ind], num, dp);
    }

    return dp[ind][target] = (take + nontake)%mod;
}

int findWays(vector<int> &num, int target){
    int n =num.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,num,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it : arr){
        totSum += it;
    }
    
    if((totSum - d < 0) || (totSum-d)%2) return false;
    return findWays(arr, (totSum-d)/2);
}



//Third Solution :- Tabulation 
const int mod =1e9+7;
int findWays(vector<int> &num, int k){
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    if(num[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
     
    if(num[0]!=0 && num[0]<=k){               //second base case
        dp[0][num[0]] = 1;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=k; target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
            if(num[ind]<=target){
                taken = dp[ind-1][target-num[ind]];
            }
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it : arr){
        totSum += it;
    }
    
    if((totSum - d < 0) || (totSum-d)%2) return false;
    return findWays(arr, (totSum-d)/2);
}


//Fourth Solution :- Space Optimized Solution 
const int mod =1e9+7;
int findWays(vector<int> &num, int k){
    int n=num.size();
    vector<int> prev(k+1,0);
    
    if(num[0]==0) prev[0]=2;
    else prev[0]=1;
     
    if(num[0]!=0 && num[0]<=k){               //second base case
        prev[num[0]] = 1;
    }
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0] = true;
        for(int target= 0; target<=k; target++){
            int notTaken = prev[target];
    
            int taken = 0;
            if(num[ind]<=target){
                taken = prev[target-num[ind]];
            }
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it : arr){
        totSum += it;
    }
    
    if((totSum - d < 0) || (totSum-d)%2) return false;
    return findWays(arr, (totSum-d)/2);
}