// Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.
// The digit sum of a positive integer is the sum of all its digits.

// Example 1:
// Input: num = 4
// Output: 2
// Explanation:
// The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    

// Example 2:
// Input: num = 30
// Output: 14
// Explanation:
// The 14 integers less than or equal to 30 whose digit sums are even are
// 2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.



//Solution Approach :-
class Solution {
public:
    int dig(int k)
    {
     int sum=0;
        while(k)
        {
            sum+=k%10;
            k/=10;
        }
        return sum;
    }
    
    int countEven(int num) {
        int count=0;
        
        for(int i=1;i<=num;i++)
        {
            if(dig(i)%2==0) count++;
        }
        return count;
    }
};



//Solution :- 
int countEven(int num) {
    if(num==1)
        return 0;
    int i=2;
    int count=0;
    while(i<=num){
        if(i<10){
            if(i%2==0)
                count++;
            
        }
        else if(i<100){
            int t1=i/10;
            int t2=i%10;
            if((t1+t2)%2==0)
                count++;
                       }
        else if(i<999){
            int temp=i;
            int t1=temp%10;
            temp=temp/10;
            int t2=temp%10;
            temp=temp/10;
            int t3=temp%10;
            if((t1+t2+t3)%2==0)
                count++;
           
        }
        i++;
    }
     return count;
}