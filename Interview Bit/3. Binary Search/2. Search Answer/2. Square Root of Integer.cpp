// Given an integer A.
// Compute and return the square root of A.
// If A is not a perfect square, return floor(sqrt(A)).
// DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.
// NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.

//Hint 1
// Think about the answer of this “Is a particular number r less than floor(sqrt(x))?”
// Answer of the above problem as a function of r will look like [1,1,……1,0,0……0]. Can you use this fact to devise a solution now?

//Solution Approach
// Think in terms of binary search.
// Let us say S is the answer.
// We know that 0 <= S <= x.
// Consider any random number r.
// If r*r <= x, S >= r
// If r*r > x, S < r.
// Maybe try to run a binary search for S.


// First Method :-
int Solution::sqrt(int A) {
    int i=0;
    int j=A;
    j=min(j,46340);    // 46340 is the sqrt of Integer.MAX_VALUE
    int mid=0;
    int res=-1;
    while(i<=j){
        mid=i+(j-i)/2;
        if((long) (mid * mid) == (long)A){
            return mid;
        }
        if((long) (mid * mid) > (long)A){
            j=mid-1;
        }
        else{
            res=mid;
            i=mid+1;
        }
    }
    return res;
}




//Second Method :-
// Note: r * r will overflow if not done carefully. So instead, we eliminate the multiplcation and resort to a little bit of division.
// Refer to the following solution:

class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};

