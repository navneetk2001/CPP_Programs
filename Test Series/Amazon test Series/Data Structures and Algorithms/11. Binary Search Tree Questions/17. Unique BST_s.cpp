https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1/?category[]=Dynamic%20Programming&page=1&query=category[]Dynamic%20Programmingpage1



//Solution Approach :-
int numTrees(int n) {
	long mod = 1000000007;
	vector<long> dp(n+1);
	dp[0] = dp[1] = 1;
   	for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] = (dp[i] + dp[j] * dp[i-j-1]) % mod;
        }
   	}
   	return dp[n];
}



//Second Solution :-
int fun(vector<int>&v, int n, int m){
	if(v[n]!=0){
		return v[n];
	}
	
	for(int i=0;i<n;i++){
       	long long x = fun(v, i, m) % m;
       	int y = fun(v, n-1-i, m) % m;
       	v[n] = (v[n] + (x * y) % m) % m;
   	}
   	return v[n];
}

int numTrees(int n) {
   vector<int> v(n+1,0);
   v[0]=v[1]=1;
   return fun(v,n,1e9+7);
}



//Third Solution :-
int numTrees(int N){
    long int dp[N+1];
    int mod = 1000000007;
    dp[0] = 1;
    
    for(int i = 1; i < N+1; ++i) {
        long bsts = 0;
        for(int low = 0, high = i-1; low < i; ++low, --high) {
            bsts += (dp[low] % mod * dp[high] % mod) % mod;
        }
        dp[i] = bsts % mod;
    }
    
    return (int)dp[N];
}



//Fourth Solution :-
class Solution {
    int catalan_Number(int n){
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            catalan[i] = 0;
            for(int j=0;j<i;++j){
                catalan[i] += catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_Number(n);
    }
};