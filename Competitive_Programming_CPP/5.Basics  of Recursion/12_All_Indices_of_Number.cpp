/*
@csalgo

All Indices of Number

Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

@csalgo

*/



// First Method :-

#include<iostream>
using namespace std;

int All_Index(int A[],int n,int num,int Output_Arr[])
{
	if (n==0)
	{
		return 0;
	}
	int small_Array=All_Index(A,n-1,num,Output_Arr);
    if (A[n-1]==num)
	{
        Output_Arr[small_Array]=n-1;
        return small_Array+1; 
    }
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

	int Output_Arr[n];


	int Index = All_Index(A,n,num,Output_Arr);
	for(int i=0;i<Index;i++)
	{
		cout<<Output_Arr[i]<<" ";
	}
	
} 


/*

// Second Method

#include<iostream>
using namespace std;


int AllIndexesRecursive(int input[], int size, int x, int output[])
{ 

    // If an empty array comes to the function, then return zero 
    if (size == 0) { 
        return 0; 
    } 

    // Getting the recursive answer 
    int smallAns = AllIndexesRecursive(input + 1, size - 1, x, output); 

    // If the element at index 0 is equal to x then add 1 to the array values and shift them right by 1 step 
    if (input[0] == x) { 
        for (int i = smallAns - 1; i >= 0; i--) { 
            output[i + 1] = output[i] + 1; 
        } 

        // Put the start index in front of the array 
        output[0] = 0; 
        smallAns++; 
    } 
    else { 

        // If the element at index 0 is not equal to x then add 1 to the array values 
        for (int i = smallAns - 1; i >= 0; i--) { 
            output[i] = output[i] + 1; 
        } 
    } 
    return smallAns; 
} 

// Function to find all indices of a number 
void AllIndexes(int input[], int n, int x) 
{
	int output[n]; 
    int size = AllIndexesRecursive(input, n, x, output);  
                                
    for (int i = 0; i < size; i++) 
    { 
        cout << output[i] << " "; 
    } 
}


int main()
{
	int n;
	cin>>n;

    int input[n]; 
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}

	int x;
	cin>>x;

	//int Indexes = AllIndexesRecursive(input,n,x,output);
	AllIndexes(input,n,x);
	
}  
    

*/




