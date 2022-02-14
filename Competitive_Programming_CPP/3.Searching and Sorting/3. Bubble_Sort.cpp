/*

Coding Problem
Problem Name: Bubble Sort
Problem Level: EASY
Problem Description: 
#### Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Bubble Sort'.


##### Note:
    Change in the input array/list itself. You don't need to return or print the elements.


##### Input format : 
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the array/list.

    Second line contains 'N' single space separated integers representing the elements in the array/list.

##### Output format :
    For each test case, print the elements of the array/list in sorted order separated by a single space.

    Output for every test case will be printed in a separate line.

##### Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^3
    Time Limit: 1 sec
 ##### Sample Input 1:
    1
    7
    2 13 4 1 3 6 28

##### Sample Output 1:
    1 2 3 4 6 13 28

##### Sample Input 2:
    2
    5
    9 3 6 2 0
    4
    4 3 2 1

##### Sample Output 2:
    0 2 3 6 9
    1 2 3 4

*/


/*

#include<iostream>
using namespace std;
 
void BubbleSort(int Arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                int temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
    }
    
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
    
    BubbleSort(Arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }

}

*/


// Recursive implementation of BUBBLE Sort


/*
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n)
{
   
    if (n == 1)
        return;
 
   
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
 
   
    bubbleSort(arr, n-1);
}
 

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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

    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}

*/


//  Recursive implementation of BUBBLE Sort :- Second Approach 

#include <iostream>
using namespace std;
 

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1]) {
            swap(arr, i, i + 1);
        }
    }
 
    if (n - 1 > 1) {
        bubbleSort(arr, n - 1);
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

    bubbleSort(arr, n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
 
    return 0;
}

