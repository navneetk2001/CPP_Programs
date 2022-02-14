Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that it is closest to X.

Example 1:
Input:
N = 4
A[] = {-1 , 2, 1, -4}
X = 1
Output: 2
Explaination: 
Sums of triplets:
(-1) + 2 + 1 = 2
(-1) + 2 + (-4) = -3
2 + 1 + (-4) = -1
2 is closest to 1.

Example 2:
Input:
N = 5
A[] = {1, 2, 3, 4, -5}
X = 10
Output: 9
Explaination: 
Sums of triplets:
1 + 2 + 3 = 6
2 + 3 + 4 = 9
1 + 3 + 4 = 7
...
9 is closest to 10.


int closest3Sum(int A[], int N, int X){
	//sort
	sort(A.begin(), A.end());

	int diff=INT_MAX;
	int ans=0;

	for(int i=0;i<N;i++){
		int st=i+1;
		int end=N-1;
		int target = X-A[i];

		while(st<end){
			if(abs(A[st] + A[end] - target) < diff){
				diff=abs(A[st] + A[end] - target);
				ans=A[i]+A[st]+A[end];
			}
			else if(A[st] + A[end] > target){
				end--;
			}
			else{
				st++;
			}
		}
	}
	return ans;
}







// Function to return the sum of a
// triplet which is closest to x
int solution(vector<int>& arr, int x)
{
    // To store the closest sum
    int closestSum = INT_MAX;

    // Run three nested loops each loop 
    // for each element of triplet
    for (int i = 0; i < arr.size() ; i++) 
    {
        for(int j =i + 1; j < arr.size(); j++)
        {
            for(int k =j + 1; k < arr.size(); k++)
            {
                //update the closestSum
                if(abs(x - closestSum) > abs(x - (arr[i] + arr[j] + arr[k])))
                    closestSum = (arr[i] + arr[j] + arr[k]);
            } 
        }
    }
    // Return the closest sum found
    return closestSum;
}




int solution(vector<int>& arr, int x)
{
    // Sort the array
    sort(arr.begin(), arr.end());

    // To store the closest sum
  //not using INT_MAX to avoid overflowing condition 
    int closestSum = 1000000000;

    // Fix the smallest number among
    // the three integers
    for (int i = 0; i < arr.size() - 2; i++) {

        // Two pointers initially pointing at
        // the last and the element
        // next to the fixed element
        int ptr1 = i + 1, ptr2 = arr.size() - 1;

        // While there could be more pairs to check
        while (ptr1 < ptr2) {

            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[ptr1] + arr[ptr2];
            
              // if sum is equal to x, return sum as
              if (sum == x)
              return sum;
            // If the sum is more closer than
            // the current closest sum
            if (abs(x - sum) < abs(x - closestSum)) {
                closestSum = sum;
            }

            // If sum is greater then x then decrement
            // the second pointer to get a smaller sum
            if (sum > x) {
                ptr2--;
            }

            // Else increment the first pointer
            // to get a larger sum
            else {
                ptr1++;
            }
        }
    }

    // Return the closest sum found
    return closestSum;
}