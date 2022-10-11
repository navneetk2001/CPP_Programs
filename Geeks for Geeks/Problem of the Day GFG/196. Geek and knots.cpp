// M hooks are present in a straight line on wall A and N hooks are present in a straight line on wall B. Each hook on wall A is connected to each hooks on wall B by ropes. K ropes must be used to make the desired giant knot. How many such knots can Geek make ?
// Note: 2 knots are considered to be the same if they involve the same hooks. 

// Example 1:
// Input:
// M = 3, N = 2, K = 2
// Output: 3
// Explaination:  hooks on Wall A are A1 A2 A3.
//                hooks on wall B are B1 B2. 
// Joining                            is same as joining 
//  A1  A2  A3                           A1  A2  A3
//  |       |                            |       |
//  B1      B2                           B2      B1 
// because the two groups involve the same hooks. But the groups (A1-B1, A3-B2), (A1-B1, A2-B2), (A2-B1, A3-B2) are all different.  

// Example 2:
// Input:
// M = 2, N = 2, K = 2
// Output: 1
// Explaination: Any one of (A1-B1, A2-B2) and (A1-B2, A2-B1) can be used.




//Solution Approach :-
class Solution {
public:
    const int mod = 1e9 + 7;
    long long int dp[1001][1001];

    long long comb(int n, int k) {
        if(k > n){
            return 0;
        }

        if(k == 0 or k == n){
            return 1;
        }

        if(dp[n][k]!=0){
            return dp[n][k];
        }

        return dp[n][k] = (comb(n-1,k) % mod + comb(n-1,k-1) % mod) % mod;
    }

    int knots(int M, int N, int k) {
        memset( dp, 0, sizeof dp );

        long long int a = comb(M, k);
        long long int b = comb(N, k);

        return (a % mod * b % mod) % mod;
    }
};




//Second Solution :-
long dp[1001][1001];
int mod=1000000007;
long long solve(int n,int k){
    if(n<k){
       return 0;
    }
    if(n==k || k==0){
       return 1;
    }
   
    for(int  i=0;i<=n;i++){
        dp[i][0]=1;
        dp[i][i]=1;
        for(int j=1;j<i;j++){
           dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
        }
    }
    return dp[n][k]%mod;
}

int knots(int M, int N, int K){
    memset(dp,0,sizeof(dp));
    long long x=solve(N,K);
    long long y=solve(M,K);
    
    return (x%mod * y%mod)%mod;
}




//Third Solution :- 
int mod=1000000007;
long long getNcR(int n, int r) {
    if (r > n-r) {
        r = n-r;
    }
    vector<int> pascalTriangleRow(r+1, 0);
    pascalTriangleRow[0] = 1; 

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--){
            pascalTriangleRow[j] = (pascalTriangleRow[j] + pascalTriangleRow[j - 1]) % mod;
        }
    }
    return pascalTriangleRow[r];
}

int knots(int M, int N, int K){
    long long x = getNcR(N,K);
    long long y = getNcR(M,K);

    return (x % mod * y % mod) % mod;
}
