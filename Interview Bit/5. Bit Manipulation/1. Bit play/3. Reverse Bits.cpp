// Reverse the bits of an 32 bit unsigned integer A.

// Input 2:
//  3

// Output 2:
//  3221225472

// Explanation 2:
//         00000000000000000000000000000011    
// =>      11000000000000000000000000000000


//Hint :-
How do you swap the ‘i’th bit with the ‘j’th bit?
Try to figure out if you could use the XOR operation to do it.

//Solution Approach :- 
Reversing bits could be done by swapping the n/2 least significant bits with its most significant bits.
The trick is to implement a function called swapBits(i, j), which swaps the ‘i’th bit with the ‘j’th bit.
If you still remember how XOR operation works:
0 ^ 0 == 0, 
1 ^ 1 == 0, 
0 ^ 1 == 1, and 
1 ^ 0 == 1.
We only need to perform the swap when the ‘i’th bit and the ‘j’th bit are different.
To test if two bits are different, we could use the XOR operation. Then, we need to toggle both ‘i’th and ‘j’th bits.
We could apply the XOR operation again.
By XOR-ing the ‘i’th and ‘j’th bit with 1, both bits are toggled.
Bonus approach (The divide and conquer approach):
Remember how merge sort works? Let us use an example of n == 8 (one byte) to see how this works:
              01101001
             /        \
           0110       1001
          /   \       /   \
         01    10    10    01
        /\     /\    /\     /\
       0  1   1  0  1  0   0  1
The first step is to swap all odd and even bits. After that swap consecutive pairs of bits, and so on …
Therefore, only a total of log(n) operations are necessary.
Example:
For the first step, you would do:
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);


//First Solution :-
unsigned int Solution::reverse(unsigned int a) {
    unsigned int b=0;   //to store the reverse number
    for(int i=0;i<32;i++){
        b<<=1;     //left shift :-> make space for a new bit
        b|=(a&1);  //extract and store the new bit (right most)
        a>>=1;     //right shift :-> extract the next bit(i+1)
    }
    return b;
}

//Second Solution :-
unsigned int Solution::reverse(unsigned int a) {
    int res=0;   //to store the reverse number
    for(int i=0;i<32;i++){
        int lsb = a & 1;
        int reverseLsb = lsb << (31-i);
        res = res | reverseLsb;
        a = a >> 1;  
    }
    return res;
}

//Third Solution :- 
unsigned int Solution::reverse(unsigned int A) {
    int sum =0;
    int cnt = 0;
    while( A > 0 ){
      if( A%2 == 1 ){
        int x = 31-cnt;
        sum += (1<<x);
      } 
      A/=2;
      cnt++;
    }
    return sum;
}


//Fourth Solution :- 
unsigned int Solution::reverse(unsigned int A) {
    unsigned int B = 0; //B will hold the reversed number
    for(int i=0;i<32;i++){  //Iterating on all bit positions
        int k = A & 1;      //Extracting the rightmost bit from A (the ith bit in original number)
        B <<= 1;            //Shifting B to left (rightmost bit becomes 0)
        B |= k;             //Adding the extracted bit
        A >>= 1;            //Now the (i+1)st bit shifts to the rightmost position in A
    }
    return B;
}


//Fifth Solution :-
unsigned int Solution::reverse(unsigned int A) {
    int a[32] = {0};
    long long int x = A,i=31;
    while(i>-1)
    {
        a[i]=x%2;
        x=x/2;
        i--;
    }
    
    for(int i=0;i<16;i++)
    {
        swap(a[i],a[31-i]);
    }
    unsigned int p=1,sum=0;
    for(i=31;i>=0;i--)
    {
        sum = sum + (a[i]*p);
        p=p*2;
    }
    return sum;
}
