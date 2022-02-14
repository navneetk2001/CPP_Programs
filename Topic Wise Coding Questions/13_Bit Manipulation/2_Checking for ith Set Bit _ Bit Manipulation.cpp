#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,i;
	cin>>t;

	while(t--){
		cin>>n>>i;

		int f=1;
		f=f<<i;
        
        int res=n&f;
        if(res==0) cout<<"false"<<endl;
        else cout<<"True"<<endl;
	}
}