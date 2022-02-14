#include<bits/stdc++.h>
using namespace std;

//we will built this linear search uing recursion
//we will break our subarray in 2 parts :-one of one element and other of n-1 elements
int lastOcc(int*a, int n, int key){
	if(n==0)
		return -1;

	//rec case
	int i = lastOcc(a+1,n-1,key);
	if(i==-1){
		if(a[0]==key){
			return 0;
		}
		else{
			return -1;
		}
	}
	//otherwise
	return i+1;
}



int main(){
	int a[]={1,2,3,7,4,5,6,7,10};
	int key=7;
	int n=sizeof(a)/sizeof(int);

	int ans=firstOcc(a,n,key);
	cout<<ans<<endl;
}