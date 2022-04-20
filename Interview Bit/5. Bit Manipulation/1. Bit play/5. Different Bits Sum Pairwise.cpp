// We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.
// You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.
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
Assume that all values in input have only 1 bit i.e. Ai = 0 or 1.
Lets say A = count of elements which are 0
and B = count of elements which are 1
In this case our answer is just 2AB, since each such pair contributes 1 to answer.
Can you combine this logic if we have multiple bits?
Note that all bits are independent in counting, since we are counting number of bits which are different in each pair.
So, we just do the same process for all different bits. Since Ai is an integer, we just have to do this for 31 different bits, so our solution is O(31*N).


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



//Second Solution :- //BruteForce Solution
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
int Solution::cntBits(vector<int> &A) {
    int n=A.size();
    long long int ans=0;

    for(int i=0;i<31;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(A[j]&1){
                count++;
            }
            A[j]>>=1;
        }
        ans+=count*((long long)n-count)*2;
    }
    return ans%1000000007;
}


//Fourth Solution
typedef long long ll;
void x(ll n, ll ar[]){
    ll t=0;
    while(n>0){
        if(n%2)
            ar[t]++;
        ar[t]%=1000000007;
        t++;
        n/=2;
    }
}
int Solution::cntBits(vector<int> &A) {
    ll n=A.size(),i,ar[32],t=0;
    for(i=0;i<32;i++)
        ar[i]=0;
    for(i=0;i<n;i++)
        x(A[i],ar);
    
    for(i=0;i<32;i++)
        t=(t+(2*ar[i]*(n-ar[i]))%1000000007)%1000000007;
    return t;
}


