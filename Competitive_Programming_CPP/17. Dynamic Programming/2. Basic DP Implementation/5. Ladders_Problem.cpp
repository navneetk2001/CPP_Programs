//we have to reach at N steps :-> Given max jump of k of each steps
//Output # ways to reach Nth step

//Approach :- f(n) = f(n-1) + f(n-2) + f(n-3) +.......+ f(n-k)

#include<iostream>
#include<climits>
using namespace std;

//Top-Down Dp Solution :-
int ladders_topdown(int n, int k, int dp[]){
	if(n==0){  //base case
		return 1;
	}

	if(dp[n]!=0){   //LookUp
		return dp[n];
	}

	//rec case
	int ways=0;
	for(int i=1;i<=k;i++){
		if(n-i >= 0){
			ways +=ladders_topdown(n-i, k, dp);
		}
	}
	return dp[n]=ways;
}

//bottom-up solution :-
int ladders_bottomup(int n, int k){
    int dp[100]={0};

	dp[0]=1; //base case
	for(int i=1;i<=n;i++){
		dp[i]=0;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				dp[i]+=dp[i-j];
			}
		}
	}
	return dp[n];
}

//DP - Ladders Optimized Approach :-
//It will be like a sliding window, we only need a window of k
// dp[n+1] = dp[n] - dp[n+1 - k-1]   =>  dp[n]- dp[n-k]
// dp[n] = 2*dp[n-1] - dp[n-k-1]

int ladders_optimised(int n, int k){
	int dp[100]={0};

	dp[0]=dp[1]=1; //base case
	for(int i=2;i<=k;i++){
		dp[i]=2*dp[i-1];
	}

	for(int i=k+1;i<=n;i++){
		dp[i]=2*dp[i-j] - dp[i-k-1];
	}
	return dp[n];
}


int main(){
    int n,k;
    cin>>n>>k;

    int dp[100]={0};
	cout<<ladders_topdown(n,k,dp)<<endl;

	return 0;
}

