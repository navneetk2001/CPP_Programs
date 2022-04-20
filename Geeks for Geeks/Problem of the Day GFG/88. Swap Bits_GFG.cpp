Given a number X and two positions (from right side) in binary representation of x, write a program that swaps N bits at given two positions and returns the result.

Example 1:
Input:
X = 47
P1 = 1
P2 = 5
N = 3
Output: 227
Explanation:
The 3 bits starting from the second bit (from the right side) are swapped with 3 bits
starting from 6th position (from the right side) 
X = 47 (00101111)
[001]0[111]1
ANS = [111]0[001]1
ANS = 227 (11100011)
Hence, the result is 227.  
 

Example 2:
Input:
X = 28
P1 = 0
P2 = 3
N = 2
Output: 7


//Solution Approach :- Simple brute force solution
// get bit from p1
// unset bit at p2
// set bit at p2
// repeat same for p1
 
int swapBits(int x, int p1, int p2, int n){
    for(int i=0;i<n;i++)
    {
      // get bits at both position 
      int  getp1bit = (x&(1<<p1+i))>0;
      int  getp2bit = (x&(1<<p2+i))>0;
                
      // create a bitmask  ex 111011 to remove 3rd bit
      int  unsetp1mask = ~(1<<(p1+i));
      int  unsetp2mask = ~(1<<(p2+i));
    
      // remove bit from both positions 
      x = x & unsetp1mask;
      x = x & unsetp2mask;

     // shift p1's bit to p2 position and vice versa
     getp1bit= getp1bit<<(p2+i);
     getp2bit= getp2bit<<(p1+i);

     // set bit 
      x = x|getp2bit;
      x = x|getp1bit;
    }
    return x;
}


//Second Solution :- Prerequisite knowledge to solve the problem 
To set a bit use or 
To unset a bit use and 
If (a ^ b)== c
	b = a ^ c
	a = b ^ c
To swap N bits  lets consider an example 

47 => 00101111
a = 111 (say)
b = 001 (say)
c = a ^ b => 110

Now, To perform xor operation on index from p1 and p2 we require ..110…110…. form. 
so, we would update c as 
   c = (c << p1) | (c << p2);


int swapBits(int x, int p1, int p2, int k){
    unsigned int a = (x >> p1) & ((1U << k) - 1);   // 00000111
    unsigned int b = (x >> p2) & ((1U << k) - 1);   // 00000001
    unsigned int c = (a ^ b);                       // 00000110
    c = ((c << p1)  | (c << p2));                   // 11001100
    
    return (x ^ c);     // 00101111 ^ 11001100 => 11100011(227)
}



//Third Solution :-
int swapBits(int x, int p1, int p2, int n){
    vector<int>v(32,0);
    int i=0,p=0;
    while(x){
        int t=x&1;
        v[i++]=t;
        x>>=1;
    }
    
    while(n--)
        swap(v[p1++],v[p2++]);
    
    for(int i=0;i<32;i++){
       if(v[i])
           x+=pow(2,p);
       p++;
    }
    return x;
}


//Fourth Solution :-simple solution using left shift and right shift
int swapBits(int x, int p1, int p2, int n)
{
    int ans1=0,ans2=0;
    for(int i=p1;i<p1+n;i++)if(x&(1<<i))ans1+=(1<<i);
    for(int i=p2;i<p2+n;i++)if(x&(1<<i))ans2+=(1<<i);
    int s=p2-p1;
 
    return (x-ans1+(ans1<<s)-ans2+(ans2>>s));
}