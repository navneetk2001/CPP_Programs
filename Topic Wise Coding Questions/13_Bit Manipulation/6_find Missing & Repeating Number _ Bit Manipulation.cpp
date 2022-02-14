#include<bits/stdc++.h>
using namespace std;

//Bit-Manipulation Approach
int main(){
	int t,n;
	cin>>t;

	while(t--){
        int ar[1001];

		cin>>n,res=0;
		for(int i=1;i<=n;i++){
			cin>>ar[n];
		}

		for(int i=1;i<=n;i++){
			res=res^ar[i]^i;
		}

		int setBit=res & ~(res-1);  //Give LSB
		int L=0, R=0;

		for(int i=1;i<=n;i++){
			if(ar[i]&setBit){
				L=L^ar[i];
			}
			else{
				R=R^ar[i];
			}
		}

		for(int i=1;i<=n;i++){
			if(i&setBit){
				L=L^i;
			}
			else{
				R=R^i;
			}
		}

		bool isL_Missing=true;
		for(int i=1;i<=n;i++){
			if(ar[i]==L){
				isL_Missing=false;
				break;
			}
		}
		if(isL_Missing==true){
			cout<<"Missing Number = "<<L<<" Repeating Number = "<<R<<endl;
		}
		else{
			cout<<"Missing Number = "<<R<<" Repeating Number = "<<L<<endl;
		}
	}
}
