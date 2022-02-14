/*
@csalgo

Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

@csalgo5 

*/




#include<iostream>
using namespace std;


void merge(int arr[],int l, int mid, int r)
{
	int n1=mid-l+1;
	int n2=r-mid;

	int a[n1];
	int b[n2];

	for (int i=0;i<n1;i++)
	{
		a[i]=arr[l+i];
	}
	
	for (int i=0;i<n2;i++)
	{
		b[i]=arr[mid+1+i];
	}
	
	int i=0;
	int j=0;
	int k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			k++;  i++;
		}
		else
		{
			arr[k]=b[j];
			k++;  j++;
		}
	}
	
	while(i<n1)
	{
		arr[k]=a[i];
		k++; i++;
	}
	
	while(i<n2)
	{
		arr[k]=b[j];
		k++; j++;
	}
}

void mergeSort(int arr[],int l, int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		
		merge(arr,l,mid,r);
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


    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}