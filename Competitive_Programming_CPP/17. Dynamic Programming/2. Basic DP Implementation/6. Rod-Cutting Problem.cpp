Rod Cutting Problem :- 
---------------------
N = 8

Ex :- 1
length | 1 2 3  4  5   6   7   8
------------------------------------
price  | 1 5 8  9  10  17  17  20

MaxProfit = 24


//profit = price[i] + f(N-cutLength)

#include<iostream>
#include<climits>
using namespace std;

//Recursive case
int max_Profit(int prices[], int n){
	//base case
	if(n<=0){
		return 0;
	}

	//rec case
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		int cut=i+1;

		int current_ans = prices[i] + max_Profit(prices,n-cut);
		ans=max(ans,current_ans);
	}
	return ans;
} 

//bottom up dp solution :- 
int max_Profit_dp(int prices[], int n){
	int dp[n+1];
	dp[0]={0};

	for(int len=1;len<=n;len++){
		int ans=INT_MIN;
		for(int i=0;i<len;i++){
			int cut=i+1;
			int current_ans=prices[i]+dp[len-cut];
			ans=max(ans,current_ans);
		}
		//computed the ans for dp[len]
		dp[len]=ans;
	}
	return dp[n];
} 


int main(){
    int prices[] = {1,5,8,9,10,17,17,20};
    int n=sizeof(prices)/sizeof(int);

	cout<<max_Profit(prices,n)<<endl;

	cout<<max_Profit_dp(prices,n,dp)<<endl;

	return 0;
}
