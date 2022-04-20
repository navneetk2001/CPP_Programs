//Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.
//Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.
// For example,
// A=[1, 3, 5]
// We return
// f(1, 1) + f(1, 3) + f(1, 5) + 
// f(3, 1) + f(3, 3) + f(3, 5) +
// f(5, 1) + f(5, 3) + f(5, 5) =

// 0 + 1 + 1 +
// 1 + 0 + 2 +
// 1 + 2 + 0 = 8

//Hint :-
Assume that all values in input have only 1 bit i.e. Ai = 0 or 1.
How would you solve now?
Can you combine this logic if we have multiple bits?

//Solution Approach :- 
Suppose the given array contains only binary numbers, i.e A[i] belongs to [0, 1].
Let X be the number of elements equal to 0, and Y be the number of elements equals to 1.
Then, sum of hamming distance of all pair of elements equals 2XY, as every pair containing one element from X and one element from Y contribute 1 to the sum.
As A[i] belongs to [0, 231 - 1] and we are counting number of different bits in each pair, we can consider all the 31 bit positions independent.
For example:
A = [2, 4, 6] = [0102, 1002, 1102]</p>
At bit position 0 (LSB): x = 3, y = 0
At bit position 1: x = 1, y = 2
At bit position 2(MSB): x = 1, y = 2
Total sum = number of pairs having different bit at each bit-position = (2 * 3 * 0) + (2 * 1 * 2) + (2 * 1 * 2) = 8
Time complexity: O(N)
Space complexity: O(1)

//First Solution :-
int Solution::hammingDistance(const vector<int> &A) {
    long long ans = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < 32; i++) {
        long long int number_of_ones = 0;
        long long int number_of_zeros = 0;

        for (int x: A) {
            if ((1 << i) & x) number_of_ones++;
            else number_of_zeros++;
        }

        ans = (ans + (number_of_ones * number_of_zeros * 2) % MOD) % MOD;
    }

    return ans;
}



//Second Solution :- //BruteForce Approach 
int hd(int x, int y) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) & (x^y)) {
            count++;
        }
    }
    return count;
}

int Solution::hammingDistance(const vector<int> &A) {
    long long ans = 0;
    long long MOD = 1000000007;

    for (int x: A) {
        for (int y: A) {
            ans = (ans + hd(x, y)) % MOD;
        }
    }

    return ans;
}


//Third Solution :- 
int Solution::hammingDistance(const vector<int> &A) {
    
    long long int n=A.size(),count=0,ans=0,mod=1000000007;
    for(int i=0;i<32;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
                count++;
        }
        ans=(ans+(count*(n-count)*2))%mod;
    }
    
    return ans;
}

