Given two integers a and b. Find the sum of two numbers without using arithmetic operators.

Example 1:
Input:
a = 5, b = 3
Output: 8
Explanation : 5 + 3 = 8

Example 2:
Input:
a = 10, b = 30
Output: 40
Explanation: 10 + 30 = 40



//Solution Approach :-
int sum(int a , int b){
   short carry = 0;
   int ans = 0;
   for(int i = 0; i < 30; i++){
       int bit1 = (a>>i) & 1;
       int bit2 = (b>>i) & 1;
       int sum = carry + bit1 + bit2;
       if(sum == 0) 
       		carry = 0;
       else if(sum == 1){
           ans |= (1<<i);
           carry = 0;
       }
       else if(sum == 2){
           carry = 1;
       }
       else if(sum == 3){
           ans |= (1<<i);
           carry = 1;
       }
   }
   return ans;
}



//Second Solution :-
class Solution
{
    public:
    int sum(int a , int b)
    {
        int carry = 0 , ans = 0;
        for(int i = 0 ;  i < 30 ; i++){
            int bit1 = (a &(1 << i)) ? 1 : 0;
            int bit2 = (b &(1 << i)) ? 1 : 0;
            if(bit1 && bit2){
                if(carry){
                    ans |= (1 << i);
                }
                carry = 1;
            }
            else if(bit1){
                if(carry == 0)
                ans |= (1 << i);
            }
            else if(bit2){
                if(carry == 0)
                ans |= (1 << i);
            }
            else if(carry){
                ans |=(1 << i);
                carry = 0;
            }
        }
        return ans;
    }
};



//Third Solution :-
class Solution
{
    public:
    int sum(int a , int b)
    {
        int c = a&b;
        int s = a^b;
        
        while(c){
            int shift = c<<1;
            c = s&shift;
            s = s^shift;
        }
        return s;
    }
};


//Fourth Solution :-
int sum(int a , int b)
{
    if(b==0)
        return a;
    else
        return sum(a^b,(unsigned)(a&b)<<1);
}