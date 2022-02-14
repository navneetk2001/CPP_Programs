/*
@csalgo

Last Index of Number

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
3

@csalgo3

*/

/*

// First Method :-

#include<iostream>
using namespace std;

int Last_Index(int A[],int n,int num)
{
	if (n==0)
	{
		return -1;
	}
	if (A[n-1]==num)
	{
		return n-1;
	}
	int small_Array=Last_Index(A,n-1,num);
	return small_Array;
	
}

int main()
{
	int n;
	cin>>n;

    int A[n]; 
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	int num;
	cin>>num;

	cout<<Last_Index(A,n,num);
	
} 

*/



// Second Method :-

#include<iostream>
using namespace std;

int Last_Index(int A[],int n,int num)
{
	if (n==0)
	{
		return -1;
	}
	int ans=Last_Index(A+1,n-1,num);
    if(ans!=-1)
    {
        return ans+1;
    }
    else{
         if(A[0]==num)
         {
             return ans+1;
         }
        else
        {
            return -1;
        }
    }
}
	

int main()
{
	int n;
	cin>>n;

    int A[n]; 
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	int num;
	cin>>num;

	cout<<Last_Index(A,n,num);
	
} 




