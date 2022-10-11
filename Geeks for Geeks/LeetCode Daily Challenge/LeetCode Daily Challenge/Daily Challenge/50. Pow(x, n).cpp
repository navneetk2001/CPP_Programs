// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:
// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25




//Different Solution Approaches :- 5 different choices when talk with interviewers
//After reading some good sharing solutions, I'd like to show them together. You can see different ideas in the code.

//1. nest myPow
double myPow(double x, int n) {
    if(n<0){
       	return 1/x * myPow(1/x, -(n+1));
    }
    if(n==0){
    	return 1;
    }
    if(n==2){
    	return x*x;
    }
    if(n%2==0){
    	return myPow(myPow(x, n/2), 2);
    }
    else{
    	return x*myPow( myPow(x, n/2), 2);
    }
}


//2. double myPow
double myPow(double x, int n) { 
    if(n==0){
    	return 1;
    }
    double t = myPow(x,n/2);
    if(n%2){
    	return n<0 ? 1/x*t*t : x*t*t;
    }
    else{
    	return t*t;
    }
}



//3. double x
double myPow(double x, int n) { 
    if(n==0){
    	return 1;
    }
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}



//4. iterative one
double myPow(double x, int n) { 
    if(n==0){
    	return 1;
    }
    if(n<0){
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}


//5. bit operation
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        auto i = n;
        while(n!=0) {
            if(n&1)ans*=x;
            x*=x;
            n=n/2;
        }
        return i>=0?ans:1/ans; 
    }
};