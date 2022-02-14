#include<bits/stdc++.h>
using namespace std;

//Brute-Force Approach :- O(n^2)
int main(){
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
        int ar[n+1];

		for(int i=1;i<=n;i++){
			cin>>ar[n];
		}

		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res+=ar[i]^ar[j];
			}
		}
		cout<<res<<endl;
	}
}


//Bit-Manipulation Approach :- O(nlogn)
int main(){
	int t,n;
	cin>>t;

	while(t--){
        int ar[1001];

		cin>>n,res=0;
		for(int i=1;i<=n;i++){
			cin>>ar[n];
		}

		for(int i=0;i<31;i++){
			int cnt_zero=0, cnt_one=0;
			for(int j=1;j<=n;j++){
				if(ar[i]&(1<<i)){
					cnt_one++;
				}
				else{
					cnt_zero++;
				}
			}
			int p=cnt_zero*cnt_one;
			res+=(1<<i)*p;
		}
		cout<<res<<endl;
	}
}