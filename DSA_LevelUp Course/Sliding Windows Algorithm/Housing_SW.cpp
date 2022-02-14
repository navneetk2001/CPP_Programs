#include<iostream>
using namespace std;

void housing(int *arr, int n, int k){
	int i=0;
	int j=0;
	int curr_sum=0;

	while(j<n){
		//expand to right
		curr_sum+=arr[j];
		j++;

		//remove elemrnts from left till curr_sum>sum & i<j

		while(curr_sum > k and i<j){
			curr_sum=curr_sum-arr[i];
			i++;
		}
        
        //check if at any given point
		if(curr_sum==k){
			// Print that window
			cout<<i<<" - "<<j-1<<endl;
		}
	}
	return;
}

int main(){
	int plots[]={1,3,2,1,4,1,3,2,1,1};
	int n=sizeof(plots)/sizeof(int);
	int k=8;

	housing(plots,n,k);

	return 0;
}

// variation for this problem :-
// 1. Smallest window that contains the required sum.
// 2. Handle if you have negative integers in the array.