/*
@csalgo

Check Number

Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false

@csalgofalse

*/



#include<iostream>
using namespace std;


bool is_Present(int A[],int n,int num)
{
	if (n==0)
	{
		return false;
	}
	else if(A[n-1]==num)
	{
		return true;
	}
	else
	    return is_Present(A,n-1,num);
	
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
	
		
    if (is_Present(A,n,num))
    {
	    cout<<true;
    }
    else
    {
	    cout<<false;
    }


	//cout<<is_Present(A,n,num);	
} 


