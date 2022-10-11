https://atcoder.jp/contests/dp/tasks/dp_n



//Solution Approach :-
#include <bits/stdc++.h>
using namespace std;
  
long long int dp[405][405];
 
long long recur(int i, int j, vector<long long int> &vc,vector<long long> &sum){
	if(i==j){
		return 0;
	}
	if(i>j){
		return 0;
	}
 
	if(dp[i][j]!=-1){
		return dp[i][j]; 
	}
	
	long long minm=LLONG_MAX;
	for(int k=i;k<j;k++){
		long long temp = recur(i,k,vc,sum) + recur(k+1,j,vc,sum) + sum[j];
		if(i>0){
			temp-=sum[i-1];
		}
		minm=min(minm,temp);
	}
	return dp[i][j] = minm;
}
  
int main(){
	int n;
	cin>>n;
	vector<long long> vc(n,0);
	for(int i=0;i<n;i++){
		cin>>vc[i];
	}
	memset(dp,-1,sizeof(dp));
	
    vector<long long> sum(n,0);
    sum[0]=vc[0];
    for(int i=1;i<n;i++){
		sum[i]=vc[i]+sum[i-1];
	}
 
	long long int ans = recur(0,n-1,vc,sum);
	cout<<ans<<endl;
	return 0;
}