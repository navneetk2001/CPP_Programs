// Divide two integers without using multiplication, division and mod operator.
// Return the floor of the result of the division.
// Example:
// 	5 / 2 = 2
// Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
// Note: INT_MAX = 2^31 - 1

//Hint :-
dividend = answer * divisor + c
You need to find the answer here without using any of the operators mentioned in the question. Think about the binary expansion of answer.
We can work with bits without using the standard operators. If you can find what bits are set in answer you will be done.

//Solution Approach :- 
Think in terms of bits.
How do you do the division with bits?
How do you determine the most significant bit in the answer?
Iterate on the bit position ‘i’ from 31 to 1 and find the first bit for which divisor«i is less than dividend.
How do you use (1) to move forward in similar fashion?


//First Solution :-
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


//Second Solution :-
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

