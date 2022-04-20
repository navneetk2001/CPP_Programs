// Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.
// Return the count modulo 10^9 + 7.

// Input 1:
//  A = 3
// Output 1:
//  4
// Explanation 1:
//  DECIMAL    BINARY  SET BIT COUNT
//     1          01        1
//     2          10        1
//     3          11        2
//  1 + 1 + 2 = 4 
//  Answer = 4 % 1000000007 = 4

//Hint :-
If we observe bits from rightmost side at distance i than bits get inverted after 2i position in vertical sequence.
For example A = 5;
0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
Observe the right most bit (i = 0) the bits get flipped after (20 = 1)
Observe the 3rd rightmost bit (i = 2) the bits get flipped after (22 = 4)
So, We can count bits in vertical fashion such that at i’th right most position bits will be get flipped after 2i iteration;

//Solution Approach :- 
So, we will iterate till the number of bits in the number. And we don’t have to iterate every single number in the range from 1 to A.
We will perform the following operations to get the desired result.

First of all, we will add 1 to the number in order to compensate 0. As the binary number system starts from 0. So now A = A + 1.
We will keep the track of the number of set bits encountered till now. And we will initialise it with A/2.
We will keep one variable which is a power of 2, in order to keep track of bit we are computing.
We will iterate till the power of 2 becomes greater than A.
We can get the number of pairs of 0s and 1s in the current bit for all the numbers by dividing A by current power of 2.
Now we have to add the bits in the set bits count. We can do this by dividing the number of pairs of 0s and 1s by 2 which will give us the number of pairs of 1s only and after that, we will multiply that with the current power of 2 to get the count of ones in the groups.
Now there may be a chance that we get a number as number of pairs, which is somewhere in the middle of the group i.e. the number of 1s are less than the current power of 2 in that particular group. So, we will find modulus and add that to the count of set bits.
Time Complexity : O(logA)


//First Solution :-
#define lli long long int
int Solution::solve(int A) {
  A++; 
  lli i=2,ans=0;
  while(A/i>0)
  {
      ans+=A/i *(i/2); //a full set of 1 
      ans+=(A%i>(i/2))?A%i-(i/2):0; // a partial set of 1
      i*=2;
  }
  ans+=(A%i>(i/2))?A%i-(i/2):0;  //last partial set of 1 cuz no. of full set of ones is 0
  return (ans%1000000007); //finally take mod as took long long so no problem
}

//Second Solution :-
int extra_val(int A, int pos)
{
    if(A%pos - pos/2 <0)
    {
        return 0;
    }
    else
    {
        return A%pos - pos/2 + 1;
    }
}

int Solution::solve(int A) {
    long long int pos = 2;
    long long int ans = 0;
    while(pos<A)
    {
        ans += ((A/pos)*pos/2 + extra_val(A,pos));
        pos*=2;
    }
    ans += ((A/pos)*pos/2 + extra_val(A,pos));
    if(A==pos)
    {
        ans+=1;
    }
    ans%=1000000007;
    return ans;
}

//Third Solution :- 
#define MOD 1000000007
    #define ll long long int
    ll leftmost (ll n) {    //function to find the leftmost set bit
        int pos = 0;
        while(n > 1)  {
            pos++;
            n = n >> 1;
        }
        return pos;
    }
    ll countBits (ll n)  {
        if(n == 0)    return 0; //if the number is 0 return 0
        ll m = leftmost(n);
        if(n == ((1 << (m + 1)) - 1))   return ((m + 1)*(1 << m));  //if number is of form 2^b-1 return directly
        n = n - (1 << m);   //if not all bits are set
        return (n + 1) + (m * ( 1 << (m - 1))) + countBits(n);  //recursively calling for the rest of the bits
    }
    int Solution::solve(int n) {
        ll result = countBits(n);
        return result%MOD;
    }


//Fourth Solution :-
int Solution::solve(int A) {
    vector<int> vstrips;
    int set_bits = 0;
    int rep = 0;
    int sets = 0;
    int unpack_elements = 0;
    int unpack_set_bits = 0;
    int total_set_bits = 0;
    int i=0;
    while(pow(2,i) <= A ){
        rep = pow(2,i+1); //repeat of bits in vertical order
        sets = (A+1)/rep;
        unpack_elements = (A+1)%rep;

        if(rep/2 != 0 && unpack_elements != 0 && unpack_elements/(rep/2)){
            unpack_set_bits = unpack_elements%(rep/2);
        }
        else{
            unpack_set_bits = 0;
        }

        total_set_bits += sets*pow(2,i) + unpack_set_bits;
        total_set_bits %= 1000000007;
        i++;
    }

    return total_set_bits%1000000007;
}
