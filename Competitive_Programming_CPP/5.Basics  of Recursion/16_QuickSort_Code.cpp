/*
@csalgo

Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

@csalgo5 7 



*/



#include<iostream>
using namespace std;

void swap(int arr[],int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(int arr[],int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	
	for(int j=l;j<r;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	
	swap(arr,i+1,r);
	return i+1;
}

void quickSort (int arr[] ,int l, int r)
{
	if(l<r)
	{
		int pi=partition(arr,l,r);
		quickSort(arr,l,pi-1);
		quickSort(arr,pi+1,r);
	}
}

int main()
{
	int n;
	cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    quickSort(arr,0,n-1);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}