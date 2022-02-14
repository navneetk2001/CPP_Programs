// Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

// Example 1:
// Input:
// N = 2
// Output:
// 2
// Explanation:
// 2 is represented as "10" in Binary. As we see there's only one set bit
// and it's in Position 2 and thus the Output 2.

// Example 2:
// Input:
// N = 5
// Output:
// -1
// Explanation:
// 5 is represented as "101" in Binary.
// As we see there's two set bits and thus the Output -1.


//we will get position by :-
//if its a power of 2 :- index= logN+1
//if its not a power of 2 :- index=-1

class Solution {
  public:
    int findPosition(int N) {
        if(N==0){
        	return -1;
        }
        if((N&(N-1))==0){
        	return log2(N)+1;
        }
        else{
        	return -1;
        }
    }
};