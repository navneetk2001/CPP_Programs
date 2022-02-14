#include <bits/stdc++.h>
using namespace std;

int minimum_Subset_sum_diff(int arr[],int n){
	int range=0;
	for(int i=0;i<n;i++){
		range+=arr[i];  // taking sum of the array for range 
	}
    vector<int> v = SubsetSum(arr,range,n);  // we need to store the last row values in a vector so that we can know which values can be possible values for subset sum->s1.
    
    int mn=INT_MAX;
    // iterating through the last row of the matrix
    for(int i=0;i<v.size();i++){   // v is a vector which stores last rows values 
    	mn=min(mn,(range-2*v[i]));  // taking minimum from the last row
    }
    return mn;
}

vector<int> SubsetSum(int arr[], int sum, int n){
	int t[n+1][sum+1];   // size according to values that is changing in recursive function parameters
    memset(t, false,sizeof(t));    // initialize t with false values
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0){
				t[i][j]=false;
			}
			if(j==0){
				t[i][j]=true;
			}
		}
	}
    
    for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
				t[i][j]=(t[i][j-arr[i-1]] || t[i-1][j]);  // include or exclude
	        }
	        else{
	        	t[i][j]=t[i-1][j];   //exclude
	        }
		}
	}
	
	vector<int> v; // contains all subset sums possible with n elements // creating a vector varible to store all the element of the last row 
	for (int j = 0; j <= sum; j++) // from the range we need to exclude the element which is not there in the existing problem 
		if (t[n][j] == true) // keep true to only those place whose subset sum exist
			v.push_back(j); // store in the vector 

	return v;
}

int main() {
	int n; 
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << minimum_Subset_sum_diff(arr, n) << endl;
	return 0;
}