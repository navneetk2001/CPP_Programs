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
void QuickSort(vector<int> &a, int s, int e){
	//base case
	if(s>=e)
		return;
	//rec case
	int p=partition(a,s,e);
	QuickSort(a,s,p-1);
	QuickSort(a,p+1,e);
}

int main()
{
	vector<int> arr{10,5,2,0,7,6,4};
	
	int s=0;
	int e=arr.size()-1;
	QuickSort(arr,s,e);

	for(int x : arr){
		cout<<x<<" ";
	}
    cout<<endl;

	return 0;
}