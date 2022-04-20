// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

// Example 1:
// Input:
// a = 10, b= 3
// Output: 3
// Exaplanation: 10/3 gives quotient as 3 and remainder as 1.

// Example 2:
// Input:
// a = 43, b = -8
// Output: -5
// Explanation: 43/-8 gives quotient as -5 and remainder as 3.



//Optimal Solution Approach :- Follow below in binary representation  using bit maipulation
//Dividend = Divvisor * Quotient + Remainder
// 43 = 8 * Quo + rem
// 43 = 8 * pow(2, 2)  => 43 - 8 * 2^2  => 11
// 11 = 8 * pow(2,0)   => 11 - 8 * 2^0 => 3

// 43 = 8 * (pow(2,2) + pow(2,0)) + 3
// 43 = 8 * Quotient + Remainder        //Represent Quotient in Binary Form
// Quotient => 4+1 => 5

// 1<<2 => 4
// 1<<0 => 1


//Solution using bit Manipulation for GFG :-
class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long quotient = 0, temp =0;
        for(int i=31;i>=0;i--){
	        if(temp + (divisor << i) <= dividend){
	            temp += divisor << i;
	            quotient += 1ll << i;
	        }
    	}

    	if(sign==-1) quotient=-quotient;
    	return quotient;
    }
};



//First Solution :- Using Bit Manipulation 
int Solution::divide(int A, int B) {
    long long a=A, b=B;
    int sign = 0;   //0 for positive and 1 for negative

    if(a==0) return 0;
    if(b==0) return INT_MAX;
    if((a>0 && b<0) || (a<0 && b>0)) sign = 1;
    if(a<0) a=-a;
    if(b<0) b=-b;

    long long int ans=0, temp=0;
    for(int i=31;i>=0;i--){
        if(temp+(b<<i)<=a){
            temp+=b<<i;
            ans+=1ll<<i;
        }
    }

    if(sign==1) ans=-ans;
    if(ans>INT_MAX || ans<INT_MIN) return INT_MAX;
    return ans;

}


//Second Solution :- Repetated division  :- T.C :- O(N)
int Solution::divide(int A, int B) {
    if(A==INT_MIN&&B==-1)
        return INT_MAX;
        
    long long int a=A,b=B;
    int sign = ((A < 0) ^ (B < 0)) ? -1 : 1;
    a=abs(a);
    b=abs(b);

    int ans=0;
    while(a>=b){ 
        a=a-b;
        ans++;
    }
    return ans*sign;
}

//Third Solution :- 
int Solution::divide(int A, int B) {
    int n1 = A < 0, n2 = B < 0;
    long long int a = A, b = B;
    a = abs(a);
    b = abs(b);
    double da = log(a);
    double db = log(b);
    long long int ans = exp(da - db);
    if (n1 ^ n2)
        ans = -ans;
    if (ans > INT_MAX || ans < INT_MIN)
        return INT_MAX ;
    return ans;
}





