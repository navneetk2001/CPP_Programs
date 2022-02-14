#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a, int s, int e){
	int pivot = a[e];
	int i=s-1;

	for(int j=s; j<e; j++){
		if(a[j] < pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

//sorting method
int quickSelect(vector<int> &a, int s, int e, int k){
	//assuming that k will be inside of array
	int p=partition(a,s,e);
	if(p==k){
		return a[p];
	}
	else if (k<p){
		return quickSelect(a,s,p-1,k);
	}
	else{
		return quickSelect(a,p+1,e,k);
	}
	
}

int main()
{
	vector<int> arr{10,5,2,0,7,6,4};
	
	int s=0;
	int e=arr.size()-1;
	int k=4;

	cout<<quickSelect(arr,0,e,k)<<endl;

	return 0;
}