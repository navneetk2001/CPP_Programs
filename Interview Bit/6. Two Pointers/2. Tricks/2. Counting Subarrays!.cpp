// Given an array A of N non-negative numbers and you are also given non-negative number B.
// You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.
// Input 1:
//  A = [2, 5, 6]
//  B = 10
// Output 1:
//  4

// Input 2:
//  A = [1, 11, 2, 3, 15]
//  B = 10
// Output 2:
//  4

// Explanation 1: The subarrays with sum less than B are {2}, {5}, {6} and {2, 5},
// Explanation 2: The subarrays with sum less than B are {1}, {2}, {3} and {2, 3}


//Hint 
// Try to use two pointers and maintain a sliding window of a subarray with sum less than B.
// Think of using the above idea to find a solution to the problem.

//Solution Approach :-
// A simple solution is to generate all subarrays of the array and then count the number of arrays having sum less than B.
// Time complexity : O(N2).
// An efficient solution is based on sliding window technique that can be used to solve the problem.
// We use two pointers start and end to represent starting and ending point of sliding window. (Not that we need to find contiguous parts).
// Initially both start and end point to the beginning of the array, i.e. index 0. Now, let’s try to add a new element el.
// There are two possible conditions.
// 1st case :
// If sum is less than B, increment end by one position. So contiguous arrays this step produce are (end – start). We also add el to previous sum. There are as many such arrays as the length of the window.
// 2nd case :
// If sum becomes greater than or equal to B, this means we need to subtract starting element from sum so that the sum again becomes less than B. So we adjust the window’s left border by incrementing start.
// We follow the same procedure until end < array size.
// Time complexity : O(N).

//First Solution
int Solution::solve(vector &A, int B) {
	int i=0, j=0, count=0;

	for (i=0; i<A.size(); i++){
	    int sum=0;
	    for (j=i; j>=0; j--){
	        sum+=A[j];
	        if(sum<B) {
	        	count++;
	        }
	        else {
	        	break;
	        }
	    }
	}
	return count;
}

//Second Solution
int Solution::solve(vector &A, int B) {
	int n=A.size();
	int i=0,j=0;
	int ans=0;
	int sum=0,prej=-1;

	while(i<n && j<n)
	{
	    if(j!=prej)
	        sum+=A[j];
	    if(sum<B) 
	    {
	        ans+=(j-i)+1;
	        prej=j;
	        j++;
	    }
	    else
	    {
	        prej=j;
	        sum-=A[i];
	        i++;
	    }
	}
	return ans;
}

//Third Solution
int Solution::solve(vector<int> &A, int B) {
	int n=A.size();
	int i=0;
	int j=0;
	int count=0;

	int CurrSum=0;
	while(j<n){
	    CurrSum+=A[j];
	    while(CurrSum>=B){
	        CurrSum-=A[i++];
	    }
	    count+=(j-i+1);
	    j++;
	}
	return count;
}


//Fourth Solution :-
int Solution::solve(vector<int> &A, int B) {
    int n = A.size(); 
    int sum[n+1]; 
    sum[0] = 0;
    for(int i=1;i<=n; i++){     //Prefix Sum
        sum[i] = sum[i-1] + A[i-1];
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(sum[j+1] - sum[i] < B) {
            	ans++;
            }
        }
    }
    return ans;
}
