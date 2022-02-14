#include<iostream>
using namespace std;

int main(){
	long long N;
	cin>>N;
		
	cout<<N<<" ";
	while(N>1){
		if(N%2==0){
			N/=2;
		}
		else{
			N=N*3+1;
		}
		cout<<N<<" ";
	}
	return 0;
}