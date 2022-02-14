#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin>>t;

	while(t--){
		cin>>a>>b;

		int diff=b-a;

		int res=0;
		int f=1;
		
		for(int i=0;i<32;i++){
			if(diff>(f<<i)) continue;    // (f<<i) => 2^i
			else{
				if((a&(f<<i)) && (b&(f<<i)))  // if ith bit of both a and b are set
					res+=f<<i;  // res+=2^i
			}
		}
		cout<<res<<endl;
	}
}