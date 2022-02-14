#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin>>t;

	while(t--){
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		
		int cnt;
		int res=0;
		for(int i=1;i<=n;i++){
			cnt = (i) * (n-i+1);  // no of subarrays in which element appears in 
			if(cnt%2) res^=arr[i];
		}
		cout<<res<<endl;
	}
}