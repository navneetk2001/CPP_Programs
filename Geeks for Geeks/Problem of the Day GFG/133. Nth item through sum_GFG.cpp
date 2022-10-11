// Given two sorted arrays A and B of length L1 and L2, we can get a set of sums(add one element from the first and one from second). Find the Nth element in the set considered in sorted order.
// Note: Set of sums should have unique elements.

// Example 1:
// Input: L1 = 2, L2 = 2
// A = {1, 2}
// B = {3, 4}
// N = 3
// Output: 6
// Explaination: The set of sums are in the order 4, 5, 6.

// Example 2:
// Input: L1 = 5, L2 = 4
// A = {1, 3, 4, 8, 10}
// B = {20, 22, 30, 40}
// N = 4
// Output: 25
// Explaination: The numbers before it are 21, 23 and 24.



//Solution Approach :-
class Solution{
public:
    int nthItem(int L1, int L2, int A[], int B[], int N){
        set<int> s;
        for(int i=0;i<L1;i++){
            for(int j=0;j<L2;j++){
                s.insert(A[i]+B[j]);
            }
        }

        int a=1;
        for(auto it:s){
            if(a==N){
               return it;
            }
            a++;
        }
        return -1;
    }
};



//Second Solution :-
int nthItem(int L1, int L2, int A[], int B[], int N){
    map<int,int> set;
    for(int i = 0 ; i < L1 ; ++i){
        for(int j = 0 ; j < L2 ; ++j){
            ++set[A[i] + B[j]];
        }
    }

    for(auto &ele : set){
        if(--N == 0){
            return ele.first ;
        }
    }
    return -1 ;
}


