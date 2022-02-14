// n----->1
// n----->n/3  if n%3==0
// n----->n/2  if n%2==0
// n----->n-1  

//f(n) = min{f(n/3), f(n/2), f(n-1)}+1

#include<iostream>
using namespace std;

//Top-Down Dp :-
int minSteps(int n, int dp[]){
	//Base case
	if(n==1){
		return 0;
	}
	if(dp[n]!=0){   //Lookup if n is already computed
		return dp[n];
	}
	//Rec case
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	//Compute if dp[n] is not known
	if(n%3==0){
		op1=minSteps(n/3,dp);
	}
	if(n%2==0){
		op2=minSteps(n/2,dp);
	}
	op3=minSteps(n-1,dp);

	int ans=min(min(op1,op2),op3)+1;
	return dp[n]=ans;
}

//Bottom-up Dp :-
int minSteps_BU(int n){
	int dp[100]={0};
	//Base case
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int op1,op2,op3;
		op1=op2=op3=INT_MAX;
		//Compute if dp[n] is not known
		if(n%3==0){
			op1=dp[i/3];
		}
		if(n%2==0){
			op2=dp[i/2];
		}
		op3=dp[i-1];

		dp[i]=min(min(op1,op2),op3)+1;
	}
	return dp[n];
}


int main(){
	int n;
	cin>>n;

    int dp[100]={0};
	cout<<minSteps(n)<<endl;

	
	cout<<minSteps_BU(n)<<endl;

	return 0;
}

