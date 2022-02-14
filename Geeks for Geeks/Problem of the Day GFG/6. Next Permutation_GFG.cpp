Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:
Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.

Example 2:
Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last 
permutation. So, the next permutation 
is the lowest one.






Optimized Approach :- //E.g. :- {1 3 5 4 2}
//1. Iterate from behind & find A[i]<A[i+1] :->Find Index 1
    // ind[1]=1
//2. Ind[2]>Ind[1] :-> Find Index 2
    // ind[2]=3
//3. swap(ind[2], ind[1]) :-> {1 4 5 3 2}
//4. reverse(1+1,end) :- {1 4 2 3 5}


vector<int> nextPermutation(int N, int arr[]){
	int i=N-2;
	while(i>=0){
		if(arr[i]<arr[i+1])
			break;
		i--;
	}

	if(i>=0){
		int j=N-1;
		while(arr[i]>=arr[j])
			j--;
		swap(i,j,arr);
	}
	reverse(i+1,arr);
	vector<int>ans;
	for(int x:arr){
		ans.push_back(x);
	}

	return x;
}

void swap(int i, int j, int arr[]){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void reverse(int i, int arr[]){
	int start = i;
	int end = arr.length()-1;

	while(start<end){
		swap(start,end,arr);
		start++;
		end--;
	}
}



//Another Solution :-
vector<int> nextPermutation(int n, vector<int> arr)
{
    // If number of digits is 1 then just return the vector
    if (n == 1)
        return arr;

    // Start from the right most digit and find the first
    // digit that is
    // smaller than the digit next to it.
    int i = 0;
    for (i = n - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1])
            break;
    }

    // If there is a possibility of a next greater element
    if (i != 0) {
        // Find the smallest digit on right side of (i-1)'th
        // digit that is
        // greater than number[i-1]
        for (int j = n - 1; j >= i; j--) {
            if (arr[i - 1] < arr[j]) {
                // Swap the found smallest digit i.e. arr[j]
                // with arr[i-1]
                swap(arr[i - 1], arr[j]);
                break;
            }
        }
    }

    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    reverse(arr.begin() + i, arr.end());

    // If i is 0 that means elements are in decreasing order
    // Therefore, no greater element possible then we just
    // return the lowest possible
    // order/element formed from these digits by just
    // reversing the vector

    return arr;
}
