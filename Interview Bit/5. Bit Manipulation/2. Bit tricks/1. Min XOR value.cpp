// Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

// Example Input 1:
//     A = [0, 2, 5, 7]
// Example Output 1:
//     2
// Explanation:
//     0 xor 2 = 2
// Example Input 2:
//     A = [0, 4, 7, 9]
// Example Output 2:
//     3

//Hint :-
The brute-force would be to try every pair (x, y). If the array is sorted, do you need to check for every pair? Try to reduce the number of checked pairs.

//Solution Approach :- 
The first step is to sort the array. The answer will be the minimal value of X[i] XOR X[i+1] for every i.

Proof:
Let’s suppose that the answer is not X[i] XOR X[i+1], but A XOR B and there exists C in the array such as A <= C <= B.
Next is the proof that either A XOR C or C XOR B are smaller than A XOR B.
Let A[i] = 0/1 be the i-th bit in the binary representation of A
Let B[i] = 0/1 be the i-th bit in the binary representation of B
Let C[i] = 0/1 be the i-th bit in the binary representation of C

This is with the assumption that all of A, B and C are padded with 0 on the left until they all have the same length
Example: A=169, B=187, C=185
A=101010012
B=101110112
C=101110012
Let i be the leftmost (biggest) index such that A[i] differs from B[i]. There are 2 cases now:
1. C[i] = A[i] = 0,
then (A XOR C)[i] = 0 and (A XOR B)[i] = 1
This implies (A XOR C) < (A XOR B)
2. C[i] = B[i] = 1,
then (B XOR C)[i] = 0 and (A XOR B)[i] = 1
This implies (B XOR C) < (A XOR B)

Time complexity: O(N * logN) to sort the array and O(N) to find the smallest XOR
Space complexity: O(N)


//First Solution :-
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int min=INT_MAX; //INT_MAX-->macro function..initialize it.
    int val;
    for(int i=0;i<A.size()-1;i++)
    {
        val=A[i]^A[i+1];
        if(val<min)
            min=val;
    }
    return min;
}

//Second Solution :-
int Solution::findMinXor(vector<int> &A) {
    map<int, int> m;
    for (int i = 0; i < A.size(); i++) {
        m[A[i]]++;
        
        if(m[A[i]]>1)
            return 0;
    }

    int mn = INT_MAX, c = 0, i = 0;
    for (auto a : m)
    {
        if (i)
            mn = min(mn, a.first ^ c);
        c = a.first;
        i++;
    }
    return mn;
}


//Third Solution :- 
void quickSort(vector<int> &A, int start, int end) {
	if (start >= end) return;
	int i = start + 1;
	int j = end;
	int pivot = A[start];
	while (1) {
		while (i <= end && A[i] <= pivot) i++;
		while (j >= start && A[j]>pivot) j--;
		if (j <i) break;
		std::swap(A[i], A[j]);
	}
	swap(A[start], A[j]);
	quickSort(A, start, j - 1);
	quickSort(A, j + 1, end);
}

int Solution::findMinXor(vector<int> &A) {
	quickSort(A, 0, A.size() - 1);
	int min = INT_MAX;
	for (int i = 0; i < A.size() - 1; i++) {
		int tempResult = A[i] ^ A[i + 1];
		if (tempResult < min) min = tempResult;
	}
	return min;
}

