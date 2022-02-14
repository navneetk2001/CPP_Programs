Given an array arr[] of size N containing equal number of odd and even numbers. Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.
Note: There are multiple possible solutions, Print any one of them. Also, 0-based indexing is considered.

Example 1:
Input:
N = 6
arr[] = {3, 6, 12, 1, 5, 8}
Output:
1
Explanation:
6 3 12 1 8 5 is a possible solution.
The output will always be 1 if your rearrangement is correct.

Example 2:
Input:
N = 4
arr[] = {1, 2, 3, 4}
Output :
1


//Solution :-
void reArrange(int arr[], int N){
	int odd=1;
	int even=0;

	int ans[N];
	for(int i=0;i<N;i++){
		if(arr[i]%2==0){
			ans[even]=arr[i];
			even+=2;
		}
		if(arr[i]%2==1){
			ans[odd]=arr[i];
			odd+=2;
		}
	}

	for(int i=0;i<N;i++){
		arr[i]=ans[i];
	}
}




void reArrange(int arr[], int n){
	int odd=1;
	int even=0;

	while(1){
		while(even<n && arr[even]%2==0){
			even+=2;
		}
		while(odd<n && arr[odd]%2==1){
			odd+=2;
		}
		if(even>=n || odd>=n)
			break;

		swap(arr[odd], arr[even]);
	}
}
