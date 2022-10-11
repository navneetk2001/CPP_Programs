https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/#


You are given an array A of N integers where N is even. Consider an empty array B and perform the following operations on A exactly N/2 times:
Choose any two elements of A and erase them from A.
Append the product of those two elements at the end of B.
You have to perform the operations in such a way that the maximum value on B is minimized. Find this value.

Example 1:
Input:
N = 4
A = { -12, 17, -13, 17 }
Output: -204
Explanation:
Step 1: Select 17 and -12. Remove from A. Add (17 * -12) = -204 in B.
Step 2: Select 17 and -13. Remove from B. Add (17 * -13) = -221 in B.
B = {-204, -221}. -204 is the max value of B.

Example 2:
Input:
N = 2
A = { 2, 6 }
Output: 12
Explanation: B = {12}




//Solution Approach :-  Greedy
//if equal number of +ve and -ve :- then we sort the array in a fair way
//if unequal number of +ve and -ve :- then we will always get a +ve answer
//so in this case only sort the array

class Solution {
  public:
    long long maximumMultiple(int N, int A[]) {
        sort(A, A + N);
        int cnt = 0; //to store negative count;

        for(int i=0; i<N; i++){
            if(A[i]<0){    //count number of negatives
                cnt++;
            }
        }

        //negatives == positives, then reverse only negative side
        if(2 * cnt == N){
            reverse(A, A + (N / 2));
        }

        long long maxi = -1e18 + 7;     //store maximum number
        for(int i = 0; i < N; i++){
            maxi = max(maxi, (long long)A[i] * A[N - i -1]);
        }
        return maxi;
    }
};

