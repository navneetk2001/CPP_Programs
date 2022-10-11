https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//First Solution :- Using Recursion
int f(int ind, int target, vector<int> &num){
    if(target==0) return 1;    //base case
    if(ind==0) return (num[0]==target);   //second base case;

    int nontake=f(ind-1, target, num);
    int take = 0;
    if(num[ind]<=target){
        take=f(ind-1, target-num[ind], num);
    }

    return take + nontake;
}

int findWays(vector<int> &num, int target){
    int n =num.size();
    return f(n-1,target,num);
}



//Second Solution :- Memoization 
int f(int ind, int target, vector<int> &num, vector<vector<int>> &dp){
    if(target==0) return 1;    //base case
    if(ind==0) return (num[0]==target);   //second base case;
    if(dp[ind][target]!=-1) return dp[ind][target];
    
    int nontake=f(ind-1, target, num, dp);
    int take = 0;
    if(num[ind]<=target){
        take=f(ind-1, target-num[ind], num, dp);
    }

    return dp[ind][target] =take + nontake;
}

int findWays(vector<int> &num, int target){
    int n =num.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,num,dp);
}


//Third Solution :- Tabulation 
int findWays(vector<int> &num, int k){
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0; i<n; i++){   //base case
        dp[i][0] = 1;
    }
     
    if(num[0]<=k){               //second base case
        dp[0][num[0]] = 1;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
            if(num[ind]<=target){
                taken = dp[ind-1][target-num[ind]];
            }
        
            dp[ind][target]= notTaken + taken;
        }
    }
    return dp[n-1][k];
}


//Fourth Solution :- Space Optimized Solution 
int findWays(vector<int> &num, int k){
    int n=num.size();
    vector<int> prev(k+1,0);
    
    prev[0] = 1;
    
    if(num[0]<=k){
        prev[num[0]] = 1;
    }
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            int notTaken = prev[target];
    
            int taken = 0;
            if(num[ind]<=target){
                taken = prev[target-num[ind]];
            }
        
            cur[target]= notTaken + taken;
        }
        prev = cur;
    }
    return prev[k];
}
