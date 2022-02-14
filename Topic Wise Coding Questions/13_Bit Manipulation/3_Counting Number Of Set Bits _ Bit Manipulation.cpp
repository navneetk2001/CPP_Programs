#include<bits/stdc++.h>
using namespace std;

//First Approach : Using right shift to find total set bits
int main(){
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;

		int cnt=0;
		while(n>0){
			if((n&1)>0)
				cnt++;
			n=n>>1;        //Right Shift
		}
		cout<<"No of set bits: "<<cnt<<endl;
	}
}


//Second Approach : Based on simple Observation
int main(){
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;

		int cnt=0;
		while(n>0){
			cnt++;
			n=n&(n-1);
		}
		cout<<"No of set bits: "<<cnt<<endl;
	}
}