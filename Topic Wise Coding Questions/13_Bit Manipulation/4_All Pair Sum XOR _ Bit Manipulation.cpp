#include<bits/stdc++.h>
using namespace std;

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
			res=res^(2*ar[i]);
		}
		cout<<res<<endl;
	}
}