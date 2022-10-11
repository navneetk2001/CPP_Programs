// Write a function that takes an integer and returns the number of 1 bits it has.
// Input1:
//     11
// Output1:
// 3

//Hint :-
// A bruteforce solution will be to convert number into base 2 and count number of ones.
// Can you think of something better tho? Maybe a solution which runs in O(number_of_ones) atleast. It’s really similar to the trick used to check if a number is a power of 2 in O(1) approx.

//Solution Approach :- 
// Bruteforce:
// Iterate 32 times, each time determining if the ith bit is a ’1′ or not.
// This is probably the easiest solution, and the interviewer would probably not be too happy about it.
// This solution is also machine dependent (You need to be sure that an unsigned integer is 32-bit).
// In addition, this solution is not very efficient too because you need to iterate 32 times no matter what.

// A better solution:
// This special solution uses a trick which is normally used in bit manipulations.
// Notice what x - 1 does to bit representation of x.
// x - 1 would find the first set bit from the end, and then set it to 0, and set all the bits following it.

// Which means if x = 10101001010100
//                               ^
//                               |
//                               |
//                               |

//                        First set bit from the end
// Then x - 1 becomes 10101001010(011)

// All other bits in x - 1 remain unaffected.
// This means that if we do (x & (x - 1)), it would just unset the last set bit in x (which is why x&(x-1) is 0 for powers of 2).
// Can you use the above fact to come up with a solution ?


//First Solution :-
int Solution::numSetBits(unsigned int A) {
  int cnt=0;
	while(A){
		cnt++;
		A=A&(A-1);
	}
	return cnt;
}

//Second Solution :-
int Solution::numSetBits(unsigned int A) {
    int cnt=0;
	while(A){
		if(A & 1) cnt++;
        A>>=1;
	}
	return cnt;
}


//Third Solution :- 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++){
            if((n&1<<i)!=0){
                count++;
            }
        }
        return count;
    }
};

//Fourth Method :- 
int Solution::numSetBits(unsigned int A) {
    return __builtin_popcount(A);
}


