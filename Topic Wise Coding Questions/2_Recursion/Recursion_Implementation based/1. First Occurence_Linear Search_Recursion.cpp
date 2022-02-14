#include<bits/stdc++.h>
using namespace std;

//we will built this linear search uing recursion
//we will break our subarray in 2 parts :-one of one element and other of n-1 elements
int firstOcc(int*a, int n, int key){
	if(n==0)
		return -1;

	//rec case
	if(a[0]==key){
		return 0;
	}
	int i = firstOcc(a+1,n-1,key);
	if(i==-1){
		returrn -1;
	}
	return i+1;
}

//Different style of writing the same function
//its like converting a for loop in recursive code
int linearSearch(int*a, int i, int n, int key){
	if(i==n){
		return -1;
	}
	//rec case 
	if(a[i]==key){
		return i;
	}
	return linearSearch(a,i+1,n,key);
}

int main(){
	int a[]={1,2,3,7,4,5,6,7,10};
	int key=7;
	int n=sizeof(a)/sizeof(int);

	int ans=firstOcc(a,n,key);
	cout<<ans<<endl;
}