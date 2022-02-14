// Inversion Count
#include<iostream>
using namespace std;

int merge(int *arr, int s, int e){
	int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;

	int temp[10000];
	int cnt = 0; //cross inversions count

	while(i<=mid and j<=e){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			k++;
			i++;
		}
		else{
			temp[k++]=arr[j++];
			cnt+=mid-i+1;
		}
	}

	// fill the arrays if some elements are left in one of the arrays
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=e){
		temp[k++]=arr[j++];
	}

	//copy all elemnts back to array a
	for(int i=s;i<=e;i++){
		a[i]=temp[i];
	}

	return cnt;
}


int inversion_count(int *arr, int s, int e){
	//base case
	if(s>=e) return 0;

	//merge sort
	int mid=(s+e)/2;
	int x = inversion_count(a,s,mid);
	int y = inversion_count(a,mid+1,e);
	int z = merge(a,s,e);  //cross inversions

	return x+y+z;
}

int main(){
    int arr[] = {1, 5, 2, 6, 3, 0};
	int n = sizeof(arr)/sizeof(int);

	cout<<inversion_count(arr,o,n-1)<<endl;

	return 0;
}

