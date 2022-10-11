// Implement pow(x, n) % d.
// In other words, given x, n and d,
// find (x^n % d)
// Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.

// Example Input:
// x = 2
// n = 3
// d = 3
// Example Output: 2
// Example Explanation: 2^3 % 3 = 8 % 3 = 2.

//Solution Approach
// There are two major things to note here:
// 1. Overflow situation: Note that if x is large enough, multiplying x to the answer might overflow in integer.
// 2) Multiplying x one by one to the answer is O(n). We are looking for something better than O(n).
// If n is even, note the following:
// x ^ n = (x * x) ^ n/2
// Can you use the above observation to come up with a solution better than O(n)?


// First Method :-
int Solution::pow(int x, int n, int d) {
    long long int res=1,p=x,q=n;
    while(q>=1){
        if(q==1) {
            res*=p%d;
            q=q/2;
        }       
        else if(q%2==0){
            p=p*p%d;
            q=q/2;
        }
        else{
            res=res*p%d;
            q=q-1;
        }    
    }
    return (res+d)%d;
}


//Second Method :-
int Solution::pow(int x, int n, int p) {
     if (n == 0) 
        return 1 % p;

    long long ans = 1, base = x;
    while (n > 0) 
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % p;
            n--;
        } 
        else
        {
            base = (base * base) % p;
            n /= 2;
        }
    }
    if (ans < 0) {
        ans = (ans + p) % p;
    }
    return ans;
}


//Third Method :-
int Solution::pow(int x, int n, int d) {
    if(x==0)return 0;
    if(n==0)return 1;
    long long int a=pow(x,n>>1,d),ans=1;
    if(n%2)ans=x;
    ans=(ans*a)%d;
    ans=(ans*a)%d;
    return (ans+d)%d;
}


//Fourth Method :-   //x^n
double myPow(double x, int n){
    double ans = 1.0;
    long nn = n;
    if(nn<0)  nn = -1*nn;
    while(nn>0){
        if(nn%2==1){
            ans=ans*x;
            nn=nn-1;
        }
        else{
            x *= x;
            nn = nn/2;
        }
    }
    if(n<0) ans = (double)(1.0) / (double)(ans);
    return ans;
}





