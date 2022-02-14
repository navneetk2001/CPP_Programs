//Approach :-
//For no of balanced Binary Tree for height H , there can be 3 situations 
//1.    h         2.  h      3.   h
//     / \           / \         / \
//    h-1 h-1      h-1  h-2     h-2 h-1

// For a height h , No of binary tree possible , h -> (x^x)*x + 2*(x^x)*y

#include<bits/stdc++.h>
using namespace std;

int balancedBT(int h){
	if(h==0 || h==1){
		return 1;
	}
    
    int m = pow(10,9)+7;
	int x = balancedBT(h-1);
	int y = balancedBT(h-2);

	long res1=(long)x*x;
	long res2=(long)x*y*2;

	int ans1=(int)(res1%m);
	int ans2=(int)(res2%m);

	int ans = (ans1 + ans2)%m;

	return ans;
}

int main(){
	int h;
	cin>>h;

	int ans=balancedBT(h);
	cout<<"No. of Balanced Binary Tree in a height"<< h <<" will be : "ans<<endl;
}