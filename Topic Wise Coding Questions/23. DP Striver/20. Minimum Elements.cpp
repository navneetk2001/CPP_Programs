https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0


//First Solution :- Using Recursion
int f(int ind, int T, vector<int> &nums){
    if(ind==0){    //base case
        if(T % nums[0] == 0) return T/nums[0];
        else return 1e9;
    }

    int nontake = 0 + f(ind-1, T, nums);
    int take = INT_MAX;
    if(nums[ind]<=T){
        take = 1 + f(ind,  T-nums[ind], nums);
    }

    return min(take,nontake);
}

int minimumElements(vector<int> &num, int T)
{
    int n=num.size();
    int ans = f(n-1,T,num);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

//Second Solution :- Memoization 
int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp){
    if(ind==0){    //base case
        if(T % nums[0] == 0) return T/nums[0];
        else return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];

    int nontake = 0 + f(ind-1, T, nums, dp);
    int take = INT_MAX;
    if(nums[ind]<=T){
        take = 1 + f(ind,  T-nums[ind], nums, dp);
    }

    return dp[ind][T] = min(take,nontake);
}

int minimumElements(vector<int> &num, int T)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(T+1,-1));

    int ans = f(n-1,T,num,dp);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}




//Third Solution :- Tabulation 
int minimumElements(vector<int> &num, int target)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int T=0; T<=target; T++){
        if(T%num[0] == 0){
            dp[0][T] = T / num[0];
        }
        else{
            dp[0][T] = 1e9;
        }
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int nontake = 0 + dp[ind-1][T];
            int take = INT_MAX;
            if(num[ind]<=T){
                take = 1 + dp[ind][T-num[ind]];
            }
            dp[ind][T] = min(take,nontake);
        }
    }

    int ans = dp[n-1][target];
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}



//Fourth Solution :- Space Optimized Solution 
int minimumElements(vector<int> &num, int target)
{
    int n=num.size();
    vector<int> prev(target+1,0), cur(target+1,0);
    for(int T=0; T<=target; T++){
        if(T%num[0] == 0){
            prev[T] = T / num[0];
        }
        else{
            prev[T] = 1e9;
        }
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int nontake = 0 + prev[T];
            int take = INT_MAX;
            if(num[ind]<=T){
                take = 1 + cur[T-num[ind]];
            }
            cur[T] = min(take,nontake);
        }
        prev = cur;
    }

    int ans = prev[target];
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

