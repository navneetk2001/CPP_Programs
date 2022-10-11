https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0


//First Solution :- Using Recursion
bool f(int ind, int target, vector<int> &arr){
	if(target==0) return true;    //base case
	if(ind==0) return (arr[0]==target);   //second base case;

	bool nontake=f(ind-1, target, arr);
	bool take = false;
	if(arr[ind]<=target){
		take=f(ind-1, target-arr[ind], arr);
	}

	return take | nontake;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
	return f(n-1,k,arr);
}


//Second Solution :- Memoization 
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target==0) return true;    //base case
    if(ind==0) return (arr[0]==target);   //second base case;
    
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }

    bool nontake=f(ind-1, target, arr, dp);
    bool take = false;
    if(arr[ind]<=target){
        take=f(ind-1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = take | nontake;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}


//Third Solution :- Tabulation 
bool subsetSumToK(int n, int k, vector<int> &arr){
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
    return dp[n-1][k];
}



//Fourth Solution :- Space Optimized Solution 
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k){
        prev[arr[0]] = true;
    }
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
            if(arr[ind]<=target){
                taken = prev[target-arr[ind]];
            }
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    return prev[k];
}