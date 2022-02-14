#include<bits/stdc++.h>
using namespace std;

void AllOccurences(int *a, int i, int n, int key){
	if(i==n){
		return -1;
	}
	if(a[i]==key){
		cout<<i<<" , ";
	}
	AllOccurences(a,i+1,n,key);
}

int storeOcc(int *a, int i, int n, int key, int *out, int j){
	//base case
	if(i==n){
		return j;  //j denotes the count of elements stored in output array
	}
	if(a[i]==key){
		out[j]=i;
		//increment j to accomodate current occurence
		return storeOcc(a,i+1,n,key,out,j+1);
	}
	//j remains unchanged
	return storeOcc(a,i+1,n,key,out,j);
}

int main(){
	int a[]={1,2,3,7,4,5,6,7,10};
	int key=7;
	int n=sizeof(a)/sizeof(int);

	AllOccurences(a,0,n,key);

	int out[100];
	int cnt=storeOcc(a,0,n,key,out,0);

	for(int k=0;k<cnt;k++){
		cout<<output[k]<<" ";
	}

	return 0;
}