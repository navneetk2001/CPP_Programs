// Given an integer array A of size N.
// You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.
// For example, if A = [3, 4, 5] :
// Subarray    Operation   Result
// 3       None            3
// 4       None            4
// 5       None            5
// 3,4   3 XOR 4         7
// 4,5   4 XOR 5         1
// 3,4,5    3 XOR 4 XOR 5   2
// Now we take the resultant values and XOR them together:
// 3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.

//Hint :-
Just think for each element how many subarrays it will contribute its value to.
Like any element ith index in array A will occur (i + 1) * (N - i) times.
Try to use the above idea to find a solution to the problem.

//Solution Approach :- 
As we know a ⊕ a = 0. When we write all substrings, we have to check how many numbers occur an even number of times and how many numbers occur an odd number of times. If the list is 0 indexed, the number at ith index will occur (i + 1) * (N - i) times.
If N is even, either i + 1 or N - i will be even. Each number will occur an even number of times, and the answer will be 0 .
If N is odd and i is even, the product of the XOR will be odd. In that case, the answer is the XOR of the even indexed elements.

//First Solution :-
int Solution::solve(vector<int> &A) {
     if(A.size()%2==0)
        return 0;
        
    int XOR = 0;
    for(int i=0;i<A.size();i+=2)
        XOR^=A[i];
    return XOR;
}

//Second Solution :-
int Solution::solve(vector<int> &A) {
    int n=A.size();
    int cnt;
    int res=0;
    for(int i=0;i<n;i++){
        cnt = (i+1) * (n-i);  // no of subarrays in which element appears in 
        if(cnt%2) res^=A[i];
    }
    return res;
}

//Third Solution :- 
int Solution::solve(vector<int> &a) {
    int n=a.size(),i,s;
    s=0;
    if(n%2==0)return 0;
    for(i=0;i<n;i++)
    {
        if(i%2==0){s=(s^a[i]);}
    }
    return s;
}


