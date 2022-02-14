//you have to find maximum profit by selling all the bottles
//And its also given that in yth year, bottle price will be increased by y*price[i]
//And its also given you can only sell first or last bottle in a year

//We can first think of greedy approach but it will fail 

//In dp approach :- f(i,j,y) = max{p[i]*y + f(i+1,j,y+1), p[j]*y + f(i,j-1,y+1)}

#include<iostream>
#include<climits>
using namespace std;

//Recurrsive Solution :-
int profit(int wines[], int i, int j, int y){
	if(i>j){ //Bae case
		return 0;
	}
	//Rec case
	int op1=wines[i]*y + profit(wines,i+1,j,y+1);
	int op2=wines[j]*y + profit(wines,i,j-1,y+1);

	return max(op1,op2);
}

//Bottom-up Dp
int profit_dp(int wines[], int i, int j, int y, int dp[][100]){
	if(i>j){ //Bae case
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}

	int op1=wines[i]*y + profit_dp(wines,i+1,j,y+1,dp);
	int op2=wines[j]*y + profit_dp(wines,i,j-1,y+1,dp);

	return dp[i][j] = max(op1,op2);
}

int main(){
    int wines[] = {2,3,5,1,4};
    int n=sizeof(wines)/sizeof(int);

    int y=1;
	cout<<profit(wines,0,n-1,y)<<endl;

    int dp[100][100]={0};
	cout<<profit_dp(wines,0,n-1,y,dp)<<endl;

	return 0;
}

