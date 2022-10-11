https://atcoder.jp/contests/dp/tasks/dp_m



//Solution Approach :-
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define mem(a,b) memset(a, b, sizeof a)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<;
#define fast_in_out ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mod = 1e9 + 7;

/*********************************************************************************************************************************************/

ll arr[100005];
ll dp[105][100005];

ll solve(int i,int n,int k){
    if(k==0){
     	return 1;
    }
    
    if(i>=n || k<0){
        return 0;
    }
    
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    
    ll ans = 0;
    for(int j=0;j<=arr[i];j++){
        // if(k>=j){
        ans = (ans%mod +  solve(i+1,n,k-j)%mod)%mod;
        // }
        // else{
        //   break;
        // }
    }

    return dp[i][k] = ans%mod;
}


ll solve_BottomUp(int n,int k){
    ll dp[n+1][k+1];
   
    // for(int i=0;i<=n;i++){
    //     dp[i][0] = 1;
        
    // }
   	for(int i=0;i<=k;i++){
        // dp[0][i] = 0;
        dp[1][i] = i>arr[0] ? 0 : 1;
    }


   	for(int i=2;i<=n;i++){
    	// ll ans = 0;
    	for(int j=0;j<=k;j++){
        	if(j==0){
            	dp[i][j] = dp[i-1][j];
        	}else{
            	dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - ((j-1-arr[i-1]>=0)?dp[i-1][j-1-arr[i-1]] : 0 ))%mod;
        	}
    	}
   	}
   	return dp[n][k];
}




int main()
{
	fast_in_out;
	#ifndef ONLINE_JUDGE
		freopen("../../C-Plus-Plus/input.txt","r", stdin);
		freopen("../../C-Plus-Plus/output.txt","w", stdout);
	#endif
	int t=1;
	// cin>>t;
	while(t--)
	{

	    int n,k;
	    cin>>n>>k;
	    // memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }

	    // cout<<solve(0,n,k);
	    cout<<solve_BottomUp(n,k);

	}
	return 0;
}