#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,i;
	cin>>t;

	while(t--){
		cin>>n>>i;

		cout<<"Left Shift: "<<n<<" << "<<i<<" = "<<(n<<i)<<endl;  //Binary Left Shift : N = N*(2^i);

		cout<<"Right Shift: "<<n<<" >> "<<i<<" = "<<(n>>i)<<endl;  //Binary Right Shift : N = N/(2^i);
	}
}