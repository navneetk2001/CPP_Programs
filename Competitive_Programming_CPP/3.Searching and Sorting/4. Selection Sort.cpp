/*

#include<iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;

    int Arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }


    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]<Arr[i])
            {
                int temp=Arr[j]
                Arr[j]=Arr[i];
                Arr[i]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
        {
            cout<<Arr[i]<<" ";
        }
}

*/   



/*


#include<iostream>
using namespace std;
 

void SelectionSort(int Arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=Arr[i];
        int minIndex=i;

        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]<min)
            {
                min=Arr[j];
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            Arr[minIndex]=Arr[i];
            Arr[i]=min;
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


    SelectionSort(Arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }
}

*/



  // Recursive implementation of Binary Search



#include <iostream>
using namespace std;
 

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
void selectionSort(int arr[], int i, int n)
{
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min]) {
            min = j;   
        }
    }

    swap(arr, min, i);
 
    if (i + 1 < n) {
        selectionSort(arr, i + 1, n);
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
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
 
    selectionSort(arr, 0, n);
    printArray(arr, n);
 
    return 0;
}







