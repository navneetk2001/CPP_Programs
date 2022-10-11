// Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and the count of set bit in X is equal to the count of set bits in B.

// Example 1:
// Input: 
// A = 3, B = 5
// Output: 3
// Explanation:
// Binary(A) = Binary(3) = 011
// Binary(B) = Binary(5) = 101
// The XOR will be minimum when x = 3 i.e. (3 XOR 3) = 0 and the number of set bits in 3 is equal to the number of set bits in 5.

// Example 2:
// Input: 
// A = 7, B = 12
// Output: 6
// Explanation:
// (7)2= 111
// (12)2= 1100
// The XOR will be minimum when x = 6 i.e. (6 XOR 7) = 1 and the number of set bits in 6 is equal to the number of set bits in 12.





//Solution Approach :- BASIC SOLUTION - O(N logN) Time Complexity
// First calculate the count of no.of.set bits in A and B. Based on the number of set bits in A and B, we have three cases.
// We know that XOR of a number with itself is zero. Considering this two points , we can get the required number.
// 1. CASE 1 : If the Number of Set bits in A and B are equal, then we can simply consider X=A because since the number of set bits in A and B are equal, then the number of set bits in X must also be equal to number of set bits in A . So If we take X=A , XOR will be minimum with the required condition of no.of.set bits.
// 2. CASE 2 : If the Number of set bits in A is greater than number of set bits in B. In this case , we try to minimise the XOR and maintain same no.of.set bits as in B, in that case we need to eliminate the 1's contributed by MSB's in XOR.
// 3. CASE 3 : If the Number of Set bits in A are lesser than that in B, simply set the bits of A from LSB until the number of set bits in A are equal to that of B. This is done because, we can't decrease the value of A, in order to increase set bits only thing we can do is to set the bits to right as much as possible to minimise the xor value.

class Solution {
public:
  	int count(int x){
      	int c=0;
      	while(x){
          	c += (x&1);
          	x>>=1;
      	}
      	return c;
  	}
    
    int minVal(int a, int b) {
        int ans=0;
        if(count(a) == count(b)){
            ans=a;
        }
        else if(count(a)>count(b)){
            int i=0;
            int x=a;
            while(count(x)>count(b)){
                x=x>>1;
                i++;
            }
            x=(x<<i);
            ans=x;
        }
        else{
            int x=a;
            int i=0;
            while(count(x)<count(b)){
                 x=x|(1<<i);
                 i++;
            }
           ans=x;
        }
        return ans;
    }
};




//Second Solution :-
class Solution {
  public:
    int minVal(int a, int b) {
        int c=0;
        while(b){
            b=b&(b-1);
            c++;
        }

        int ans=0;
        for(int i=31;i>=0;i--){
            if(c<=0){
                break;
            }
            if((a&(1<<i))>0){
                c--;
                ans+=(1<<i);
            }
        }
        
        for(int i=0;i<31&&c>0;i++){
            if((ans&(1<<i))==0){
                ans+=(1<<i);
                c--;
            }
        }
        return ans;
    }
};



//Third Solution :-
// Given two integers, 'a' and 'b', the task is to find an 
    // integer, 'x', such that 'x' XOR 'a' is minimal and the 
    // count of ones for 'x' is that of 'b'. 
    // 
    // Strategy: Initialize 'x' to 'a' and keep the most-significant 
    // bits (MSBs) from 'a' so that when 'x' is XORed with the 
    // original 'a', the MSBs will cancel out, leaving the remaining 
    // bits to contribute as little as possible to the XOR value. In 
    // the case where 'b' has more set bits than 'a' does, i.e., 
    // ones need to be added to 'x', then keep all the set bits from
    // 'a' but flip its least-significant zeroes until enough bits
    // are set.


class Solution {
    static int LSB(int x){          // Returns the least-significant bit (LSB)
        return x & -x;              // E.g., LSB(0b01101000) -> 0b0001000
    }
    
    static int countBits(int x){     // Repeatedly applies LSB to count bits in O(log(N)) time
        int n{};
        while (x) {
            ++n;
            x &= ~LSB(x);
        }
        return n;
    }
    
public:
    int minVal(int a, int b) {
        int na = countBits(a), nb = countBits(b);
        
        for(int i = 0; i < na - nb; ++i) {
            a &= ~LSB(a);                // Strip off excess least-significant ones
        }
        for(int i = 0; i < nb - na; ++i) {
            a |= LSB(~a);                // Flip the least-significant zeros
        }
        return a;                        // 'x' is the new 'a'
    }
};



//Fourth Solution :-
int minVal(int a, int b) {
    int cnta = __builtin_popcount(a), cntb = __builtin_popcount(b), x = 0 ;
    if(cntb <= cnta){
        int to_use = cntb;
        for(int i=30 ; i>=0 ; i--){
            if(a&(1<<i) && to_use)
                x = (x|(1<<i)) , to_use-- ;
        }
        return x ;
    }
    else{
        int extra = cntb-cnta ;
        for(int i=0 ; i<31 ; i++){
            if(a&(1<<i))
                x = (x|(1<<i)) ;
            else if(extra)
                x = (x|(1<<i)), extra--  ; 
        }
        return x ;
    }
}

//Explanation: let cnta be no of bits set in ‘a’ and cntb be no of bits set in ‘b’.
//if cnta ≥ cntb , then flipping the bits of ‘a’ from the most significant side onwards would be most beneficial for us so as to make the XOR minimum. ( note: 1xor1 = 0 , so set x's bit to 1 where a's bit is 1. set cntb of those bits to 1 from most significant side).
//if cnta < cntb , then after flipping all the bits of a and making it zero, we need to further flip some 0's and make them 1, in order to make total set bits of x to cntb. To minimise this, set bits from least significant side onwards. Make sure not to flip the bits you have already flipped. 


//Fifth Solution :-
//count no of set bits in n 
int setBits(int n){
    int cnt=0;
    while(n){
        n&=(n-1);
        cnt++;
    }
    return cnt;
}

// closest power of 2 greater than equal to n
int nearestPower(int n){ 
    int x=1;
    while(n){
        n>>=1;
        x<<=1;
    }
    return x>>1;
}

int minVal(int a, int b) {
    int bitsA=setBits(a),bitsB=setBits(b);
    if(bitsA==bitsB){
        return a;
    }

    int ans=0;
    for(int i=nearestPower(a);i>0 && bitsB;i>>=1){
        if(a & i){
           ans|=i;
           bitsB--;
        }
    }

    if(bitsB){
        for(int i=1;bitsB;i<<=1){
            if(!(a&i)){
                ans|=i;
                bitsB--;
            }
        }
    }
    return ans;
}



//Sixth Solution :-
int minVal(int a, int b) {
    int cnt_a = __builtin_popcount(a);
    int cnt_b = __builtin_popcount(b);
    
    int num = 0;
    if(cnt_a >= cnt_b){
        num = a;
        int tmp = cnt_a-cnt_b, i=0;
        while(tmp){
            if((1&(num>>i)) == 1){
                num ^= (1<<i);
                tmp -= 1;
            }
            i += 1;
        }
    }
    else{
        num = a;
        int tmp = cnt_b-cnt_a, i=0;
        while(tmp){
            if((1&(num>>i)) == 0){
                num |= 1<<i;
                tmp -= 1;
            }
            i += 1;
        }
    }
    return num;
}