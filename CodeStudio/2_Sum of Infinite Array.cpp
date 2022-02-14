/*
Problem Statement

Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.
For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
Now you are given Q queries, each query consists of two integers “L“ and “R”. 
Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

Note : The value of the sum can be very large, return the answer as modulus 10^9+7.
*/



//First Approach :- Brute Force
/*
Instead of creating a new infinite array B which has a repeated array A elements in the form 
[A1, A2,... AN, A1, A2,... AN, A1, A2,... AN…....]. We will traverse array A, again and again, to find the sum as array A 
is only repeating in infinite array B.
So the brute force approach is, for each query,
we run a loop from L to R, and for each index i, add the value at index (i%N) of the array A i.e A[i%N] to sum. 
So this way we can find the sum of the required subarray from index L to R in an infinite array B.
*/

/*
    Time Complexity:O(Q*(R-L))
    Space Complexity:O(1).
    
    Where Q is the number of given queries, and L and R are the given two indexes in each query.
*/


int mod = 1000000007;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {

    // It stores answer for each query.
    vector<int> ans;

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++) {
        
        vector<long long> range = queries[i];
        long long l = range[0] - 1;
        long long r = range[1] - 1;

        // It stores the sum
        long long sum = 0;

        for (long long i = l; i <= r; i++) {
            int index = (int) (i % n);
            sum = (sum + arr[index]) % mod;
        }
        sum %= mod;
        // Add answer to each query
        ans.push_back((int) sum);

    }

    return ans;
    
}






//Second Approach :-
/*
Prefix Sum Array
The better idea is to first create the sum array in which sumArray[i] stores the sum from (A[0]+....+A[i]). 
Now instead of iterating from L to R like in the previous approach, we find the sum using our sumArray[].

Let’s take an example, where array A = [1,2,3] and we have to find the sum of the subarray of the infinite array(as shown in below fig) 
from index 3 to 10 (0-based indexing). 
Now instead of iterating from 3 to 10 and then calculate the sum. We can observe one thing that we are going to 
traverse the array A again and again so instead of doing this, we can first find the sum from index 0 to index 10 say a, 
and then find the sum from index 0 to 2 say b, then subtract b from a as a-b, which is the sum of subarray from index 3 to 10
in an infinite array B.
Now to find the sum, from index 0 to any index X, we first find how many number of times the given array A can comes completely upto index X. 
which can be simply found by X / N say count , and sum will be count * sumArray[N] where N is the length of array A. 
Now for the remaining part of the subarray sum can be found by sumArray[ (X % N)]. 
Consider array A = {1, 2, 3} and we have to find the sum between L= 1 and R = 5. 
Then Till index 5 the array A repeats itself one time i.e {1, 2, 3, 1, 2} which can be calculated as R/N i.e 1 and 
the remaining elements till index 5 are {1, 2} which can be calculated as R%N. So the sum till index 5 is R/N * sumArray(N) + sumArray(R%N).
So this way we can find the sum without iterating from L to R.
*/

/*
    Time Complexity:O(Q+N).
    Space Complexity:O(N).

    Where N is the size of the given array, and Q is the number of queries given.
*/

int mod = 1000000007;

// Function to calculate prefix sum upto index x of the infite array.
long long func(vector<long long> &sumArray, long long x, long long n) {

    // Number of times the given array comes completely upto index x.
    long long count = (x / n) % mod;

    long long res = (count * sumArray[(int) n]) % mod;

    // Adding the remaining elements sum.
    res = (res + sumArray[(int) (x % n)]) % mod;

    return res;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {

    // It stores answer for each query.
    vector<int> ans;

    // It store cumulative sum where sumArray[i] = sum(A[0]+..A[i]).
    vector<long long> sumArray(n + 1);

    for (int i = 1; i <= n; i++) {
        sumArray[i] = (sumArray[i - 1] + arr[i - 1]) % mod;
    }

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++) {
        vector<long long> range = queries[i];
        long long l = range[0];
        long long r = range[1];

        // It stores the prefix sum from index 0 to index r in an infinite array.
        long long rsum = func(sumArray, r, n);

        // It stores the prefix sum from index 0 to index l-1 in an infinite array.
        long long lsum = func(sumArray, l - 1, n);

        // Add answer for each query.
        ans.push_back((int) ((rsum - lsum + mod) % mod));

    }

    return ans;
    
}