/*



*/



/*
#include<iostream>
using namespace std;


int LinearSearch(int Arr[],int n,int elem)
{
	for(int i=0;i<n;i++)
	{
		if(Arr[i]==elem)
			return i;
		
	}
	return -1;
		
}



int main()
{
	int n;
	cin>>n;

	int Arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>Arr[i];
	}


	int elem;
	cin>>elem;

    int result=LinearSearch(Arr,n,elem);
    if(result==-1)
    {
    	cout<<"Element is not found ";
    }
    else
    {
    	cout<<"Element is found at index "<<result;
    }
	
	return 0;
}

*/


#include<iostream>
using namespace std;
 
int main()
{
	int flag=0;
	int i;


	int n;
	cin>>n;
	
	int Arr[n];
	for(i=0;i<n;i++)
	{
		cin>>Arr[i];
	}
	
	int elem;
	cin>>elem;
	


	for(i=0;i<n;i++)
	{
		if(Arr[i]==elem)
		{
			flag=1;
			break;
		}
	}
	
	if(flag)
		cout<<"\nElement is found at position "<<i;
	else
		cout<<"\nElement is not present in array";
		
	return 0;
}



