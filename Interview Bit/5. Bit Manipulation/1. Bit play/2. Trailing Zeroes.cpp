// Given an integer A, count and return the number of trailing zeroes.
// Input 1:
//  A = 18
// Output 1:
//  1
//  18 in binary is represented as: 10010, there is 1 trailing zero.


//Hint :-
// A simple solution is to traverse bits from LSB (Least Significant Bit) and increment count while bit is 0.
// This will take O(log A) time. 
// Can you do it in O(1)?

//Solution Approach :- 
// A simple solution is to traverse bits from LSB (Least Significant Bit) and increment count while bit is 0.
// Time Complexity: O(log A)

// We can do better and solve this in O(1) using a look up table.
// The lookup table solution is based on following concepts :
// -> The solution assumes that negative numbers are stored in 2’s complement form which is true for most of the devices. If numbers are represented in 2’s complement form, then (x & -x) [Bitwise and of x and minus x] produces a number with only last set bit.
// -> Once we get a number with only one bit set, we can find its position using lookup table. It makes use of the fact that the first 32 bit position values are relatively prime with 37, so performing a modulus division with 37 gives a unique number from 0 to 36 for each. These numbers may then be mapped to the number of zeros using a small lookup table.


//First Solution :-
int Solution::solve(int A) {
    for(int i=0;i<32;i++){
        if(A&(1<<i)){ 
            return i;
        }
    }
}

//Second Solution :-
int Solution::solve(int A) {
    int count=0;
    while(A%2 == 0){
        A = A>>1;    //A=A/2;    :-> Doing right shift till we get one at last index
        count++;
    }
    return count;
}

//Third Solution :- 
int Solution::solve(int A) {
    if(A&1){
        return 0;
    }
    return log2(A^A-1);
}


//Fourth Solution :- 
int Solution::solve(int A) {
    int c=0;
    int i=1;
    int z=A&i;
    while(z!=i){
        i=i<<1;
        z=A&i;
        c++;
    }
    return c;
}

