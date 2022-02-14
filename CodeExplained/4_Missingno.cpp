// Missingno!
// You are given an integer n, along with an array of n-1 numbers in the range 1 to n, with no duplicates. One number is missing from the array. Find that number


#include<bits/stdc++.h>
using namespace std;

int missing_no (int n, vector<int> arr) {
   int i = 0;
	while(i<n-1){
		if(arr[i]!=arr[arr[i]-1]){
			swap(arr[i],arr[arr[i]-1]);
		}
		else{
			i++;
		}
	}
   int missing=0;
   for(int i=0;i<n-1;i++){
      if(arr[i]!=i+1){
         missing=i+1;
      }
   }
   return missing;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr = 0; i_arr < n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    int out_;
    out_ = missing_no(n, arr);
    cout << out_;
}