// Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

// Example 1:
// Input: N  = 7
// A[] = {20, 8, 22, 4, 12, 10, 14}
// K1 = 3, K2 = 6
// Output: 26
// Explanation:
// 3rd smallest element is 10
// 6th smallest element is 20
// Sum of all element between K1 & K2 is 12 + 14 = 26
 
// Example 2:
// Input: N = 6
// A[] = {10, 2, 50, 12, 48, 13}
// K1= 2, K2 = 6
// Output: 73



//Solution Approach :-
long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
    sort(A, A + N);
    long long sum = 0;
    
    for(long long i = K1; i < K2 - 1; ++i){
        sum += A[i];
    }
    
    return sum;
}


//Second Solution :- using priority_queue
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2){
    priority_queue<long long> pq;
    for(long long i = 0; i < K2; i++){
    	pq.push(A[i]);
    }

    for (long long i = K2; i < N; i++) {
        if(pq.top() > A[i]){
            pq.pop();
            pq.push(A[i]);
        }
    }

    long long ans = 0;
    while(pq.size() > K1 + 1) {
        pq.pop();
        ans += pq.top();
    }
    return ans;
}



//Third Solution :-
// 1. Find the K1 smallest 
// 2. Find the K2 smallest
// 3. then loop over the array and find the value in between(K1, K2) smallest

long long KthSmall(long long v[], int n, long long k){
    priority_queue<int, vector<int>> pq;    // Max Heap

    for (int i = 0; i < k; i++){
        pq.push(v[i]);
    }

    for (int i = k; i < n; i++){
        if (v[i] < pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}

long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
    long long temp1 = KthSmall(A, N, K1);
    long long temp2 = KthSmall(A, N, K2);
    
   	long long sum1 = 0;
    for (int i = 0; i < N; i++){
        if (A[i] > temp1 && A[i] < temp2){
            sum1 += A[i];
        }
    }
    return sum1;
}
