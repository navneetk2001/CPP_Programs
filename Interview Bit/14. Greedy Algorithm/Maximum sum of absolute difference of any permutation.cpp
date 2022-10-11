https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/




//Solution Approach :-
// For the implementation of the above algorithm -> 
// 1. We will sort the array. 
// 2. Calculate the final sequence by taking one smallest element and largest element from the sorted array and make one vector array of this final sequence. 
// 3. Finally, calculate the sum of absolute difference between the elements of the array.

#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n){
	vector<int> finalSequence;

	sort(a, a + n);	   // sort the original array so that we can retrieve the large elements from the end of array elements
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);             //we will insert one smallest element
		finalSequence.push_back(a[n - i - 1]);     //we will insert one largest element then
	}
	if (n % 2 != 0){	                           // If there are odd elements, push the middle element at the end.
		finalSequence.push_back(a[n/2]);
	}

	int MaximumSum = 0;            	//store the maximum sum of absolute difference
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum += abs(finalSequence[i] -finalSequence[i + 1]);
	}
	
	MaximumSum += abs(finalSequence[n - 1] - finalSequence[0]);   	// absolute difference of last element and 1st element
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}



//Second Solution :-
// Algorithm:
// sort the array
// initialize 2 variable i=0, j = size – 1
// set a flag (true if we will increment i and false if we will decrement j) in order to track which variable needs to be changed. since after first move we will select next min value i.e. increment i, it will be initialised as true;
// run the while loop and calculate sum for every i and j, and change i and j accordingly
// after the loop we need to calculate the difference of middle element and first. this will be done separately.

#include <bits/stdc++.h>
using namespace std;

long long int maxSum(int arr[], int n){
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	bool off = true;
	long long int sum = 0;
	
	while (i < j) {
		sum += abs(arr[i] - arr[j]);
		if (!off) {
			j--;
		}
		else {
			i++;
		}
		off = !off;
	}
	sum += abs(arr[i] - arr[0]);
	return sum;
}

int main(){
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << maxSum(a, n) << endl;
}


