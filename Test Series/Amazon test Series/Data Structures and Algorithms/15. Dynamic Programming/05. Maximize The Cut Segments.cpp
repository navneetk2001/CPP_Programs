https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#



//Solution Approach :- Recursion
class Solution{
public:
    //Function to find the maximum number of cuts.
    int solve(int ind, int &x, int &y, int &z){
        if(ind < 0){   // if n<0 that means cut becomes greater then return INT_MIN
        	return INT_MIN;
        }
        if(ind == 0){
        	return 0;
        }
        
        int choice1 = 1 + solve(ind - x, x, y, z);
        int choice2 = 1 + solve(ind - y, x, y, z);
        int choice3 = 1 + solve(ind - z, x, y, z);
        
        int ans = max(choice1, max(choice2, choice3));
        return ans;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = solve(n, x, y, z);
        return (ans<0 ? 0 : ans);
    }

};



//Second Solution :- Memoization
class Solution{
public:
    //Function to find the maximum number of cuts.
    int solve(int ind, int &x, int &y, int &z, vector<int> &dp){
        if(ind < 0){   // if n<0 that means cut becomes greater then return INT_MIN
        	return INT_MIN;
        }
        if(ind == 0){
        	return 0;
        }
        if(dp[ind] != -1){
        	return dp[ind];
        }
        
        int choice1 = 1 + solve(ind - x, x, y, z, dp);
        int choice2 = 1 + solve(ind - y, x, y, z, dp);
        int choice3 = 1 + solve(ind - z, x, y, z, dp);
        
        dp[ind] = max(choice1, max(choice2, choice3));
        return dp[ind];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = solve(n,x,y,z,dp);
        return (ans<0 ? 0 : ans);
    }

};




//Third Solution :- Tabulation
int maximizeTheCuts(int n, int x, int y, int z){
    vector <int> dp(10001);
    dp[x] = 1;
    dp[y] = 1;
    dp[z] = 1;
    
    for(int i=1; i<=n; i++){
        if(i-x >= 0 && dp[i-x]){
            dp[i] = max(dp[i], 1+dp[i-x]);
        }
        if(i-y >= 0 && dp[i-y]){
            dp[i] = max(dp[i], 1+dp[i-y]);
        }
        if(i-z >= 0 && dp[i-z]){
            dp[i] = max(dp[i], 1+dp[i-z]);
        }
    }
    return dp[n];
}



//Fourth Solution :-
int solve(int n, int x, int y, int z)
{
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        if(i-x >=0){
        	dp[i]=max(dp[i],dp[i-x]+1);
        }
        if(i-y>=0){
        	dp[i]=max(dp[i],dp[i-y]+1);
        }
        if(i-z>=0){
        	dp[i]=max(dp[i],dp[i-z]+1);
        }
    }
    return dp[n] < 0 ? 0 : dp[n];
}

int maximizeTheCuts(int n, int x, int y, int z){
    return solve(n,x,y,z);
}

