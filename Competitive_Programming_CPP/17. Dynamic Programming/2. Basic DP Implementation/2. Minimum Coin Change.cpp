//Minimum No.of coins needed to make a target amount
//We have infinite number of coins of each denominations

//First you will think of greedy approach but it will not be correct
//f(n) = min[f(n - coins[i])] for all n-coins[i]>=0

#include<iostream>
#include<climits>
using namespace std;

//Top-Down Dp :-
int minCoins(int n, int coins[], int T, int dp[]){
	//Base case
	if(n==0){
		return 0;
	}
	if(dp[n]!=0){   //Lookup if n is already computed
		return dp[n];
	}
	int ans=INT_MAX;
	for(int i=0;i<T;i++){
		if(n-coins[i]>=0){
			int subProb = minCoins(n-coins[i],coins,T,dp);
			ans=min(ans,subProb+1);
		}
	}
	dp[n]=ans;
	return dp[n];
}

//Bottom-up Dp :-
int minCoins_BU(int n, int coins[], int T){
	int dp[100]={0};
	
	for(int i=1;i<=n;i++){
		dp[i]=INT_MAX;  //initialize current ans as infinity
		for(int j=0;j<T;j++){
			if(i-coins[j]>=0){
				int subProb=dp[i-coins[j]];
				dp[i]=min(dp[i],subProb+1);
			}
		}
	}
	return dp[n];
}


int main(){
	int N=15;
    int coins[] = {1,7,10};
    int T=sizeof(coins)/sizeof(int);

    int dp[100]={0};
	cout<<minCoins(N,coins,T,dp)<<endl;

	
	cout<<minCoins_BU(N,coins,T)<<endl;

	return 0;
}

