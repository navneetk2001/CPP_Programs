/*
Coding Problem
Problem Name: Merge Two Sorted Arrays
Problem Level: MEDIUM
Problem Description: 
#### You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.

##### Input Format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the first array/list.

    Second line contains 'N' single space separated integers representing the elements of the first array/list.

    Third line contains an integer 'M' representing the size of the second array/list.

    Fourth line contains 'M' single space separated integers representing the elements of the second array/list.


##### Output Format : 
    For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.

    Output for every test case will be printed in a separate line.

##### Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^5
    0 <= M <= 10^5
    Time Limit: 1 sec 
 ##### Sample Input 1 : 
    1
    5
    1 3 4 7 11
    4
    2 4 6 13

##### Sample Output 1 :
    1 2 3 4 4 6 7 11 13 

##### Sample Input 2 : 
    2
    3
    10 100 500
    7
    4 7 9 25 30 300 450
    4
    7 45 89 90
    0

##### Sample Output 2 :
    4 7 9 10 25 30 100 300 450 500
    7 45 89 90

*/


/*


#include<iostream>
using namespace std;
 
void mergeSortedArray(int Arr1[],int n,int Arr2[],int m, int SortedArray[])
{
    int i=0;
    int j=0;
    int k=0;

    

    while(i<n && j<m)
    {
        if(Arr1[i]<Arr2[j])
        {
            SortedArray
            [k]=Arr1[i];
            k++;
            i++;
        }
        else
        {
            SortedArray[k]=Arr2[j];
            k++;
            j++;
        }
    }

    while(i<n)
    {
        SortedArray[k]=Arr1[i];
        k++;
        i++;
    }

    while(j<m)
    {
        SortedArray[k]=Arr2[j];
        k++;
        j++;
    }
    
}



int main()
{
    int n;
    cin>>n;

    int Arr1[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arr1[i];
    }


    int m;
    cin>>m;

    int Arr2[m];
    for(int j=0;j<m;j++)
    {
        cin>>Arr2[j];
    }
    

    int SortedArray[m+n];
    mergeSortedArray(Arr1,n,Arr2,m,SortedArray);


    for(int i=0;i<n+m;i++)
    {
        cout<<SortedArray[i]<<" ";
    }

    return 0;
}

*/





//program to merge two array using recursive function


#include<iostream>
#include<conio.h>
using namespace std;

void merge_r(int a1[],int a2[],int c[],int s1,int s2,int i=0,int j=0,int k=0){

if(i<s1 && j<s2){

    if(a1[i]>a2[j]){
    c[k++]=a2[j++];

    }else{
    c[k++]=a1[i++];
    }
    merge_r(a1,a2,c,s1,s2,i,j,k);

}
else{

        if(i<s1){
            c[k++]=a1[i++];
             merge_r(a1,a2,c,s1,s2,i,j,k);
        }

        if(j<s2){
            c[k++]=a2[j++];
             merge_r(a1,a2,c,s1,s2,i,j,k);

        }

}
}

int main(){

int *a1= new int;
int *a2= new int;
int *c  =new  int;
int s1,s2;

cout<<"Size of the first array : ";
cin>>s1;

cout<<"Size of the Second array : ";
cin>>s2;

for (int i=0;i<s1;i++){
    cin>>a1[i];

}
for (int i=0;i<s2;i++){
    cin>>a2[i];
}

merge_r(a1,a2,c,s1,s2);

for(int i=0;i<s1+s2;i++){
    cout<<c[i]<<" ";
}

getch();

delete []a1;
delete []a2;

}




