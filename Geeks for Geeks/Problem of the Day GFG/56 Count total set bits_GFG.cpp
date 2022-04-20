// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Example 1:
// Input: N = 4
// Output: 5
// Explanation:
// For numbers from 1 to 4.
// For 1: 0 0 1 = 1 set bits
// For 2: 0 1 0 = 1 set bits
// For 3: 0 1 1 = 2 set bits
// For 4: 1 0 0 = 1 set bits
// Therefore, the total set bits is 5.

// Example 2:
// Input: N = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive), 
// the total number of set bits is 35.



//Solution Approach :-
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n==0)
        	return 0;

        int x= log2(n);
        int ans = x*(1<<(x-1)) + (n-(1<<x))+1+countSetBits(n-(1<<x));
        return ans;
    }
};


//Second Solution :-
int countSetBits(int n)
{
   int count = 0;
   int i = 1;
   int x = 0;
   if( n == 0 )
   {
       return 0;
   }
   while(i <= n)
   {
       x  = i;
       while(x > 0)
       {
           (x & 1)? count++ : 0;
           x = x >> 1;
       }
       i++;
   }
   
   return count;
}


//Third Solution :-
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
         int i=log2(n);
         int r=0;
         int x=1;
         for(int j=0;j<=i;j++)
         {
             int y=n-(x-1);
             int d1=y/x;
             r+=(ceil((double)d1/2))*x;
             if(d1%2==0)
             r+=y%x;
             x*=2;
         }
         return r;
    }
};